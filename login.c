#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct lưu thông tin người dùng
typedef struct {
    char name[100];         // Tên
    int age;                // Tuổi
    char cccd[20];          // Số CCCD
    char address[200];      // Địa chỉ
    char email[100];        // Email
} DataUser;

// Node của danh sách liên kết kép
typedef struct DUser {
    DataUser data;            // Thông tin người dùng
    struct DUser *nextL;      // Con trỏ đến phần tử trước
    struct DUser *nextR;      // Con trỏ đến phần tử sau
} DUser, *PDUser;

// Danh sách liên kết kép
typedef struct ListUser {
    PDUser H;  // Con trỏ đến phần tử đầu
    PDUser T;  // Con trỏ đến phần tử cuối
} *ListUser;

// Hàm kiểm tra email hợp lệ
int isValidEmail(const char *email) {
    const char *at = strchr(email, '@');
    const char *dot = strrchr(email, '.');
    return at && dot && at < dot && dot - at > 1;
}

// Tạo danh sách người dùng
ListUser createListUser() {
    ListUser list = (ListUser)malloc(sizeof(struct ListUser));
    if (list == NULL) {
        printf("Khong the cap phat bo nho\n");
        return NULL;
    }
    list->H = NULL;
    list->T = NULL;
    return list;
}

// Thêm người dùng vào danh sách
ListUser addUser(ListUser list, DataUser data) {
    PDUser newUser = (PDUser)malloc(sizeof(DUser));
    if (newUser == NULL) {
        printf("Khong the cap phat bo nho\n");
        return list;
    }

    newUser->data = data;
    newUser->nextL = NULL;
    newUser->nextR = NULL;

    if (list->H == NULL) {
        list->H = newUser;
        list->T = newUser;
    } else {
        list->T->nextR = newUser;
        newUser->nextL = list->T;
        list->T = newUser;
    }
    return list;
}

// Hiển thị danh sách người dùng
void showListUser(ListUser list) {
    PDUser current = list->H;
    while (current != NULL) {
        printf("Email: %s, Ten: %s, Tuoi: %d, CCCD: %s, Đia chi: %s\n",
               current->data.email, current->data.name, current->data.age,
               current->data.cccd, current->data.address);
        current = current->nextR;
    }
    printf("\n====================\n");
}

// Hàm nhập thông tin người dùng
DataUser inputUserInfo() {
    DataUser user;

    // Nhập email
    do {
        printf("Nhap email: ");
        fgets(user.email, sizeof(user.email), stdin);
        user.email[strcspn(user.email, "\n")] = '\0'; // Xóa ký tự xuống dòng
        if (!isValidEmail(user.email)) {
            printf("Email khong hop le. Vui long nhap lai.\n");
        }
    } while (!isValidEmail(user.email));

    printf("Nhap ten: ");
    fgets(user.name, sizeof(user.name), stdin);
    user.name[strcspn(user.name, "\n")] = '\0'; // Xóa ký tự xuống dòng

    printf("Nhap tuoi: ");
    scanf("%d", &user.age);
    getchar(); // Xóa ký tự \n còn lại trong bộ đệm

    printf("Nhap so CCCD: ");
    fgets(user.cccd, sizeof(user.cccd), stdin);
    user.cccd[strcspn(user.cccd, "\n")] = '\0';

    printf("Nhap Dia chi: ");
    fgets(user.address, sizeof(user.address), stdin);
    user.address[strcspn(user.address, "\n")] = '\0';

    return user;
}

// Hàm tìm kiếm người dùng theo email
PDUser searchByEmail(ListUser list, const char *email) {
    PDUser current = list->H;
    while (current != NULL) {
        if (strcmp(current->data.email, email) == 0) {
            return current;
        }
        current = current->nextR;
    }
    return NULL;
}

// Hàm xóa người dùng theo email
void deleteByEmail(ListUser list, const char *email) {
    PDUser deleteNode = searchByEmail(list, email);
    if (!deleteNode) {
        printf("Khong tim thay nguoi dung: %s\n", email);
        return;
    }

    if (deleteNode == list->H) {
        list->H = deleteNode->nextR;
        if (list->H) {
            list->H->nextL = NULL;
        } else {
            list->T = NULL;
        }
    } else if (deleteNode == list->T) {
        list->T = deleteNode->nextL;
        if (list->T) {
            list->T->nextR = NULL;
        }
    } else {
        deleteNode->nextL->nextR = deleteNode->nextR;
        deleteNode->nextR->nextL = deleteNode->nextL;
    }

    free(deleteNode);
}

int main() {
    ListUser userList = createListUser();
    if (userList == NULL) {
        return 1;
    }

    int choice;
    do {
        printf("\nQuan ly nguoi dung:\n");
        printf("1. Them nguoi dung\n");
        printf("2. Hien thi danh sach nguoi dung\n");
        printf("3. Tim kiem nguoi dung theo email\n");
        printf("4. Xoa nguoi dung theo email\n");
        printf("0. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
        case 1: {
            DataUser newUser = inputUserInfo();
            userList = addUser(userList, newUser);
            break;
        }
        case 2:
            showListUser(userList);
            break;
        case 3: {
            char email[100];
            printf("Nhap email can tim: ");
            fgets(email, sizeof(email), stdin);
            email[strcspn(email, "\n")] = '\0';
            PDUser foundUser = searchByEmail(userList, email);
            if (foundUser) {
                printf("Nguoi dung tim thay: \n");
                printf("Email: %s, Ten: %s, Tuoi: %d, CCCD: %s, Dia chi: %s\n",
                       foundUser->data.email, foundUser->data.name,
                       foundUser->data.age, foundUser->data.cccd,
                       foundUser->data.address);
            } else {
                printf("Khong tim thay nguoi dung voi email: %s\n", email);
            }
            break;
        }
        case 4: {
            char email[100];
            printf("Nhap email can xoa: ");
            fgets(email, sizeof(email), stdin);
            email[strcspn(email, "\n")] = '\0';
            deleteByEmail(userList, email);
            break;
        }
        case 0:
            printf("Thoat chuong trinh.\n");
            break;
        default:
            printf("Lua chon khong hop le.\n");
        }
    } while (choice != 0);

    return 0;
}
