/**
 *	Priklad c. 1, zaklady jazyka C
 *	  
 *	Definice promennych, datove typy, inicializace.
 *	Komentare, jednoradkove, viceradkove.	
 *	Vypisovani zprav na obrazovku,  "Ahoj svete" .
 *	Formatovany vypis apod.
 *	Seznameni s kompilaci (debug/release), vyvojovym prostredim, ladenim. 
 *	
 *	This file is part of the 0VP course 
 *	https://www.vutbr.cz/studium/ects-katalog/detail-predmetu?apid=126886&oid=8451
 *
 *	New BSD License
 *
 */

#include "stdio.h"

int main(int argc, char *argv[])
{
	/*	
	Zakladni datove typy
	celociselne:
	char, short, int, long

	prefixy: signed, unsigned
	unsigned		0..2^n - 1
	signed		-2^(n-1)..2(n-1)-1

	racionalni: 
	float, doule, long double	

	norma C89/90 jazyka C nezna datovy typ bool
	pouziva se int, kdy 
	0 = false
	1 = true (resp. jakakoliv nenulova hodnota)
	*/

	// lokalni promenne lze vytvorit pouze na zacatku dane funkce
	// definice promenych, 
	// promenne je prideleno jmeno, dat. typ, pamet,  pripad. je inicializovana
	int value;
	int a = 10;
	int b = 20;
	int c = 0;
		
	char ch = '*';
	int distance = 74;
	float exact_distance = 73.8f;

	// definovani constant 
	#define PI 3.14159265
	const double SECOND_PI = 3.14159265;
		
	//-----------------------------------------------------------------------------------------------------------------------------------
	// vypisovani zpravy na obrazovku

	puts("Hello world."); // vypiseme zpravu do konzole a automat. se odradkuje
	// formatovany vypis
	printf("Ahoj svete!\n"); // takto vypiseme take zpravu a odradkujeme 
	
	/* 	Takto vytvorime 
	viceradkovy komentar  	*/
	
	// takto vytvorime jednoradkovy komentar
	printf("Z Brna je to %d Km do Hradiste daleko.\n", distance); // takto to jde taky :) 
	printf("Z Brna je to %f Km do Hradiste daleko.\n", exact_distance); 
	
	// vypsovani s urcenim presnosti
	printf("Pi = %4.2f \n", SECOND_PI); 
	
	// pozor! zde vypisujeme neinicializovanou promennou, 
	// na obrazovku se vypise nesmysl
	//printf("Value = %d \n", value); 
	
	// musime do promenne priradit hodnotu
	value = 100; 
	printf("Value = %d \n", value); 
	
	// soucet dvou promenych
	printf("Soucet a+b = %d \n", a+b); 

	// soucet dvou promenych a ulozeni do treti promenne
	c= a+b;
	printf("c = %d \n", a+b); 


	return 0;
}