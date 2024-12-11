#ifndef HOTEL_H
#define HOTEL_H

typedef struct Data  
{
    int rating  ;   // from 1 to 100 
    int available_room ;    // from 0 
    char* name  ;       
    char* location ;
    int hotline ;
} Data;

typedef struct DHotel
{
    Data data ;
    struct DHotel *nextL , *nextR ;
} DHotel;

typedef DHotel* PDHotel;

typedef struct ListHotel
{
    PDHotel H ;
    PDHotel T ;
}* ListHotel ;

// Function prototypes 
void showTestHotels();
ListHotel createListHotel() ;
ListHotel addHotel(ListHotel list , Data data );
PDHotel searchByName(ListHotel List , const char* name );
void deleteByName(ListHotel list, const char* name);
void showListHotel(ListHotel list);
void swapData(ListHotel list, PDHotel a, PDHotel b) ;
PDHotel Partition(ListHotel list, PDHotel first, PDHotel last) ;
void Quicksort(ListHotel list, PDHotel first, PDHotel last) ;


#endif // HOTEL_H
