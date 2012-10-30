/**
 * 
 *	Priklad c. 5, zaklady jazyka C
 *
 *	Pointry, volume 1! 
 *	
 *	This file is part of the 0VP course 
 *	https://www.vutbr.cz/studium/ects-katalog/detail-predmetu?apid=126886&oid=8451
 *
 *	New BSD License
 *
 */

#define  _CRT_SECURE_NO_WARNINGS

#include "stdio.h"
#include "stdlib.h"

void swap(int *x, int *y)
{
	int tmp = *x;

	*x = *y;
	*y = tmp;
}

void swap_ptrs(int **x, int **y)
{
	int *tmp = *x;

	*x = *y;
	*y = tmp;
}


int main(int argc, char *argv[])
{
	int a = 5;
	int *p;

	int *p_int = NULL;
	char *str;
	int *pole;

	int i=0;

	int x, y;


	//-----------------------------------------------------------------------------------------------------------------------------------
	p = &a;
	
	printf("Adresa a = %p\n", &a);
	printf("Adresa p = %p\n", p);
	printf("Absolutni adresa p = %p\n" ,&p);
	printf("Hodnota ulozena na adrese %p = %d\n\n", p, *p);

	// prirazeni hodnoty na adresu ulozenou v p tj do a
	*p = 10;	
	printf("Hodnota a = %d\n", a);

	printf("\n");
	

	//-----------------------------------------------------------------------------------------------------------------------------------
	// dynamicka alokace 
	p_int = (int*) malloc(sizeof(int));
	//*p_int = 10;
	printf("Hodnota ulozena na adrese %p = %d\n\n", p_int, *p_int);
	free(p_int);

	// dynamicka alokace 
	p_int = (int*) calloc(1, sizeof(int));
	//*p_int = 10;
	printf("Hodnota ulozena na adrese %p = %d\n\n", p_int, *p_int);
	free(p_int);

	// dynamicka alokace 
	if ( (p_int = (int*) malloc(sizeof(int))) != NULL)
	{
		*p_int = 10;
		printf("Hodnota ulozena na adrese %p = %d\n\n", p_int, *p_int);
		free(p_int);
	} else 
		printf("Snap! Chyba, malo pameti! \n");


	//  pouziti ptr jako argumentu fce
	x = 10; 
	y = 5;

	swap(&x, &y);
	printf("x = %d, y = %d\n", x, y);

	swap_ptrs(&x, &y);
	printf("x = %d, y = %d\n", x, y);

	printf("\n");

	//-----------------------------------------------------------------------------------------------------------------------------------
	// prace na polu :) 

	// pole cisel typu int
	pole = (int *) malloc(10 * sizeof(int));

	for(i=0; i<10; i++)
	{
		pole[i] = i;
	}

	// vypsani hodnot pole
	for(i=0; i<10; i++)
	{
		printf("pole[%d] = %d \n", i, pole[i]);
	}

	printf("\n");

	//-----------------------------------------------------------------------------------------------------------------------------------
	// retezec => pole znaku ukoncene 0
	str = (char *) malloc(1024 * sizeof(char));
	strcpy(str, "Hello World!"); // DANGER, pozor na preteceni
	printf("%s \n", str);
	
	// prepiseme str
	for(i=0; i<5; i++)
	{
		str[i] = 'A';
	}
	str[i] = '\0'; // musime ukoncit str znakem '\0'
	printf("%s \n", str);
	
	free(str);


	//-----------------------------------------------------------------------------------------------------------------------------------
	printf("\n");
	return 0;
}

