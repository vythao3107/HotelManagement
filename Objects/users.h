#ifndef USERS_H
#define USERS_H

typedef struct DataUser
{
    int id;         // from 100000 to 999999
    char *name;     // had a space ??? 
} DataUser ;

typedef struct DUser 
{
    DataUser  data;
    struct DUser  *nextL, *nextR;
} DUser ;

typedef DUser  *PDUser ;

typedef struct ListUser
{
    PDUser  H;
    PDUser  T;
} *ListUser;

void showTestUser();
ListUser createListUser();
ListUser addUser (ListUser list, DataUser  data);
PDUser  searchByID(ListUser List, int id );
void deleteByID(ListUser list, int id );
void showListUser(ListUser list);
void freeMemoryUser(ListUser list);
void readUserData(ListUser list);
void writeUserData(DataUser data);
#endif