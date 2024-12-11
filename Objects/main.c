#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "history.h"

// Assuming that the function prototypes and implementations are available.

int main()
{
    // Create a list of history
    ListHistory historyList = createListHistory();

    // Create test data
    DataHistory data1 = {"Hotel A", "Location A", 241211};
    DataHistory data2 = {"Hotel B", "Location B", 251211};
    DataHistory data3 = {"Hotel C", "Location C", 261211};

    // Add the data to the list
    historyList = addHistory(historyList, data1);
    historyList = addHistory(historyList, data2);
    historyList = addHistory(historyList, data3);

    // Show the list of histories
    printf("Displaying History List:\n");
    showListHistory(historyList);

    // Search for a history by name
    printf("\nSearching for Hotel B:\n");
    PDHistory searchResult = searchByNameHistory(historyList, "Hotel B");
    if (searchResult != NULL)
    {
        printf("Found Hotel: %s, Location: %s, Date: %d\n", searchResult->data.name_hotel, searchResult->data.location, searchResult->data.date);
    }
    else
    {
        printf("Hotel not found.\n");
    }

    // Delete a history by name
    printf("\nDeleting Hotel A:\n");
    deleteByNameHistory(historyList, "Hotel A");
    showListHistory(historyList);

    // Quicksort the history list by date
    printf("\nSorting history by date:\n");
    QuicksortByDate(historyList, historyList->H, historyList->T);
    showListHistory(historyList);

    return 0;
}
