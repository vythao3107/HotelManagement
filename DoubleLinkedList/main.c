#include <stdio.h>
#include <stdlib.h> // Include for malloc
#include <stdbool.h>


typedef struct Data
{
    int id ;
    char*  name ;

}Data ;

typedef struct DNode {
    Data data ;
    struct DNode *nextL, *nextR;
} DNode; 

typedef DNode* PDNode;

typedef struct DoubleLinkedList{
    PDNode H; // first pointer  
    PDNode T; // last pointer 
} *DoubleLinkedList;



// Function to create an empty double linked list
DoubleLinkedList createList() {
    DoubleLinkedList list = (DoubleLinkedList)malloc(sizeof(struct DoubleLinkedList));
    if (list == NULL) {
        // Handle memory allocation failure
        return NULL;
    }
    list->H = NULL; // Initialize the head pointer to NULL
    list->T = NULL; // Initialize the tail pointer to NULL
    return list; // Return the initialized list
}

// Function to add a node to the end of the list
DoubleLinkedList addNode(DoubleLinkedList list, Data data ) 
{
    PDNode newNode = (PDNode)malloc(sizeof(DNode)); // Allocate memory for a new node
    if (newNode == NULL) 
    {
        printf("Memory allocation failed\n");
        return list; // Return the unchanged list
    }

    newNode->data = data ; // Set the data for the new node
    newNode->nextL = NULL; // Initialize left pointer to NULL
    newNode->nextR = NULL; // Initialize right pointer to NULL

    if (list->H == NULL) { // If the list is empty
        list->H = newNode; // Set the new node as the head
        list->T = newNode; // Set the new node as the tail
    } else {
        list->T->nextR = newNode; // Link the new node to the end of the list
        newNode->nextL = list->T; // Link the new node back to the current tail
        list->T = newNode; // Update the tail to the new node
    }
    return list; // Return the modified list
}

PDNode searchByName( DoubleLinkedList list , const char* name  )
{
    PDNode iterator = list->H ;
    while (iterator != NULL)
    {
        if( iterator->data.name == name )return iterator ;
        iterator = iterator->nextR;
    }
    return NULL;
}

// Function to delete a node by name 
void deleteByName(DoubleLinkedList list, const char* name) {
    PDNode deleteNode = searchByName(list, name);
    if (!deleteNode) {
        printf("Node with name '%s' not found.\n", name);
        return;
    }

    // If the node to delete is the first node
    if (deleteNode == list->H) {
        list->H = deleteNode->nextR; // Update head
        printf("The new first node : %s and %d  \n" , list->H->data.name , list->H->data.id);
        if (list->H) { // If there are other nodes
            list->H->nextL = NULL;
        } else { // If this was the only node
            list->H = NULL;
        }
    }
    // If the node to delete is the last node
    else if (deleteNode == list->T) {
        list->T = deleteNode->nextL; // Update tail
        if (list->T) { // If there are other nodes
            list->T->nextR = NULL;
        }
    }
    // If the node is in the middle
    else {
        deleteNode->nextL->nextR = deleteNode->nextR;
        deleteNode->nextR->nextL = deleteNode->nextL;
    }
    // Free dynamically allocated memory
    free(deleteNode);
}


// Function to print the list from head to tail
void printList(DoubleLinkedList list) {
    PDNode current = list->H; // Start from the head
    while (current != NULL) {
        printf("%d %s ", current->data.id , current->data.name); // Print the data
        current = current->nextR; // Move to the next node
    }
    printf("\n");
}

// Quicksort by id in descending order 
void swapData(DoubleLinkedList list , PDNode a , PDNode b)
{
    Data temp = a->data ;
    a->data = b->data  ;
    b->data = temp  ;
}

PDNode Partition(DoubleLinkedList list , PDNode first , PDNode last )
{
    printList(list);
    if ( first == last) return NULL;

    bool check_smaller = false ;    // check j < i : true 
    bool check_equal  = false  ;    // check j = i true  ;

    bool check_i = true  ;  // check over last 
    bool check_j = true  ;  // check over first 

    PDNode i = first->nextR , j = last ;
    int pivot = first->data.id ;

    while ( ! check_smaller  )
    {

        // Iterate i index 
        while( (!check_smaller && i->data.id  <= pivot ) && check_i )
        {
            if ( i == last ) check_i = false ; else i = i->nextR ;
        }

        // Iterate j index 
        while(( !check_smaller && j->data.id > pivot )  && check_j )
        {
            if ( i == j ) check_smaller = true ;
            if ( i != j && check_equal ) check_smaller = true ;
            if ( j == first ) check_j = false ; else j = j->nextL ;
        }

        if( !check_smaller )
        {
            if (i == j )
            {
                if( ! check_i  )check_smaller = true ;
            }
            else swapData(list , i , j);
        }
    }
    return j ;
}

void Quicksort( DoubleLinkedList list , PDNode first , PDNode last )
{
    if ( first != last )
    {
        PDNode j = Partition(list , first , last );     // find j index 
        swapData(list , first , j);

        if ( j != NULL ){
            if ( j ->nextL != NULL )  
            {
                if ( j != first )Quicksort(list , first , j->nextL );
            }
            if ( j ->nextR != NULL) 
            {
                if ( j != last ) Quicksort(list , j->nextR , last );
            }
        }
    }else return ;
}

