#include "s21_test.h"

START_TEST(test_eq_1) {
  int rows = 9, columns = 5;

  matrix_t sample_1;
  s21_create_matrix(rows, columns, &sample_1);

  matrix_t sample_2;
  s21_create_matrix(rows, columns, &sample_2);

  ck_assert_int_eq(s21_eq_matrix(&sample_1, &sample_2), SUCCESS);

  s21_remove_matrix(&sample_1);
  s21_remove_matrix(&sample_2);
}
END_TEST

START_TEST(test_eq_2) {
  int rows = 3, columns = 4;

  matrix_t sample_1;
  s21_create_matrix(rows, columns, &sample_1);
  copy_matrix(MATRIX3_4, &sample_1, rows, columns);

  matrix_t sample_2;
  s21_create_matrix(rows, columns, &sample_2);
  copy_matrix(MATRIX3_4, &sample_2, rows, columns);

  ck_assert_int_eq(s21_eq_matrix(&sample_1, &sample_2), SUCCESS);

  s21_remove_matrix(&sample_1);
  s21_remove_matrix(&sample_2);
}
END_TEST

START_TEST(test_eq_3) {
  int rows = 1, columns = 1;

  matrix_t sample_1;
  s21_create_matrix(rows, columns, &sample_1);
  copy_matrix(MATRIX1_1, &sample_1, rows, columns);

  matrix_t sample_2;
  s21_create_matrix(rows, columns, &sample_2);
  copy_matrix(MATRIX1_1, &sample_2, rows, columns);

  ck_assert_int_eq(s21_eq_matrix(&sample_1, &sample_2), SUCCESS);

  s21_remove_matrix(&sample_1);
  s21_remove_matrix(&sample_2);
}
END_TEST

START_TEST(test_eq_4) {
  int rows = 3, columns = 4;

  matrix_t sample_1;
  s21_create_matrix(rows, columns, &sample_1);
  copy_matrix(MATRIX3_4, &sample_1, rows, columns);

  matrix_t sample_2;
  s21_create_matrix(rows, columns, &sample_2);
  copy_matrix(MATRIX3_4, &sample_2, rows, columns);
  sample_2.matrix[1][2] = -33.4259001;  // разница в значениях: 1e-7

  ck_assert_int_eq(s21_eq_matrix(&sample_1, &sample_2), FAILURE);

  s21_remove_matrix(&sample_1);
  s21_remove_matrix(&sample_2);
}
END_TEST

START_TEST(test_eq_5) {
  int rows_1 = 3, columns_1 = 4;
  matrix_t sample_1;
  s21_create_matrix(rows_1, columns_1, &sample_1);
  copy_matrix(MATRIX3_4, &sample_1, rows_1, columns_1);

  int rows_2 = 3, columns_2 = 3;
  matrix_t sample_2;
  s21_create_matrix(rows_2, columns_2, &sample_2);
  copy_matrix(MATRIX3_3, &sample_2, rows_2, columns_2);

  ck_assert_int_eq(s21_eq_matrix(&sample_1, &sample_2), FAILURE);

  s21_remove_matrix(&sample_1);
  s21_remove_matrix(&sample_2);
}
END_TEST

START_TEST(test_eq_6) {
  int rows_1 = 7, columns_1 = 3;
  matrix_t sample_1;
  s21_create_matrix(rows_1, columns_1, &sample_1);

  int rows_2 = 3, columns_2 = 3;
  matrix_t sample_2;
  s21_create_matrix(rows_2, columns_2, &sample_2);
  copy_matrix(MATRIX3_3, &sample_2, rows_2, columns_2);

  ck_assert_int_eq(s21_eq_matrix(&sample_1, &sample_2), FAILURE);

  s21_remove_matrix(&sample_1);
  s21_remove_matrix(&sample_2);
}
END_TEST

START_TEST(test_eq_7) {
  int rows = 3, columns = 4;

  matrix_t sample_1;
  s21_create_matrix(rows, columns, &sample_1);
  copy_matrix(MATRIX3_4, &sample_1, rows, columns);
  sample_1.columns = 0;

  matrix_t sample_2;
  s21_create_matrix(rows, columns, &sample_2);
  copy_matrix(MATRIX3_4, &sample_2, rows, columns);
  sample_2.columns = 0;

  ck_assert_int_eq(s21_eq_matrix(&sample_1, &sample_2), FAILURE);

  sample_1.columns = columns;  // для избежания утечки памяти
  sample_2.columns = columns;
  s21_remove_matrix(&sample_1);
  s21_remove_matrix(&sample_2);
}
END_TEST

START_TEST(test_eq_8) {
  int rows = 3, columns = 4;

  matrix_t sample_1;
  s21_create_matrix(rows, columns, &sample_1);
  copy_matrix(MATRIX3_4, &sample_1, rows, columns);
  sample_1.rows = -1;

  matrix_t sample_2;
  s21_create_matrix(rows, columns, &sample_2);
  copy_matrix(MATRIX3_4, &sample_2, rows, columns);
  sample_2.rows = -1;

  ck_assert_int_eq(s21_eq_matrix(&sample_1, &sample_2), FAILURE);

  sample_1.rows = rows;  // для избежания утечки памяти
  sample_2.rows = rows;
  s21_remove_matrix(&sample_1);
  s21_remove_matrix(&sample_2);
}
END_TEST

START_TEST(test_eq_9) {
  int rows = 3, columns = 4;

  matrix_t sample_1;
  s21_create_matrix(rows, columns, &sample_1);
  copy_matrix(MATRIX3_4, &sample_1, rows, columns);

  ck_assert_int_eq(s21_eq_matrix(&sample_1, NULL), FAILURE);

  s21_remove_matrix(&sample_1);
}
END_TEST

START_TEST(test_eq_10) {
  int rows = 3, columns = 3;

  matrix_t sample_1;
  s21_create_matrix(rows, columns, &sample_1);
  copy_matrix(MATRIX3_3, &sample_1, rows, columns);

  ck_assert_int_eq(s21_eq_matrix(NULL, &sample_1), FAILURE);

  s21_remove_matrix(&sample_1);
}
END_TEST

Suite *eq_suite(void) {
  Suite *s;
  TCase *tc_core_eq;

  s = suite_create("Suite - s21_eq_matrix");
  tc_core_eq = tcase_create("Core");

  tcase_add_test(tc_core_eq, test_eq_1);
  tcase_add_test(tc_core_eq, test_eq_2);
  tcase_add_test(tc_core_eq, test_eq_3);
  tcase_add_test(tc_core_eq, test_eq_4);
  tcase_add_test(tc_core_eq, test_eq_5);
  tcase_add_test(tc_core_eq, test_eq_6);
  tcase_add_test(tc_core_eq, test_eq_7);
  tcase_add_test(tc_core_eq, test_eq_8);
  tcase_add_test(tc_core_eq, test_eq_9);
  tcase_add_test(tc_core_eq, test_eq_10);
  suite_add_tcase(s, tc_core_eq);

  return s;
}