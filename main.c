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
/*          int len=0;
            int i, j;
            int *analysis;
            Item *auxlists[32];
            Item *aux;

            analysis = (int*)malloc(POW2TO*sizeof(int));

            Item *temp = head;
            while(temp != NULL)
            {
                temp = temp->next;
                len++;
            }

            analyze_to_binary(len, &analysis);

            temp = head;
            for(i=0; i<POW2TO; i++)
            {
                if(*(analysis + i*sizeof(int)) != 0)
                    {
                        printf("IN %d\n", (int)pow(2, (double)i));
                        auxlists[i] = temp;
                        for (j = 0; j < ((int)pow(2, (double)i)-1); j++)
                        {
                            temp = temp->next;                        
                        }
                        aux = temp->next;
                        temp->next=NULL;
                        temp = aux;

                        Sort(&(auxlists[i]), (int)pow(2, (double)i));                                 
                    }
                else
                {
                    auxlists[i] = NULL;
                }                
            }

            printf("DONE\n");

            i = 0;
            while(auxlists[i] == NULL)
            {
                i++;
            }

            for(j=0; j<POW2TO; j++)
            {
                if((auxlists[j] != NULL) && (j!=i))
                    merged(&auxlists[i], &auxlists[j], 0);
            }

            head = auxlists[i];
*/

        mergesort(&head);

        }
        else
            ;
    }

    return 0;
}
