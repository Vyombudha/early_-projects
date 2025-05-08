#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Node
{
    char string[256];
    struct Node *next;
};

struct linkedList
{
    struct Node *head;
    struct Node *finalNode;
};

struct Node *createNode(char string[])
{
    struct Node *newNode = malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Error in allocating Memory for node with string %s\n", string);
        exit(EXIT_FAILURE);
    }

    strcpy(newNode->string, string);
    newNode->next = NULL;
    return newNode;
}

void insert(struct linkedList **list, char string[])
{
    struct Node *node = createNode(string);
    if (node == NULL)
    {
        printf("Error in memory allocation for Node!\n");
        exit(EXIT_FAILURE);
    }

    if ((*list)->head == NULL)
    {
        (*list)->head = node;
        (*list)->finalNode = node;
    }
    else
    {
        (*list)->finalNode->next = node;
        (*list)->finalNode = node;
    }
}

void printList(struct linkedList *list, int index)
{
    struct Node *temp = list->head;
    if (temp == NULL)
    {
        printf("Index: %d, string: <empty> ", index);
        return;
    }

    if (temp == list->finalNode)
    {
        printf("Index: %d, string: %s.", index, temp->string);
        return;
    }

    printf("Index: %d, strings: ", index);
    while (temp != NULL)
    {
        if (temp == list->finalNode)
        {
            printf("%s.", temp->string);
        }
        else
        {
            printf("%s, ", temp->string);
        }
        temp = temp->next;
    }
}

struct linkedList *createList()
{
    struct linkedList *list = malloc(sizeof(struct linkedList));
    if (list == NULL)
    {
        printf("Error in memory allocation for Linked List!\n");
        exit(EXIT_FAILURE);
    }
    list->head = NULL;
    list->finalNode = NULL;
    return list;
}

void freeList(struct linkedList **list)
{
    struct Node *temp = (*list)->head, *currentNode;
    while (temp != NULL)
    {
        currentNode = temp;
        temp = temp->next;
        free(currentNode);
    }
    free(*list);
    *list = NULL;
}

bool searchInList(struct linkedList *list, char *string)
{
    struct Node *temp = list->head;
    while (temp != NULL)
    {
        if (strcmp(temp->string, string) == 0)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void deleteNode(struct linkedList **list, char *string)
{
    struct Node *temp = (*list)->head, *prev = NULL;

    if (temp == NULL) // if List is empty
    {
        printf("\nThe List is empty!\nTry again with a non empty List\n");
        return;
    }

    if (strcmp(temp->string, string) == 0) //  if head node is the node to be deleted
    {
        if ((*list)->finalNode == (*list)->head)  //  if it is single Node List
        {
            free(temp);
            (*list)->finalNode = NULL;
            (*list)->head = NULL;
        }
        else 
        {
            (*list)->head = (*list)->head->next;
            free(temp);
        }
        return;
    }

    while (temp != NULL)
    {
        if (strcmp(temp->string, string) == 0)
        {
            printf("\n%s was found in the List and has benn deleted!\n", string);
            if (temp == (*list)->finalNode)
            {
                prev->next = NULL;
                (*list)->finalNode = prev;
            }
            else
            {
                prev->next = temp->next;
            }
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    printf("\n%s was not found in the List!\n", string);
}
