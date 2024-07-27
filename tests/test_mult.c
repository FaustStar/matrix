#include "s21_test.h"

START_TEST(test_mult_1) {
  int rows_1 = 2, columns_1 = 3;
  matrix_t sample_1;
  s21_create_matrix(rows_1, columns_1, &sample_1);
  copy_matrix(MATRIX2_3, &sample_1, rows_1, columns_1);

  int rows_2 = 3, columns_2 = 3;
  matrix_t sample_2;
  s21_create_matrix(rows_2, columns_2, &sample_2);
  copy_matrix(MATRIX3_3__1, &sample_2, rows_2, columns_2);

  matrix_t result;

  matrix_t expected_res;
  s21_create_matrix(rows_1, columns_2, &expected_res);
  copy_matrix(RES_MATRIX2_3__2, &expected_res, rows_1, columns_2);

  ck_assert_int_eq(s21_mult_matrix(&sample_1, &sample_2, &result), OK);
  check_res(&result, &expected_res);

  s21_remove_matrix(&sample_1);
  s21_remove_matrix(&sample_2);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected_res);
}
END_TEST

START_TEST(test_mult_2) {
  int rows_1 = 2, columns_1 = 4;
  matrix_t sample_1;
  s21_create_matrix(rows_1, columns_1, &sample_1);
  copy_matrix(MATRIX2_4, &sample_1, rows_1, columns_1);

  int rows_2 = 4, columns_2 = 3;
  matrix_t sample_2;
  s21_create_matrix(rows_2, columns_2, &sample_2);
  copy_matrix(MATRIX4_3, &sample_2, rows_2, columns_2);

  matrix_t result;

  matrix_t expected_res;
  s21_create_matrix(rows_1, columns_2, &expected_res);
  copy_matrix(RES_MATRIX2_3__3, &expected_res, rows_1, columns_2);

  ck_assert_int_eq(s21_mult_matrix(&sample_1, &sample_2, &result), OK);
  check_res(&result, &expected_res);

  s21_remove_matrix(&sample_1);
  s21_remove_matrix(&sample_2);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected_res);
}
END_TEST

START_TEST(test_mult_3) {
  int rows_1 = 2, columns_1 = 4;
  matrix_t sample_1;
  s21_create_matrix(rows_1, columns_1, &sample_1);
  copy_matrix(MATRIX2_4, &sample_1, rows_1, columns_1);

  int rows_2 = 4, columns_2 = 3;
  matrix_t sample_2;
  s21_create_matrix(rows_2, columns_2, &sample_2);

  matrix_t result;

  matrix_t expected_res;
  s21_create_matrix(rows_1, columns_2, &expected_res);

  ck_assert_int_eq(s21_mult_matrix(&sample_1, &sample_2, &result), OK);
  check_res(&result, &expected_res);

  s21_remove_matrix(&sample_1);
  s21_remove_matrix(&sample_2);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected_res);
}
END_TEST

START_TEST(test_mult_4) {
  int rows_1 = 2, columns_1 = 4;
  matrix_t sample_1;
  s21_create_matrix(rows_1, columns_1, &sample_1);

  int rows_2 = 4, columns_2 = 3;
  matrix_t sample_2;
  s21_create_matrix(rows_2, columns_2, &sample_2);
  copy_matrix(MATRIX4_3, &sample_2, rows_2, columns_2);

  matrix_t result;

  matrix_t expected_res;
  s21_create_matrix(rows_1, columns_2, &expected_res);

  ck_assert_int_eq(s21_mult_matrix(&sample_1, &sample_2, &result), OK);
  check_res(&result, &expected_res);

  s21_remove_matrix(&sample_1);
  s21_remove_matrix(&sample_2);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected_res);
}
END_TEST

START_TEST(test_mult_5) {
  int rows_1 = 1, columns_1 = 1;
  matrix_t sample_1;
  s21_create_matrix(rows_1, columns_1, &sample_1);
  copy_matrix(MATRIX1_1, &sample_1, rows_1, columns_1);

  int rows_2 = 1, columns_2 = 1;
  matrix_t sample_2;
  s21_create_matrix(rows_2, columns_2, &sample_2);
  copy_matrix(MATRIX1_1, &sample_2, rows_2, columns_2);

  matrix_t result;

  matrix_t expected_res;
  s21_create_matrix(rows_1, columns_2, &expected_res);
  expected_res.matrix[0][0] = 1168.409124;

  ck_assert_int_eq(s21_mult_matrix(&sample_1, &sample_2, &result), OK);
  check_res(&result, &expected_res);

  s21_remove_matrix(&sample_1);
  s21_remove_matrix(&sample_2);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected_res);
}
END_TEST

// ----------- Checking of the error situations -----------

START_TEST(test_mult_6) {
  int rows_1 = 2, columns_1 = 3;
  matrix_t sample_1;
  s21_create_matrix(rows_1, columns_1, &sample_1);
  copy_matrix(MATRIX2_3, &sample_1, rows_1, columns_1);

  int rows_2 = 2, columns_2 = 3;
  matrix_t sample_2;
  s21_create_matrix(rows_2, columns_2, &sample_2);
  copy_matrix(MATRIX2_3__1, &sample_2, rows_2, columns_2);

  matrix_t result;

  ck_assert_int_eq(s21_mult_matrix(&sample_1, &sample_2, &result), ERROR_CALC);

  s21_remove_matrix(&sample_1);
  s21_remove_matrix(&sample_2);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_mult_7) {
  int rows_1 = 2, columns_1 = 3;
  matrix_t sample_1;
  s21_create_matrix(rows_1, columns_1, &sample_1);
  copy_matrix(MATRIX2_3, &sample_1, rows_1, columns_1);

  int rows_2 = 3, columns_2 = 3;
  matrix_t sample_2;
  s21_create_matrix(rows_2, columns_2, &sample_2);
  copy_matrix(MATRIX3_3__1, &sample_2, rows_2, columns_2);

  ck_assert_int_eq(s21_mult_matrix(&sample_1, &sample_2, NULL), ERROR_MATRIX);

  s21_remove_matrix(&sample_1);
  s21_remove_matrix(&sample_2);
}
END_TEST

START_TEST(test_mult_8) {
  int rows_2 = 3, columns_2 = 3;
  matrix_t sample_2;
  s21_create_matrix(rows_2, columns_2, &sample_2);
  copy_matrix(MATRIX3_3__1, &sample_2, rows_2, columns_2);

  matrix_t result;

  ck_assert_int_eq(s21_mult_matrix(NULL, &sample_2, &result), ERROR_MATRIX);

  s21_remove_matrix(&sample_2);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_mult_9) {
  int rows_1 = 2, columns_1 = 3;
  matrix_t sample_1;
  s21_create_matrix(rows_1, columns_1, &sample_1);
  copy_matrix(MATRIX2_3, &sample_1, rows_1, columns_1);

  matrix_t result;

  ck_assert_int_eq(s21_mult_matrix(&sample_1, NULL, &result), ERROR_MATRIX);

  s21_remove_matrix(&sample_1);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_mult_10) {
  int rows = 3, columns = 3;

  matrix_t sample_1;
  s21_create_matrix(rows, columns, &sample_1);
  sample_1.rows = -9;

  matrix_t sample_2;
  s21_create_matrix(rows, columns, &sample_2);
  copy_matrix(MATRIX3_3__1, &sample_2, rows, columns);

  matrix_t result;

  ck_assert_int_eq(s21_mult_matrix(&sample_1, &sample_2, &result),
                   ERROR_MATRIX);

  sample_1.rows = rows;
  s21_remove_matrix(&sample_1);
  s21_remove_matrix(&sample_2);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_mult_11) {
  int rows = 3, columns = 3;

  matrix_t sample_1;
  s21_create_matrix(rows, columns, &sample_1);

  matrix_t sample_2;
  s21_create_matrix(rows, columns, &sample_2);
  copy_matrix(MATRIX3_3__1, &sample_2, rows, columns);
  sample_2.columns = 0;

  matrix_t result;

  ck_assert_int_eq(s21_mult_matrix(&sample_1, &sample_2, &result),
                   ERROR_MATRIX);

  sample_2.columns = columns;
  s21_remove_matrix(&sample_1);
  s21_remove_matrix(&sample_2);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_mult_12) {
  int rows = 3, columns = 3;

  matrix_t sample_1;
  s21_create_matrix(-7, columns, &sample_1);
  sample_1.rows = rows;
  sample_1.columns = columns;

  matrix_t sample_2;
  s21_create_matrix(rows, columns, &sample_2);
  copy_matrix(MATRIX3_3__1, &sample_2, rows, columns);

  matrix_t result;

  ck_assert_int_eq(s21_mult_matrix(&sample_1, &sample_2, &result),
                   ERROR_MATRIX);

  s21_remove_matrix(&sample_1);
  s21_remove_matrix(&sample_2);
  s21_remove_matrix(&result);
}
END_TEST

Suite *mult_suite(void) {
  Suite *s;
  TCase *tc_core_mult;

  s = suite_create("Suite - s21_mult_matrix");
  tc_core_mult = tcase_create("Core");

  tcase_add_test(tc_core_mult, test_mult_1);
  tcase_add_test(tc_core_mult, test_mult_2);
  tcase_add_test(tc_core_mult, test_mult_3);
  tcase_add_test(tc_core_mult, test_mult_4);
  tcase_add_test(tc_core_mult, test_mult_5);
  tcase_add_test(tc_core_mult, test_mult_6);
  tcase_add_test(tc_core_mult, test_mult_7);
  tcase_add_test(tc_core_mult, test_mult_8);
  tcase_add_test(tc_core_mult, test_mult_9);
  tcase_add_test(tc_core_mult, test_mult_10);
  tcase_add_test(tc_core_mult, test_mult_11);
  tcase_add_test(tc_core_mult, test_mult_12);
  suite_add_tcase(s, tc_core_mult);

  return s;
}