#include <stdio.h>
#include <string.h>

typedef struct usersInfo {
    char username[50];
    char password[50];
}USER;

# define max_users 100
USER registeredUser[max_users];
int user_count=0;

//UDF for Registration Functionality
void registerUser() {
    FILE *file = fopen("User Information.txt", "a");

    printf("\n| --- Register --- |\n");
    printf("Enter username: ");
    scanf("%s",&registeredUser[user_count].username);
    printf("Enter password: ");
    scanf("%s",&registeredUser[user_count].password);
    
    user_count++;
    printf("Registration Successful!\n");

    printf("user count = %d",user_count);


    fprintf(file, "Username: %s\n", registeredUser[user_count].username);
    fprintf(file, "Password: %s\n", registeredUser[user_count].password);
    fclose(file);
}

//UDF for Log in Functionality
void loginUser() {

    char username[50], password[50];
    printf("\n| --- Login --- |\n");
    printf("Enter username: ");
    scanf("%s",username);
    printf("Enter password: ");
    scanf("%s",password);

    int found=0;
    for(int i=0;i<user_count;i++){
        if (strcmp(username, registeredUser[i].username) == 0 && strcmp(password, registeredUser[i].password) == 0) {
            printf("Login successful. Welcome, %s!\n", username);
            found=1;
            break;
        }
        if(found!=1) {
            printf("Invalid username or password.\n");
        }
    }

}

int main() {
    int choice;

    while (1) {
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
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
