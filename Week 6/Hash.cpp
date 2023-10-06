#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20

struct User {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

struct User users[MAX_USERS];
int userCount = 0;

void registerUser() {
    if (userCount >= MAX_USERS) {
        printf("Udah Max Bro.\n");
        return;
    }

    printf("Masukin Nama: ");
    scanf("%s", users[userCount].username);

    printf("Masukin Password: ");
    scanf("%s", users[userCount].password);

    userCount++;

    printf("Berhasil Regis.\n");
}

int loginUser() {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Masukin Nama: ");
    scanf("%s", username);

    printf("Masukin Password: ");
    scanf("%s", password);

    for (int i = 0; i < userCount; i++) {
        if (strcmp(username, users[i].username) == 0 && strcmp(password, users[i].password) == 0) {
            printf("Selamat Dateng Bro %s!\n", users[i].username);
            return 1;
        }
    }

    printf("Salah Nama ato passwword.\n");
    return 0;
}

int main() {
    int choice;
    int loggedIn = 0;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Exit\n");

        printf("Masukin Pilihan: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                if (!loggedIn) {
                    loggedIn = loginUser();
                } else {
                    printf("Udah login.\n");
                }
                break;
            case 3:
                printf("Keluar...\n");
                return 0;
            default:
                printf("Ada ada saja.\n");
        }
    }

    return 0;
}
