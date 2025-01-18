// Write a recursive program to find a Fibonacci sequence.
#include <stdio.h>
#include <conio.h>
int fibo(int);
int main()
{
    int num, i;
    printf("Enter the number to find the number of fabinacci sequence:");
    scanf("%d", &num);
    printf("Fibonacci series upto %dth term are:\n", num);
    for (i = 1; i <= num; i++)
    {
        printf("%d\t", fibo(i));
    }
}
int fibo(int n)
{
    if (n == 1 || n == 2)
    {
        return 1;
    }
    else
    {
        return fibo(n - 1) + fibo(n - 2);
    }
}
