#include "s21_test.h"

START_TEST(test_inverse_1) {
  int rows = 3, columns = 3;

  matrix_t sample;
  s21_create_matrix(rows, columns, &sample);
  copy_matrix(MATRIX3_3, &sample, rows, columns);

  matrix_t result;

  matrix_t expected_res;
  s21_create_matrix(rows, columns, &expected_res);
  copy_matrix(RES_MATRIX3_3__5, &expected_res, rows, columns);

  ck_assert_int_eq(s21_inverse_matrix(&sample, &result), OK);
  check_res(&result, &expected_res);

  s21_remove_matrix(&sample);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected_res);
}
END_TEST

START_TEST(test_inverse_2) {
  int rows = 3, columns = 3;

  matrix_t sample;
  s21_create_matrix(rows, columns, &sample);
  copy_matrix(MATRIX3_3__1, &sample, rows, columns);

  matrix_t result;

  matrix_t expected_res;
  s21_create_matrix(rows, columns, &expected_res);
  copy_matrix(RES_MATRIX3_3__7, &expected_res, rows, columns);

  ck_assert_int_eq(s21_inverse_matrix(&sample, &result), OK);
  check_res(&result, &expected_res);

  s21_remove_matrix(&sample);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected_res);
}
END_TEST

START_TEST(test_inverse_3) {
  int rows = 2, columns = 2;

  matrix_t sample;
  s21_create_matrix(rows, columns, &sample);
  copy_matrix(MATRIX2_2, &sample, rows, columns);

  matrix_t result;

  matrix_t expected_res;
  s21_create_matrix(rows, columns, &expected_res);
  copy_matrix(RES_MATRIX2_2__1, &expected_res, rows, columns);

  ck_assert_int_eq(s21_inverse_matrix(&sample, &result), OK);
  check_res(&result, &expected_res);

  s21_remove_matrix(&sample);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected_res);
}
END_TEST

START_TEST(test_inverse_4) {
  int rows = 1, columns = 1;

  matrix_t sample;
  s21_create_matrix(rows, columns, &sample);
  copy_matrix(MATRIX1_1, &sample, rows, columns);

  matrix_t result;

  matrix_t expected_res;
  s21_create_matrix(rows, columns, &expected_res);
  expected_res.matrix[0][0] = 0.0292552;

  ck_assert_int_eq(s21_inverse_matrix(&sample, &result), OK);
  check_res(&result, &expected_res);

  s21_remove_matrix(&sample);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected_res);
}
END_TEST

// ----------- Checking of the error situations -----------

START_TEST(test_inverse_5) {
  int rows = 4, columns = 3;

  matrix_t sample;
  s21_create_matrix(rows, columns, &sample);
  copy_matrix(MATRIX4_3, &sample, rows, columns);

  matrix_t result;

  ck_assert_int_eq(s21_inverse_matrix(&sample, &result), ERROR_CALC);

  s21_remove_matrix(&sample);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_inverse_6) {
  int rows = 2, columns = 2;

  matrix_t sample;
  s21_create_matrix(rows, columns, &sample);
  copy_matrix(MATRIX2_2__1, &sample, rows, columns);

  matrix_t result;

  ck_assert_int_eq(s21_inverse_matrix(&sample, &result), ERROR_CALC);

  s21_remove_matrix(&sample);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_inverse_7) {
  int rows = 2, columns = 2;

  matrix_t sample;
  s21_create_matrix(rows, columns, &sample);
  copy_matrix(MATRIX2_2__2, &sample, rows, columns);

  matrix_t result;

  ck_assert_int_eq(s21_inverse_matrix(&sample, &result), ERROR_CALC);

  s21_remove_matrix(&sample);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_inverse_8) {
  int rows = 3, columns = 3;

  matrix_t sample;
  s21_create_matrix(rows, columns, &sample);
  copy_matrix(MATRIX3_3, &sample, rows, columns);

  ck_assert_int_eq(s21_inverse_matrix(&sample, NULL), ERROR_MATRIX);

  s21_remove_matrix(&sample);
}
END_TEST

START_TEST(test_inverse_9) {
  matrix_t result;

  ck_assert_int_eq(s21_inverse_matrix(NULL, &result), ERROR_MATRIX);

  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_inverse_10) {
  int rows = 3, columns = 3;

  matrix_t sample;
  s21_create_matrix(rows, columns, &sample);
  sample.rows = 0;

  matrix_t result;

  ck_assert_int_eq(s21_inverse_matrix(&sample, &result), ERROR_MATRIX);

  sample.rows = rows;
  s21_remove_matrix(&sample);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_inverse_11) {
  int rows = 3, columns = 3;

  matrix_t sample;
  s21_create_matrix(rows, columns, &sample);
  sample.columns = -1;

  matrix_t result;

  ck_assert_int_eq(s21_inverse_matrix(&sample, &result), ERROR_MATRIX);

  sample.columns = columns;
  s21_remove_matrix(&sample);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_inverse_12) {
  int rows = 3, columns = 3;

  matrix_t sample;
  s21_create_matrix(rows, 0, &sample);
  sample.rows = rows;
  sample.columns = columns;

  matrix_t result;

  ck_assert_int_eq(s21_inverse_matrix(&sample, &result), ERROR_MATRIX);

  s21_remove_matrix(&sample);
  s21_remove_matrix(&result);
}
END_TEST

Suite *inverse_suite(void) {
  Suite *s;
  TCase *tc_core_inverse;

  s = suite_create("Suite - s21_inverse_matrix");
  tc_core_inverse = tcase_create("Core");

  tcase_add_test(tc_core_inverse, test_inverse_1);
  tcase_add_test(tc_core_inverse, test_inverse_2);
  tcase_add_test(tc_core_inverse, test_inverse_3);
  tcase_add_test(tc_core_inverse, test_inverse_4);
  tcase_add_test(tc_core_inverse, test_inverse_5);
  tcase_add_test(tc_core_inverse, test_inverse_6);
  tcase_add_test(tc_core_inverse, test_inverse_7);
  tcase_add_test(tc_core_inverse, test_inverse_8);
  tcase_add_test(tc_core_inverse, test_inverse_9);
  tcase_add_test(tc_core_inverse, test_inverse_10);
  tcase_add_test(tc_core_inverse, test_inverse_11);
  tcase_add_test(tc_core_inverse, test_inverse_12);
  suite_add_tcase(s, tc_core_inverse);

  return s;
}