﻿// Сумма элементов [The sum of elements]
// 
// Дана математическая квадратная матрица размером N.
// Необходимо разработать функцию (или программу), 
// которая вычисляет сумму элементов матрицы, 
// расположенных на главной и побочной диагоналях.
#include "logic.h"

int sum_main_and_second_diagonales_elements(int** matrix, int n) {

	if (matrix == nullptr || n <= 0)
	{
		return 0;
	}

	int sum = 0;

	for (int i = 0; i < n; i++)
	{
		sum += matrix[i][i] + matrix[i][n - 1 - i];
	}

	

	return sum - (n % 2 == 0 ? 0 : matrix[n / 2][n / 2]);
}