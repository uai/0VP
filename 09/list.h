#ifndef LIST_H
#define LIST_H


#include <stdlib.h>

typedef struct node link_t;
typedef unsigned int data_t;
typedef unsigned int uint;

struct node
{
	link_t *prior;
	link_t *next;
	data_t data;
};

int push_back(data_t data);
int erase();

uint get_size();
data_t get_data(uint n);

//void print_data();
void print_data(void (*print_data)(data_t));


// nemusime tyto fce odhalovat venkovne
//link_t* front();
//link_t* back();
//link_t* at(uint n);
//int erase_node(link_t *node);



#endif /*LIST_H*/
