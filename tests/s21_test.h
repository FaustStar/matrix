#ifndef S21_MATRIX_TEST_H
#define S21_MATRIX_TEST_H

#include <check.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_matrix.h"

#define EPS_CHECK 1e-6

#define MATRIX1_1         \
  (double *[]) {          \
    (double[]) { 34.182 } \
  }

#define MATRIX2_2                                                  \
  (double *[]) {                                                   \
    (double[]){159.167, -1687.997}, (double[]) { 3795.67, 1.7851 } \
  }

#define MATRIX2_2__1                                   \
  (double *[]) {                                       \
    (double[]){0, -1687.997}, (double[]) { 0, 1.7851 } \
  }

// det(MATRIX2_2__2) = 0
#define MATRIX2_2__2                                                \
  (double *[]) {                                                    \
    (double[]){0.000156, -0.00015}, (double[]) { 0.000067, 0.0005 } \
  }

#define MATRIX2_3                                             \
  (double *[]) {                                              \
    (double[]){2.6, 5.8, 1.0}, (double[]) { 3.7, 0.0, -17.1 } \
  }

#define MATRIX2_3__1                                                      \
  (double *[]) {                                                          \
    (double[]){-189.35, -37.0, 25.104}, (double[]) { 36.7, -17.3, 48.58 } \
  }

#define MATRIX2_4                                              \
  (double *[]) {                                               \
    (double[]){-5, 15, 47, 38}, (double[]) { 27, -13, -14, 8 } \
  }

#define MATRIX3_4                                                   \
  (double *[]) {                                                    \
    (double[]){15.0056767, 0.0017769, -2.0056017, 3.0030044},       \
        (double[]){-4.0011767, 10.0065769, -33.4259002, 1.5533448}, \
        (double[]) {                                                \
      7.6734219, 13.9137824, 2.0056017, -8.8137925                  \
    }                                                               \
  }

#define MATRIX3_3                                                          \
  (double *[]) {                                                           \
    (double[]){67.15, -14.367, -3.2}, (double[]){37.25, -10.876, 111.105}, \
        (double[]) {                                                       \
      56.87, 1654.2, -4.1589                                               \
    }                                                                      \
  }

#define MATRIX3_3__1                                                   \
  (double *[]) {                                                       \
    (double[]){12, 57.5, 14.267896}, (double[]){-3.782, 1.256, -0.14}, \
        (double[]) {                                                   \
      26, 37.64, 8.7                                                   \
    }                                                                  \
  }

#define MATRIX4_3                                                          \
  (double *[]) {                                                           \
    (double[]){0, 64, 32}, (double[]){-25, 67, 23}, (double[]){0, -4, 38}, \
        (double[]) {                                                       \
      -1, -7, 0                                                            \
    }                                                                      \
  }

#define MATRIX5_5                                              \
  (double *[]) {                                               \
    (double[]){67.15, -14.367, -3.2, 16.0, -9.15},             \
        (double[]){37.25, -10.876, 111.105, 0, -48.6},         \
        (double[]){56.87, 1654.2, -4.1589, 167.3, 97.38},      \
        (double[]){3.8, 74.0, 6.1, 0.198, -12.7}, (double[]) { \
      -1.6, 0.8, 2.8, -4.5, 0.1                                \
    }                                                          \
  }

// (MATRIX2_2* alg complements)
#define RES_MATRIX2_2                                              \
  (double *[]) {                                                   \
    (double[]){1.7851, -3795.67}, (double[]) { 1687.997, 159.167 } \
  }

// (MATRIX2_2 (-1))
#define RES_MATRIX2_2__1                                                   \
  (double *[]) {                                                           \
    (double[]){0.0000002, 0.0002634}, (double[]) { -0.0005923, 0.0000248 } \
  }

// (MATRIX2_3__1 * 6.789643)
#define RES_MATRIX2_3                                                    \
  (double *[]) {                                                         \
    (double[]){-1285.61890205, -251.216791, 170.447197872}, (double[]) { \
      249.1798981, -117.4608239, 329.84085694                            \
    }                                                                    \
  }

// (MATRIX2_3 - MATRIX2_3__1)
#define RES_MATRIX2_3__1                                                \
  (double *[]) {                                                        \
    (double[]){191.95, 42.8, -24.104}, (double[]) { -33, 17.3, -65.68 } \
  }

// (MATRIX2_3 * MATRIX3_3__1)
#define RES_MATRIX2_3__2                                    \
  (double *[]) {                                            \
    (double[]){35.2644, 194.4248, 44.9845296}, (double[]) { \
      -400.2, -430.894, -95.9787848                         \
    }                                                       \
  }

// (MATRIX2_4 * MATRIX4_3)
#define RES_MATRIX2_3__3                                     \
  (double *[]) {                                             \
    (double[]){-413, 231, 1971}, (double[]) { 317, 857, 33 } \
  }

// (MATRIX3_3 + MATRIX3_3) or (2 * MATRIX3_3)
#define RES_MATRIX3_3                                                    \
  (double *[]) {                                                         \
    (double[]){134.3, -28.734, -6.4}, (double[]){74.5, -21.752, 222.21}, \
        (double[]) {                                                     \
      113.74, 3308.4, -8.3178                                            \
    }                                                                    \
  }

// (MATRIX3_3 + MATRIX3_3__1)
#define RES_MATRIX3_3__1                                                      \
  (double *[]) {                                                              \
    (double[]){79.15, 43.133, 11.067896}, (double[]){33.468, -9.62, 110.965}, \
        (double[]) {                                                          \
      82.87, 1691.84, 4.5411                                                  \
    }                                                                         \
  }

// (MATRIX3_3 - MATRIX3_3__1)
#define RES_MATRIX3_3__2                                   \
  (double *[]) {                                           \
    (double[]){55.15, -71.867, -17.467896},                \
        (double[]){41.032, -12.132, 111.245}, (double[]) { \
      30.87, 1616.56, -12.8589                             \
    }                                                      \
  }

// (MATRIX3_3 ^T)
#define RES_MATRIX3_3__3                                                   \
  (double *[]) {                                                           \
    (double[]){67.15, 37.25, 56.87}, (double[]){-14.367, -10.876, 1654.2}, \
        (double[]) {                                                       \
      -3.2, 111.105, -4.1589                                               \
    }                                                                      \
  }

// (MATRIX3_3* alg complements)
#define RES_MATRIX3_3__4                                                   \
  (double *[]) {                                                           \
    (double[]){-183744.6588036, 6473.460375, 62237.46812},                 \
        (double[]){-5353.1909163, -97.286135, -111896.58129}, (double[]) { \
      -1631.048735, -7579.90075, -195.15265                                \
    }                                                                      \
  }

// (MATRIX3_3 (-1))
#define RES_MATRIX3_3__5                                           \
  (double *[]) {                                                   \
    (double[]){0.0145475, 0.0004238, 0.0001291},                   \
        (double[]){-0.0005125, 0.0000077, 0.0006001}, (double[]) { \
      -0.0049275, 0.0088591, 0.0000154                             \
    }                                                              \
  }

// (MATRIX3_3__1* alg complements)
#define RES_MATRIX3_3__6                                           \
  (double *[]) {                                                   \
    (double[]){16.1968, 29.2634, -175.01048},                      \
        (double[]){36.7936054, -266.565296, 1043.32}, (double[]) { \
      -25.9704773, -52.2811826, 232.537                            \
    }                                                              \
  }

// (MATRIX3_3__1 (-1))
#define RES_MATRIX3_3__7                                           \
  (double *[]) {                                                   \
    (double[]){-0.0261228, -0.0593422, 0.0418862},                 \
        (double[]){-0.0471971, 0.4299272, 0.0843211}, (double[]) { \
      0.2822639, -1.6827084, -0.375045                             \
    }                                                              \
  }

// (MATRIX4_3 ^T)
#define RES_MATRIX3_4                                                   \
  (double *[]) {                                                        \
    (double[]){0, -25, 0, -1}, (double[]){64, 67, -4, -7}, (double[]) { \
      32, 23, 38, 0                                                     \
    }                                                                   \
  }

Suite *create_suite(void);
Suite *remove_suite(void);
Suite *eq_suite(void);
Suite *sum_suite(void);
Suite *sub_suite(void);
Suite *mult_number_suite(void);
Suite *mult_suite(void);
Suite *transpose_suite(void);
Suite *determinant_suite(void);
Suite *complements_suite(void);
Suite *inverse_suite(void);

// helpers
void check_created_matrix(int rows, int columns, matrix_t *sample);
void check_no_matrix(matrix_t sample);
void copy_matrix(double **src, matrix_t *dst, int rows, int columns);
void check_res(matrix_t *res, matrix_t *expected_res);

#endif