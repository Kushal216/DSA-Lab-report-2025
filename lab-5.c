// Write a recursive program to find the factorial value of given number.
#include <stdio.h>
#include <conio.h>
long int factorial(int);
int main()
{
    int num;
    long int fact;
    printf("Enter the number to find the factorial of the number: ");
    scanf("%d", &num);
    fact = factorial(num);
    printf("Factorial of %d is: %ld", num, fact);
    getch();
}
long int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}
