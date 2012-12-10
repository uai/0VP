/**
* 
*	Priklad c. 9, zaklady jazyka C
*
*	Obousmerny seznam
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
#include "string.h"

#include "list.h"


typedef struct 
{
	char *fist_name;
	char *last_name;
	uint age;
}Person;


//------------------------------------------------------------------------------------------
//  vlastni funkce pro tisk a free dat ulozenych v seznamu
//------------------------------------------------------------------------------------------
void my_print(data_t *data)
{ 
	if(data != NULL)
	{
		printf("First name: %s \n", ((Person*)data)->fist_name);
		printf("Last name : %s \n", ((Person*)data)->last_name);
		printf("Age       : %d \n", ((Person*)data)->age);
		printf("\n");
	}
	
}

int my_erase_data(data_t *data)
{ 
	// vlastni funkce pro uvolneni  dat
	Person *tmp = ((Person*)data);
	
	if(tmp != NULL)
	{
		free(tmp->fist_name);
		free(tmp->last_name);
		free(tmp);

		tmp = NULL;
		
		return 1;
	}
	
	return 0;
}
//------------------------------------------------------------------------------

 Person* alloc_person()
{
	Person *person = NULL;
	person = (Person*) malloc(sizeof(Person));

	if (person != NULL)
	{
		person->fist_name = (char*) calloc(50, sizeof(char));
		person->last_name = (char*) calloc(50, sizeof(char));
		person->age = 0;

	}

	return person;
}


int main(int argc, char *argv[])
{
	Person *person;
	
	// naplnime seznam datama
	person = alloc_person();
	strcpy(person->fist_name, "Franta");
	strcpy(person->last_name, "Obdrzalek");
	person->age = 10;
	push_back((void*)person);

	person = alloc_person();
	strcpy(person->fist_name, "Alois");
	strcpy(person->last_name, "Navratil");
	person->age = 24;
	push_back(person);

	person = alloc_person();
	strcpy(person->fist_name, "Josef");
	strcpy(person->last_name, "Margotka");
	person->age = 38;
	push_back(person);

	// vypiseme velikost seznamu
	printf("List size = %d \n\n", get_size());

	//print_data();
	print_data(&my_print);

	// smazeme seznam
	erase(&my_erase_data);

	// vypiseme velikost seznamu
	printf("\nList size = %d \n", get_size());


	return 0;
}