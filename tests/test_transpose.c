#include "s21_test.h"

START_TEST(test_transpose_1) {
  int rows = 3, columns = 3;

  matrix_t sample;
  s21_create_matrix(rows, columns, &sample);
  copy_matrix(MATRIX3_3, &sample, rows, columns);

  matrix_t result;

  matrix_t expected_res;
  s21_create_matrix(rows, columns, &expected_res);
  copy_matrix(RES_MATRIX3_3__3, &expected_res, rows, columns);

  ck_assert_int_eq(s21_transpose(&sample, &result), OK);
  check_res(&result, &expected_res);

  s21_remove_matrix(&sample);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected_res);
}
END_TEST

START_TEST(test_transpose_2) {
  int rows = 3, columns = 3;

  matrix_t sample;
  s21_create_matrix(rows, columns, &sample);
  copy_matrix(RES_MATRIX3_3__3, &sample, rows, columns);

  matrix_t result;

  matrix_t expected_res;
  s21_create_matrix(rows, columns, &expected_res);
  copy_matrix(MATRIX3_3, &expected_res, rows, columns);

  ck_assert_int_eq(s21_transpose(&sample, &result), OK);
  check_res(&result, &expected_res);

  s21_remove_matrix(&sample);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected_res);
}
END_TEST

START_TEST(test_transpose_3) {
  int rows_1 = 4, columns_1 = 3;
  matrix_t sample;
  s21_create_matrix(rows_1, columns_1, &sample);
  copy_matrix(MATRIX4_3, &sample, rows_1, columns_1);

  matrix_t result;

  int rows_2 = 3, columns_2 = 4;
  matrix_t expected_res;
  s21_create_matrix(rows_2, columns_2, &expected_res);
  copy_matrix(RES_MATRIX3_4, &expected_res, rows_2, columns_2);

  ck_assert_int_eq(s21_transpose(&sample, &result), OK);
  check_res(&result, &expected_res);

  s21_remove_matrix(&sample);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected_res);
}
END_TEST

START_TEST(test_transpose_4) {
  int rows_1 = 3, columns_1 = 4;
  matrix_t sample;
  s21_create_matrix(rows_1, columns_1, &sample);
  copy_matrix(RES_MATRIX3_4, &sample, rows_1, columns_1);

  matrix_t result;

  int rows_2 = 4, columns_2 = 3;
  matrix_t expected_res;
  s21_create_matrix(rows_2, columns_2, &expected_res);
  copy_matrix(MATRIX4_3, &expected_res, rows_2, columns_2);

  ck_assert_int_eq(s21_transpose(&sample, &result), OK);
  check_res(&result, &expected_res);

  s21_remove_matrix(&sample);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected_res);
}
END_TEST

START_TEST(test_transpose_5) {
  int rows = 1, columns = 1;

  matrix_t sample;
  s21_create_matrix(rows, columns, &sample);
  copy_matrix(MATRIX1_1, &sample, rows, columns);

  matrix_t result;

  matrix_t expected_res;
  s21_create_matrix(rows, columns, &expected_res);
  copy_matrix(MATRIX1_1, &expected_res, rows, columns);

  ck_assert_int_eq(s21_transpose(&sample, &result), OK);
  check_res(&result, &expected_res);

  s21_remove_matrix(&sample);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected_res);
}
END_TEST

// ----------- Checking of the error situations -----------

START_TEST(test_transpose_6) {
  int rows = 3, columns = 3;
  matrix_t sample;
  s21_create_matrix(rows, columns, &sample);
  copy_matrix(MATRIX3_3, &sample, rows, columns);

  ck_assert_int_eq(s21_transpose(&sample, NULL), ERROR_MATRIX);

  s21_remove_matrix(&sample);
}
END_TEST

START_TEST(test_transpose_7) {
  matrix_t result;

  ck_assert_int_eq(s21_transpose(NULL, &result), ERROR_MATRIX);

  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_transpose_8) {
  int rows = 3, columns = 3;

  matrix_t sample;
  s21_create_matrix(rows, columns, &sample);
  sample.rows = -9;

  matrix_t result;

  ck_assert_int_eq(s21_transpose(&sample, &result), ERROR_MATRIX);

  sample.rows = rows;
  s21_remove_matrix(&sample);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_transpose_9) {
  int rows = 3, columns = 3;

  matrix_t sample;
  s21_create_matrix(rows, columns, &sample);
  sample.columns = 0;

  matrix_t result;

  ck_assert_int_eq(s21_transpose(&sample, &result), ERROR_MATRIX);

  sample.columns = columns;
  s21_remove_matrix(&sample);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_transpose_10) {
  int rows = 3, columns = 5;

  matrix_t sample;
  s21_create_matrix(-16, columns, &sample);
  sample.rows = rows;
  sample.columns = columns;

  matrix_t result;

  ck_assert_int_eq(s21_transpose(&sample, &result), ERROR_MATRIX);

  s21_remove_matrix(&sample);
  s21_remove_matrix(&result);
}
END_TEST

Suite *transpose_suite(void) {
  Suite *s;
  TCase *tc_core_transpose;

  s = suite_create("Suite - s21_transpose_matrix");
  tc_core_transpose = tcase_create("Core");

  tcase_add_test(tc_core_transpose, test_transpose_1);
  tcase_add_test(tc_core_transpose, test_transpose_2);
  tcase_add_test(tc_core_transpose, test_transpose_3);
  tcase_add_test(tc_core_transpose, test_transpose_4);
  tcase_add_test(tc_core_transpose, test_transpose_5);
  tcase_add_test(tc_core_transpose, test_transpose_6);
  tcase_add_test(tc_core_transpose, test_transpose_7);
  tcase_add_test(tc_core_transpose, test_transpose_8);
  tcase_add_test(tc_core_transpose, test_transpose_9);
  tcase_add_test(tc_core_transpose, test_transpose_10);
  suite_add_tcase(s, tc_core_transpose);

  return s;
}