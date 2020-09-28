#ifndef LISTS_H_INCLUDED
#define LISTS_H_INCLUDED

#include "structs.h"

void push(Item **ptr, int key, char *value);
void pop(Item **ptr);
void print(Item *ptr);
int key_exists(int key, Item *head);

void Sort(Item **head, Item **A, Item **B, int len)

int length(Item *head);

#endif // LISTS_H_INCLUDED
