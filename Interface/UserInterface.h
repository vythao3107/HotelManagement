#ifndef USERINTERFACE_H
#define USERINTERFACE_H
#include "../Objects/history.h"
#include "../Objects/hotels.h"
#include "../Objects/users.h"

int userInterface(historyManager manager, ListHotel hotels, ListUser users);
void showHotel(PDHotel hotel );
DataUser signInUser();
DataUser signUpUser();
void saveHistory(historyManager list, int id, DataHistory data);

#endif 