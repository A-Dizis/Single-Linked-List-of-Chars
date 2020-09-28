#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>

#include "lists.h"

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

void merge(Item **A, Item **B, int len)
{
    int i;
    Item *temp = (Item*)malloc(sizeof(Item));

    temp = *B;
    temp->next = (*B)->next;
    temp->key = (*B)->key;
    temp->value = (char*)malloc(sizeof(char)* (strlen((*B)->value) + 1) );
    strcpy(temp->value, (*B)->value);

    while(i<len)
    {
        if((*A)->key > (*B)->key)
        {

            temp->next = *A;
            *A = temp;



            (*B)->key = (*B)->next->key;
            free((*B)->value);
            (*B)->value = (char*)malloc(sizeof(char)* (strlen((*B)->next->value) + 1) );
            strcpy((*B)->value, (*B)->next->value);
            (*B)->next = (*B)->next->next;
            (*B) = (*B)->next;

            temp = *B;
            temp->next = (*B)->next;
            temp->key = (*B)->key;
            temp->value = (char*)malloc(sizeof(char)* (strlen((*B)->value) + 1) );
            strcpy(temp->value, (*B)->value);

        }

    }
    free(temp);
}

void Sort(Item **head, Item **A, Item **B, int len)
{
    int i = 0;
    int j = (len/2);

    if((len%2) != 1)
    {
        Item *half = (Item*)malloc(sizeof(Item));

        half = *A;
        for(i=0; i<j, i++)
            half = half->next;

        Sort(A, &half, j)


        half = *B;
        for(i=0; i<j, i++)
            half = half->next;

        Sort(B, &half,j);
    }

    merge(A, B, len);

}
