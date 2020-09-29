#ifndef LISTS_H_INCLUDED
#define LISTS_H_INCLUDED

#include "structs.h"

#define POW2TO 32

void help(void);

void push(Item **ptr, int key, char *value);
void pop(Item **ptr);
void print(Item *ptr);

int key_exists(int key, Item *head);
void split_list(Item **A, Item **B, int len);
void analyze_to_binary(int lenght, int **analysis);

void merged(Item **A, Item **B, int len);
void Sort(Item **A, int len);
void mergesort(Item **head);

int length(Item *head);

#endif // LISTS_H_INCLUDED
