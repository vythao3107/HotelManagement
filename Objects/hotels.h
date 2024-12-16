#ifndef HOTEL_H
#define HOTEL_H

typedef struct DataHotel  
{
    int rating  ;   // from 1 to 100 
    int available_room ;    // from 0 
    char* name  ;       
    char* location ;
    int hotline ;
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
ListHotel addHotel(ListHotel list , DataHotel data );
PDHotel searchByNameHotel(ListHotel List , const char* name );
void showHotel(PDHotel hotel);
void deleteByNameHotel(ListHotel list, const char* name);
void showListHotel(ListHotel list);
void swapDataHotel(ListHotel list, PDHotel a, PDHotel b) ;
PDHotel PartitionHotel(ListHotel list, PDHotel first, PDHotel last) ;
void QuicksortHotel(ListHotel list, PDHotel first, PDHotel last) ;
void freeMemoryHotel(ListHotel list);
void readHotelData(ListHotel list);
void writeHotelData(ListHotel list , DataHotel data);

#endif // HOTEL_H
