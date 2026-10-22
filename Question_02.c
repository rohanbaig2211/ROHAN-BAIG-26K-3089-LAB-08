#include <stdio.h>
 
//-----------------------------------------------------

void welcome()
{
    printf("Welcome to Shopping Mart\n\n");
}
 

//----------------------------------------------

void showMenu()
{
    printf("Products:\n");
    printf("1. Rice    - 12.50\n");
    printf("2. Milk    - 4.25\n");
    printf("3. Bread   - 3.00\n");
    printf("4. Eggs    - 6.75\n");
    printf("5. Oil     - 15.00\n");
}
 
//-------------------------------------------------------

float getPrice(int p)
{
    if (p == 1)
        return 12.50;
    else if (p == 2)
        return 4.25;
    else if (p == 3)
        return 3.00;
    else if (p == 4)
        return 6.75;
    else
        return 15.00;
}
 
//----------------------------------------------------

float itemPrice(float price, int qty)
{
    return price * qty;
}
 
//---------------------------------------------------

float calcSubtotal(int qty[])
{
    int i;
    float sum = 0;
    for (i = 0; i < 5; i++)
    {
        sum = sum + itemPrice(getPrice(i + 1), qty[i]);
    }
    return sum;
}
 
//--------------------------------------------------------

float calcDiscount(float subtotal)
{
    if (subtotal >= 100)
        return subtotal * 0.10;
    else
        return 0;
}

 //-----------------------------------------------------------

float calcFinal(float subtotal, float discount)
{
    return subtotal - discount;
}
 
//--------------------------------------------------------

void showReceipt(int qty[], float subtotal, float discount, float final)
{
    int i;
    printf("\n----- RECEIPT -----\n");
    printf("Product  Qty  Price  Total\n");
    for (i = 0; i < 5; i++)
    {
        if (qty[i] > 0)
        {
            printf("%d        %d    %.2f  %.2f\n", i + 1, qty[i], getPrice(i + 1), itemPrice(getPrice(i + 1), qty[i]));
        }
    }
    printf("Subtotal: %.2f\n", subtotal);
    printf("Discount: %.2f\n", discount);
    printf("Final Bill: %.2f\n", final);
}
 
//----------------------------------------------------------

int askContinue()
{
    char ch;
    printf("\nContinue shopping? (y/n): ");
    scanf(" %c", &ch);
    if (ch == 'y')
        return 1;
    else
        return 0;
}
 
//------------------------------------------------------

int main()
{
    int qty[5];
    int i, p, q;
    char more;
    float subtotal, discount, final;
    int again = 1;
 
    welcome();
 
    while (again == 1)
    {
        for (i = 0; i < 5; i++)
        {
            qty[i] = 0;
        }
 
        do
        {
            showMenu();
            printf("Enter product number: ");
            scanf("%d", &p);
            printf("Enter quantity: ");
            scanf("%d", &q);
 
            if (p >= 1 && p <= 5 && q > 0)
            {
                qty[p - 1] = qty[p - 1] + q;
            }
            else
            {
                printf("Invalid input\n");
            }
 
            printf("Add more products? (y/n): ");
            scanf(" %c", &more);
        } while (more == 'y');
 
        subtotal = calcSubtotal(qty);
        discount = calcDiscount(subtotal);
        final = calcFinal(subtotal, discount);
 
        showReceipt(qty, subtotal, discount, final);
 
        again = askContinue();
    }
 
    printf("Thank you!\n");
    return 0;
}