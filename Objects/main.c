#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "history.h"

int main()
{
    // Create History Manager
    historyManager manager = createHistoryManager();
    ListHistory user1 = createListHistory();
    ListHistory user2 = createListHistory();

    // Add some list histories to the manager
    manager = addListHistory(manager, 1, 8490);
    manager = addListHistory(manager, 2, 8490);

    // Add some histories to user1
    DataHistory data1 = {"Grand Hotel", "Hanoi", 240101};
    DataHistory data2 = {"Beach Resort", "Danang", 240215};
    user1 = addHistory(user1, data1);
    user1 = addHistory(user1, data2);

    // Add some histories to user2
    DataHistory data3 = {"Mountain Lodge", "Sapa", 240110};
    DataHistory data4 = {"City Inn", "HCMC", 240305};
    user2 = addHistory(user2, data3);
    user2 = addHistory(user2, data4);

    // Show the full history manager
    printf("\nInitial History Manager:\n");
    showHistoryManager(manager);

    // Search for a history in user1's list
    PDHistory searchResult = searchByNameHistory(user1, "Grand Hotel");
    if (searchResult)
    {
        printf("\nFound history: %s, %s, %d\n", searchResult->data.name_hotel, searchResult->data.location, searchResult->data.date);
    }
    else
    {
        printf("\nHistory not found.\n");
    }

    // Delete a history from user2
    deleteByNameHistory(user2, "City Inn");
    printf("\nHistory Manager after deleting 'City Inn' from user2:\n");
    showHistoryManager(manager);

    // Sort histories for user1 by date
    if (user1->H && user1->T)
    {
        QuicksortByDate(user1, user1->H, user1->T);
        printf("\nUser1's history after sorting by date:\n");
        showListHistory(user1);
    }

    // Delete a user list from the history manager
    deleteByIDHistory(manager, 1);
    printf("\nHistory Manager after deleting user1:\n");
    showHistoryManager(manager);

    // Clean up memory (not shown here for brevity)

    return 0;
}
