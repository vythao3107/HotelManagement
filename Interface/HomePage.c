#include<stdio.h>
#include<stdbool.h>
#include<time.h>

#include "../Objects/history.h"
#include "../Objects/hotels.h"
#include "../Objects/users.h"

#include "UserInterface.h"

bool checkAccount() ;

int main()
{
    printf("BEGIN PROGRAMING \n");
    printf("Console like this\n");

    // Initialization 
    historyManager list_history_mananger = createHistoryManager();
    ListUser user_manager = createListUser();
    ListHotel hotel_manager = createListHotel();

    // Read file txt 
    readHistoryData(list_history_mananger);
    readUserData(user_manager);
    readHotelData(hotel_manager);

    // Get interface of client 
    int system_key ;
    printf("WELCOME TO HOMEPAGE \n");
    printf("You are [User/Hotel Manager/Admin] = [0/1/2] : ");
    scanf("%d",&system_key);

    // User Interface module 
    while (system_key == 0)
    {
        system_key = userInterface(list_history_mananger , hotel_manager , user_manager);
    }

    // printf("SHOW LIST HISTORY\n");
    // showHistoryManager(list_history_mananger);

    // Free memories
    freeMemoryHistoryManager(list_history_mananger);
    freeMemoryUser(user_manager);
    freeMemoryHotel(hotel_manager);
    printf("END PROGRAMING \n");
}

