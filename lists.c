#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>

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
            printf("String lenght:%d\n", (int)len);
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
            printf("String lenght:%d\n", (int)len);
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

void analyze_to_binary(int length, int **analysis)
{
    int i=0;
    int remainder=length;

    for(i=0; i<POW2TO; i++)
    {
        *(*analysis + i*sizeof(int)) = remainder%2;
        remainder = remainder/2;
    }
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
    {   
        if((*A) == NULL)
        {
                (*A) = (*B);
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

    if(j > 1)
    {
        Sort(A, j);
        Sort(&half, j);
    }

    merged(A, &half, len);
}


void mergesort(Item **head)
{
    int len = 0;
    int i, j;
    int *analysis;
    Item *auxlists[POW2TO];
    Item *aux;

    analysis = (int *)malloc(POW2TO * sizeof(int));

    Item *temp = *head;

    while (temp != NULL)
    {
        temp = temp->next;
        len++;
    }

    analyze_to_binary(len, &analysis);

    temp = *head;
    for (i = 0; i < POW2TO; i++)
    {
        if (*(analysis + i * sizeof(int)) != 0)
        {
            printf("IN %d\n", (int)pow(2, (double)i));
            auxlists[i] = temp;
            for (j = 0; j < ((int)pow(2, (double)i) - 1); j++)
            {
                temp = temp->next;
            }
            aux = temp->next;
            temp->next = NULL;
            temp = aux;

            Sort(&(auxlists[i]), (int)pow(2, (double)i));
        }
        else
        {
            auxlists[i] = NULL;
        }
    }

    i = 0;
    while (auxlists[i] == NULL)
    {
        i++;
    }

    for (j = 0; j < POW2TO; j++)
    {
        if ((auxlists[j] != NULL) && (j != i))
            merged(&auxlists[i], &auxlists[j], 0);
    }

    *head = auxlists[i];
}
