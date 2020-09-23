#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

struct item
{
    struct item *next;
    char *value;
};

typedef struct item Item;

void help(void)
{
    printf("Help:\n"
           "e: exit program\n"
           "n: push new item in list\n"
           "d: pop last it from the list\n"
           "p: print the items in the list\n"
           "h: this help\n\n");
}

void push(Item **ptr)
{
    char n[50];
    size_t len = 0;
    Item *temp = NULL;
    char *tempc = NULL;

    if( (*ptr) == NULL )
    {
        (*ptr) = (Item*)(malloc(sizeof(Item)));
        (*ptr)->next = NULL;

        scanf("%s", n);
        getchar();

        len = strlen(n);

        printf("lenght:%d\n\n", (int)len);

        tempc = (*ptr)->value;
        tempc = (char *)malloc(sizeof(char) * (len + 1));

        strcpy(tempc, n);

        (*ptr)->value = tempc;
    }

    else
    {
        temp = (Item*)(malloc(sizeof(Item)));
        temp->next = *ptr;

        scanf("%s", n);
        getchar();

        len = strlen(n);

        printf("lenght:%d\n\n", (int)len);

        tempc = (char *)malloc(sizeof(char) * (len + 1));

        strcpy(tempc, n);

        temp->value = tempc;
        (*ptr) = temp;
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
        puts(temp->value);

        temp = temp->next;
    }

    free(temp);
}

int main()
{
    char c = 'i';

    Item* head = NULL;



    while(1)
    {
         printf("WHAT TO DO? \(help h)\n\n");

        c = getchar();
        getchar();

        if(c == 'n')
            push(&head);

        else if(c == 'd')
            pop(&head);

        else if(c == 'p')
            print(head);

        else if(c == 'h')
            help();

        else if(c == 'e')
            break;

        else
            ;
    }

    return 0;
}
