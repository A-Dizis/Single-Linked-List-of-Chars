#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>

#include "lists.h"



void help(void)
{
    printf(
        "Help:\n"
        "e: find if, a particular key, exist\n"
        "n: push new item in list\n"
        "d: pop last it from the list\n"
        "p: print the items in the list\n"
        "s: sort he list based on key\n"
        "q: quit\n"
        "h: this help\n\n"
        );
}


void push(Item **ptr, int key, char *value)
{
    size_t len = 0;
    Item *tempstruct = NULL;
    char *tempvalue = NULL;
    int tempkey = 0;

    if(value == NULL)
    {
        printf("Dummy entrance not allowed\n");
    }
    else
    {
        if( (*ptr) == NULL )
        {
            (*ptr) = (Item*)(malloc(sizeof(Item)));
            (*ptr)->next = NULL;

            len = strlen(value);
            printf("value lenght:%d\n", (int)len);
            tempvalue = (char *)malloc(sizeof(char) * (len + 1));
            strcpy(tempvalue, value);

            tempkey = key;

            (*ptr)->value = tempvalue;
            (*ptr)->key = tempkey;
        }

        else
        {
            tempstruct = (Item*)(malloc(sizeof(Item)));
            tempstruct->next = *ptr;

            len = strlen(value);
            printf("value lenght:%d\n", (int)len);
            tempvalue = (char *)malloc(sizeof(char) * (len + 1));
            strcpy(tempvalue, value);
            tempstruct->value = tempvalue;

            tempkey = key;
            tempstruct->key = tempkey;

            (*ptr) = tempstruct;
        }
    }
}

void pop(Item **ptr)
{
    Item *temp;

    if(*ptr == NULL)
    {
        ;
    }
    else if((*ptr)->next == NULL)
    {
        free((*ptr)->value);
        free(*ptr);

        *ptr = NULL;
    }
    else
    {
        temp = (Item*)(malloc(sizeof(Item)));
        temp->next = (*ptr)->next->next;

        temp->key = (*ptr)->next->key;
        temp->value = (char*)malloc(sizeof(char) * (strlen((*ptr)->next->value) + 1));
        strcpy(temp->value, (*ptr)->next->value);

        free((*ptr)->value);
        free(*ptr);

        (*ptr) = temp;
    }
}

void print(Item *ptr)
{
    Item *temp;
    temp = (Item*)(malloc(sizeof(Item)));
    temp = ptr;

    while(temp != NULL)
    {
        printf("KEY:");
        printf("%15.0d    ", temp->key);
        printf("VALUE:");
        puts(temp->value);

        temp = temp->next;
    }

    free(temp);
}

int key_exists(int key, Item *head)
{
    Item *temp;
    temp = head;

    while(temp != NULL)
    {
        if(temp->key == key)
            return 1;

        temp = temp->next;
    }
    return 0;
}

int length(Item *head)
{
    int i = 0;
    Item *temp = head;

    while(temp != NULL)
    {
        i++;
        temp = temp->next;
    }
    return i;
}
void split_list(Item **A, Item **B, int len)
{
    Item *temp = *A;
    for(int i=0; i<((len/2)-1); i++)
        temp = temp->next;
    *B = temp->next;
    temp->next = NULL;
}

void merged(Item **A, Item **B, int len)
{
    Item *temp, *aux, *head;

    temp = *B;
    if((*A) == NULL || (*B) == NULL)
        printf("Empty List!\n");
    else if((*A)->next == NULL || (*B)->next == NULL)
    {
        if((*A)->key > (*B)->key)
        {
            (*B)->next = (*A);
            (*A)->next = NULL;
            (*A) = (*B);
        }
        else
        {
            (*A)->next = (*B);
            (*B)->next = NULL;
        }
    }
    else
    {
        if((*A)->key > (*B)->key)
        {
            head = (*B);
            (*B) = (*B)->next;
            head->next = NULL;
        }
        else
        {
            head = (*A);
            (*A) = (*A)->next;
            head->next = NULL;
        }

        aux = head;

        while(((*A) != NULL) && ((*B)!= NULL))
        {
            if((*A)->key > (*B)->key)
            {
                aux->next = (*B);
                *B = (*B)->next;
                aux->next->next = NULL;
            }
            else
            {
                aux->next = *A;
                *A = (*A)->next;
                aux->next->next = NULL;
            }
            aux = aux->next;
        }

        if((*A) == NULL)
        {
            aux->next = *B;
            *A = head;
        }
        else
        {
            aux->next = *A;
            *A = head;
        }
    }
}
void Sort(Item **A, int len)
{
    int j = (len/2);
    Item *half;
    half = NULL;

    split_list(A, &half, len);

    if(j > 0)
    {
        Sort(A, j);
        printf("Sort %d !\n", len);
        Sort(&half, j);
        printf("Sort %d !\n", len);
    }

    merged(A, &half, len);
    printf("Merge %d !\n", len);
}
