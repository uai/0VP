#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

typedef unsigned int uint;
typedef struct node link_t;
typedef void   data_t;

typedef int  (*erase_fun)(data_t*);
typedef void (*print_fun)(data_t*);

struct node
{
	link_t *prior;
	link_t *next;
	data_t *data;
};

int     push_back(data_t *data);
int     erase(erase_fun eraser);
int		erase_link(uint n, erase_fun eraser);

uint    get_size();
data_t* get_data(uint n);
link_t* get_node(uint n);

void    print_data(print_fun print);



#endif /*LIST_H*/
