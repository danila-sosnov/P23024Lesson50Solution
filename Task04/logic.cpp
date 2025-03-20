// Сумма элементов столбцов с экстремальными элементами
// [The Sum of elements of columns with extreme elements]
// 
// Дана математическая прямоугольная матрица размером N на M.
// Необходимо разработать функцию (или программу), которая 
// высчитывает сумму элементов в тех столбцах заданной матрицы,
// которые содержат хотя бы один экстремальный элемент.

#include "logic.h"

int get_extreme_value(int** matrix, int n, int m, bool type)
{
	int value = matrix[0][0];
	

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			bool condition = type ? matrix[i][j] < value : matrix[i][j] > value;
			if (condition)
			{
				value = matrix[i][j];
			}
		}

	}

	return value;
}

bool is_extreme_value_in_colomn(int** matrix, int n, int index, int min, int max)
{
	for (int i = 0; i < n; i++)
	{
		if (matrix[i][index] == max || matrix[i][index] == min)
		{
			return true;
		}
	}

	return false;
}

int sum_elements_of_columns_with_extreme_value(int** matrix, int n, int m) {

	if (matrix == nullptr || n <= 0 || m <= 0)
	{
		return 0;
	}

	int max = get_extreme_value(matrix, n, m,false);
	int min = get_extreme_value(matrix, n, m,true);

	int sum = 0;

	for (int j = 0; j < m; j++)
	{
		if (is_extreme_value_in_colomn(matrix,n,j,min,max))
		{

			for (int i = 0; i < n; i++)
			{
				sum += matrix[i][j];
			}
		}
	}
	return sum;
}