#include<stdio.h>
#include<stdbool.h>

#include "../Objects/history.h"
#include "../Objects/hotels.h"
#include "../Objects/users.h"

#include "UserInterface.h"

bool checkAccount() ;

int main()
{
    printf("BEGIN PROGRAMING \n");

    // Initialization 
    historyManager list_history_mananger = createHistoryManager();
    ListUser user_manager = createListUser();
    ListHotel hotel_manager = createListHotel();

    // Read file txt 
    readHistoryData(list_history_mananger);
    readUserData(user_manager);
    readHotelData(hotel_manager);

    // showListHotel(hotel_manager);
    // printf("\nSearching function : \n");
    // printf("%d\n" , searchByNameHotel(hotel_manager, "hotel_3")->data.available_room);

    // User Interface module 
    int system_key = 1 ;

    while (system_key == 1)
    {
        system_key = userInterface(list_history_mananger , hotel_manager , user_manager);
    }

    // Free memories
    freeMemoryHistoryManager(list_history_mananger);
    freeMemoryUser(user_manager);
    freeMemoryHotel(hotel_manager);
    printf("END PROGRAMING \n");
}

