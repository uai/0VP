/**
 *	Priklad c. 2, zaklady jazyka C
 *	  
 *	Vypisovani na obrazovku, cteni hodnot z obr.
 *	Ridici struktury.
 *	
 *	
 *	This file is part of the 0VP course 
 *	https://www.vutbr.cz/studium/ects-katalog/detail-predmetu?apid=126886&oid=8451
 *
 *	New BSD License
 *
 */

#define _CRT_SECURE_NO_WARNINGS

#define BUFF_SIZE 1024 // konstanta

#include "stdio.h"
//#include "conio.h"  

int main(int argc, char *argv[])
{
	// promenne		
	char ch;
	int cele = 0;
	float realne;

	char string[BUFF_SIZE]; // pole znaku

	int pocet = 0;
	unsigned int i = 0;

	int a, b, c, d = 0;
	
	const unsigned int MAX_REPEATS = 10; // konstanta
		
	//-------------------------------------------------------------------------------------------------------------------------
	// vypisovani zpravy na obrazovku

	putchar('A');
	putchar('h');
	putchar('o');
	putchar('j');
	putchar(' ');

	putc('t', stdout); // definujeme vystupni stream 
	putc('a', stdout);
	putc('d', stdout);
	putc('y', stdout);
	putc(' ', stdout);
	putc('j', stdout);
	putc('e', stdout);	

	printf(" nas dalsi "); 

	fprintf(stdout, "paradni "); 
	fprintf(stderr, "program. ");   

	puts("Hura!!!\n"); 
	
	//-------------------------------------------------------------------------------------------------------------------------
	// ziskavani hodnot
	printf("\nZiskavani hodnot ze vstupu: \n");

	printf("Zadej 1 znak: ");
	ch = getchar();	
	while(getchar() != '\n');
	printf("Zadany znak = %c \n\n", ch);

	// funkce getchar
	printf("Zadej opet 1 znak: ");
	ch = getc(stdin);
	while(getc(stdin) != '\n');
	printf("Zadany znak = %c \n\n", ch);

	printf("Zadej opet 1 znak: ");
	scanf("%c", &ch);
	printf("Zadany znak = %c \n\n", ch);
	
	printf("Zadej celociselne cislo: ");
	scanf("%d", &cele);
	printf("Zadane celociselne cislo = %d \n\n", cele);

	printf("Zadej realne cislo: ");
	scanf("%f", &realne);
	printf("Zadane realne cislo = %f \n\n", realne);

	printf("Zadej cele a realne cislo: ");
	pocet = scanf("%d %f", &cele, &realne);
	printf("Zadane  cele cislo = %d a realne cislo = %f \nPocet" 
		"precteneych hodnot = %d \n", cele, realne, pocet);

	printf("Zadej realne cislo: ");
	scanf("%f", &realne);
	printf("Zadane realne cislo = %4.2f \n", realne);
	printf("Zadane realne cislo = %4.6f \n\n", realne);

	printf("Zadej retezec: ");
	scanf("%s", string);
	printf("String = %s \n", string); // !!!

	//-------------------------------------------------------------------------------------------------------------------------
	// ridici struktury

	// podminka if
	printf("\n\nPodminka If: \n");
	printf("Zadej cislo: ");
	pocet = scanf("%d", &cele);

	if( cele > 10)
	{
		printf("Vetsi jak 10! \n");
	}	

	printf("\n\n");
	
	printf("Zadej cislo: ");
	scanf("%d", &cele);

	if( cele > 10)
	{
		printf("Vetsi jak 10! \n");
	}
	else
	{
		printf("Mensi jak 10! \n");	// vypise se i kdyz zadame 10
	}

	printf("\n\n");

	printf("Zadej cislo: ");
	scanf("%d", &cele);

	if( cele > 10)
	{
		printf("Vetsi jak 10! \n");
	}
	else if (cele == 10)
	{
		printf("Deseeet! \n");
	}
	else
	{
		printf("Mensi jak 10! \n");
	}

	// cyklus for
	printf("\n\nCyklus For: \n");
	
	for (i=0; i < MAX_REPEATS; i++)
	{
		printf("%3d - Ahoj svete! \n", i);
	}

	// cyklus while
	printf("\n\nCyklus While: \n");
	i = 0;
	while(i < MAX_REPEATS){
		printf("%3d - Ahoj svete! \n", i);
		i++;
	}

	// cyklus do-while
	printf("\n\nCyklus Do-While: \n");
	i = 0;
	do
	{
		printf("%3d - Ahoj svete! \n", i);
		i++;
	} while(i < MAX_REPEATS);


	// nekonecny cyklus
	printf("\n\nNekonecny cyklus: \n");
	i = 0;
	while(1)
	{
		printf("%3d - Ahoj svete! \n", i);
		i++;

		if (i >= MAX_REPEATS + 10) break;
	}
	
	printf("\n\n");

	for (i=0;;i++)
	{
		printf("%3d - Ahoj svete! \n", i);
		//i++;

		if (i == MAX_REPEATS + 10) 
		{
			printf("Ukoncuji for... \n");
			break;			
		}
	}

	// swich  /prepinac/
	printf("\n\nPrepinac switch: \n");

	printf("Zadej cislo od 1-5: ");
	scanf("%d", &cele);

	switch (cele)
	{
	case 1:
		printf("Jedna! \n");
		break;
	case 2:
		printf("Jedna! \n");
		break;
	case 3:
		
	{
			
		printf("Jedna, dva, tri... rozhodci je kamarad! \n");
			
		break;
		
	}
	
	case 4:
		
		printf("Ctyri! \n");
		
		break;
	
	case 5:
		
		printf("Pet! \n");
		
		break;
		
	default:
		printf("Mimo rozsah! \n");
		break;
	}
	
	//-------------------------------------------------------------------------------------------------------------------------

	// inicializace promennych
	printf("\n\nInicializace promennych: \n");
	a = b = c = d;
	printf("a = %d, b = %d, c = %d, d = %d \n", a,b,c,d);
	
	

	return 0;
}