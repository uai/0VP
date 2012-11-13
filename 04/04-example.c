/**
 * 
 *	Priklad c. 4, zaklady jazyka C
 *
 *	Soubory, otevirani, zavirami, cteni a taky aj zapisovani! 
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

#define BUFFER_SIZE 10

int main(int argc, char *argv[])
{
	FILE *f,*fcopy;
	char c;
	int i;

	char buffer[BUFFER_SIZE];
	
	int fsize = 0;
	int bytes_read = 0;
	char *pole = NULL;

  /* Zpusoby prace se souborem  
	Textovy rezim:
	"r"	read:  Otevre soubor pro cteni, soubor musi existovat. 
	"w"	write: Vytvori soubor pro zapis, pokud soubor neexistuje vytvori prazdny soubor.
                       Pokud stejnomenny soubor existuje je jeho obsah prepsan.   	 
	"a"	append: Otevre soubor pro zapis, kde se bude pokracovat v zapisovani na konci souboru.  
                         Cteni souboru je mozne kdekoliv. Funkce pro posuvy v souboru "fseek, fsetpos, rewind".
	"r+"	read/update: Otevre soubor pro cteni a zapis, soubor musi existovat. 
	"w+"	write/update: Vytvori soubor pro zapis, pokud soubor neexistuje vytvori prazdny soubor.
                                  Pokud stejnomenny soubor existuje je jeho obsah prepsan.   	 
	"a+"	append/update: Otevre soubor pro zapis, kde se bude pokracovat v zapisovani na konci souboru.  
                                     Cteni souboru je mozne kdekoliv. Funkce pro posuvy v souboru "fseek, fsetpos, rewind".

	Binarni rezim:
	 "rb"	read:  Otevre soubor pro cteni v binarnim rezimu, soubor musi existovat. 
	 "wb"	write: Vytvori soubor pro zapis v binarnim rezimu, pokud soubor neexistuje vytvori prazdny soubor.
			 Pokud stejnomenny soubor existuje je jeho obsah prepsan.   	 
    */

	// cteni souboru znak po znaku
	//-------------------------------------------------------------------------------------------------------------------------

	// otevreni souboru
	f = fopen("original.txt","r");  

	//cteni postupne znak po znaku do konce souboru
	while((c = getc(f))!= EOF)
		putchar(c);

	putchar('\n');

	fclose(f);   //zavreni souboru

	printf("\n");

	// zapisovani do souboru
	//-------------------------------------------------------------------------------------------------------------------------
	printf("Zapsani do souboru 'zapsany.txt' \n");

	//otevreni souboru pro zapis
	f = fopen("zapsany.txt","w");   
	fprintf(f,"zaèátek zápisu do souboru\n");   //zapis do souboru

	for (i = 32; i < 127; i++)
	{
		fprintf(f," znak = %c",(char)i);       //zapis do souboru
	}
	fclose(f);   //zavreni souboru

	printf("\n");


	// kopirovani soubou, varianta 1
	//-------------------------------------------------------------------------------------------------------------------------
	printf("Kopirovani souboru 'original.txt' do souboru 'kopie1.txt' \n");

	//otevreni souboru pro cteni + kontrola zda se otevreni podarilo
	if((f = fopen("original.txt","r")) == NULL){   
		printf("Chyba otevreni souboru\n");         
	}else{
		fcopy = fopen("kopie1.txt","w");

		while((c = getc(f))!= EOF)
			putc(c,fcopy);

		if(fclose(f) == EOF)         //kontrola správnosti uzavreni
			printf("Chyba uzavreni souboru\n");

		fclose(fcopy);
	}
	
	// kopirovani soubou, varianta 2
	//-------------------------------------------------------------------------------------------------------------------------
	printf("Kopirovani souboru 'original.txt' do souboru 'kopie2.txt' \n");

	//otevreni souboru pro cteni + kontrola zda se otevreni podarilo
	if((f = fopen("original.txt","r")) == NULL){   
		printf("Chyba otevreni souboru\n");         
	}else{

		fcopy = fopen("kopie2.txt","w");

		while(fgets(buffer, 10, f) != NULL)
			fputs(buffer, fcopy);

		fclose(f);
		fclose(fcopy);
	}

	// kopirovani soubou, varianta 3
	//-------------------------------------------------------------------------------------------------------------------------
	printf("Kopirovani souboru 'original.txt' do souboru 'kopie3.txt' \n");

	if((f = fopen("original.txt","r")) == NULL){   
		printf("Chyba otevreni souboru\n");         
	}else{

		fcopy = fopen("kopie3.txt","w");

		while(fscanf(f, "%c", &c) != EOF)
			fprintf(fcopy,"%c",c);

		fclose(f);
		fclose(fcopy);
	}
	
	// kopirovani soubou, varianta 4
	//-------------------------------------------------------------------------------------------------------------------------
	printf("Kopirovani souboru 'original.txt' do souboru 'kopie4.txt' \n");

	// tato varianta pouziva dynamicky alokavane pole o velikosti celeho
	// do ktereho se ulozi cely obsah souboru, tento pristup je samozrejme nevhodny 
	// pri velke velikosti soboru, lepsi by bylo vytvorit pole o urcite velikosti 
	// napr. 1024bajtu (1kB) a postupne prochazet kopirovany soubor a ukladat 
	// do nej data, ktere se nasledne zapisi do noveho souboru, s tim ze si pohlidame
	// kolyk bajtu se nacetlo (na konci souboru resp. posledni buffer) tolik zapiseme

	//otevreni souboru pro cteni + kontrola zda se otevreni podarilo
	if((f = fopen("original.txt","rb")) == NULL){   
		printf("Chyba otevreni souboru\n");         
	}else{
		fcopy = fopen("kopie4.txt","wb");
				
		// potrebujeme zjistit velikost souboru
		// pomoci fseek skocime na konec souboru
		fseek (f , 0 , SEEK_END);

		// ftell nam vraci aktualni pozici v souboru, tj. v tomto pripade konenc souboru
		fsize = ftell (f);

		// rewind nas vrati na pocatek souboru
		rewind (f);

		// alokujeme pamet pro cely soubor
		pole = (char*) malloc (sizeof(char)*fsize);
		if (pole == NULL) 
		{
			fputs ("SPatna alokace pameti", stderr); 
			exit(1); // ukonceni programu
		}
		
		// nahrajeme data do alokovane pameti
		bytes_read = fread (pole, 1, fsize, f);
		if (bytes_read != fsize) 
		{
			fputs ("Chyba cteni souboru!",stderr); 
			exit(1);
		}

		// zapiseme obsah pole do noveho souboru
		bytes_read = fwrite (pole, 1, fsize, fcopy);
		if (bytes_read != fsize) 
		{
			fputs ("Chyba pri zapisu do souboru!",stderr); 
			exit(1);
		}
		
		// uvolneni souboru a pole
		fclose(f);
		fclose(fcopy);
		free(pole);
	}

	printf("\n");
	return 0;
}
