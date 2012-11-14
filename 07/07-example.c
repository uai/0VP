/**
* 
*	Priklad c. 7, zaklady jazyka C
*
*	Makra!
*	Pointry, volume 3! Ale uz jen trosku. :) 
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
#include "assert.h"

#define WINDOWS

// podmineny preklad
// v pripade ze je definovano WINDOWS
// includuje se windows.h jinak dals .h soubory
#ifdef WINDOWS
#include <windows.h>
#else
#include <sys/types.h> 
#include <sys/stat.h>
#include <unistd.h>
#endif

// makra preprocesoru
#define PI 3.14
#define AHOJ "ahoj!\n"   

// makra s argumenty, pozor 
#define MIN(X, Y)  ((X) < (Y) ? (X) : (Y))

// makro vytvarejici alias funkce, zjednoduseni zapisu
#define myputchar(x) putc(x, stdout)

// ukazka nevhodneho zapisu makra
#define HALF_FPRINTF(file) fprintf (file, "%s %d",
// takto je to lepsi 
#define FULL_FPRINTF(file, s, d) fprintf (file, "%s %d", s, d);

// funkce, ktera zjisti take min
int my_min(int a, int b)
{
	return a<b ? a:b;
}

// inline funkce, pozor keyword "inline" je definovano v C99 std.
// v C89 neni, vetsina kompileru podporuje rozsireni __inline
__inline int inline_min(int a, int b)
{
	return a<b ? a:b;
}

void print_int(int *num) 
{
	assert (num != NULL);
	printf ("%d\n", *num);
}

void print_double(double *num) 
{
	assert (num != NULL);
	printf ("%f\n", *num);
}

int main(int argc, char *argv[])
{
	int i = 0;
	int a = 5;
	int b = 10;

	double c = 10;

	int *ptr = NULL;

	void *vptr;

	//-----------------------------------------------------------------------------------------------------------------------------------
	// Makra
	printf("pi = %f \n", PI);
	
	//  pouzijeme makro
	printf("mensi je %d \n", MIN(a,b));
	// a takto se makro rozvine
	printf("mensi je %d \n", ((a) < (b) ? (a) : (b)));
	// volani fce my_min
	printf("mensi je %d \n", my_min(a,b));
	// volani inline fce
	printf("mensi je %d \n", inline_min(a,b));

	//  i takto jde pouzit makro, jako alias fce
	putc('*', stdout);
	putchar('*');
	myputchar('*');
	printf("\n");
	
	// pouziti nevhodneho makra
	HALF_FPRINTF(stderr) "!ahoj!", 35);
	// pouzit vhodnejsiho makra
	FULL_FPRINTF(stderr, "!nazdar!", 45);
	printf("\n");

	// pouziti makra __FILE__
	printf("Ahoj tady je: %s \n", __FILE__);
	printf("a volam z radku: %d \n", __LINE__);
	printf("a to prave dnes: %s \n", __DATE__);
	printf("Fiiiiio\n");
	//-----------------------------------------------------------------------------------------------------------------------------------

	// pouziti assert
	// spusti se asserace, pokud kompilujeme v DEBUG modu, tj. je definovano DEBUG
	// v pripade rls modu se aserace neprovede
	// v ptr je NULL
	//print_int(ptr);
	
	// ted ptr ukazuje na 'a' a vse je OK
	ptr = &a;
	print_int(ptr);
	//-----------------------------------------------------------------------------------------------------------------------------------
	// a jeset trosku neco k ptr, genericke pointry 
	
	vptr = &b;
	print_int(vptr); // warning nekompatibilni *int a *void
	print_int((int*) vptr);

	vptr = &c; 
	print_double((double*) vptr);





	return 0;
}

