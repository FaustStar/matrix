#include "s21_test.h"

int main(void) {
  int number_failed;
  Suite *s[] = {create_suite(),      remove_suite(),    eq_suite(),
                sum_suite(),         sub_suite(),       mult_number_suite(),
                mult_suite(),        transpose_suite(), determinant_suite(),
                complements_suite(), inverse_suite(),   NULL};
  SRunner *sr;

  for (int i = 0; s[i] != NULL; i++) {
    if (!i)
      sr = srunner_create(
          s[i]);  // создание раннера на основе 1-го набора тестов
    else
      srunner_add_suite(sr, s[i]);  // добавление в раннер остальных наборов
  }

  srunner_set_fork_status(sr, CK_NOFORK);  // убрать "still reachable" memory
                                           // leaks, возникающие из-за check.h
  srunner_run_all(sr, CK_NORMAL);  // CK_VERBOSE
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (!number_failed) ? EXIT_SUCCESS : EXIT_FAILURE;
}