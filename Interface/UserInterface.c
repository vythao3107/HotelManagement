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

    printf("Do you want to search by Hotel Location [Y/N] = [1/0]?\n");

    int confirm_search_by_location;
    printf("Enter in here: ");
    scanf("%d", &confirm_search_by_location);

    // If user choose option 1 , display more information about the hotel .
    // Then , check whether they want to book or not .
    if (confirm_search_by_location == 1)
    {
        //printf("Your choose : %d \n", confirm_search_by_location );
        char *name_hotel = (char*)malloc(50* sizeof(char));
        printf("Enter hotel's name in here : ");
        scanf("%s", name_hotel);

        PDHotel hotel = searchByNameHotel(hotels, name_hotel);

        printf("Show detail hotel's information :\n");
        if ( hotel != NULL ) showHotel( hotel ) ; 
        else 
        { 
            printf("Hotel not found !\n");
            free(name_hotel);
            return 0 ;
        }

        // Check whether the user wants to book or not.
        printf("Do you prefer this hotel ? \n");
        printf("And do you book this hotel ? [Y/N] = [1/0]\n");

        int check_book_user ;
        printf("Please enter your decision: ");
        scanf("%d", &check_book_user);

        if ( check_book_user == 1)
        {
            printf("Welcome to %s hotel \n" , hotel->data.name);
        }
        free(name_hotel);
        //return 1 ;
    } else return 0 ;
    return 1;
}
