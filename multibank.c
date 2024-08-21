#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>
//int current_money = 0;
void deposite();
void loading();
void update();
void delet();
void withdraw();
void search_account();
void menu();
void transfer();
void nl();
void border();
void new_acc();
void name_list();

int curr_money;
struct account
{
    char name1[40];
     int acc_number;
    char type[40];
    int current_money;
    int deposite;
    int transfer;
    int withdraw;
    int password;
    long int aadhar;
};

int main()
{
    //int choice;

    loading();

    menu();

    return 0;
}
void new_acc()
{

    FILE *fp;
    fp = fopen("bankrecord.txt", "a");

    struct account a1;
    a1.transfer = 0;
      a1.withdraw = 0;
    a1.deposite = 0;
    srand((time(0)));

    printf("Enter new user name: ");
    scanf("%s", a1.name1);

    printf("Enter your type of account: ");
    scanf("%s", a1.type);
    printf("Enter your aadhar number for KYC: ");
    scanf("%d", &a1.aadhar);
    printf("\nKYC created succesfully....");

    printf("\nAccount number generated succesfully..............");
    Sleep(5000);
    loading();
    long int random = 171 * rand();
    printf("YOUR ACCOUNT NUMBER IS:%ld", random);
    a1.acc_number = random;
    nl();
    nl();
    printf("please do some minimum deposite of atleast 5000/-RS to open your account\n");
    scanf("%d", &a1.current_money);
    if (a1.current_money >= 5000)
    {
        printf("Account created succesfully...........");
        border();

        fprintf(fp, "%s\t\t%s\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", a1.name1, a1.type, a1.acc_number, a1.deposite, a1.withdraw, a1.transfer, a1.current_money);
    }
    else
    {
        printf("\nSorry,we can't open your account due to insuffient amount deposited initially");
    }

    fclose(fp);
    nl();
    menu();
}
void search_account()
{  int acc;
    FILE *fp;
    struct account a2;
    char n1[40];
    fp = fopen("bankrecord.txt", "r");
    printf("Enter the account number of user: ");
    scanf("%s", &acc);
    while (fscanf(fp, "%s   %s    %d    %d    %d    %d    %d", a2.name1, a2.type, &a2.acc_number, &a2.deposite, &a2.withdraw, &a2.transfer, &a2.current_money) != EOF)
    {
        if (acc==a2.acc_number)
        {
            printf("USERNAME: %s\n", a2.name1);
            printf("ACCOUNT NUMBER: %d\n", a2.acc_number);
            printf("ACCOUNT STATUS: %s\n", a2.type);
            printf("CURRENT BANK BALANCE: %d", a2.current_money);
        }
    }
    fclose(fp);
    nl();
    menu();
}
void deposite()
{
    FILE *fp1, *fp, *fp2;
    struct account a1;
    time_t t;
    char name[67];
    t = time(&t);
    int deposite;
    int acc;
    fp1 = fopen("tran.txt", "a");
    fp = fopen("temp.txt", "w");
    fp2 = fopen("bankrecord.txt", "r");

    printf("Enter account number of user: ");
    scanf("%d", &acc);
    while (fscanf(fp2, "%s   %s    %d    %d    %d    %d     %d", a1.name1, a1.type, &a1.acc_number, &a1.deposite, &a1.withdraw, &a1.transfer, &a1.current_money) != EOF)
    {
        if (acc==a1.acc_number)
        {
            printf("Enter the amount you want to deposite: ");
            scanf("%d", &deposite);
            a1.deposite += deposite;
            a1.current_money += deposite;
            fprintf(fp1, "\n====================================================\n");

            fprintf(fp1, "User name : %s,has deposited amount of %d at %s ,current amount in account is:%d", a1.name1, deposite, ctime(&t), a1.current_money);
            fprintf(fp1, "\n====================================================\n");
        }
        fprintf(fp, "%s   %s    %d    %d    %d    %d    %d\n", a1.name1, a1.type, a1.acc_number, a1.deposite, a1.withdraw, a1.transfer, a1.current_money);
    }
    fclose(fp1);
    fclose(fp);
    fclose(fp2);
    fp = fopen("temp.txt", "r");
    fp2 = fopen("bankrecord.txt", "w");
    while (fscanf(fp, "%s   %s    %d    %d    %d    %d    %d", a1.name1, a1.type, &a1.acc_number, &a1.deposite, &a1.withdraw, &a1.transfer, &a1.current_money) != EOF)
    {
        fprintf(fp2, "%s\t\t%s\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", a1.name1, a1.type, a1.acc_number, a1.deposite, a1.withdraw, a1.transfer, a1.current_money);
    }

    fclose(fp);
    fclose(fp2);
    nl();
    menu();
}
void transfer()
{
    FILE *fp2, *fp, *fp1;
    struct account a1, a2;
    time_t t;
     int acc;
    t = time(&t);
    char name[67];
    int transfer;
     char *name4;
    fp2 = fopen("bankrecord.txt", "r");
    fp = fopen("temp.txt", "w");
    printf("Enter the account of the user: ");
    scanf("%s", &acc);

    while (fscanf(fp2, "%s   %s    %d    %d    %d    %d   %d", a1.name1, a1.type, &a1.acc_number, &a1.deposite, &a1.withdraw, &a1.transfer, &a1.current_money) != EOF)
    {
        if (acc==a1.acc_number)
        {
            printf("Enter the amount to be tranfer: ");
            scanf("%d", &transfer);
            name4 = a1.name1;

            if (transfer <= a1.current_money)
            {
                a1.current_money -= transfer;
                a1.transfer += transfer;
                curr_money = a1.current_money;
            }
            else
            {
                printf("You have insuffient balance for transfer...............");
                menu();
            }
        }

        fprintf(fp, "%s   %s    %d    %d    %d    %d     %d\n", a1.name1, a1.type, a1.acc_number, a1.deposite, a1.withdraw, a1.transfer, a1.current_money);
    }
    fclose(fp);

    fclose(fp2);

    fp = fopen("temp.txt", "r");
    fp2 = fopen("bankrecord.txt", "w");
    while (fscanf(fp, "%s   %s    %d    %d    %d    %d    %d", a1.name1, a1.type, &a1.acc_number, &a1.deposite, &a1.withdraw, &a1.transfer, &a1.current_money) != EOF)
    {
        fprintf(fp2, "%s\t\t%s\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", a1.name1, a1.type, a1.acc_number, a1.deposite, a1.withdraw, a1.transfer, a1.current_money);
    }
    fclose(fp);
    fclose(fp2);

    fp1 = fopen("tran.txt", "a");
    fp2 = fopen("bankrecord.txt", "r");
    fp = fopen("temp.txt", "w");
    printf("Enter the account to which you want to tranfer: ");
    scanf("%d", &acc);

    while (fscanf(fp2, "%s   %s    %d    %d    %d    %d   %d", a1.name1, a1.type, &a1.acc_number, &a1.deposite, &a1.withdraw, &a1.transfer, &a1.current_money) != EOF)
    {
        if (acc == a1.acc_number)
        {
            a1.current_money += transfer;
            a1.deposite += transfer;

            fprintf(fp1, "\n====================================================\n");

            fprintf(fp1, "User name: %s has transfer the amount of %d on %s to account %ld, current balance left %d \n", name4, transfer, ctime(&t), a1.acc_number, curr_money);
            fprintf(fp1, "\n====================================================\n");
        }

        fprintf(fp, "%s   %s    %d    %d    %d    %d     %d\n", a1.name1, a1.type, a1.acc_number, a1.deposite, a1.withdraw, a1.transfer, a1.current_money);
    }
    fclose(fp);
    fclose(fp1);
    fclose(fp2);

    fp = fopen("temp.txt", "r");
    fp2 = fopen("bankrecord.txt", "w");
    while (fscanf(fp, "%s   %s    %d    %d    %d    %d    %d", a1.name1, a1.type, &a1.acc_number, &a1.deposite, &a1.withdraw, &a1.transfer, &a1.current_money) != EOF)
    {
        fprintf(fp2, "%s\t\t%s\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", a1.name1, a1.type, a1.acc_number, a1.deposite, a1.withdraw, a1.transfer, a1.current_money);
    }
    fclose(fp);
    fclose(fp2);

    nl();

    menu();
}

void menu()
{
    int choice;
    border();
    printf("*********MAIN MENU***********");
    border();
    printf("1.CREATE A NEW ACCOUNT\n");
    printf("2.ACCOUNT CURRENT INFORMATION\n");
    printf("3.DEPOSITE MONEY\n");
    printf("4.TRANSFER MONEY\n");
    printf("5.WITHDRAW MONEY\n");
    printf("6.DELETE ANY ACCOUNT\n");
    printf("7.UPDATE ACCOUNT\n");
    printf("8.LIST OF TOTAL ACCOUNTS IN THIS BANK\n");
    printf("9.EXIT");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        system("cls");
        new_acc();
        break;
    case 2:
        system("cls");
        search_account();
        break;
    case 3:
        system("cls");
        deposite();
        break;
    case 4:
        system("cls");
        transfer();
        break;
    case 5:
        system("cls");
        withdraw();
        break;
    case 6:
        system("cls");
        delet();
        break;
    case 7:
        system("cls");
        update();
    case 8:
        system("cls");
        name_list();
        break;
    case 9:
        exit(1);

    default:
        printf("wrong option try again\n");
    }
    menu();
}

void nl()
{
    printf("\n");
}
void border()
{
    printf("\n");
    for (int i = 1; i <= 10; i++)
    {
        printf("===");
    }
    printf("\n");
}

void withdraw()
{
    FILE *fp1, *fp2, *fp;
    struct account a1;
    time_t t;
    int acc;
    t = time(&t);
     char name[67];
    int withdraw;
    fp1 = fopen("tran.txt", "a");
    fp2 = fopen("bankrecord.txt", "r");
    fp = fopen("temp.txt", "w");
    printf("Enter the account number of user: ");
    scanf("%d", &acc);

    while (fscanf(fp2, "%s   %s    %d    %d    %d    %d   %d", a1.name1, a1.type, &a1.acc_number, &a1.deposite, &a1.withdraw, &a1.transfer, &a1.current_money) != EOF)
    {
        if (acc==a1.acc_number)
        {
            printf("Enter the amount to be withdraw: ");
            scanf("%d", &withdraw);
            if (withdraw <= a1.current_money)
            {
                a1.current_money -= withdraw;
                a1.withdraw += withdraw;
                fprintf(fp1, "\n====================================================\n");
                fprintf(fp1, "\n user name: %s has withdraw the amount of %d in %s , current balance in account is %d \n", a1.name1, withdraw, ctime(&t), a1.current_money);
                fprintf(fp1, "\n====================================================\n");
            }
            else
            {
                printf("insuffient balance");
            }
        }

        fprintf(fp, "%s   %s    %d    %d    %d    %d     %d\n", a1.name1, a1.type, a1.acc_number, a1.deposite, a1.withdraw, a1.transfer, a1.current_money);
    }
    fclose(fp);
    fclose(fp1);
    fclose(fp2);

    fp = fopen("temp.txt", "r");
    fp2 = fopen("bankrecord.txt", "w");
    while (fscanf(fp, "%s   %s    %d    %d    %d    %d    %d", a1.name1, a1.type, &a1.acc_number, &a1.deposite, &a1.withdraw, &a1.transfer, &a1.current_money) != EOF)
    {
        fprintf(fp2, "%s\t\t%s\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", a1.name1, a1.type, a1.acc_number, a1.deposite, a1.withdraw, a1.transfer, a1.current_money);
    }
    fclose(fp);
    fclose(fp2);
    nl();
    loading();
}
void update()
{
     int acc;
    struct account a1;
    char name[50];
    printf("Enter the user account number which you want to update:");
    scanf("%d", &acc);
    FILE *fp, *fp1;
    fp = fopen("bankrecord.txt", "r");
    fp1 = fopen("temp.txt", "w");
    while (fscanf(fp, "%s   %s    %d    %d    %d    %d   %d", a1.name1, a1.type, &a1.acc_number, &a1.deposite, &a1.withdraw, &a1.transfer, &a1.current_money) != EOF)
    {
        if (acc==a1.acc_number)
        {
            printf("Enter your new name to be updated\n");
            scanf("%s", a1.name1);
            printf("Enter your new account type\n");
            scanf("%s", a1.type);
            
            
        }
        fprintf(fp1, "%s   %s    %d    %d    %d    %d   %d\n", a1.name1, a1.type, a1.acc_number, a1.deposite, a1.withdraw, a1.transfer, a1.current_money);
    }
    fclose(fp);
    fclose(fp1);
    fp = fopen("bankrecord.txt", "w");
    fp1 = fopen("temp.txt", "r");
    while (fscanf(fp1, "%s   %s    %d    %d    %d    %d   %d", a1.name1, a1.type, &a1.acc_number, &a1.deposite, &a1.withdraw, &a1.transfer, &a1.current_money) != EOF)
    {
        fprintf(fp, "%s\t\t%s\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", a1.name1, a1.type, a1.acc_number, a1.deposite, a1.withdraw, a1.transfer, a1.current_money);
    }
    fclose(fp);
    fclose(fp1);
}
void delet()
{
    struct account a1;
    int acc;
    char name[50];
    int found = 0;
    printf("Enter the user account number which you want to delete:");
    scanf("%d",&acc);
    FILE *fp, *fp1;
    fp = fopen("bankrecord.txt", "r");
    fp1 = fopen("temp.txt", "w");
    while (fscanf(fp, "%s   %s    %d    %d    %d    %d   %d", a1.name1, a1.type, &a1.acc_number, &a1.deposite, &a1.withdraw, &a1.transfer, &a1.current_money) != EOF)
    {
        if (acc==a1.acc_number)
        {
            found = 1;
        }
        if (found == 0)
        {
            fprintf(fp1, "%s   %s    %d    %d    %d    %d   %d\n", a1.name1, a1.type, a1.acc_number, a1.deposite, a1.withdraw, a1.transfer, a1.current_money);
        }
        found = 0;
    }
    fclose(fp);
    fclose(fp1);
    fp = fopen("bankrecord.txt", "w");
    fp1 = fopen("temp.txt", "r");
    while (fscanf(fp1, "%s   %s    %d    %d    %d    %d   %d", a1.name1, a1.type, &a1.acc_number, &a1.deposite, &a1.withdraw, &a1.transfer, &a1.current_money) != EOF)
    {
        fprintf(fp, "%s\t\t%s\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", a1.name1, a1.type, a1.acc_number, a1.deposite, a1.withdraw, a1.transfer, a1.current_money);
    }
    fclose(fp);
    fclose(fp1);
}
void name_list()
{

    struct account a1;

    FILE *fp;
    fp = fopen("bankrecord.txt", "r");
    printf("NAME\t\tTYPE\t\tACC.NO\t\tDEPOSITE\t\tWITHDRAW\t\tTRANSFER\t\tCURRENT MONEY\n");
    while (fscanf(fp, "%s   %s    %d    %d    %d    %d   %d", a1.name1, a1.type, &a1.acc_number, &a1.deposite, &a1.withdraw, &a1.transfer, &a1.current_money) != EOF)
    {

        printf("%s\t\t%s\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", a1.name1, a1.type, a1.acc_number, a1.deposite, a1.withdraw, a1.transfer, a1.current_money);
    }
}
void loading()
{
    system("cls");

    char a = 177, b = 219;
    printf("\n\n\n\n");
    printf("\t");
    for (int i = 1; i <= 20; i++)
    {
        printf("%c", a);
    }
    printf("\r");
    printf("\t");
    for (int i = 1; i <= 20; i++)
    {
        printf("%c", b);
        Sleep(100);
    }

    system("cls");
}
