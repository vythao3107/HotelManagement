#ifndef HOTELINTERFACE_H
#define HOTELINTERFACE_H
#include "../Objects/history.h"
#include "../Objects/hotels.h"
#include "../Objects/users.h"

int hotelInterface(historyManager manager, ListHotel hotels, ListUser users);
void saveHotelInfo( ListHotel hotels , DataHotel hotel) ;
DataHotel getInfoHotel();
void updateHotelData(ListHotel hotels , DataHotel hotel) ;

#endif 