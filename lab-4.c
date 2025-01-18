// Write a program to convert Infix Expression into Prefix Expression.
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
int prec(char);
void main()
{
    int i, op = -1, pre = -1;
    char pre_stack[100], op_stack[100];
    //  char equ[100],pre_stack[100], op_stack[100];
    //   printf("Enter the valid Equation:");
    //   gets(equ);
    // char equ[] = "(A+B*C$D)/((E+F-G)*H)$I/J";
    char equ[] = "(A+B*C/D)*(E-F/G)";
    int length = strlen(equ);
    for (i = length - 1; i >= 0; i--)
    {
        if (equ[i] == ')')
        {
            op_stack[++op] = equ[i];
        }
        else if (isalpha(equ[i]))
        {
            pre_stack[++pre] = equ[i];
        }
        else if (equ[i] == '(')
        {

            while (op >= 0 && op_stack[op] != ')')
            {
                pre_stack[++pre] = op_stack[op--];
            }
            op--;
        }
        else
        {
            while (op >= 0 && prec(op_stack[op]) > prec(equ[i]))
            {
                pre_stack[++pre] = op_stack[op--];
            }
            op_stack[++op] = equ[i];
        }
    }
    while (op >= 0)
    {
        pre_stack[++pre] = op_stack[op--];
    }
    printf("The Prefix Expression is: ");
    for (i = length; i >=0; i--)
    {
        printf("%c", pre_stack[i]);
    }
    getch();
}

int prec(char ch)
{
    switch (ch)
    {
    case '$':
        return (4);
    case '*':
    case '/':
        return (3);
    case '-':
    case '+':
        return (2);
    default:
        return 0;
    }
}
