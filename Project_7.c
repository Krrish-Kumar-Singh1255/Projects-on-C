#include <stdio.h>
#include <string.h>
#include  <stdlib.h>
#include <time.h>

void create_account();
void deposit_money();
void withdraw_money();
void check_balance();
void show_details(int *count);

const char* ACCOUNT_DEATILS="account.dat";

typedef struct 
{
    int acc_no;
    char account_holder_name[30];
    float money;
}Account;


int main() {
    int check=0;
    while (1)
    {
        printf("\n*** Bank Management System ***\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Check Balance\n");
        printf("5. Bank Deatils\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d",&choice);
        getchar();
        switch (choice)
        {
        case 1:
        create_account();
            break;
    
        case 2:
        deposit_money();
            break;
    
        case 3:
        withdraw_money();
            break;
    
        case 4:
        check_balance();
            break;
        
        case 5:
        show_details(&check);
            break;

        case 6:
        return 0;
            break;
    
        default:
        printf("\nEntered invalid choice! Choose correctly.\n");
            break;
        }
    }
}

void create_account() {
    FILE *file=fopen(ACCOUNT_DEATILS,"ab+");
    if(file==NULL) {
        printf("\nFile does not opened successfuly.");
        return ;
    }
    Account account;Account acc_read;
    printf("Enter Your Name: ");
    fgets(account.account_holder_name,30,stdin);
    account.account_holder_name[strlen(account.account_holder_name)-1]='\0';
    change :
    srand(time(0));
    account.acc_no=24100+rand()%100;
    while (fread(&acc_read,sizeof(acc_read),1,file))
    {
        if (acc_read.acc_no==account.acc_no)
        {
            goto change;
        }   
    }
    account.money=0;
    fwrite(&account,sizeof(account),1,file);
    fclose(file);
    printf("\nAccount Successfuly Created with Account Number %d\n",account.acc_no);
    file=NULL;
}


void deposit_money() {
    FILE *file=fopen(ACCOUNT_DEATILS,"rb+");
    if (file==NULL)
    {
        printf("\nFile does not opened successfuly.\n");
        return;
    }
    Account acc_read;float d_money;int account_no;
    printf("Enter Your Account Number: ");
    scanf("%d",&account_no);
    while (fread(&acc_read,sizeof(acc_read),1,file))
    {
        if (acc_read.acc_no==account_no)
        {
            printf("Enter amount to deposit: ");
            scanf("%f",&d_money);
            if (d_money>0)
            {
                acc_read.money+=d_money;
                fseek(file, -sizeof(acc_read), SEEK_CUR);
                fwrite(&acc_read,sizeof(acc_read),1,file);
                printf("\nSuccessfully deposited Rs.%.2f. New balance is Rs.%.2f.\n",d_money,acc_read.money);
            }
            else {
                printf("\nInvalid amount!\n");
            }
            fclose(file);
            return;
        }
    }
    printf("\nAccount does not found.\n");
    fclose(file);
}


void withdraw_money() {
    FILE *file=fopen(ACCOUNT_DEATILS,"rb+");
    if (file==NULL)
    {
        printf("\nFile does not opened successfuly.\n");
        return;
    }
    Account acc_read;float w_money;int account_no;
    printf("Enter Your Account Number: ");
    scanf("%d",&account_no);
    while (fread(&acc_read,sizeof(acc_read),1,file))
    {
        if (acc_read.acc_no==account_no)
        {
            printf("Enter amount to withdraw: ");
            scanf("%f",&w_money);
            if (w_money<=acc_read.money)
            {
                acc_read.money-=w_money;
                fseek(file, -sizeof(acc_read), SEEK_CUR);
                fwrite(&acc_read,sizeof(acc_read),1,file);
                printf("\nSuccessfully withdrawn Rs.%.2f. Remaining balance is Rs.%.2f.\n",w_money,acc_read.money);
            }
            else {
                printf("\nInsufficient Balance!\n");
            }
            fclose(file);
            return;
        }
    }
    printf("\nAccount does not found.\n");
    fclose(file);
}


void check_balance() {
    FILE *file=fopen(ACCOUNT_DEATILS,"rb+");
    if(file==NULL) {
        printf("\nFile does not opened successfuly.\n");
        return ;
    }
    Account account;int account_no;
    printf("Enter Account Number: ");
    scanf("%d",&account_no);
    getchar();
    while (fread(&account,sizeof(account),1,file))
    {
        if(account.acc_no==account_no) {
            printf("\nYour current balance is Rs.%.2f.\n",account.money);
            fclose(file);
            file=NULL;
            return;
        }
    }
    printf("\nAccount does not found.\n");
    fclose(file);
    file=NULL;
}

void show_details(int *count) {
    if (*count==3)
    {
        printf("\nMax Attempt Reached!\n");
        return;
    }
    FILE *file=fopen(ACCOUNT_DEATILS,"rb");
    if (file==NULL)
    {
        printf("\nUnable to open file\n");
        return ;
    }
    int pass;
    printf("Enter Password: ");
    scanf("%d",&pass);
    if(pass==100324) {
        Account acc_detail;
        *count=0;
        while (fread(&acc_detail,sizeof(acc_detail),1,file))
        {
            printf("\nAccount Holder Name: %s , Account Number: %d , Balance: Rs.%.2f.\n",acc_detail.account_holder_name,acc_detail.acc_no,acc_detail.money);
        }
        fclose(file);
        file=NULL;
    }
    else {
        *count=*count+1;
        printf("\nWrong password! %d Attempt left.\n",3-*count);
    }
    return;
}