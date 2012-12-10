#include "list.h"
#include "stdio.h"

link_t *pFirst  = NULL; 
link_t *pLast   = NULL; 
link_t *pActual = NULL; 

uint size = 0;

void next()
{
	pActual = pActual->next;
}

// vraci ukazatel na prvni node
link_t* front()
{
	return pFirst;
}

// vraci ukazatel na posledni node
link_t* back()
{
	return pLast;
}

// vvraci ukazatel na node v pozici v seznamu dle parametru 
link_t* at(uint n)
{
	uint i;

	pActual = front(); // jsme na prvnim node
	for(i=1; i<n; i++)
	{
		next();
	}

	return pActual;
}

// pridani itemu dna konec seznamu 
int push_back(data_t data)
{
	link_t *pNew;
	pNew = (link_t *) malloc(sizeof(link_t));

	if (pNew == NULL){
		printf("Cannot allocate link item. \n");
		return 0;
	}

	// pokud je posledni node NULL (tj. pridavame prvni node)
	// nemuzeme do nej ukladat

	if(pFirst == NULL)
	{
		pFirst = pNew;
	}
	
	if(pLast) 
		pLast->next = pNew;

	pNew->prior = pLast;
	pNew->next  = NULL;
	pNew->data  = data;

	// zvysime velikost o 1
	size++;
	// nastavime novy node jako posledni pridany a ze je zaroven i aktualni prvek 
	pLast = pActual = pNew;

	return 1;
}

// smazani pouze jednoho node ze seznamu
int erase_node(link_t *node)
{
	link_t *tmp;
		
	// pokud je node NULL nemuzeme jej smazat
	if (!node)
		return 0;

	// pred samotnym smazanim node musime 
	// upravit ukazatele na dalsi node, jako je predchozi a nasledujici
	if (node->prior != NULL)
	{
		// pokud je pred nasim uzel jeste jeden uzel 
		// a zaroven po nasem uzlu k smazani dalsi uzel
		// musime zajistit uvolneni naseho uzlu a napojeni techto dvou uzlu
		if(node->next != NULL)
		{
			node->prior->next = node->next;
			node->next->prior = node->prior;
			tmp = node->next;
		}
		else
		{
			// pokud neni po nasem uzlu jiz dalsi uzel
			node->prior->next = NULL;
			pLast = tmp = node->prior;
		}
	}
	else
	{
		// pred nasim uzlem neni jiz uzel
		// ale jeste nas uzel muze ukazovat na dalsi uzel 
		// proto v tomto nasledujicim uzlu 
		// musime nastavit ze je prior jiz NULL
		if (node->next != NULL)
		{
			node->next->prior = NULL;
			pFirst = tmp = node->next;
		} 
		else // pokud se jedna o posledni uzel
			tmp = NULL;
	}

	free(node);
	node = NULL;
	size--;

	// jako aktualni node je nastaven tmp 
	pActual = tmp;

	return 1;
}

// smazani vsech node ze seznamu
int erase()
{
	pActual = pFirst;

	while(size)
	{
		erase_node(pActual);
	}
	
	return 1;
}

// vraci velikost seznamu
uint get_size()
{
	return size;
}

// vraci data z daneho uzlu v poradi dle n ze seznamu
data_t get_data(uint n)
{
	if(n>=0 && n<size)
	{
		at(n);

		return pActual->data;
	}
	return 0;
}

// !!!HELPER tvytiskneme si data
//void print_data()
void print_data(void (*print)(data_t))
{
	uint i  = 0;

	pActual = pFirst;
	for (i=0; i<size; i++)
	{
		//printf("list[%d] = %d \n", i, pActual->data);
		printf("List item [%d] = ", i);
		print(pActual->data);

		next();
	}
}


