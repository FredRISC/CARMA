// See LICENSE for license details.

//**************************************************************************
// Transpose benchmark
//--------------------------------------------------------------------------
//
// This benchmark tests a vectorized matrix transpose implementation.

#include "stdio.h"
#include <string.h>
#include "util.h"

//--------------------------------------------------------------------------
// Input/Reference Data

#include "dataset2.h"

//--------------------------------------------------------------------------
// Main

void *vec_transpose (size_t, size_t, const int8_t*, int8_t*);

int main( int argc, char* argv[] )
{
  int8_t results_data[ARRAY_SIZE] = {0};

#if PREALLOCATE
  // If needed we preallocate everything in the caches
  vec_transpose(DIM_N, DIM_M, input_matrix, results_data);
  memset(results_data, 0, sizeof(results_data));
#endif


  unsigned long cycles1, cycles2;
  int64_t total;
  cycles1=read_csr(mcycle);
  setStats(1);
  vec_transpose(DIM_N, DIM_M, input_matrix, results_data);
  setStats(0);
  cycles2=read_csr(mcycle);
  total = cycles2 - cycles1;
  printf("total cycles for transposing: %d",total);
  // Check the results
  return 0;
  //verifyFloat( ARRAY_SIZE, results_data, verify_data );
}
