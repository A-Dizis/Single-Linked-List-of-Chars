#include "lists.h"

#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>

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
