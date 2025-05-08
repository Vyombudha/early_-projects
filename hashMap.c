#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "list.h"
struct hashMap
{
    struct linkedList **hashTable;
    int size;
};

struct hashMap *newMap(int size)
{
    // HashMap Struct allocation
    struct hashMap* map = malloc(sizeof(struct hashMap ));
    if (map == NULL)
    {
        printf("Error In Allocating Memory for HashMap!\n");
        exit(EXIT_FAILURE);
    }

    // HashTable initialization
    struct linkedList** hashTable = malloc(sizeof(struct linkedList *) * size);
    if (hashTable == NULL)
    {
        printf("Error In Allocating Memory for HashTable of Size %d\n", size);
        exit(EXIT_FAILURE);
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            hashTable[i] = createList();
        }
    }

    map->size = size;
    map->hashTable = hashTable;

    return map;
}

int hash(const char *str,int size)
{
    unsigned long hash1 = 5381;
    int c;
    while ((c = *str++))
        hash1 = ((hash1 << 5) + hash1) + c; // hash * 33 + c
    return hash1 % size;
}

int search(struct hashMap* map,char string[])
{
    struct linkedList** hashTable  = map->hashTable; 
    int index = hash(string,map->size);
    if(searchInList(hashTable[index],string))
    {
        return index;
    }
    else
    {
        return -1;
    }
}

void insertValues(struct hashMap* map, char *string)
{
    int index = hash(string,map->size);
    struct linkedList** hashTable = map->hashTable;
    insert(&hashTable[index], string); // Auto Hanldes all collisions and inserts
}

void printTable(struct hashMap* map)
{
    struct linkedList** hashTable = map->hashTable;
    for (int i = 0; i < map->size; i++)
    {
        printList(hashTable[i],i);
        printf("\n");
    }
}

void freeTable(struct hashMap* map)
{
    struct linkedList** hashTable = map->hashTable;
    for (int i = 0; i < map->size ; i++)
    {
        freeList(&hashTable[i]);
    }
    free(hashTable);
}

void deleteValue(struct hashMap* map, char string[])
{
    struct linkedList** hashTable = map->hashTable;

    int index = search(map,string);
    if (index != -1)
    {
        deleteNode(&hashTable[index], string);
        printf("%s is in %d index of the Table and has been deleted!\n", string, index);
    }
    else
    {
        printf("%s is not in the given table!, Try again\n", string);
    }
}

