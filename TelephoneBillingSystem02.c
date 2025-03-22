#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include<conio.h>

struct userInfo {
    char username[50];
    char email[50];
    char password[50];
} user;

struct userInfo registeredUser;

//UDF for Password validation Functionality
int isPasswordValid(char *password) {
    int hasUpper = 0, hasLower = 0, hasDigit = 0, hasSpecial = 0;
    for (int i = 0; password[i]; i++) {
        if (isupper(password[i])) 
            hasUpper = 1;
        else if (islower(password[i])) 
            hasLower = 1;
        else if (isdigit(password[i])) 
            hasDigit = 1;
        else 
            hasSpecial = 1;
    }
    return hasUpper && hasLower && hasDigit && hasSpecial && strlen(password) >= 8;
}

//UDF for Set Password Functionality
void maskPassword(char *password) {
    char ch;
    int i = 0;
    
    printf("Enter password: ");
    while ((ch = getch())!= '\r') {
        if (ch == '\b' && i > 0) {
            printf("\b \b");
            i--;
        } else if (isprint(ch) && i < 49) {
            password[i++] = ch;
            printf("*");
        }
    }
    password[i] = '\0';
}

//UDF for Registration Functionality
void registerUser() {
    FILE *file = fopen("UserInformation.txt", "a");
    
    printf("\n| --- Register --- |\n");
    printf("Enter username: ");
    scanf("%s", user.username);
    printf("Enter email: ");
    scanf("%s", user.email);
    
    do {
        maskPassword(user.password);
        if (!isPasswordValid(user.password)) {
            printf("\nPassword must be at least 8 characters with upper/lowercase, number, and special character.\n");
        }
    } while (!isPasswordValid(user.password));

    fprintf(file, "Email: %s\nPassword: %s\n", user.email, user.password);
    fclose(file);

    printf("\nRegistration successful!\n");
}

//UDF for Log in Functionality
void loginUser() {
    char email[50], password[50];
    int found = 0;

    printf("\n| --- Login --- |\n");
    printf("Enter email: ");
    scanf("%s", email);
    maskPassword(password);

    FILE *file = fopen("UserInformation.txt", "r");
    if (file == NULL) {
        printf("\nNo users registered yet.\n");
        return;
    }

    while (fscanf(file, "Email: %s\nPassword: %s\n", user.email, user.password) != EOF) {
        if (strcmp(email, user.email) == 0 && strcmp(password, user.password) == 0) {
            found = 1;
            break;
        }
    }
    fclose(file);

    if (found) {
        printf("\nLogin successful. Welcome, %s!\n", user.username);
    } else {
        printf("\nInvalid email or password.\n");
    }
}

int main() {
    int choice;
    while(1) {
        //Navigation Menu
        printf("\n| --- Menu --- |\n");
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Select from Navigation Menu: ");
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
                return 0;
            default: 
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
