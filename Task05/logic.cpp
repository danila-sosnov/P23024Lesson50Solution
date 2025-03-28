// Последний локальный минимум
// [The last local minimum]
// 
// Дана математическая прямоугольная матрица размером N на M.
// Необходимо разработать эффективную функцию (или программу), которая 
// находит и возвращает местоположение последнего локального минимума. 

#include "logic.h"

bool is_local_min(int** matrix, int n, int m, int i, int j)
{
	if (matrix == nullptr || n <= 0 || m <= 0)
	{
		return false;
	}

	if (i > 0 && matrix[i - 1][j] <= matrix[i][j])
	{
		return false;
	}
	if (i < n - 1 && matrix[i + 1][j] < matrix[i][j])
	{
		return false;
	}
	if (j > 0 && matrix[i][j - 1] <= matrix[i][j])
	{
		return false;
	}
	if (j < m - 1 && matrix[i][j + 1] < matrix[i][j])
	{
		return false;
	}


	return true;
}

void get_last_local_minimum(int** matrix, int n, int m, int* ii, int* jj) {

	
	

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (is_local_min(matrix, n, m, i, j))
			{
				*ii = i + 1;
				*jj = j + 1;

			}
		}
	}
		
	if (n == 1 && m == 1)
	{
		*ii = 0;
		*jj = 0;
	}
		
}