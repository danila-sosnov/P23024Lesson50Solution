// Минимальный максимум среди всех локальных максимумов
// [The minimum maximum among all local maxima].
// 
// Дана математическая прямоугольная матрица размером N на M.
// Необходимо разработать функцию (или программу), которая 
// находит значение локального максимума, который является
// минимальным среди всех локальных максимумов. 

#include "logic.h"
#include <iostream>


bool is_local_max(int** matrix, int n, int m, int i, int j)
{
	

	if (i > 0 && matrix[i - 1][j] >= matrix[i][j])
	{
		return false;
	}
	if (i < n - 1 && matrix[i + 1][j] >= matrix[i][j])
	{
		return false;
	}
	if (j > 0 && matrix[i][j - 1] >= matrix[i][j])
	{
		return false;
	}
	if (j < m - 1 && matrix[i][j + 1] >= matrix[i][j])
	{
		return false;
	}


	return true;
}

int get_min_maximum(int** matrix, int n, int m) {

	if (matrix == nullptr || n <= 0 || m <= 0)
	{
		return 0;
	}

	int minLocalMax = INT_MAX;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (is_local_max(matrix, n, m, i, j))
			{
				if (matrix[i][j] < minLocalMax)
				{
					minLocalMax = matrix[i][j];
				}
			}
		}
	}

	if (n == 1 && m == 1)
	{
		minLocalMax = 0;
	}

	return minLocalMax;
}