#include "s21_test.h"

START_TEST(test_remove_1) {
  matrix_t sample;
  s21_create_matrix(17, 6, &sample);
  s21_remove_matrix(&sample);
  check_no_matrix(sample);
}
END_TEST

START_TEST(test_remove_2) {
  matrix_t sample;
  s21_create_matrix(0, 8, &sample);
  s21_remove_matrix(&sample);
  check_no_matrix(sample);
}
END_TEST

START_TEST(test_remove_3) {
  matrix_t sample;
  s21_create_matrix(4, 0, &sample);
  s21_remove_matrix(&sample);
  check_no_matrix(sample);
}
END_TEST

START_TEST(test_remove_4) {
  matrix_t sample;
  s21_create_matrix(0, 0, &sample);
  s21_remove_matrix(&sample);
  check_no_matrix(sample);
}
END_TEST

START_TEST(test_remove_5) {
  matrix_t sample;
  s21_create_matrix(12, -9, &sample);
  s21_remove_matrix(&sample);
  check_no_matrix(sample);
}
END_TEST

START_TEST(test_remove_6) {
  matrix_t sample;
  s21_create_matrix(-3, 16, &sample);
  s21_remove_matrix(&sample);
  check_no_matrix(sample);
}
END_TEST

START_TEST(test_remove_7) {
  matrix_t sample;
  s21_create_matrix(-1, -9, &sample);
  s21_remove_matrix(&sample);
  check_no_matrix(sample);
}
END_TEST

Suite *remove_suite(void) {
  Suite *s;
  TCase *tc_core_remove;

  s = suite_create("Suite - s21_remove_matrix");
  tc_core_remove = tcase_create("Core");

  tcase_add_test(tc_core_remove, test_remove_1);
  tcase_add_test(tc_core_remove, test_remove_2);
  tcase_add_test(tc_core_remove, test_remove_3);
  tcase_add_test(tc_core_remove, test_remove_4);
  tcase_add_test(tc_core_remove, test_remove_5);
  tcase_add_test(tc_core_remove, test_remove_6);
  tcase_add_test(tc_core_remove, test_remove_7);
  suite_add_tcase(s, tc_core_remove);

  return s;
}