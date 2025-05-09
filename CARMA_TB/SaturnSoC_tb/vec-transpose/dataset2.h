#define DIM_M 16
#define DIM_N 16
#define ARRAY_SIZE 256


int8_t input_matrix[ARRAY_SIZE] = {
  62, 68, 83, 71, 39, 20, 89, 87,
  33, 71, 19, 71, 67, 34, 28, 78,
  24, 52, 59, 8, 92, 40, 94, 34,
  62, 99, 78, 26, 8, 98, 10, 6,
  23, 0, 2, 72, 30, 52, 31, 42,
  76, 49, 68, 8, 35, 89, 3, 11,
  39, 54, 94, 19, 21, 86, 55, 3,
  86, 40, 39, 51, 14, 38, 82, 34,
  75, 99, 39, 98, 38, 73, 50, 46,
  6, 55, 76, 37, 61, 10, 63, 23,
  63, 68, 47, 55, 50, 56, 63, 35,
  41, 4, 14, 24, 18, 32, 81, 93,
  80, 60, 64, 23, 20, 7, 16, 61,
  23, 42, 31, 49, 68, 50, 12, 51,
  40, 36, 67, 14, 5, 86, 42, 78,
  69, 37, 93, 74, 51, 10, 48, 14,
  8, 82, 98, 31, 77, 2, 25, 53,
  7, 24, 27, 12, 95, 60, 61, 52,
  14, 77, 55, 71, 30, 95, 72, 45,
  79, 76, 12, 42, 62, 73, 12, 29,
  91, 37, 63, 85, 3, 49, 39, 35,
  33, 58, 73, 43, 92, 52, 8, 64,
  64, 62, 77, 45, 57, 32, 75, 35,
  5, 17, 62, 83, 48, 83, 45, 95,
  62, 75, 98, 12, 78, 12, 71, 41,
  0, 21, 47, 88, 61, 89, 48, 7,
  67, 96, 34, 61, 80, 94, 13, 25,
  64, 55, 50, 35, 2, 63, 71, 93,
  95, 36, 83, 93, 41, 49, 88, 91,
  85, 93, 98, 10, 0, 15, 98, 94,
  19, 14, 70, 74, 12, 3, 29, 9,
  40, 20, 1, 61, 12, 74, 52, 61,
};
int8_t verify_data[ARRAY_SIZE] = {
  62, 24, 23, 39, 75, 63, 80, 40,
  8, 14, 91, 64, 62, 67, 95, 19,
  68, 52, 0, 54, 99, 68, 60, 36,
  82, 77, 37, 62, 75, 96, 36, 14,
  83, 59, 2, 94, 39, 47, 64, 67,
  98, 55, 63, 77, 98, 34, 83, 70,
  71, 8, 72, 19, 98, 55, 23, 14,
  31, 71, 85, 45, 12, 61, 93, 74,
  39, 92, 30, 21, 38, 50, 20, 5,
  77, 30, 3, 57, 78, 80, 41, 12,
  20, 40, 52, 86, 73, 56, 7, 86,
  2, 95, 49, 32, 12, 94, 49, 3,
  89, 94, 31, 55, 50, 63, 16, 42,
  25, 72, 39, 75, 71, 13, 88, 29,
  87, 34, 42, 3, 46, 35, 61, 78,
  53, 45, 35, 35, 41, 25, 91, 9,
  33, 62, 76, 86, 6, 41, 23, 69,
  7, 79, 33, 5, 0, 64, 85, 40,
  71, 99, 49, 40, 55, 4, 42, 37,
  24, 76, 58, 17, 21, 55, 93, 20,
  19, 78, 68, 39, 76, 14, 31, 93,
  27, 12, 73, 62, 47, 50, 98, 1,
  71, 26, 8, 51, 37, 24, 49, 74,
  12, 42, 43, 83, 88, 35, 10, 61,
  67, 8, 35, 14, 61, 18, 68, 51,
  95, 62, 92, 48, 61, 2, 0, 12,
  34, 98, 89, 38, 10, 32, 50, 10,
  60, 73, 52, 83, 89, 63, 15, 74,
  28, 10, 3, 82, 63, 81, 12, 48,
  61, 12, 8, 45, 48, 71, 98, 52,
  78, 6, 11, 34, 23, 93, 51, 14,
  52, 29, 64, 95, 7, 93, 94, 61,
};
