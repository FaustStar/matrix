#include "s21_test.h"

START_TEST(test_sum_1) {
  int rows = 3, columns = 3;

  matrix_t sample_1;
  s21_create_matrix(rows, columns, &sample_1);
  copy_matrix(MATRIX3_3, &sample_1, rows, columns);

  matrix_t sample_2;
  s21_create_matrix(rows, columns, &sample_2);
  copy_matrix(MATRIX3_3__1, &sample_2, rows, columns);

  matrix_t result;

  matrix_t expected_res;
  s21_create_matrix(rows, columns, &expected_res);
  copy_matrix(RES_MATRIX3_3__1, &expected_res, rows, columns);

  ck_assert_int_eq(s21_sum_matrix(&sample_1, &sample_2, &result), OK);
  check_res(&result, &expected_res);

  s21_remove_matrix(&sample_1);
  s21_remove_matrix(&sample_2);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected_res);
}
END_TEST

START_TEST(test_sum_2) {
  int rows = 3, columns = 3;

  matrix_t sample_1;
  s21_create_matrix(rows, columns, &sample_1);
  copy_matrix(MATRIX3_3, &sample_1, rows, columns);

  matrix_t sample_2;
  s21_create_matrix(rows, columns, &sample_2);
  copy_matrix(MATRIX3_3, &sample_2, rows, columns);

  matrix_t result;

  matrix_t expected_res;
  s21_create_matrix(rows, columns, &expected_res);
  copy_matrix(RES_MATRIX3_3, &expected_res, rows, columns);

  ck_assert_int_eq(s21_sum_matrix(&sample_1, &sample_2, &result), OK);
  check_res(&result, &expected_res);

  s21_remove_matrix(&sample_1);
  s21_remove_matrix(&sample_2);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected_res);
}
END_TEST

START_TEST(test_sum_3) {
  int rows = 3, columns = 3;

  matrix_t sample_1;
  s21_create_matrix(rows, columns, &sample_1);
  copy_matrix(MATRIX3_3, &sample_1, rows, columns);

  matrix_t sample_2;
  s21_create_matrix(rows, columns, &sample_2);

  matrix_t result;

  matrix_t expected_res;
  s21_create_matrix(rows, columns, &expected_res);
  copy_matrix(MATRIX3_3, &expected_res, rows, columns);

  ck_assert_int_eq(s21_sum_matrix(&sample_1, &sample_2, &result), OK);
  check_res(&result, &expected_res);

  s21_remove_matrix(&sample_1);
  s21_remove_matrix(&sample_2);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected_res);
}
END_TEST

START_TEST(test_sum_4) {
  int rows = 3, columns = 3;

  matrix_t sample_1;
  s21_create_matrix(rows, columns, &sample_1);

  matrix_t sample_2;
  s21_create_matrix(rows, columns, &sample_2);
  copy_matrix(MATRIX3_3__1, &sample_2, rows, columns);

  matrix_t result;

  matrix_t expected_res;
  s21_create_matrix(rows, columns, &expected_res);
  copy_matrix(MATRIX3_3__1, &expected_res, rows, columns);

  ck_assert_int_eq(s21_sum_matrix(&sample_1, &sample_2, &result), OK);
  check_res(&result, &expected_res);

  s21_remove_matrix(&sample_1);
  s21_remove_matrix(&sample_2);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected_res);
}
END_TEST

START_TEST(test_sum_5) {
  int rows = 1, columns = 1;

  matrix_t sample_1;
  s21_create_matrix(rows, columns, &sample_1);
  copy_matrix(MATRIX1_1, &sample_1, rows, columns);

  matrix_t sample_2;
  s21_create_matrix(rows, columns, &sample_2);
  copy_matrix(MATRIX1_1, &sample_2, rows, columns);

  matrix_t result;

  matrix_t expected_res;
  s21_create_matrix(rows, columns, &expected_res);
  expected_res.matrix[0][0] = 68.364;

  ck_assert_int_eq(s21_sum_matrix(&sample_1, &sample_2, &result), OK);
  check_res(&result, &expected_res);

  s21_remove_matrix(&sample_1);
  s21_remove_matrix(&sample_2);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected_res);
}
END_TEST

// ----------- Checking of the error situations -----------

START_TEST(test_sum_6) {
  int rows_1 = 3, columns_1 = 3;
  matrix_t sample_1;
  s21_create_matrix(rows_1, columns_1, &sample_1);
  copy_matrix(MATRIX3_3, &sample_1, rows_1, columns_1);

  int rows_2 = 3, columns_2 = 4;
  matrix_t sample_2;
  s21_create_matrix(rows_2, columns_2, &sample_2);
  copy_matrix(MATRIX3_4, &sample_2, rows_2, columns_2);

  matrix_t result;

  ck_assert_int_eq(s21_sum_matrix(&sample_1, &sample_2, &result), ERROR_CALC);

  s21_remove_matrix(&sample_1);
  s21_remove_matrix(&sample_2);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_sum_7) {
  int rows_1 = 3, columns_1 = 3;
  matrix_t sample_1;
  s21_create_matrix(rows_1, columns_1, &sample_1);
  copy_matrix(MATRIX3_3, &sample_1, rows_1, columns_1);

  int rows_2 = 2, columns_2 = 3;
  matrix_t sample_2;
  s21_create_matrix(rows_2, columns_2, &sample_2);
  copy_matrix(MATRIX2_3, &sample_2, rows_2, columns_2);

  matrix_t result;

  ck_assert_int_eq(s21_sum_matrix(&sample_1, &sample_2, &result), ERROR_CALC);

  s21_remove_matrix(&sample_1);
  s21_remove_matrix(&sample_2);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_sum_8) {
  int rows_1 = 3, columns_1 = 3;
  matrix_t sample_1;
  s21_create_matrix(rows_1, columns_1, &sample_1);
  copy_matrix(MATRIX3_3, &sample_1, rows_1, columns_1);

  int rows_2 = 3, columns_2 = 3;
  matrix_t sample_2;
  s21_create_matrix(rows_2, columns_2, &sample_2);
  copy_matrix(MATRIX3_3__1, &sample_2, rows_2, columns_2);

  ck_assert_int_eq(s21_sum_matrix(&sample_1, &sample_2, NULL), ERROR_MATRIX);

  s21_remove_matrix(&sample_1);
  s21_remove_matrix(&sample_2);
}
END_TEST

START_TEST(test_sum_9) {
  int rows_2 = 3, columns_2 = 3;
  matrix_t sample_2;
  s21_create_matrix(rows_2, columns_2, &sample_2);
  copy_matrix(MATRIX3_3__1, &sample_2, rows_2, columns_2);

  matrix_t result;

  ck_assert_int_eq(s21_sum_matrix(NULL, &sample_2, &result), ERROR_MATRIX);

  s21_remove_matrix(&sample_2);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_sum_10) {
  int rows_1 = 3, columns_1 = 3;
  matrix_t sample_1;
  s21_create_matrix(rows_1, columns_1, &sample_1);
  copy_matrix(MATRIX3_3, &sample_1, rows_1, columns_1);

  matrix_t result;

  ck_assert_int_eq(s21_sum_matrix(&sample_1, NULL, &result), ERROR_MATRIX);

  s21_remove_matrix(&sample_1);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_sum_11) {
  int rows = 3, columns = 3;

  matrix_t sample_1;
  s21_create_matrix(rows, columns, &sample_1);
  sample_1.rows = -2;

  matrix_t sample_2;
  s21_create_matrix(rows, columns, &sample_2);
  copy_matrix(MATRIX3_3__1, &sample_2, rows, columns);

  matrix_t result;

  ck_assert_int_eq(s21_sum_matrix(&sample_1, &sample_2, &result), ERROR_MATRIX);

  sample_1.rows = rows;
  s21_remove_matrix(&sample_1);
  s21_remove_matrix(&sample_2);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_sum_12) {
  int rows = 3, columns = 3;

  matrix_t sample_1;
  s21_create_matrix(rows, columns, &sample_1);

  matrix_t sample_2;
  s21_create_matrix(rows, columns, &sample_2);
  copy_matrix(MATRIX3_3__1, &sample_2, rows, columns);
  sample_2.columns = -15;

  matrix_t result;

  ck_assert_int_eq(s21_sum_matrix(&sample_1, &sample_2, &result), ERROR_MATRIX);

  sample_2.columns = columns;
  s21_remove_matrix(&sample_1);
  s21_remove_matrix(&sample_2);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_sum_13) {
  int rows = 3, columns = 3;

  matrix_t sample_1;
  s21_create_matrix(-1, columns, &sample_1);
  sample_1.rows = rows;
  sample_1.columns = columns;

  matrix_t sample_2;
  s21_create_matrix(rows, columns, &sample_2);
  copy_matrix(MATRIX3_3__1, &sample_2, rows, columns);

  matrix_t result;

  ck_assert_int_eq(s21_sum_matrix(&sample_1, &sample_2, &result), ERROR_MATRIX);

  s21_remove_matrix(&sample_1);
  s21_remove_matrix(&sample_2);
  s21_remove_matrix(&result);
}
END_TEST

Suite *sum_suite(void) {
  Suite *s;
  TCase *tc_core_sum;

  s = suite_create("Suite - s21_sum_matrix");
  tc_core_sum = tcase_create("Core");

  tcase_add_test(tc_core_sum, test_sum_1);
  tcase_add_test(tc_core_sum, test_sum_2);
  tcase_add_test(tc_core_sum, test_sum_3);
  tcase_add_test(tc_core_sum, test_sum_4);
  tcase_add_test(tc_core_sum, test_sum_5);
  tcase_add_test(tc_core_sum, test_sum_6);
  tcase_add_test(tc_core_sum, test_sum_7);
  tcase_add_test(tc_core_sum, test_sum_8);
  tcase_add_test(tc_core_sum, test_sum_9);
  tcase_add_test(tc_core_sum, test_sum_10);
  tcase_add_test(tc_core_sum, test_sum_11);
  tcase_add_test(tc_core_sum, test_sum_12);
  tcase_add_test(tc_core_sum, test_sum_13);
  suite_add_tcase(s, tc_core_sum);

  return s;
}