// Copyright 2020 ETH Zurich and University of Bologna.
//
// SPDX-License-Identifier: Apache-2.0
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

// Author: Matheus Cavalcante, ETH Zurich
//         Samuel Riedel, ETH Zurich

#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "imatmul.h"
#include "util.h"

#define TotalBits 32 //1 word

// Define Matrix dimensions:
// C = AB with A=[MxN], B=[NxP], C=[MxP]  //8192*4/8=64*64=4096  //16*16*8/32=256*8/32=64
extern uint64_t M; //64
extern uint64_t N; //64
extern uint64_t P; //64

extern int8_t a[] __attribute__((aligned(TotalBits))); //64*4=256 = SEW*LMUL = total bit in a vregister (capped by VLEN=256)   //8*4=32
extern int8_t b[] __attribute__((aligned(TotalBits))); //256 = 8 words = 32 bytes
extern int8_t c[] __attribute__((aligned(TotalBits)));
// Gold results
extern int8_t g[] __attribute__((aligned(TotalBits)));

// Verify the matrix
int verify_matrix(int8_t *result, int8_t *gold, size_t R, size_t C) {
  for (int8_t i = 0; i < R; ++i) {
    for (int8_t j = 0; j < C; ++j) {
      int8_t idx = i * C + j;
      if (result[idx] != gold[idx]) {
        return (i + j) == 0 ? -1 : idx;
      }
    }
  }
  return 0;
}

int main() {
  printf("IMATMUL\n");
  unsigned long cycles1, cycles2, instr2, instr1;

  for (int s = 4; s <= M; s *= 2) { //4, 16, 64
    printf("Calculating a (%d x %d) x (%d x %d) matrix multiplication...\n", s,
           s, s, s);

    // Matrices are initialized --> Start calculating
    printf("Calculating imatmul...\n");
    instr1 = read_csr(minstret);
    cycles1 = read_csr(mcycle);
    imatmul(c, a, b, s, s, s); //M, N, P = 64
    asm volatile("fence");
    instr2 = read_csr(minstret);
    cycles2 = read_csr(mcycle);


    // Metrics
    int64_t runtime = cycles2 - cycles1;
    float performance = 2.0 * s * s * s / runtime;

    printf("The execution took %d cycles.\n", runtime);
    printf("The performance is %ld OPs/1000 cycles.\n", (uint64_t)(1000.0 * performance));

    // Verify the result only for s == M (to keep it simple)
    if (s == M) {
      // Verify the result
      printf("Verifying result...\n");
      int error = verify_matrix(c, g, s, s);
      if (error != 0) {
        printf("Error code %d\n", error);
        printf("c[%d]=%d\n", error, c[error]);
        return error;
      } else {
        printf("Passed.\n");
      }
    }
  }

  return 0;
}
