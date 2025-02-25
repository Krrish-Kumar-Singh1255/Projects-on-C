#include <stdio.h>
#include<math.h>
void input(float *response1,float *response2);
void add(float response1,float response2);
void substract(float response1,float response2);
void multiply(float response1,float response2);
void divide(float response1,float response2);
void modulus(float response1,float response2);
void power(float response1,float response2);
int main() {
    int choice;float response1,response2;
    file:
    printf("----------------------------------------------\n");
    printf("Welcome to Simple Calculator\n\n");
    printf("Choose one of the following options:\n1. Add\n2. Substract\n3. Multiply\n4. Divide\n5. Modulus\n6. Power\n7. Exit\n");
    printf("Now, enter your choice: ");
    scanf("%d",&choice);
    if(choice==1) {
        input(&response1,&response2);
        add(response1,response2);
    }  
    else if (choice==2) {
        input(&response1,&response2);
        substract(response1,response2);
    }
    else if (choice==3) {
        input(&response1,&response2);
        multiply(response1,response2);       
    }
    else if (choice==4) {
        input(&response1,&response2);
        divide(response1,response2);
    }
    else if (choice==5) {
        input(&response1,&response2);
        modulus(response1,response2);
    }
    else if (choice==6) {
        printf("\n !! You have to enter power in the second number section !!\n");
        input(&response1,&response2);
        power(response1,response2);
    }
    else if (choice==7)
    {
        return 0;
    }
    else {
        printf("\nYou entered invalid choice,enter choice properly!!\n\n");
    }
    goto file;
}

void input(float *response1,float *response2) {
    printf("\nPlease enter the first number: ");
    scanf("%f",response1);
    printf("Now, enter the second number: ");
    scanf("%f",response2);
}

void add(float response1,float response2) {
    float result=response1+response2;
    printf("\nResult of operation is: %.2f\n\n",result);
}

void substract(float response1,float response2) {
    float result=response1-response2;   
    printf("\nResult of operation is: %.2f\n\n",result);
}

void multiply(float response1,float response2) {
    float result=response1*response2;   
    printf("\nResult of operation is: %.2f\n\n",result);
}

void divide(float response1,float response2) {
    if(response2!=0) {
        float result=response1/response2; 
        printf("\nResult of operation is: %.2f\n\n",result);
    }  
    else {
        printf("\nInvalid Argument for Division\n\n");
    }
}

void modulus(float response1,float response2) {
    if (response2!=0) {
        float result=fmod(response1,response2);
        printf("\nResult of operation is: %.2f\n\n",result);
    }
    else {
        printf("\nInvalid Argument for Modulus\n\n");
    }
}

void power(float response1,float response2) {
    if ((response1!=0 && response2!=0) && (response1!=0 || response2 > 0) && (response1 > 0 || response2==(int)response2) ) {
        float result=powf(response1,response2);
        printf("\nResult of operation is: %.2f\n\n",result);
    }
    else {
        printf("\nInvalid Argument for Modulus\n\n");
    }
}
