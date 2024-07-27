#include "s21_test.h"

void check_created_matrix(int rows, int columns, matrix_t *sample) {
  ck_assert_int_eq(rows, sample->rows);
  ck_assert_int_eq(columns, sample->columns);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      ck_assert_double_eq_tol(0, sample->matrix[i][j], EPS_CHECK);
    }
  }
}

void check_no_matrix(matrix_t sample) {
  ck_assert_int_eq(0, sample.rows);
  ck_assert_int_eq(0, sample.columns);
  ck_assert_ptr_null(sample.matrix);
}

void copy_matrix(double **src, matrix_t *dst, int rows, int columns) {
  for (int i = 0; i < rows; i++) {
    memcpy(dst->matrix[i], src[i], columns * sizeof(double));
  }
}

void check_res(matrix_t *res, matrix_t *expected_res) {
  ck_assert_int_eq(expected_res->rows, res->rows);
  ck_assert_int_eq(expected_res->columns, res->columns);
  for (int i = 0; i < expected_res->rows; i++) {
    for (int j = 0; j < expected_res->columns; j++) {
      ck_assert_double_eq_tol(expected_res->matrix[i][j], res->matrix[i][j],
                              EPS_CHECK);
    }
  }
}