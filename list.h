#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* The Node will be each index of the LinkedList consisting of Node which Stores a string of size 256 characters and then 
   the pointer to the next Node */

struct Node
{
    char string[256];
    struct Node *next;
};

/* The linkedList is the struct where we will keep track of head and tail nodes to make Passing a specific List into functions more easy
   and insertions very efficient at O(1) aka Constant Time */

struct linkedList
{
    struct Node *head;
    struct Node *finalNode;
};


/* These are the Create Node Functions */
struct Node* createNode(char string[]);
struct linkedList* createList();


/* These are the List Modifying/Printing Functions */
void insert(struct linkedList** list,char string[]);
void freeList(struct linkedList** list);
void printList(struct linkedList* list,int index);
int searchInList(struct linkedList* list, char *string);
void deleteNode(struct linkedList** list,char *string);


#endif // LIST_H