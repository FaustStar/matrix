#include "s21_test.h"

START_TEST(test_create_1) {
  matrix_t sample;
  int rows = 2;
  int columns = 3;
  ck_assert_int_eq(s21_create_matrix(rows, columns, &sample), OK);
  check_created_matrix(rows, columns, &sample);
  s21_remove_matrix(&sample);
}
END_TEST

START_TEST(test_create_2) {
  matrix_t sample;
  int rows = 1;
  int columns = 1;
  ck_assert_int_eq(s21_create_matrix(rows, columns, &sample), OK);
  check_created_matrix(rows, columns, &sample);
  s21_remove_matrix(&sample);
}
END_TEST

START_TEST(test_create_3) {
  matrix_t sample;
  int rows = 150;
  int columns = 20;
  ck_assert_int_eq(s21_create_matrix(rows, columns, &sample), OK);
  check_created_matrix(rows, columns, &sample);
  s21_remove_matrix(&sample);
}
END_TEST

START_TEST(test_create_4) {
  matrix_t sample;
  ck_assert_int_eq(s21_create_matrix(0, 5, &sample), ERROR_MATRIX);
  check_no_matrix(sample);
  s21_remove_matrix(&sample);
}
END_TEST

START_TEST(test_create_5) {
  matrix_t sample;
  ck_assert_int_eq(s21_create_matrix(10, 0, &sample), ERROR_MATRIX);
  check_no_matrix(sample);
  s21_remove_matrix(&sample);
}
END_TEST

START_TEST(test_create_6) {
  matrix_t sample;
  ck_assert_int_eq(s21_create_matrix(0, 0, &sample), ERROR_MATRIX);
  check_no_matrix(sample);
  s21_remove_matrix(&sample);
}
END_TEST

START_TEST(test_create_7) {
  matrix_t sample;
  ck_assert_int_eq(s21_create_matrix(-1, 14, &sample), ERROR_MATRIX);
  check_no_matrix(sample);
  s21_remove_matrix(&sample);
}
END_TEST

START_TEST(test_create_8) {
  matrix_t sample;
  ck_assert_int_eq(s21_create_matrix(15, -19, &sample), ERROR_MATRIX);
  check_no_matrix(sample);
  s21_remove_matrix(&sample);
}
END_TEST

START_TEST(test_create_9) {
  matrix_t sample;
  ck_assert_int_eq(s21_create_matrix(-3, -5, &sample), ERROR_MATRIX);
  check_no_matrix(sample);
  s21_remove_matrix(&sample);
}
END_TEST

START_TEST(test_create_10) {
  ck_assert_int_eq(s21_create_matrix(12, 7, NULL), ERROR_MATRIX);
}
END_TEST

Suite *create_suite(void) {
  Suite *s;
  TCase *tc_core_create;

  s = suite_create("Suite - s21_create_matrix");
  tc_core_create = tcase_create("Core");

  tcase_add_test(tc_core_create, test_create_1);
  tcase_add_test(tc_core_create, test_create_2);
  tcase_add_test(tc_core_create, test_create_3);
  tcase_add_test(tc_core_create, test_create_4);
  tcase_add_test(tc_core_create, test_create_5);
  tcase_add_test(tc_core_create, test_create_6);
  tcase_add_test(tc_core_create, test_create_7);
  tcase_add_test(tc_core_create, test_create_8);
  tcase_add_test(tc_core_create, test_create_9);
  tcase_add_test(tc_core_create, test_create_10);
  suite_add_tcase(s, tc_core_create);

  return s;
}