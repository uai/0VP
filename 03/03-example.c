/**
 *	Priklad c. 3, zaklady jazyka C
 *	  
 *	Operatory!
 *	Ternarni operatory.
 *	Makra! 
 *	Funkce, funkce a zase funkce! 
 *	Podmineny preklad.
 *	
 *	This file is part of the 0VP course 
 *	https://www.vutbr.cz/studium/ects-katalog/detail-predmetu?apid=126886&oid=8451
 *
 *	New BSD License
 *
 */

#define _CRT_SECURE_NO_WARNINGS

// globalni konstanty
#define BUFFER_SIZE 1024 
#define BEEF 0xDEADBEEF 

#define TEXT_WHITE	 15
#define TEXT_YELLOW	 14
#define TEXT_RED	 12
#define TEXT_BLUE	 11
#define TEXT_GREEN	 10
#define TEXT_GREY	  8

#define WINDOWS 

// includy
#include "stdio.h"
#include "math.h"  

#ifdef WINDOWS
#include <windows.h>
#endif

// globalni promenna
double soucet = 0;

// makra
// bez parametrù
#define AHOJ "Ahoj"			
#define NAZDAR printf("Nazdar!\n");

//s parametry
#define	POWER(x) ((x)*(x))	

//viceradkove makro
#define SOUCET(a, b) soucet = (a) + (b); \
	printf("soucet a+b je: %f \n", soucet);		


//  uplny funkcni prototyp
// fce nastavujici barvu textu konzole
// castecny prototyp 
//void setCmdTextColor(int); 
void setCmdTextColor(int Color); 

//  porovnani dvou cisel 
int maximum(int a, int b)
{
	return (a > b ? a:b);
}

//  soucet dvou cisel 
int secti(int a, int b)
{
	return (a+b);
}

// umocneni cisla danym mocnitelem
double float_mocnina(double a, double b)
{
	double vysledek = pow(a, b);
	return vysledek;
}

// vytiskne prvky pole
void printPole(const int pole[], unsigned int size)
{
	unsigned int i;

	if (size == 0) return;

	for (i=0; i < size; i++)
	{
		printf("Pole[%d] = %d \n", i, pole[i]);
	}	
}

int main(int argc, char *argv[])
{
	// promenne		
	//char buffer[BUFFER_SIZE]; // pole znaku
	int i = 0;
	int j = 0;
	char ch;
	float fl = 0;
	double dbl = 15.3;

	const int pole[] = {1, 2, 3, 4, 5, 6, 7};
	int velikostPole = 0;
	
	int a = 5;
	int x = 0;
	int y = 0;

	int prvni = 0;
	int druhe = 0;
	int result = 0;

	//-----------------------------------------------------------------------------------------------------------------------------------
	setCmdTextColor(TEXT_RED);
	printf("VITEJTE V CVICENI C. 3!\n\n");
	setCmdTextColor(TEXT_WHITE);

	// operatory	
	i = !i;
	printf("i = %d \n", i); 

	i = 10;

	i++; 
	printf("i = %d \n", i);
	++i; 
	printf("i = %d \n", i);

	i--;
	printf("i = %d \n", i);
	--i;
	printf("i = %d \n", i);

	i = i + 1;
	i = i - 1;

	printf("i / 2 = %d \n", i / 2);
	printf("i * 2 = %d \n", i * 2);
	printf("Zbytek po deleni = %d \n", i % 3);

	i += 1;
	i -= 1;

	if ( i > 0 && i <= 15 )
		printf("Od peti do patnacti... \n");

	if ( i == 10 ) 
		printf("Deset \n");

	j = 5;
	if ( i == 10 || j > 1)
		printf("Podminka splnena \n");

	j *= 2;
	printf("j = %d \n", j );

	j /= 2;
	printf("j = %d \n", j );

	printf("sizeof int = %d \n", sizeof(j));
	printf("sizeof char = %d \n", sizeof(ch));
	printf("sizeof float = %d \n", sizeof(fl));
	printf("sizeof double = %d \n", sizeof(dbl));
		
	printf("velikost pole = %d \n", sizeof(pole) / sizeof(pole[0]));
	velikostPole = sizeof(pole) / sizeof(pole[0]);

	printf("a = %d \n", a);
	a = a++ + ++a; // nedefinovany stav
	printf("a = %d \n", a);

	//-----------------------------------------------------------------------------------------------------------------------------------
	// ternarni operatory
	x = (x == 0) ? 1:11;
	printf("x = %d \n", x);
	
	// slozeny ternarni operator -> tohle neni dobry napad
	y=x>0?x<10?x:x>9000?9001:0:0;
	printf("y = %d\n",y);
	
	if(x>0 && x < 10)
		y = x;
	else if (x > 9000)
		y = 9001;
	else
		y = 0;
	
	// operator carky
	for(x=0, y=0; x<5; x++, ++y){
		printf("x = %d, y = %d \n", x, y);
	}
	
	//-----------------------------------------------------------------------------------------------------------------------------------
	// makra
	printf("%s \n", AHOJ);
	NAZDAR;
	printf("%d \n", POWER(10));
	SOUCET(x, y);

	//-----------------------------------------------------------------------------------------------------------------------------------
	// funkce

	printf("Zadej prvni cislo: ");
	scanf("%d", &prvni);

	printf("Zadej druhe cislo: ");
	while (!scanf("%d", &druhe))
	{
		fflush(stdin); 
		printf("Zadej cislo: ");	
	}
	result = secti(prvni, druhe);
	printf("A+B = %d  \n", result);

	printPole(pole, velikostPole);

	//-----------------------------------------------------------------------------------------------------------------------------------
	// podmineny preklad

	setCmdTextColor(TEXT_YELLOW);
#ifndef NDEBUG
	printf("DEBUG \n");
#else
	printf("RELEASE \n");
#endif
	setCmdTextColor(TEXT_WHITE);

	//-----------------------------------------------------------------------------------------------------------------------------------
	// booleovska algebra
	for(i = 0; i <= 15; i++){
		printf("i = %2d --> ", i);

		if((i >= 5) && (i <= 10)){
			printf("AND True , ");
		}else{
			printf("AND False, ");
		}

		if((i < 5) || (i > 10)){
			printf("OR True  \n");
		}else{
			printf("OR False \n");
		}
	}

	return 0;
}

/**
 *  Nastavuje barvu textu v kozolovem vystupu.  
 *  Je pouze implementovano pod windows.
 *
 * @param $a
 *   Hodnota typu int.
 *
 * @param $b
 *   Hodnota typu int.
 *
 * @return
 *   Vraci soucet dvou vstupnich hodnot.
 */
 void setCmdTextColor(int Color)
{
#ifdef WINDOWS
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon, (WORD)Color);
#endif
	// *nix version not implemented
	// on unix you can use https://en.wikipedia.org/wiki/ANSI_escape_code
}
