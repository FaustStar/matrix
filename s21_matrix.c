#include "s21_matrix.h"

int is_correct_matrix(matrix_t *A) {
  return (A && A->matrix && A->rows > 0 && A->columns > 0) ? OK : ERROR_MATRIX;
}

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int error = OK;
  if (result) {  // т.е. result != NULL
    result->rows = 0;  // начальная инициализации структуры
    result->columns = 0;  // чтобы избежать утечек при вызове remove_matrix()
    result->matrix = NULL;
  }
  if (rows <= 0 || columns <= 0 || result == NULL) {
    error = ERROR_MATRIX;
  } else {
    result->rows = rows;
    result->columns = columns;
    result->matrix =
        calloc(rows, sizeof(double *));  // создание массива указателей
    for (int i = 0; i < rows; i++) {
      result->matrix[i] = calloc(
          columns,
          sizeof(double));  // создание массива с элементами i-й строки матрицы
    }
  }
  return error;
}

void s21_remove_matrix(matrix_t *A) {
  if (is_correct_matrix(A) == OK) {
    for (int i = 0; i < A->rows; i++) {
      free(A->matrix[i]);
    }
    free(A->matrix);
    A->rows = 0;
    A->columns = 0;
    A->matrix = NULL;
  }
}

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int error = SUCCESS;
  if (is_correct_matrix(A) == OK && is_correct_matrix(B) == OK &&
      A->rows == B->rows && A->columns == B->columns) {
    error = compare_matrix(A, B);
  } else {
    error = FAILURE;
  }
  return error;
}

int compare_matrix(matrix_t *A, matrix_t *B) {
  int error = SUCCESS;
  int count = 0;
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      if (fabs(A->matrix[i][j] - B->matrix[i][j]) < S21_EPS) {
        count++;
      }
    }
  }
  if (count != A->rows * A->columns) {
    error = FAILURE;
  }
  return error;
}

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error = OK;
  s21_create_matrix(0, 0, result);  // начальная инициализация структуры
  if (is_correct_matrix(A) == OK && is_correct_matrix(B) == OK && result) {
    if (A->rows == B->rows && A->columns == B->columns) {
      s21_create_matrix(A->rows, A->columns, result);
      sum_matrix(A, B, result);
    } else {
      error = ERROR_CALC;
    }
  } else {
    error = ERROR_MATRIX;
  }
  return error;
}

void sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
    }
  }
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error = OK;
  s21_create_matrix(0, 0, result);  // начальная инициализация структуры
  if (is_correct_matrix(A) == OK && is_correct_matrix(B) == OK && result) {
    if (A->rows == B->rows && A->columns == B->columns) {
      s21_create_matrix(A->rows, A->columns, result);
      sub_matrix(A, B, result);
    } else {
      error = ERROR_CALC;
    }
  } else {
    error = ERROR_MATRIX;
  }
  return error;
}

void sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
    }
  }
}

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int error = OK;
  s21_create_matrix(0, 0, result);  // начальная инициализация структуры
  if (is_correct_matrix(A) == OK && result) {
    s21_create_matrix(A->rows, A->columns, result);
    mult_number(A, number, result);
  } else {
    error = ERROR_MATRIX;
  }
  return error;
}

void mult_number(matrix_t *A, double number, matrix_t *result) {
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[i][j] = A->matrix[i][j] * number;
    }
  }
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error = OK;
  s21_create_matrix(0, 0, result);  // начальная инициализация структуры
  if (is_correct_matrix(A) == OK && is_correct_matrix(B) == OK && result) {
    if (A->columns == B->rows) {
      s21_create_matrix(A->rows, B->columns, result);
      mult_matrix(A, B, result);
    } else {
      error = ERROR_CALC;
    }
  } else {
    error = ERROR_MATRIX;
  }
  return error;
}

void mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < B->columns; j++) {
      double sum = 0;
      for (int k = 0; k < A->columns; k++) {
        sum += A->matrix[i][k] * B->matrix[k][j];
      }
      result->matrix[i][j] = sum;
    }
  }
}

int s21_transpose(matrix_t *A, matrix_t *result) {
  int error = OK;
  s21_create_matrix(0, 0, result);  // начальная инициализация структуры
  if (is_correct_matrix(A) == OK && result) {
    s21_create_matrix(A->columns, A->rows, result);
    transpose(A, result);
  } else {
    error = ERROR_MATRIX;
  }
  return error;
}

void transpose(matrix_t *A, matrix_t *result) {
  for (int i = 0; i < A->columns; i++) {
    for (int j = 0; j < A->rows; j++) {
      result->matrix[i][j] = A->matrix[j][i];
    }
  }
}

int s21_determinant(matrix_t *A, double *result) {
  int error = OK;
  if (is_correct_matrix(A) == OK && result) {
    if (A->rows == A->columns) {
      determinant(A, result);
    } else {
      error = ERROR_CALC;
    }
  } else {
    error = ERROR_MATRIX;
  }
  return error;
}

//расчет определителя разложением по 1-й строке рекурсивно
void determinant(matrix_t *A, double *result) {
  if (A->rows == 1) {
    *result = A->matrix[0][0];
  } else {
    *result = 0;
    for (int j = 0; j < A->columns; j++) {
      matrix_t minor;
      s21_create_matrix(A->rows - 1, A->columns - 1, &minor);
      fill_minor(&minor, A, 0, j);
      double minor_det = 0;
      determinant(&minor, &minor_det);
      *result += pow(-1, j) * A->matrix[0][j] * minor_det;
      s21_remove_matrix(&minor);
    }
  }
}

void fill_minor(matrix_t *minor, matrix_t *A, int ignored_row,
                int ignored_col) {
  int row = 0;
  for (int i = 0; i < A->rows; i++) {
    int column = 0;
    for (int j = 0; j < A->columns; j++) {
      if (i != ignored_row && j != ignored_col) {
        minor->matrix[row][column] = A->matrix[i][j];
        column++;
      }
    }
    row += (i != ignored_row) ? 1 : 0;
  }
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int error = OK;
  s21_create_matrix(0, 0, result);  // начальная инициализация структуры
  if (is_correct_matrix(A) == OK && result) {
    if (A->rows == A->columns) {
      s21_create_matrix(A->rows, A->columns, result);
      calc_complements(A, result);
    } else {
      error = ERROR_CALC;
    }
  } else {
    error = ERROR_MATRIX;
  }
  return error;
}

void calc_complements(matrix_t *A, matrix_t *result) {
  if (A->rows != 1) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        matrix_t minor;
        s21_create_matrix(A->rows - 1, A->columns - 1, &minor);
        fill_minor(&minor, A, i, j);
        s21_determinant(&minor, &result->matrix[i][j]);
        result->matrix[i][j] *= pow(-1, i + j);
        s21_remove_matrix(&minor);
      }
    }
  } else {
    result->matrix[0][0] = 1;
  }
}

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int error = OK;
  s21_create_matrix(0, 0, result);  // начальная инициализация структуры
  if (is_correct_matrix(A) == OK && result) {
    double det = 0;
    if (s21_determinant(A, &det) == OK && fabs(det) >= S21_EPS_CHECK) {
      inverse_matrix(A, result, det);
    } else {
      error = ERROR_CALC;
    }
  } else {
    error = ERROR_MATRIX;
  }
  return error;
}

void inverse_matrix(matrix_t *A, matrix_t *result, double det) {
  matrix_t alg_complements;
  s21_calc_complements(A, &alg_complements);

  matrix_t trans_alg_compl;
  s21_transpose(&alg_complements, &trans_alg_compl);

  s21_mult_number(&trans_alg_compl, (1 / det), result);

  s21_remove_matrix(&alg_complements);
  s21_remove_matrix(&trans_alg_compl);
}