// Write a program to convert Infix Expression into Postfix Expression.
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
int prec(char);
void main()
{
  int i, op = -1, po = -1;
  char equ[100], po_stack[100], op_stack[100];
  printf("Enter the valid Equation:");
  gets(equ);
  // char equ[] = "(A+B*C$D)/((E+F-G)*H)$I/J";
  //  char equ[] = "(A+B*C/D)*(E-F/G)";
  int length = strlen(equ);
  for (i = 0; i < length; i++)
  {
    if (equ[i] == '(')
    {
      op_stack[++op] = equ[i];
    }
    else if (isalpha(equ[i]))
    {
      po_stack[++po] = equ[i];
    }
    else if (equ[i] == ')')
    {

      while (op >= 0 && op_stack[op] != '(')
      {
        po_stack[++po] = op_stack[op--];
      }
      op--;
    }
    else
    {
      while (op >= 0 && prec(op_stack[op]) >= prec(equ[i]))
      {
        po_stack[++po] = op_stack[op--];
      }
      op_stack[++op] = equ[i];
    }
  }
  while (op >= 0)
  {
    po_stack[++po] = op_stack[op--];
  }
  po_stack[++po] = '\0';
  printf("The Postfix Expression is: %s", po_stack);
  printf("\n\nProgram By: KUSHAL DHAKAL");
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
