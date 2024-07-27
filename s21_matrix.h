#ifndef S21_MATRIX_H
#define S21_MATRIX_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 1
#define FAILURE 0
#define OK 0
#define ERROR_MATRIX 1
#define ERROR_CALC 2
#define S21_EPS 1e-7
#define S21_EPS_CHECK 1e-6

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

// functions from the task
int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);
int s21_eq_matrix(matrix_t *A, matrix_t *B);
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_transpose(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

// helpers (functions used in functions above)
int is_correct_matrix(matrix_t *A);
int compare_matrix(matrix_t *A, matrix_t *B);
void sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
void sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
void mult_number(matrix_t *A, double number, matrix_t *result);
void mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
void transpose(matrix_t *A, matrix_t *result);
void determinant(matrix_t *A, double *result);
void fill_minor(matrix_t *minor, matrix_t *A, int ignored_row, int ignored_col);
void calc_complements(matrix_t *A, matrix_t *result);
void inverse_matrix(matrix_t *A, matrix_t *result, double det);

#endif