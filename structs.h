#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED

struct item
{
    struct item *next;
    char *value;
    int key;
};

typedef struct item Item;


#endif // STRUCTS_H_INCLUDED
