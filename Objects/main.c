#include <stdio.h>

#include "hotels.h"


// Test hotel functions
int main()
{
    // Create the list of hotels
    ListHotel list = createListHotel();

    // Define some test data for hotels
    Data hotel1 = {90, 10, "Hotel Paradise", "New York", 123456789};
    Data hotel2 = {75, 5, "Hotel Elegance", "Los Angeles", 987654321};
    Data hotel3 = {85, 8, "Hotel Tranquility", "Chicago", 456789123};

    // Add hotels to the list
    list = addHotel(list, hotel1);
    list = addHotel(list, hotel2);
    list = addHotel(list, hotel3);

    // Display the list of hotels
    printf("List of Hotels after adding:\n");
    showListHotel(list);

    // Search for a hotel by name

    const char *searchName = "Hotel Elegance";
    PDHotel foundHotel = searchByName(list, searchName);
    if (foundHotel)
    {
        printf("Hotel found: %s, Location: %s, Rating: %d, Rooms: %d, Hotline: %d\n",
               foundHotel->data.name, foundHotel->data.location,
               foundHotel->data.rating, foundHotel->data.available_room,
               foundHotel->data.hotline);
    }
    else
    {
        printf("Hotel with name '%s' not found.\n", searchName);
    }

    // Sort the list by rating using QuickSort
    Quicksort(list, list->H, list->T);
    printf("List of Hotels after sorting by rating:\n");
    showListHotel(list);

    // Delete a hotel by name
    const char *deleteName = "Hotel Tranquility";
    deleteByName(list, deleteName);
    printf("List of Hotels after deleting '%s':\n", deleteName);
    showListHotel(list);

    return 0;
}
