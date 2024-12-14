#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "history.h"
#include "users.h"
#include "hotels.h"

int main()
{
    // Create History Manager
    historyManager manager = createHistoryManager();
    ListHistory history1 = createListHistory();
    ListHistory history2 = createListHistory();

    // Add some list histories to the manager
    manager = addListHistory(manager, 1, 8490);
    manager = addListHistory(manager, 2, 8490);

    // Add some histories to history1
    DataHistory data1 = {"Grand Hotel", "Hanoi", 240101};
    DataHistory data2 = {"Beach Resort", "Danang", 240215};
    history1 = addHistory(history1, data1);
    history1 = addHistory(history1, data2);

    // Add some histories to history2
    DataHistory data3 = {"Mountain Lodge", "Sapa", 240110};
    DataHistory data4 = {"City Inn", "HCMC", 240305};
    history2 = addHistory(history2, data3);
    history2 = addHistory(history2, data4);

    // Show the full history manager
    printf("\nInitial History Manager:\n");
    showHistoryManager(manager);

    // Search for a history in history1's list
    PDHistory searchResult = searchByNameHistory(history1, "Grand Hotel");
    if (searchResult)
    {
        printf("\nFound history: %s, %s, %d\n", searchResult->data.name_hotel, searchResult->data.location, searchResult->data.date);
    }
    else
    {
        printf("\nHistory not found.\n");
    }

    // Delete a history from history2
    deleteByNameHistory(history2, "City Inn");
    printf("\nHistory Manager after deleting 'City Inn' from history2:\n");
    showHistoryManager(manager);

    // Sort histories for history1 by date
    if (history1->H && history1->T)
    {
        QuicksortByDate(history1, history1->H, history1->T);
        printf("\nhistory1's history after sorting by date:\n");
        showListHistory(history1);
    }

    // Delete a history list from the history manager
    deleteByIDHistory(manager, 1);
    printf("\nHistory Manager after deleting history1:\n");
    showHistoryManager(manager);

    // Clean up memory
    freeMemoryHistoryManager(manager);

    return 0;
}