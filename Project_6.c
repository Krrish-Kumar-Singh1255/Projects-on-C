#include <stdio.h>
#include <string.h>
#include <conio.h>

#define MAX_USERS 5
#define MAX_CREDENTIALS 30

typedef struct 
{
    char username[MAX_CREDENTIALS];
    char password[MAX_CREDENTIALS];
}User_details;

void register_user(int count,User_details user_detail[]);
void login_user(int count,User_details user_detail[]);
void input_details(char username[],char password[]);


int main() {
    User_details user_detail[MAX_USERS];
    int count=0;
    while (1)
    {
        int option=0;
        printf("\nWelcome to User Management");
        printf("\n1. Register\n2. Login\n3. Exit\n");
        printf("Select an option: ");
        if (scanf("%d",&option) != 1)
        {
            printf("\nIncorrect choice! Choose option properly.\n");
            while (getchar() != '\n');  // Clear input buffer
            continue;
        }
        
        getchar();
        if (option==1)
        {
            if(count < MAX_USERS){
                register_user(count,user_detail);
                count++;
            }
            else {
                printf("\nMaximum users reached.\n");
            }
        }
        else if(option==2) {
            login_user(count,user_detail);
        }
        else if(option==3){
            printf("\nExiting program.");
            return 0;
        }
        else {
            printf("\nInvalid choice! Choose option properly.\n");
        }
    }
}

void register_user(int count,User_details user_detail[]) {
    printf("\nRegister a New User.\n");
    input_details(user_detail[count].username,user_detail[count].password);
    printf("\nRegistration Successful!\n");
}

void login_user(int count,User_details user_detail[]) {
    if (count==0)
    {
        printf("\nNo users registered.\n");
    }
    else {
        User_details login_user_details;
        printf("\nLogin existing user.\n");
        input_details(login_user_details.username,login_user_details.password);
        int check=0;
        for (int i = 0; i < count; i++)
        {
           if(strcmp(login_user_details.username,user_detail[i].username)==0 && strcmp(login_user_details.password,user_detail[i].password)==0) {
                        printf("\nLogin Successful! Welcome, %s!\n",login_user_details.username);
                        check=1;
                        break;
                    }
                }
                if (check==0)
                {
                    printf("\nLogin failed! Incorrect username or password.\n");
                }
            }
}

void input_details(char username[],char password[]) {
    printf("Enter username: ");
    fgets(username,MAX_CREDENTIALS,stdin);
    username[strlen(username)-1]='\0';
    printf("Enter password (masking enabled): ");
    int i=0;
    char ch;
    while ((ch = _getch())!= '\r' )
    {
        if(ch=='\b') {
            if(i>0) {
                i--;
                printf("\b \b");
            }
        }
        else if(i< MAX_CREDENTIALS - 1) {
            password[i++]= ch;
            printf("*");
        }
        password[i]='\0';
    }
    printf("\n");
}