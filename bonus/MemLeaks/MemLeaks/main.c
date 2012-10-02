/**
 *	Ukazka detekovani memory leaku ve visual studiu
 *	
 *	Info na msdn:
 *	http://msdn.microsoft.com/en-us/library/e5ewb1h3%28v=vs.80%29.aspx
 *
 *	Postupujeme dle msdn
 *	program spustime v debug modu 
 *	(v release to nebude fungovat)
 *	po dokonceni programu se nam zobrazi v Output okne nasledujici
 *	
 *	Output:
 *	Detected memory leaks!
 *	Dumping objects ->
 *	d:\coding\memleaks\memleaks\main.cpp(38) : {67} normal block at 0x00983930, 5 bytes long.
 *	Data: <> 42 75 66 66 65 
 *	d:\coding\memleaks\memleaks\main.cpp(35) : {66} normal block at 0x009838C8, 40 bytes long.
 *	Data: <> 00 00 00 00 01 00 00 00 02 00 00 00 03 00 00 00 
 *	
 *	This file is part of the 0VP course 
 *	https://www.vutbr.cz/studium/ects-katalog/detail-predmetu?apid=126886&oid=8451
 *
 *	New BSD License
 *
 */

#define _CRT_SECURE_NO_WARNINGS	// pro pouziti depracted funkci
#define _CRTDBG_MAP_ALLOC		// pro zjisteni memory leaku

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <crtdbg.h>	// pro zjisteni memory leaku


int main(int argc, char* argv[])
{
	// definovani konstant
	const int STR_SIZE = 5;
	const int INT_ARRAY_SIZE = 10;
		
	// deklarace retezce
	char* string; 
	// definice pole 
	int* vec = (int*) malloc(INT_ARRAY_SIZE * sizeof(int)); 
	
	int i = 0;

	//  alokace pameti a kopirovani textu do retezce
	string = (char*) malloc(STR_SIZE);
	strcpy(string, "Buffer overflow here i come...");
	printf("%s \n", string);
	
	// prace s polem intu, pouzijeme o 5 prvku vice nez je 
	for(i=0; i<INT_ARRAY_SIZE; ++i) {
		vec[i] = i;
		printf("Vector[%d] = %d \n", i, vec[i]);
	}
	

	// uvolneni pameti
	//free(string);
	//free(vec);

	// pro zjisteni memory leaku
	_CrtDumpMemoryLeaks(); 

	getchar();
	return 0;
}

