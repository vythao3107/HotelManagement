#include<stdio.h>

#include"users.h"

int main()
{
    // Test initialization
    showTestUser();

    // Create the list
    ListUser userList = createListUser();

    // Add some users
    DataUser user1 = {100001, "Nguyen Van A"};
    DataUser user2 = {100002, "Tran Thi B"};
    DataUser user3 = {100003, "Le Van C"};

    userList = addUser(userList, user1);
    userList = addUser(userList, user2);
    userList = addUser(userList, user3);

    // Show the list of users
    printf("Initial user list:\n");
    showListUser(userList);

    // Search for a user by ID
    int searchId = 100002;
    PDUser foundUser = searchByID(userList, searchId);
    if (foundUser)
    {
        printf("\nUser with ID %d found: %s\n", foundUser->data.id, foundUser->data.name);
    }
    else
    {
        printf("\nUser with ID %d not found.\n", searchId);
    }

    // Delete a user by ID
    int deleteId = 100001;
    printf("\nDeleting user with ID %d...\n", deleteId);
    deleteByID(userList, deleteId);

    // Show the list after deletion
    printf("\nUser list after deletion:\n");
    showListUser(userList);

    return 0;
}
