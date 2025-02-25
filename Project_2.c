#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>

int main() {
    printf("\n=============== Welcome to Stone,paper,Scissors game!=============== \n");
    printf("Choose your object and robot will give its whoever wins gets a point, enter 0 to exit. At the end of the game your points will be reflected.\n\n");
    char response[10];
    char a[]="stone",b[]="paper",c[]="scissors";
    int user_count=0;int robot_count=0;
    srand(time(0));
    while (1) {
        printf("==> Enter your choice: ");
        scanf("%9s",response);
        for (int i = 0; response[i]; i++) {
             response[i] = tolower(response[i]);
        }
        if( !(strcmp(response,"stone" )==0 || strcmp(response,"paper")==0 || strcmp(response,"scissors")==0 )  ) {
            if( response[0]=='0' ) {
            if(user_count > robot_count) {
                printf("||CONGRATULATIONS, you won.||");
            } else if(user_count < robot_count) {
                printf("||Hard Luck, you lost.||");
            } else if(user_count==robot_count && user_count!=0 && robot_count!=0 ) {
                printf("||Damn It's a Tie.||");
            } 
            printf("Thankyou for playing our game!\n");
            printf(" [ Developed by Krrish Kumar Singh ]\n");
            break;
        }
            printf("--------------> Invalid input! Please enter 'stone', 'paper', or 'scissors'. <--------------\n");

            continue;
        }
        int num=rand()%3;
        printf("\n==> Robot's choice: ");
        if(num==0) {
            printf("%s\n\n",a);
            if( strcmp(response,"paper")==0) {
                user_count++;   
                printf("--------------> You won. <--------------\n");
            } else if( strcmp(response,"scissors")==0 ) {
                robot_count++;
                printf("--------------> You lost. <--------------\n");
            } 
            else {
                printf("--------------> It's a Draw. <--------------\n");
            }
        }    
        else if (num==1) {
            printf("%s\n",b);
            if( strcmp(response,"scissors")==0) {
                user_count++;   
                printf("--------------> You won. <--------------\n");
            } else if( strcmp(response,"stone")==0 ) {
                robot_count++;
                printf("--------------> You lost. <--------------\n");
            } 
            else {
                printf("--------------> It's a Draw. <--------------\n");
            }
        }
        else {
            printf("%s\n",c);
            if( strcmp(response,"stone")==0) {
                user_count++;   
                printf("--------------> You won. <--------------\n");
            } else if( strcmp(response,"paper")==0 ) {
                robot_count++;
                printf("--------------> You lost. <--------------\n");
            } 
            else {
                printf("--------------> It's a Draw. <--------------\n");
            }
        }
        printf("--------------> You=%d ; Robot=%d <--------------\n",user_count,robot_count);
        printf("-----------------------------------------------------------------------\n");
    }
}