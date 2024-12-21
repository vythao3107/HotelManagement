#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#include"users.h"

void showTestUser()
{
    printf("Test user libraries successfully \n");
}

ListUser createListUser()
{
    ListUser list = (ListUser)malloc(sizeof(struct ListUser));
    if (list == NULL)
    {
        // Handle memory allocation failure
        return NULL;
    }
    list->H = NULL; // Initialize the head pointer to NULL
    list->T = NULL; // Initialize the tail pointer to NULL
    return list;    // Return the initialized list
}

ListUser addUser(ListUser list, DataUser data)
{
    PDUser newHotel = (PDUser)malloc(sizeof(DUser)); // Allocate memory for a new hotel
    if (newHotel == NULL)
    {
        printf("Memory allocation failed\n");
        return list; // Return the unchanged list
    }

    newHotel->data = data;  // Set the data for the new hotel
    newHotel->nextL = NULL; // Initialize left pointer to NULL
    newHotel->nextR = NULL; // Initialize right pointer to NULL

    if (list->H == NULL)
    {                       // If the list is empty
        list->H = newHotel; // Set the new hotel as the head
        list->T = newHotel; // Set the new hotel as the tail
    }
    else
    {
        list->T->nextR = newHotel; // Link the new hotel to the end of the list
        newHotel->nextL = list->T; // Link the new hotel back to the current tail
        list->T = newHotel;        // Update the tail to the new hotel
    }
    return list; // Return the modified list
}

PDUser searchByID(ListUser list, int id )
{
    PDUser iterator = list->H; // Initialize an iterator to the head of the list
    while (iterator != NULL)    // Traverse the list until the end
    {
        // Check if the name of the current hotel matches the given name
        if (iterator->data.id == id )
            return iterator; // Return the hotel if the name matches

        iterator = iterator->nextR; // Move to the next hotel in the list
    }
    return NULL; // Return NULL if no hotel with the given name is found
}

// Function to delete a hotel by name
void deleteByID(ListUser list, int id)
{
    PDUser deleteNode = searchByID(list, id); // Search for the hotel by name
    if (!deleteNode)
    {
        printf("User with name '%d' not found.\n", id); // If not found, print a message
        return;
    }

    // If the hotel to delete is the first hotel
    if (deleteNode == list->H)
    {
        list->H = deleteNode->nextR; // Update head to the next hotel
        if (list->H)
        {                          // If there are other hotels
            list->H->nextL = NULL; // Update the previous pointer of the new head
        }
        else
        {                   // If this was the only hotel
            list->H = NULL; // Set head to NULL
        }
    }
    // If the hotel to delete is the last hotel
    else if (deleteNode == list->T)
    {
        list->T = deleteNode->nextL; // Update tail to the previous hotel
        if (list->T)
        {                          // If there are other hotels
            list->T->nextR = NULL; // Update the next pointer of the new tail
        }
    }
    // If the hotel is in the middle
    else
    {
        deleteNode->nextL->nextR = deleteNode->nextR; // Bypass the node to delete
        deleteNode->nextR->nextL = deleteNode->nextL; // Bypass the node to delete
    }

    // Free dynamically allocated memory for the deleted hotel
    free(deleteNode);
}

void showListUser(ListUser list)
{
    PDUser current = list->H; // Start from the head

    while (current != NULL)
    {
        printf("Name : [%s] \t Identifier: [%d] \n", current->data.name, current->data.id);
        current = current->nextR;
    }
    printf("\t =============== \t");
}

void freeMemoryUser(ListUser list)
{
    PDUser current = list->H; // Start from the head
    PDUser temp;

    // Free each user node
    while (current != NULL)
    {
        temp = current;
        current = current->nextR; // Move to the next user
        free(temp);               // Free the user node
    }

    // Free the list structure itself
    free(list);
}

void readUserData(ListUser list)
{
    FILE *file;
    // id|name
    file = fopen("../Interface/users.txt", "r");
    char line[256];

    // Handle
    if (file == NULL)
    {
        perror("Error opening file ");
        // return 0 ;
    }

    // Read the file line by line
    while (fgets(line, sizeof(line), file))
    if(strlen(line) != 0){
        int id ;
        char *name = (char *)malloc(50 * sizeof(char));

        // Tokenize the line
        char *token;
        token = strtok(line, "|");
        id = atoi(token); // Convert string to int

        token = strtok(NULL, "|");
        strncpy(name, token, 49); // Copy name safely
        name[49] = '\0';          // Ensure null termination

        name[strcspn(name, "\n")] = '\0';         // Remove newline from name

        // Create and add the new user
        DataUser new_user = {id , name};
        list = addUser(list, new_user);
        //showListUser(list);
    }
    fclose(file);
    printf("\n");
}

void writeUserData( DataUser data)
{
    FILE *file;
    file = fopen("../Interface/users.txt", "a");
    if (file == NULL)
    {
        perror("Error opening file");
    }

    fprintf(file, "\n%d|%s", data.id, data.name);
    fclose(file);
}
