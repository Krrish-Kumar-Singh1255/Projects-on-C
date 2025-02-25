#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    srand(time(0));
    int guess, num=rand()%20,k=0;
    printf("\n=============== WELCOME TO THE NUMBER GUESSING GAME. ===================");
    printf("\nHOW TO PLAY: You have to enter the number untill you guess the right one");
    do{
        printf("\n\nGuess the number(^-^) Range (1-20): ");
        scanf("%d",&guess);
        k++;
        if(guess>num)
        {
            printf("\n--------------> NOPE :( Please Enter Lower number <--------------");
            continue;
        }
        else if(guess<num )
        {
            printf("\n--------------> NOPE :( Please Enter Higher number <--------------");
            continue;
        }
        else
        {
            printf("");
        }
    }while(num!=guess);
    printf("\n||CONGRATULATIONS, you guessed right number.||\n");
    printf("-------------> Total attempts:%d <-------------\n",k);
    printf("Thank you for playing our game..\n");
    printf(" [ Developed by Krrish Kumar Singh.. ]\n");
    return 0;
}