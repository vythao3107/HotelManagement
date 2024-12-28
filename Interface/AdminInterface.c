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
    printf("Enter in here or exit by -1: ");

    // get choice and handle 
    int choice ;
    scanf("%d" , &choice);
    switch (choice)
    {
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
    case -1 :
        return -1 ;
    default:
        break;
    }
    return 2 ;
}