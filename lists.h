#ifndef LISTS_H_INCLUDED
#define LISTS_H_INCLUDED

#include "structs.h"

void help(void);
void push(Item **ptr, int key, char *value);
void pop(Item **ptr);
void print(Item *ptr);
int key_exists(int key, Item *head);
void split_list(Item **A, Item **B, int len);

void merged(Item **A, Item **B, int len);
void Sort(Item **A, int len);

int length(Item *head);

#endif // LISTS_H_INCLUDED
