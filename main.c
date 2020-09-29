#include "lists.h"

#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>
#include <math.h>




int main()
{
    char c = 'i';

    Item* head = NULL;

    while(1)
    {
        printf("WHAT TO DO? (help h)\n");

        c = getchar();
        getchar();

        if(c == 'n')
        {
            int key;
            char value[50];

            printf("GIVE NODE KEY(ENTER) AND VALUE(ENTER):\n");

            scanf("%d", &key);
            getchar();
            fgets(value, 50, stdin);

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
        else if(c == 's')
        {
            mergesort(&head);
        }
        else
            ;
    }

    return 0;
}
