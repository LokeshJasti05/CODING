#include <stdio.h>
#include <string.h>

#define MAX_COPS 100
#define MAX_CRIMINALS 100

struct Criminal {
    char name[50];
    char crime[100];
};

struct Cop {
    char username[50];
    char password[50];
    struct Criminal criminalLog[MAX_CRIMINALS];
    int criminalCount;
};

struct Cop cops[MAX_COPS];
int copCount = 0;

int registerCop();
int login();
void updateCriminalLog(int copIndex);
void displayCriminalDetails(int copIndex, const char criminalName[]);
void viewCriminalDetails();

int main() {
    int choice;
    do {
        printf("Police Management System\n");
        printf("1. Register Cop\n");
        printf("2. Login\n");
        printf("3. View Criminal Details\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerCop();
                break;
            case 2:
                login();
                break;
            case 3:
                viewCriminalDetails();
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

int registerCop() {
    if (copCount < MAX_COPS) {
        printf("Enter username: ");
        scanf("%s", cops[copCount].username);

        printf("Enter password: ");
        scanf("%s", cops[copCount].password);

        cops[copCount].criminalCount = 0;

        printf("Cop registered successfully!\n");
        copCount++;
        return 1;
    } else {
        printf("Cannot register more cops. Maximum limit reached.\n");
        return 0;
    }
}

int login() {
    char username[50];
    char password[50];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    for (int i = 0; i < copCount; i++) {
        if (strcmp(cops[i].username, username) == 0 && strcmp(cops[i].password, password) == 0) {
            printf("Login successful!\n");

            int updateChoice;
            printf("Do you want to update the criminal log? (1 for Yes, 0 for No): ");
            scanf("%d", &updateChoice);

            if (updateChoice == 1) {
                updateCriminalLog(i);
            }

            return 1;
        }
    }

    printf("Invalid username or password. Login failed.\n");
    return 0;
}

void updateCriminalLog(int copIndex) {
    if (copIndex >= 0 && copIndex < copCount) {
        if (cops[copIndex].criminalCount < MAX_CRIMINALS) {
            printf("Enter criminal name: ");
            scanf("%s", cops[copIndex].criminalLog[cops[copIndex].criminalCount].name);

            printf("Enter crime details: ");
            scanf("%s", cops[copIndex].criminalLog[cops[copIndex].criminalCount].crime);

            cops[copIndex].criminalCount++;

            printf("Criminal log updated successfully!\n");
        } else {
            printf("Cannot add more criminals to the log. Maximum limit reached.\n");
        }
    } else {
        printf("Invalid cop index.\n");
    }
}

void displayCriminalDetails(int copIndex, const char criminalName[]) {
    if (copIndex >= 0 && copIndex < copCount) {
        for (int i = 0; i < cops[copIndex].criminalCount; i++) {
            if (strcmp(cops[copIndex].criminalLog[i].name, criminalName) == 0) {
                printf("Criminal Details:\n");
                printf("Name: %s\n", cops[copIndex].criminalLog[i].name);
                printf("Crime: %s\n", cops[copIndex].criminalLog[i].crime);
                return;
            }
        }

        printf("Criminal not found in the log.\n");
    } else {
        printf("Invalid cop index.\n");
    }
}

void viewCriminalDetails() {
    int viewChoice;
    printf("Do you want to view criminal details? (1 for Yes, 0 for No): ");
    scanf("%d", &viewChoice);

    if (viewChoice == 1) {
        char criminalName[50];
        printf("Enter criminal name: ");
        scanf("%s", criminalName);

        for (int i = 0; i < copCount; i++) {
            displayCriminalDetails(i, criminalName);
        }
    }
}
