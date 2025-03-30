/*Write a menu driven program to illustrate basic operations of stack using array.
a) Push
b) Pop
c) Traverse
d) Exit */

// #include<stdio.h>
// #include<conio.h>
// #define MAXSIZE 10
// int stack[MAXSIZE];
// int top=-1;
// void stack_push(int val, int n)
//{
//	if(n==MAXSIZE)
//	{
//		printf("Stack is Full");
//	}
//	else
//	{
//		n=n+1;
//		stack[n]=val;
//		printf("%d sucessfully on the top of the stack. ",stack[n]);
//	}
// }
// void stack_pop(int n)
//{
//	if(n==-1)
//	{
//		printf("Stack is Empty");
//	}
//	else
//	{
//		printf("%d sucessfully on the top of the stack. ",stack[n]);
//		n--;
//	}
// }
// void stack_traverse(int n)
//	{
//		if(n==-1)
//		{
//			printf("Stack is Empty");
//		}
//		else
//		{
//			int i;
//			for(i=n;i>=0;i--)
//			{
//				printf("%d\t", stack[i]);
//			}
//			printf("\nTraverse Sucessfully. ");
//		}
//	}
//
// int main()
//{
//     int c,val,n;
//     stack[5]=22;
//     printf("Enter the current position of the stack:");
//     scanf("%d",&n);
//     printf("*****************************************************\n");
//     printf("Write a menu driven program to illustrate basic operations of stack using array.\n  1. Push\n  2. Pop\n  3. Traverse\n  4. Exit\n" );
//	printf("Enter your choice:");
//     scanf("%d",&c);
//     switch (c)
//     {
//     	case 1:
//     		{
//     			printf("Enter the value to be Push in the top of the stack:");
//     			scanf("%d",&val);
//				stack_push(val,top);
//     			break;
//			}
//		case 2:
//     		{
//     			stack_pop(n);
//     			break;
//			}
//		case 3:
//     		{
//				stack_traverse(n);
//				break;
//			}
//		case 4:
//     		{
//     			printf("Exiting from the program......\n");
//     			break;
//			}
//		default:
//			{
//				printf("You Enter the wrong choice!!!");
//			}
//	}
// }

#include <stdio.h>
#include <conio.h>
#define SIZE 100
int i;
int stack[SIZE], tos = -1, n;
void push();
void pop();
void display();
int main()
{
    int choice = 0;
    printf("Enter the number of elements in the stack: ");
    scanf("%d", &n);
    printf("\tStack Operations Using Array\n");
    printf("-----------------------------------------------------\n");
    while (choice != 4)
    {
        printf("Choose any one option from below...\n");
        printf("1) Push\n2) Pop\n3) Traverse\n4) Exit\n");
        // choice = choice+4;
        printf("\nYour Choice? ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting....");
            break;

        default:
            printf("Please enter the Valid Choice!!\n\n");
            break;
        }
    }
    printf("\nProgram By: KUSHAL DHAKAL");
    return 0;
}
void push()
{
    int val;
    if (tos == n - 1)
    {
        printf("The Stack is Full\n\n");
    }
    else
    {
        printf("Enter the value to be pushed: ");
        scanf("%d", &val);
        tos++;
        stack[tos] = val;
        printf("Value Pushed!!\n");
        printf("\n");
    }
}
void pop()
{
    if (tos == -1)
    {
        printf("Stack is Empty!!\n\n");
    }
    else
    {
        printf("The popped element is: %d\n", stack[tos]);
        tos--;
        printf("\n");
    }
}
void display()
{
    for (i = tos; i >= 0; i--)
    {
        printf("stack[%d] = %d\n", i, stack[i]);
    }
    printf("\n");
    if (tos == -1)
    {
        printf("Stack Empty!!\n\n");
    }
}
