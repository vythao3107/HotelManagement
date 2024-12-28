#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#include "../Objects/history.h"
#include "../Objects/hotels.h"
#include "../Objects/users.h"
#include "HotelInterface.h"

int hotelInterface(historyManager manager, ListHotel hotels, ListUser users)
{
    printf("WELCOME TO HOTEL INTERFACE \n");
    printf("Enter [1 ,2, 3] = [Update , Append , Exit ] : ");
    int choice;
    scanf("%d", &choice);
    DataHotel my_hotel ;

    switch (choice)
    {
    case 1 :
        // Get information about the hotel
        my_hotel = getInfoHotel();

        // Update information about the hotel
        updateHotelData(hotels, my_hotel);
        break;
    case 2 :
        // Get information about the hotel
        my_hotel = getInfoHotel();

        // Append information about the hotel
        saveHotelInfo(hotels , my_hotel );
        break;
    case 3 :
        return -1 ;
    default:
        break;
    }
    printf("GOODBYE HOTEL INTERFACE \n");

    return 1 ;
}

DataHotel getInfoHotel()
{
    int available_room , hotline , rating  ;
    char* name = (char*) malloc(50 * sizeof(char));
    char* location = (char*) malloc(50 * sizeof(char));

    printf("Enter information about your hotel : \n");
    printf("[Name] -> [Hotline] -> [Location] -> [Available Room] \n");
    scanf("%s" , name);
    scanf("%d" , &hotline);
    scanf("%s" , location);
    scanf("%d" , &available_room);
    
    DataHotel my_hotel = {0, available_room , name , location , hotline , 0};
    return my_hotel;
}

void saveHotelInfo( ListHotel hotels , DataHotel hotel)
{
    writeHotelData(hotels , hotel , true );
    addHotel(hotels , hotel );
    printf("\nSAVE THE HOTEL SUCCESSFULLY\n");
}

void updateHotelData(ListHotel hotels , DataHotel hotel)
{
    // update in doubly linked list 
    PDHotel new_data = searchByNameHotel(hotels , hotel.name);
    new_data->data = hotel ;

    PDHotel current = hotels->H; // Start from the head
    // empty file txt 
    FILE *file  ;
    file = fopen("hotels.txt" , "w");

    // Update file hotels.txt
    DataHotel data = current->data;
    fprintf(file, "%d|%d|%s|%s|%d|%d", data.rating, data.available_room, data.name, data.location, data.hotline, data.total_visitors);
    fclose(file);

    current = current->nextR ;
    while (current != NULL)
    {
        writeHotelData(hotels , current->data , true );
        current = current->nextR;
    }
}