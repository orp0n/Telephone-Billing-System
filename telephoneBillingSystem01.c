#include <stdio.h>
#include <string.h>

struct userInfo {
    char username[50];
    char password[50];
} ;

struct userInfo registeredUser;

void registerUser() {
    FILE *file = fopen("User Information.txt", "w");
    
    printf("\n| --- Register --- |\n");
    printf("Enter username: ");
    scanf("%s", registeredUser.username);
    printf("Enter password: ");
    scanf("%s", registeredUser.password);
    printf("Registration successful!\n");
    
    fprintf(file, "Username: %s\n", registeredUser.username);
    fprintf(file, "Password: %s\n", registeredUser.password);
    fclose(file);
}

void loginUser() {
    char username[50], password[50];
    printf("\n| --- Login --- |\n");
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    if (strcmp(username, registeredUser.username) == 0 && strcmp(password, registeredUser.password) == 0) {
        printf("Login successful. Welcome, %s!\n", username);
    } else {
        printf("Invalid username or password.\n");
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n| --- Menu --- |\n");
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
