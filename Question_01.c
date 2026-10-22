#include <stdio.h>

//--------------------------------------------

void welcome()
{
    printf("WELCOME \n");
}

//--------------------------------------------

void displayAmount(int Amount)
{
    printf("The WithDrawal amount is %d", Amount);
}

//---------------------------------------------

int getWithdrawalLimit()
{
    int max_limit = 5000;
    return max_limit;
}

//-------------------------------------------

int calculateBalance(int current_amount, int withdrawal)
{
    printf("The Current amount is %d", current_amount);
    int rem;
    rem = current_amount - withdrawal;
    return rem;
}

//------------------------------------------

int checkWithdrawal(int currentValue, int withdrawal)
{
    int max_limit = 5000;
    if (withdrawal <= max_limit && withdrawal <= currentValue)
    {
        int num = 1;
        return num;
    }
    else
    {
        int num = 0;
        return num;
    }
}

//---------------------------------------------------

int main()
{
    welcome();
    int Max_Limit = getWithdrawalLimit();
    printf("\nMax Limit %d\n", Max_Limit);

    int withdrawal;
    printf("\nwithdrawal Amount : ");
    scanf("\n%d", &withdrawal);
    displayAmount(withdrawal);

    int currentValue;
    printf("\n\nCurrent Amount  : ");
    scanf("%d", &currentValue);

    int rem = calculateBalance(currentValue, withdrawal);
    printf("\n\nRemaning value %d", rem);

    int num = checkWithdrawal(currentValue, withdrawal);
    printf("\nReturn value : %d", num);

    return 0;
}