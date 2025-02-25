#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int input_format();
void fill_time(char buffer_time[],int choice);
void fill_date(char buffer_date[]);
void clear_screen();

int main() {
    int choice=input_format();
    while(1) {
        char buffer_time[50], buffer_date[100];
        fill_time(buffer_time,choice);
        fill_date(buffer_date);
        clear_screen();
        printf("\nCurrent Time: %s",buffer_time);
        printf("\nDate: %s",buffer_date);
        sleep(1);
    }
    return 0;
}

int input_format() {
    printf("\nChoose the time format: ");
    printf("\n1. 24 Hour Format.");
    printf("\n2. 12 Hour Format (Default).");
    int choice;
    printf("\nMake a choice(1/2): ");
    scanf("%d",&choice);
    return choice;
}

void clear_screen() {
    #ifdef _WIN32
    system("cls");
    #else 
    system("clear");
    #endif
}

void fill_time(char buffer_time[],int choice) {
        time_t raw_time;
        time(&raw_time);
        struct tm *current_time;
        current_time=localtime(&raw_time);
        if(choice==1) {
            strftime(buffer_time,50,"%H:%M:%S",current_time);
        }
        else {
            strftime(buffer_time,50,"%I:%M:%S %p",current_time);
        }
}

void fill_date(char buffer_date[]) {
    time_t raw_time;
        time(&raw_time);
        struct tm *current_date;
        current_date=localtime(&raw_time);
        strftime(buffer_date,50,"%A %B %d %Y",current_date);
}