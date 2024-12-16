#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#include"hotels.h"

void showTestHotels()
{
    printf("Test hotel library succesful ! \n");
}

ListHotel createListHotel() {
    ListHotel list = (ListHotel)malloc(sizeof(struct ListHotel));
    if (list == NULL) {
        // Handle memory allocation failure
        return NULL;
    }
    list->H = NULL; // Initialize the head pointer to NULL
    list->T = NULL; // Initialize the tail pointer to NULL
    return list; // Return the initialized list
}

ListHotel addHotel(ListHotel list, DataHotel data) 
{
    PDHotel newHotel = (PDHotel)malloc(sizeof(DHotel)); // Allocate memory for a new hotel
    if (newHotel == NULL) 
    {
        printf("Memory allocation failed\n");
        return list; // Return the unchanged list
    }

    newHotel->data = data; // Set the data for the new hotel
    newHotel->nextL = NULL; // Initialize left pointer to NULL
    newHotel->nextR = NULL; // Initialize right pointer to NULL

    if (list->H == NULL) { // If the list is empty, set new hotel as head and tail
        list->H = newHotel; // Set the new hotel as the head
        list->T = newHotel; // Set the new hotel as the tail
    } else {
        list->T->nextR = newHotel; // Link the new hotel to the end of the list
        newHotel->nextL = list->T; // Link the new hotel back to the current tail
        list->T = newHotel; // Update the tail to the new hotel
    }
    return list; // Return the modified list
}

PDHotel searchByNameHotel(ListHotel list, const char* name) 
{
    PDHotel iterator = list->H;     // Initialize an iterator to the head of the list
    while (iterator != NULL)    // Traverse the list until the end
    {
        // Check if the name of the current hotel matches the given name
        if(strcmp(iterator->data.name , name) == 0)
            return iterator;    // Return the hotel if the name matches
        
        iterator = iterator->nextR;     // Move to the next hotel in the list
    }
    return NULL;    // Return NULL if no hotel with the given name is found
}

void showHotel(PDHotel hotel)
{
    printf("\tName : [%s]\tLocation:[%s]\n" , hotel->data.name , hotel->data.location);
    printf("\tRating :[%d]\tAvailable Room : [%d]\n" , hotel->data.rating , hotel->data.available_room);
    printf("\t\t===[%d]===\n", hotel->data.hotline);
}

// Function to delete a hotel by name 
void deleteByNameHotel(ListHotel list, const char* name) {
    PDHotel deleteNode = searchByNameHotel(list, name); // Search for the hotel by name
    if (!deleteNode) {
        printf("Hotel not found.\n"); // If not found, print a message
        return;
    }

    // If the hotel to delete is the first hotel
    if (deleteNode == list->H) {
        list->H = deleteNode->nextR; // Update head to the next hotel
        if (list->H) { // If there are other hotels
            list->H->nextL = NULL; // Update the previous pointer of the new head
        } else { // If this was the only hotel
            list->H = NULL; // Set head to NULL
        }
    }
    // If the hotel to delete is the last hotel
    else if (deleteNode == list->T) {
        list->T = deleteNode->nextL; // Update tail to the previous hotel
        if (list->T) { // If there are other hotels
            list->T->nextR = NULL; // Update the next pointer of the new tail
        }
    }
    // If the hotel is in the middle
    else {
        deleteNode->nextL->nextR = deleteNode->nextR; // Bypass the node to delete
        deleteNode->nextR->nextL = deleteNode->nextL; // Bypass the node to delete
    }

    // Free dynamically allocated memory for the deleted hotel
    free(deleteNode);
}

void showListHotel(ListHotel list) {
    if (list == NULL || list->H == NULL) {
        printf("The hotel list is empty.\n");
        return;
    }
    
    PDHotel current = list->H; // Start from the head 

    while (current != NULL) {
        printf("\nName : [%s]\tLocation :[%s]\n", current->data.name, current->data.location);
        printf("Rating : [%d] \t available rooms : [%d] \t\t hotline [%d] \n", current->data.rating, current->data.available_room, current->data.hotline);
        current = current->nextR;
    }
    printf("\t =============== \t");
}

// Function to swap data between two hotels
void swapDataHotel(ListHotel list, PDHotel a, PDHotel b) {
    DataHotel temp = a->data ; // Store data of hotel a in temp
    a->data = b->data;   // Assign data of hotel b to hotel a
    b->data = temp;      // Assign temp (original data of hotel a) to hotel b
}

// Function to partition the list for quicksort
PDHotel PartitionHotel(ListHotel list, PDHotel first, PDHotel last) {
    if (first == last) return NULL; // If the list has only one element, return NULL

    bool check_smaller = false; // Check if j < i
    bool check_equal = false;    // Check if j = i

    bool check_i = true; // Check if i is over last
    bool check_j = true; // Check if j is over first

    PDHotel i = first->nextR; // Start i from the next of first
    PDHotel j = last;         // Start j from last
    int pivot = first->data.rating; // Set pivot as the id of the first hotel

    while (!check_smaller) {
        // Iterate i index
        while ((!check_smaller && i->data.rating <= pivot) && check_i) {
            if (i == last) check_i = false; 
            else i = i->nextR; // Move i to the right
        }

        // Iterate j index
        while ((!check_smaller && j->data.rating > pivot) && check_j) {
            if (i == j) check_smaller = true; // If i and j meet, set check_smaller to true
            if (i != j && check_equal) check_smaller = true; 
            if (j == first) check_j = false; 
            else j = j->nextL; // Move j to the left
        }

        if (!check_smaller) {
            if (i == j) {
                if (!check_i) check_smaller = true; // If i has reached the end, set check_smaller to true
            } else {
                swapDataHotel(list, i, j); // Swap data between i and j
            }
        }
    }
    return j; // Return the partition index
}

// Function to perform quicksort on the list
void QuicksortHotel(ListHotel list, PDHotel first, PDHotel last) {
    if (first != last) {
        PDHotel j = PartitionHotel(list, first, last); // Find the partition index
        swapDataHotel(list, first, j); // Swap the pivot with the partition index

        if (j != NULL) {
            if (j->nextL != NULL) {
                if (j != first) QuicksortHotel(list, first, j->nextL); // Sort the left partition
            }
            if (j->nextR != NULL) {
                if (j != last) QuicksortHotel(list, j->nextR, last); // Sort the right partition
            }
        }
    } else return; // If first equals last, return
}

void freeMemoryHotel(ListHotel list)
{
    PDHotel current = list->H; // Start from the head
    PDHotel temp;

    // Free each hotel node
    while (current != NULL)
    {
        temp = current;
        current = current->nextR; // Move to the next hotel
        free(temp);               // Free the hotel node
    }

    // Free the list structure itself
    free(list);
}

void readHotelData(ListHotel list )
{
    FILE *file ;
    // rating|available_room|name|location|hotline;
    file = fopen("../Interface/hotels.txt", "r");
    char line[256];

    // Handle 
    if (file == NULL)
    {
        perror("Error opening file ");
        //return 0 ;
    }

    // Read the file line by line 
    while (fgets(line, sizeof(line) , file))
    {
        int rating, available_room, hotline;
        char *name = (char*)malloc(50 * sizeof(char));
        char *location = (char*)malloc(50 * sizeof(char));

        // Tokenize the line
        char *token;
        token = strtok(line, "|");
        rating = atoi(token); // Convert string to int

        token = strtok(NULL, "|");
        available_room = atoi(token); // Convert string to int

        token = strtok(NULL, "|");
        strncpy(name, token, 49); // Copy name safely
        name[49] = '\0'; // Ensure null termination

        token = strtok(NULL, "|");
        strncpy(location, token, 49); // Copy location safely
        location[49] = '\0'; // Ensure null termination

        token = strtok(NULL, "|");
        hotline = atoi(token); // Convert string to int
                // Remove newline characters if any at the end of name and location
        name[strcspn(name, "\n")] = '\0'; // Remove newline from name
        location[strcspn(location, "\n")] = '\0'; // Remove newline from location

        // Create and add the new hotel
        DataHotel new_hotel = {rating, available_room, name, location, hotline};
        list = addHotel(list, new_hotel);
    }
    printf("\n");
    
}

void writeHotelData(ListHotel list , DataHotel data)
{
    FILE *file ;
    file = fopen("../Interface/hotels.txt" ,"a");
    if (file == NULL)
    {
        perror("Error opening file");
    }
    
    fprintf(file ,"%d|%d|%s|%s|%d\n" , data.rating ,data.available_room , data.name , data.location , data.hotline);
    fclose(file);

}






