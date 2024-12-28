#ifndef HOTEL_H
#define HOTEL_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct DataHotel  
{
    int rating  ;   // from 1 to 100 
    int available_room ;    // from 0 
    char* name  ;       
    char* location ;
    int hotline ;
    int total_visitors ;
} DataHotel;

typedef struct DHotel
{
    DataHotel data ;
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
ListHotel addHotel(ListHotel hotels , DataHotel data );
PDHotel searchByNameHotel(ListHotel hotels , const char* name );
void showHotel(PDHotel hotel);
void deleteByNameHotel(ListHotel hotels, const char* name);
void showListHotel(ListHotel hotels);
int getNumberHotels(ListHotel hotels);
void swapDataHotel(ListHotel hotels, PDHotel a, PDHotel b) ;
PDHotel PartitionHotel(ListHotel hotels, PDHotel first, PDHotel last) ;
void QuicksortHotel(ListHotel hotels, PDHotel first, PDHotel last) ;
void freeMemoryHotel(ListHotel hotels);
void readHotelData(ListHotel hotels);
void writeHotelData(ListHotel hotels , DataHotel data , bool endline );

#endif // HOTEL_H
