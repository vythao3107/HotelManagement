#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../Objects/history.h"
#include "../Objects/hotels.h"
#include "../Objects/users.h"

void showHotel(PDHotel hotel);

int userInterface(historyManager manager, ListHotel hotels, ListUser users)
{
    printf("WELCOME TO USERINTERFACE \n");
    printf("CHECK LIST HOTEL \n");
    showListHotel(hotels);
    printf("size of first hotel's name %zu \n" , sizeof(hotels->H->data.name));

    printf("Do you want to search by Hotel Location ( enter 1 ) ?\n");

    int confirm_search_by_location;
    printf("Enter in here: ");
    scanf("%d", &confirm_search_by_location);

    // If user choose option 1 , display more information about the hotel .
    // Then , check whether they want to book or not .
    if (confirm_search_by_location == 1)
    {

        //printf("Your choose : %d \n", confirm_search_by_location );
        char *name_hotel = (char*)malloc(20* sizeof(char));
        printf("Enter hotel's name in here : ");
        scanf("%s", name_hotel);
        printf("You choose hotel : %s \n", name_hotel);
        printf("Size of name hotel %zu \n" , sizeof(name_hotel));

        PDHotel hotel = searchByNameHotel(hotels, "MountainLodge");

        printf("Show detail hotel's information :\n");
        if ( hotel != NULL ) showHotel( hotel ) ; else return 0 ;

        // Check whether the user wants to book or not.
        printf("Do you prefer this hotel ? \n");
        printf("And do you book this hotel ? \n");
        printf("1 for Yes \n" );
        printf("0 for No \n");

        int check_book_user ;
        printf("Please enter your decision: ");
        scanf("%d", &check_book_user);

        if ( check_book_user == 1)
        {
            printf("Welcome to %s hotel \n" , hotel->data.name);
        }

        //return 1 ;
    } else return 0 ;
    return 1;
}

void showHotel(PDHotel hotel)
{
    printf("Hotel's name : %s \t location : %s \n" , hotel->data.name , hotel->data.location);
    printf("Rating : %d \t Available room : %d \n " , hotel->data.rating , hotel->data.available_room);
    printf("=== Hoteline : %d === \n" , hotel->data.hotline );
}