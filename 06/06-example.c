/**
* 
*	Priklad c. 6, zaklady jazyka C
*
*	Pointry, volume 2! 
*	
*	This file is part of the 0VP course 
*	https://www.vutbr.cz/studium/ects-katalog/detail-predmetu?apid=126886&oid=8451
*
*	New BSD License
*
*	C language is all about speed. Hot, nasty, bad-ass speed. - Eleanor Roosevelt, 1936.
*/


#define  _CRT_SECURE_NO_WARNINGS

#include "stdio.h"
#include "stdlib.h"

void swap_ptrs(int ***x, int ***y)
{
	int **tmp = *x;

	*x = *y;
	*y = tmp;
}

int** alloc(int rows, int cols)
{
	int i = 0; 
	int **matrix;

	matrix = (int **) calloc(rows, sizeof(int *)); 
	//matrix = (int **) malloc(rows * sizeof(int));

	if (matrix != NULL)
	{
		for(i=0; i<rows; i++)
		{
			matrix[i] = (int *) calloc(cols, sizeof(int *)); 
			//matrix[i] = (int *) malloc(cols * sizeof(int)); 
		}
	}
	return matrix;	
}

void free_matrix(int** matrix, int rows)
{
	int i = 0; 

	for(i=0; i<rows; i++)
	{
		free(matrix[i]);
	}
	free(matrix);
}

void print_matrix(int** matrix, int rows, int cols)
{
	int i = 0; int j;	

	printf("Matice: \n");

	for(i=0; i<rows; i++)
	{
		for(j=0; j<cols; j++)
		{
			printf("%d", matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");

}

void print_matrix_reloaded(int** matrix, int rows, int cols)
{
	int i = 0;
	int j = 0;

	for(i=0; i<rows; i++)
	{
		for(j=0; j<cols; j++)
		{
			printf("matrix[%d][%d] = %d \n", i, j, matrix[i][j]);
		}
	}
	printf("\n");
}


int main(int argc, char *argv[])
{
	int a = 5;
	int i = 0;
	int j = i;

	int **matrix;
	int rows = 5;
	int cols = 5;

	int **m1;
	int **m2;

	// alokace matice
	//-----------------------------------------------------------------------------------------------------------------------------------
	matrix = alloc(rows, cols);
	print_matrix(matrix, rows, cols);
	free_matrix(matrix, rows);

	// priklad c.2 alokace dvou matic a jejich prohozeni
	//-----------------------------------------------------------------------------------------------------------------------------------
	m1 = alloc(rows, cols);
	m2 = alloc(rows, cols);

	m1[1][1] = 1;

	printf("1 ");
	print_matrix(m1, rows, cols);
	printf("2 ");
	print_matrix(m2, rows, cols);

	// prohozeni ukazatelu na matice
	swap_ptrs( &m1, &m2);

	printf("1 ");
	print_matrix(m1, rows, cols);
	printf("2 ");
	print_matrix(m2, rows, cols);

	free_matrix(m1, rows);
	free_matrix(m2, rows);
	//-----------------------------------------------------------------------------------------------------------------------------------
	return 0;
}

