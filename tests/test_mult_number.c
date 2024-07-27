#include "s21_test.h"

START_TEST(test_mult_number_1) {
  int rows = 3, columns = 3;

  matrix_t sample;
  s21_create_matrix(rows, columns, &sample);
  copy_matrix(MATRIX3_3, &sample, rows, columns);

  double number = 2;

  matrix_t result;

  matrix_t expected_res;
  s21_create_matrix(rows, columns, &expected_res);
  copy_matrix(RES_MATRIX3_3, &expected_res, rows, columns);

  ck_assert_int_eq(s21_mult_number(&sample, number, &result), OK);
  check_res(&result, &expected_res);

  s21_remove_matrix(&sample);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected_res);
}
END_TEST

START_TEST(test_mult_number_2) {
  int rows = 3, columns = 4;

  matrix_t sample;
  s21_create_matrix(rows, columns, &sample);
  copy_matrix(MATRIX3_4, &sample, rows, columns);

  double number = 1;

  matrix_t result;

  matrix_t expected_res;
  s21_create_matrix(rows, columns, &expected_res);
  copy_matrix(MATRIX3_4, &expected_res, rows, columns);

  ck_assert_int_eq(s21_mult_number(&sample, number, &result), OK);
  check_res(&result, &expected_res);

  s21_remove_matrix(&sample);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected_res);
}
END_TEST

START_TEST(test_mult_number_3) {
  int rows = 2, columns = 3;

  matrix_t sample;
  s21_create_matrix(rows, columns, &sample);
  copy_matrix(MATRIX2_3, &sample, rows, columns);

  double number = 0;

  matrix_t result;

  matrix_t expected_res;
  s21_create_matrix(rows, columns, &expected_res);

  ck_assert_int_eq(s21_mult_number(&sample, number, &result), OK);
  check_res(&result, &expected_res);

  s21_remove_matrix(&sample);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected_res);
}
END_TEST

START_TEST(test_mult_number_4) {
  int rows = 2, columns = 3;

  matrix_t sample;
  s21_create_matrix(rows, columns, &sample);
  copy_matrix(MATRIX2_3__1, &sample, rows, columns);

  double number = 6.789643;

  matrix_t result;

  matrix_t expected_res;
  s21_create_matrix(rows, columns, &expected_res);
  copy_matrix(RES_MATRIX2_3, &expected_res, rows, columns);

  ck_assert_int_eq(s21_mult_number(&sample, number, &result), OK);
  check_res(&result, &expected_res);

  s21_remove_matrix(&sample);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected_res);
}
END_TEST

START_TEST(test_mult_number_5) {
  int rows = 1, columns = 1;

  matrix_t sample;
  s21_create_matrix(rows, columns, &sample);
  copy_matrix(MATRIX1_1, &sample, rows, columns);

  double number = 6.789643;

  matrix_t result;

  matrix_t expected_res;
  s21_create_matrix(rows, columns, &expected_res);
  expected_res.matrix[0][0] = 232.083577026;

  ck_assert_int_eq(s21_mult_number(&sample, number, &result), OK);
  check_res(&result, &expected_res);

  s21_remove_matrix(&sample);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected_res);
}
END_TEST

// ----------- Checking of the error situations -----------

START_TEST(test_mult_number_6) {
  int rows = 3, columns = 3;
  matrix_t sample;
  s21_create_matrix(rows, columns, &sample);
  copy_matrix(MATRIX3_3, &sample, rows, columns);

  double number = 2;

  ck_assert_int_eq(s21_mult_number(&sample, number, NULL), ERROR_MATRIX);

  s21_remove_matrix(&sample);
}
END_TEST

START_TEST(test_mult_number_7) {
  matrix_t result;

  double number = 5.6;

  ck_assert_int_eq(s21_mult_number(NULL, number, &result), ERROR_MATRIX);

  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_mult_number_8) {
  int rows = 3, columns = 3;

  matrix_t sample;
  s21_create_matrix(rows, columns, &sample);
  sample.rows = -2;

  double number = 2.7;

  matrix_t result;

  ck_assert_int_eq(s21_mult_number(&sample, number, &result), ERROR_MATRIX);

  sample.rows = rows;
  s21_remove_matrix(&sample);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_mult_number_9) {
  int rows = 3, columns = 3;

  matrix_t sample;
  s21_create_matrix(rows, columns, &sample);
  sample.columns = -16;

  double number = 2.7;

  matrix_t result;

  ck_assert_int_eq(s21_mult_number(&sample, number, &result), ERROR_MATRIX);

  sample.columns = columns;
  s21_remove_matrix(&sample);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_mult_number_10) {
  int rows = 3, columns = 3;

  matrix_t sample_1;
  s21_create_matrix(rows, 0, &sample_1);
  sample_1.rows = rows;
  sample_1.columns = columns;

  double number = -6.1;

  matrix_t result;

  ck_assert_int_eq(s21_mult_number(&sample_1, number, &result), ERROR_MATRIX);

  s21_remove_matrix(&sample_1);
  s21_remove_matrix(&result);
}
END_TEST

Suite *mult_number_suite(void) {
  Suite *s;
  TCase *tc_core_mult_number;

  s = suite_create("Suite - s21_mult_number");
  tc_core_mult_number = tcase_create("Core");

  tcase_add_test(tc_core_mult_number, test_mult_number_1);
  tcase_add_test(tc_core_mult_number, test_mult_number_2);
  tcase_add_test(tc_core_mult_number, test_mult_number_3);
  tcase_add_test(tc_core_mult_number, test_mult_number_4);
  tcase_add_test(tc_core_mult_number, test_mult_number_5);
  tcase_add_test(tc_core_mult_number, test_mult_number_6);
  tcase_add_test(tc_core_mult_number, test_mult_number_7);
  tcase_add_test(tc_core_mult_number, test_mult_number_8);
  tcase_add_test(tc_core_mult_number, test_mult_number_9);
  tcase_add_test(tc_core_mult_number, test_mult_number_10);
  suite_add_tcase(s, tc_core_mult_number);

  return s;
}