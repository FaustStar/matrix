#include "s21_test.h"

START_TEST(test_complements_1) {
  int rows = 3, columns = 3;

  matrix_t sample;
  s21_create_matrix(rows, columns, &sample);
  copy_matrix(MATRIX3_3, &sample, rows, columns);

  matrix_t result;

  matrix_t expected_res;
  s21_create_matrix(rows, columns, &expected_res);
  copy_matrix(RES_MATRIX3_3__4, &expected_res, rows, columns);

  ck_assert_int_eq(s21_calc_complements(&sample, &result), OK);
  check_res(&result, &expected_res);

  s21_remove_matrix(&sample);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected_res);
}
END_TEST

START_TEST(test_complements_2) {
  int rows = 3, columns = 3;

  matrix_t sample;
  s21_create_matrix(rows, columns, &sample);
  copy_matrix(MATRIX3_3__1, &sample, rows, columns);

  matrix_t result;

  matrix_t expected_res;
  s21_create_matrix(rows, columns, &expected_res);
  copy_matrix(RES_MATRIX3_3__6, &expected_res, rows, columns);

  ck_assert_int_eq(s21_calc_complements(&sample, &result), OK);
  check_res(&result, &expected_res);

  s21_remove_matrix(&sample);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected_res);
}
END_TEST

START_TEST(test_complements_3) {
  int rows = 2, columns = 2;

  matrix_t sample;
  s21_create_matrix(rows, columns, &sample);
  copy_matrix(MATRIX2_2, &sample, rows, columns);

  matrix_t result;

  matrix_t expected_res;
  s21_create_matrix(rows, columns, &expected_res);
  copy_matrix(RES_MATRIX2_2, &expected_res, rows, columns);

  ck_assert_int_eq(s21_calc_complements(&sample, &result), OK);
  check_res(&result, &expected_res);

  s21_remove_matrix(&sample);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected_res);
}
END_TEST

START_TEST(test_complements_4) {
  int rows = 1, columns = 1;

  matrix_t sample;
  s21_create_matrix(rows, columns, &sample);
  copy_matrix(MATRIX1_1, &sample, rows, columns);

  matrix_t result;

  matrix_t expected_res;
  s21_create_matrix(rows, columns, &expected_res);
  expected_res.matrix[0][0] = 1;

  ck_assert_int_eq(s21_calc_complements(&sample, &result), OK);
  check_res(&result, &expected_res);

  s21_remove_matrix(&sample);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected_res);
}
END_TEST

// ----------- Checking of the error situations -----------

START_TEST(test_complements_5) {
  int rows = 4, columns = 3;

  matrix_t sample;
  s21_create_matrix(rows, columns, &sample);
  copy_matrix(MATRIX4_3, &sample, rows, columns);

  matrix_t result;

  ck_assert_int_eq(s21_calc_complements(&sample, &result), ERROR_CALC);

  s21_remove_matrix(&sample);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_complements_6) {
  int rows = 2, columns = 4;

  matrix_t sample;
  s21_create_matrix(rows, columns, &sample);
  copy_matrix(MATRIX2_4, &sample, rows, columns);

  matrix_t result;

  ck_assert_int_eq(s21_calc_complements(&sample, &result), ERROR_CALC);

  s21_remove_matrix(&sample);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_complements_7) {
  int rows = 3, columns = 3;

  matrix_t sample;
  s21_create_matrix(rows, columns, &sample);
  copy_matrix(MATRIX3_3, &sample, rows, columns);

  ck_assert_int_eq(s21_calc_complements(&sample, NULL), ERROR_MATRIX);

  s21_remove_matrix(&sample);
}
END_TEST

START_TEST(test_complements_8) {
  matrix_t result;

  ck_assert_int_eq(s21_calc_complements(NULL, &result), ERROR_MATRIX);

  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_complements_9) {
  int rows = 3, columns = 3;

  matrix_t sample;
  s21_create_matrix(rows, columns, &sample);
  sample.rows = -7;

  matrix_t result;

  ck_assert_int_eq(s21_calc_complements(&sample, &result), ERROR_MATRIX);

  sample.rows = rows;
  s21_remove_matrix(&sample);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_complements_10) {
  int rows = 3, columns = 3;

  matrix_t sample;
  s21_create_matrix(rows, columns, &sample);
  sample.columns = -4;

  matrix_t result;

  ck_assert_int_eq(s21_calc_complements(&sample, &result), ERROR_MATRIX);

  sample.columns = columns;
  s21_remove_matrix(&sample);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_complements_11) {
  int rows = 3, columns = 3;

  matrix_t sample;
  s21_create_matrix(rows, -3, &sample);
  sample.rows = rows;
  sample.columns = columns;

  matrix_t result;

  ck_assert_int_eq(s21_calc_complements(&sample, &result), ERROR_MATRIX);

  s21_remove_matrix(&sample);
  s21_remove_matrix(&result);
}
END_TEST

Suite *complements_suite(void) {
  Suite *s;
  TCase *tc_core_complements;

  s = suite_create("Suite - s21_calc_complements");
  tc_core_complements = tcase_create("Core");

  tcase_add_test(tc_core_complements, test_complements_1);
  tcase_add_test(tc_core_complements, test_complements_2);
  tcase_add_test(tc_core_complements, test_complements_3);
  tcase_add_test(tc_core_complements, test_complements_4);
  tcase_add_test(tc_core_complements, test_complements_5);
  tcase_add_test(tc_core_complements, test_complements_6);
  tcase_add_test(tc_core_complements, test_complements_7);
  tcase_add_test(tc_core_complements, test_complements_8);
  tcase_add_test(tc_core_complements, test_complements_9);
  tcase_add_test(tc_core_complements, test_complements_10);
  tcase_add_test(tc_core_complements, test_complements_11);
  suite_add_tcase(s, tc_core_complements);

  return s;
}