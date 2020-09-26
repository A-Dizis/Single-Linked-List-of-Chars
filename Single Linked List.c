#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>

struct item
{
    struct item *next;
    char *value;
    int key;
};

typedef struct item Item;

void help(void)
{
    printf("Help:\n"
           "e: find if, a particular key, exist\n"
           "n: push new item in list\n"
           "d: pop last it from the list\n"
           "p: print the items in the list\n"
           "q: quit\n"
           "h: this help\n\n");
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

int main()
{
    char c = 'i';

    Item* head = NULL;

    while(1)
    {
        printf("WHAT TO DO? \(help h)\n");

        c = getchar();
        getchar();

        if(c == 'n')
        {
            int key;
            char value[50];

            printf("GIVE NODE KEY(ENTER) AND VALUE(ENTER):\n");

            scanf("%d", &key);
            getchar();
            gets(value);

            push(&head, key, value);
        }
        else if(c == 'd')
            pop(&head);
        else if(c == 'p')
            print(head);
        else if(c == 'h')
            help();
        else if(c == 'e')
        {
            int key;

            printf("GIVE THE KEY:\n");
            scanf("%d", &key);
            getchar();
            printf("%d\n", key_exists(key, head));
        }
        else if(c == 'q')
            break;
        else
            ;
    }

    return 0;
}
