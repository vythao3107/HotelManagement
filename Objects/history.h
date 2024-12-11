#ifndef HISTORY_H
#define HISTORY_H

typedef struct DataHistory
{
    char *name_hotel ;
    char *location ;
    int date;           // year month date ex : 241211
    int past_guests ;   // 
} DataHistory;

typedef struct DHistory

{
    DataHistory data;
    struct DHistory *nextL, *nextR;
} DHistory;

typedef DHistory *PDHistory;

typedef struct ListHistory
{
    int id ;    // match user
    int phone_number; // phone number of user started by 84 
    PDHistory H;
    PDHistory T;
    struct ListHistory *nextL , *nextR ;
} *ListHistory;

typedef struct historyManager
{
    ListHistory H ;
    ListHistory T ;   
} historyManager ;


// Function prototypes for the List History 
void showTestHistorys();
ListHistory createListHistory();
ListHistory addHistory(ListHistory list, DataHistory data);
PDHistory searchByNameHistory(ListHistory List, const char *name);
void deleteByNameHistory(ListHistory list, const char *name);
void showListHistory(ListHistory list);
void swapDataHistory(ListHistory list, PDHistory a, PDHistory b);
PDHistory PartitionDate(ListHistory list, PDHistory first, PDHistory last);
void QuicksortByDate(ListHistory list, PDHistory first, PDHistory last);

// Function prototypes for the History Manager 

historyManager createHistoryManager() ;
ListHistory addListHistory(ListHistory list, DataHistory data);
PDHistory searchByIDListHistory(ListHistory List, const char *name);
void deleteByNameIDListHistory(ListHistory list, const char *name);
void showHistoryManager(ListHistory list);

#endif 