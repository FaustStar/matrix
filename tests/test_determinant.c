#include "s21_test.h"

START_TEST(test_determinant_1) {
  int rows = 3, columns = 3;

  matrix_t sample;
  s21_create_matrix(rows, columns, &sample);
  copy_matrix(MATRIX3_3, &sample, rows, columns);

  double result;

  double expected_res = -12630617.941853365;

  ck_assert_int_eq(s21_determinant(&sample, &result), OK);
  ck_assert_double_eq_tol(expected_res, result, EPS_CHECK);

  s21_remove_matrix(&sample);
}
END_TEST

START_TEST(test_determinant_2) {
  int rows = 5, columns = 5;

  matrix_t sample;
  s21_create_matrix(rows, columns, &sample);
  copy_matrix(MATRIX5_5, &sample, rows, columns);

  double result;

  double expected_res = 803212750.357917232;

  ck_assert_int_eq(s21_determinant(&sample, &result), OK);
  ck_assert_double_eq_tol(expected_res, result, EPS_CHECK);

  s21_remove_matrix(&sample);
}
END_TEST

START_TEST(test_determinant_3) {
  int rows = 1, columns = 1;

  matrix_t sample;
  s21_create_matrix(rows, columns, &sample);
  copy_matrix(MATRIX1_1, &sample, rows, columns);

  double result;

  double expected_res = 34.182;

  ck_assert_int_eq(s21_determinant(&sample, &result), OK);
  ck_assert_double_eq_tol(expected_res, result, EPS_CHECK);

  s21_remove_matrix(&sample);
}
END_TEST

START_TEST(test_determinant_4) {
  int rows = 2, columns = 2;

  matrix_t sample;
  s21_create_matrix(rows, columns, &sample);
  copy_matrix(MATRIX2_2, &sample, rows, columns);

  double result;

  double expected_res = 6407363.7020017;

  ck_assert_int_eq(s21_determinant(&sample, &result), OK);
  ck_assert_double_eq_tol(expected_res, result, EPS_CHECK);

  s21_remove_matrix(&sample);
}
END_TEST

// ----------- Checking of the error situations -----------

START_TEST(test_determinant_5) {
  int rows = 3, columns = 4;

  matrix_t sample;
  s21_create_matrix(rows, columns, &sample);
  copy_matrix(MATRIX3_4, &sample, rows, columns);

  double result;

  ck_assert_int_eq(s21_determinant(&sample, &result), ERROR_CALC);

  s21_remove_matrix(&sample);
}
END_TEST

START_TEST(test_determinant_6) {
  int rows = 4, columns = 3;

  matrix_t sample;
  s21_create_matrix(rows, columns, &sample);
  copy_matrix(MATRIX4_3, &sample, rows, columns);

  double result;

  ck_assert_int_eq(s21_determinant(&sample, &result), ERROR_CALC);

  s21_remove_matrix(&sample);
}
END_TEST

START_TEST(test_determinant_7) {
  int rows = 3, columns = 3;

  matrix_t sample;
  s21_create_matrix(rows, columns, &sample);
  copy_matrix(MATRIX3_3, &sample, rows, columns);

  ck_assert_int_eq(s21_determinant(&sample, NULL), ERROR_MATRIX);

  s21_remove_matrix(&sample);
}
END_TEST

START_TEST(test_determinant_8) {
  double result;

  ck_assert_int_eq(s21_determinant(NULL, &result), ERROR_MATRIX);
}
END_TEST

START_TEST(test_determinant_9) {
  int rows = 3, columns = 3;

  matrix_t sample;
  s21_create_matrix(rows, columns, &sample);
  sample.rows = -17;

  double result;

  ck_assert_int_eq(s21_determinant(&sample, &result), ERROR_MATRIX);

  sample.rows = rows;
  s21_remove_matrix(&sample);
}
END_TEST

START_TEST(test_determinant_10) {
  int rows = 3, columns = 3;

  matrix_t sample;
  s21_create_matrix(rows, columns, &sample);
  sample.columns = -3;

  double result;

  ck_assert_int_eq(s21_determinant(&sample, &result), ERROR_MATRIX);

  sample.columns = columns;
  s21_remove_matrix(&sample);
}
END_TEST

START_TEST(test_determinant_11) {
  int rows = 3, columns = 3;

  matrix_t sample;
  s21_create_matrix(0, columns, &sample);
  sample.rows = rows;
  sample.columns = columns;

  double result;

  ck_assert_int_eq(s21_determinant(&sample, &result), ERROR_MATRIX);

  s21_remove_matrix(&sample);
}
END_TEST

Suite *determinant_suite(void) {
  Suite *s;
  TCase *tc_core_determinant;

  s = suite_create("Suite - s21_determinant");
  tc_core_determinant = tcase_create("Core");

  tcase_add_test(tc_core_determinant, test_determinant_1);
  tcase_add_test(tc_core_determinant, test_determinant_2);
  tcase_add_test(tc_core_determinant, test_determinant_3);
  tcase_add_test(tc_core_determinant, test_determinant_4);
  tcase_add_test(tc_core_determinant, test_determinant_5);
  tcase_add_test(tc_core_determinant, test_determinant_6);
  tcase_add_test(tc_core_determinant, test_determinant_7);
  tcase_add_test(tc_core_determinant, test_determinant_8);
  tcase_add_test(tc_core_determinant, test_determinant_9);
  tcase_add_test(tc_core_determinant, test_determinant_10);
  tcase_add_test(tc_core_determinant, test_determinant_11);
  suite_add_tcase(s, tc_core_determinant);

  return s;
}