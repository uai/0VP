/**
* 
*	Priklad c. 8, zaklady jazyka C
*
*	Enum, struct...  
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

#define PLANET_COUNT 8

// vytvoreni vlastniho datoveho typu 
typedef size_t moons;
typedef double distance;

// vyctovy typ
static enum planets
{
	Mercury = 0,
	Venus,
	Earth = 2,
	Mars,
	Jupiter,
	Saturn,
	Uranus,
	Neptune,
};

static char *PlanetNames[] = {"Mercury", "Venus", "Earth", "Mars", 
	"Jupiter", "Saturn", "Uranus", "Neptune"};

//  struktura nema jmeno, ale je vytvoren datovy typ PlanetDistance, 
// coz je prave tato strukruta
typedef struct 
{
	distance FromSun;
	distance FromEarth;
} PLANET_DIST;

//  pojmenovana struktura Planet 
struct Planet
{
	char Name[20];
	PLANET_DIST distance; 
	moons moonCount;
}; 

void populatePlanets(struct Planet *ptr, int size)
{
	strcpy(ptr->Name, "Mercury");
	ptr->distance.FromEarth = 91.7;
	ptr->distance.FromSun =   58;
	ptr->moonCount = 0;	

	ptr++;
	
	strcpy(ptr->Name, "Venus");
	ptr->distance.FromEarth = 41.4;
	ptr->distance.FromSun =  108;
	ptr->moonCount = 0;	

	ptr++;

	strcpy(ptr->Name, "Earth");
	ptr->distance.FromEarth = 0;
	ptr->distance.FromSun = 149;
	ptr->moonCount = 0;	

	ptr++;

	strcpy(ptr->Name, "Mars");
	ptr->distance.FromEarth = 78.3;
	ptr->distance.FromSun   = 207;
	ptr->moonCount = 2;	
	ptr++;

	strcpy(ptr->Name, "Jupiter");
	ptr->distance.FromEarth = 390.6;
	ptr->distance.FromSun =   778;
	ptr->moonCount = 63;	

	ptr++;

	strcpy(ptr->Name, "Saturn");
	ptr->distance.FromEarth = 777;
	ptr->distance.FromSun =  1427;
	ptr->moonCount = 61;	

	ptr++;

	strcpy(ptr->Name, "Uranus");
	ptr->distance.FromEarth = 2720;
	ptr->distance.FromSun =   2860;
	ptr->moonCount = 27;	

	ptr++;

	strcpy(ptr->Name, "Neptun");
	ptr->distance.FromEarth = 4350;
	ptr->distance.FromSun =   4500; // miliony km
	ptr->moonCount = 13;
}

void initializePlanets(struct Planet planets[], int size)
{
	int i=0;

	for (i=0; i<size; i++)
	{
		planets->distance.FromEarth = 0;
		planets->distance.FromSun = 0; 
		planets->moonCount = 0;
	}

}

struct Planet getPlanet(enum planets planet, struct Planet planets[])
{
	return planets[planet];
}

void printPlanetInfo(struct Planet planet)
{
	printf("-----------------------------------------------------\n");
	printf("Name: %s.\n", planet.Name);
	printf("Distance from Sun: %.2f millions of km.\n", planet.distance.FromSun);
	printf("Distance from Earth: %.2f millions of km.\n", planet.distance.FromEarth);
	printf("Moon count: %d.\n", planet.moonCount);
	printf("-----------------------------------------------------\n");

}


int main(int argc, char *argv[])
{
	int i;
	int select = 0;
	struct Planet planets[PLANET_COUNT];
	struct Planet planet;

	initializePlanets(&planets[0], PLANET_COUNT);
	populatePlanets(&planets[0], PLANET_COUNT);

	
	for (i=0; i<PLANET_COUNT; i++)
	{
		printf("Name: %s.\n", planets[i].Name);
		printf("Distance from Sun: %.2 millions of km.\n", planets[i].distance.FromSun);
		printf("Distance from Earth: %.2 millions of km.\n", planets[i].distance.FromEarth);
		printf("Moon count: %d.\n", planets[i].moonCount);
		printf("-----------------------------------------------------\n");
		
	}
	
	//-----------------------------------------------------------------------------------------------------------------------------------
	printf("Mars distance from Sun: %.2f m of KM.\n", getPlanet(Mars, planets).distance.FromSun);

	planet = getPlanet(Mars, planets);
	printf("Mars distance from Earth: %.2f m of KM.\n", planet.distance.FromEarth);

	// vypsani jmen planet na obrazovku
	for (i=0; i<PLANET_COUNT; i++)
	{
		printf("%d - %s\n", i, PlanetNames[i]);
	}

	printf("=====================================================\n");
	printf("Vyber cislo nektere z planet: ");
	scanf("%d", &select);
	if(select >= 0 && select <= PLANET_COUNT)
	{
		switch (select)
		{
		case Mercury:
			printPlanetInfo(planets[Mercury]);
			break;
		case Venus:
			printPlanetInfo(planets[Venus]);
			break;
		case Earth:
			printPlanetInfo(planets[Earth]);
			break;
		case Mars:
			printPlanetInfo(planets[Mars]);
			break;
		case Jupiter:
			printPlanetInfo(planets[Jupiter]);
			break;
		case Saturn:
			printPlanetInfo(planets[Saturn]);
			break;
		case Uranus:
			printPlanetInfo(planets[Uranus]);
			break;
		case Neptune:
			printPlanetInfo(planets[Neptune]);
			break;
		}

		printf("Out of range... \n");
	}

	


	return 0;
}




