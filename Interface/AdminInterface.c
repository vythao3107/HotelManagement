#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

// #include "../Objects/history.h"
// #include "../Objects/hotels.h"
// #include "../Objects/users.h"
#include "AdminInterface.h"

int adminInterface(historyManager manager, ListHotel hotels, ListUser users)
{
    // Display menu 
    printf("WELCOME TO ADMIN INTERFACE \n");
    printf("1. View all hotels \n");
    printf("2. View all users \n");
    printf("3. View all history \n");
    printf("4. View hotels by rating \n" );
    printf("5. Search user by id \n");
    printf("6. Remove user by id \n");
    printf("7. Search hotel by name \n");
    printf("8. Remove hotel by name \n");
    printf("9. Display user history by id and sort by date \n");
    printf("Enter in here or exit by -1: ");

    // get choice and handle 
    int choice ;
    int id_user ;
    char* hotel_name = (char*)malloc(50 *sizeof(char));
    PDHotel my_hotel ;
    ListHistory my_history ;

    scanf("%d" , &choice);
    switch (choice)
    {
    case -1:
        free(hotel_name);
        return -1;
    case 1:
        printf("Total number of hotels  is %d.", getNumberHotels(hotels));
        showListHotel(hotels);
        break;
    case 2 :
        printf("Total number of users  is %d." , getNumberUsers(users));
        showListUser(users);
        break ;
    case 3 : 
        showHistoryManager(manager);
        break;
    case 4 :
        QuicksortHotel(hotels , hotels->H , hotels->T);
        printf("After Quick sort by rating :\n");
        showListHotel(hotels);
        break;
    case 5 :
        printf("Enter id user to search : ");
        scanf("%d" , &id_user);
        PDUser my_user = searchByID(users , id_user);

        // Display name and history 
        printf("\n ========================== \n");
        printf("User name : %s \n" , my_user->data.name);
        printf("User history : \n");
        ListHistory user_history = searchByIDHistory(manager , id_user);
        showListHistory(user_history);
        break;
    case 6:
        printf("Enter id user to remove : ");
        scanf("%d", &id_user);

        // Remove and free memory 
        deleteByID(users , id_user);
        deleteByIDHistory( manager , id_user );
        printf("User %d has been removed \n" , id_user);
        break;
    case 7:
        printf("Enter name hotel to search : ");
        scanf("%s" , hotel_name);
        my_hotel = searchByNameHotel(hotels , hotel_name);
        showHotel(my_hotel);
        break;
    case 8 :
        printf("Enter name hotel to remove : ");
        scanf("%s", hotel_name);
        my_hotel = searchByNameHotel(hotels, hotel_name);
        deleteByNameHotel(hotels , my_hotel->data.name);
        break;

    case 9 :
        printf("Enter id user to display history and sort by date \n");
        scanf("%d" , &id_user);

        my_history = searchByIDHistory(manager , id_user);

        QuicksortByDate(my_history , my_history->H , my_history->T);
        showListHistory(my_history);
        break;
    default:
        break;
    }
    return 2 ;
}