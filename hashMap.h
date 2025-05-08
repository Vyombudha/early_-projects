#ifndef HASHMAP_H
#define HASHMAP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "list.h"



// Struct hashMap has the LinkedList pointer Array and the Size of the Array/Map
struct hashMap
{
    struct linkedList **hashTable;
    int size;
};

struct hashMap *newMap(int size);

int hash(const char *str,int size);

int search(struct hashMap* map,char string[]);

void insertValues(struct hashMap* map, char *string);


void printTable(struct hashMap* map);


void freeTable(struct hashMap* map);


void deleteValue(struct hashMap* map, char string[]);




#endif

