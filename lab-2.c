/*Write a menu driven program to illustrate basic 
operations of stack using array. 
a) Push 
b) Pop 
c) Traverse 
d) Exit */

#include<stdio.h>
#include<conio.h>
#define MAXSIZE 10
int stack[MAXSIZE];
int top=-1;
void stack_push(int val, int n)
{
	if(n==MAXSIZE)
	{
		printf("Stack is Full");
	}
	else
	{
		n=n+1;
		stack[n]=val;
		printf("%d sucessfully on the top of the stack. ",stack[n]);
	}
}
void stack_pop(int n)
{
	if(n==-1)
	{
		printf("Stack is Empty");
	}
	else
	{
		printf("%d sucessfully on the top of the stack. ",stack[n]);
		n--;
	}
}
void stack_traverse(int n)
	{
		if(n==-1)
		{
			printf("Stack is Empty");
		}
		else
		{
			int i;
			for(i=n;i>=0;i--)
			{
				printf("%d\t", stack[i]);
			}
			printf("\nTraverse Sucessfully. ");
		}
	}

int main()
{
    int c,val,n;
    stack[5]=22;
    printf("Enter the current position of the stack:");
    scanf("%d",&n);
    printf("*****************************************************\n");
    printf("Write a menu driven program to illustrate basic operations of stack using array.\n  1. Push\n  2. Pop\n  3. Traverse\n  4. Exit\n" );
	printf("Enter your choice:");
    scanf("%d",&c);
    switch (c)
    {
    	case 1:
    		{
    			printf("Enter the value to be Push in the top of the stack:");
    			scanf("%d",&val);
				stack_push(val,top);
    			break;
			}
		case 2:
    		{
    			stack_pop(n);
    			break;
			}	
		case 3:
    		{
				stack_traverse(n);
				break;
			}
		case 4:
    		{
    			printf("Exiting from the program......\n");
    			break;
			}
		default:
			{
				printf("You Enter the wrong choice!!!");
			}			
	}
}

