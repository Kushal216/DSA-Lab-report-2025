// Write a program to enter n numbers and sort according to 
// 1.	Bubble sort
// 2.	Insertion sort
// 3.	Selection sort
// 4.	Quick sort
// 5.	Merge sort
// 6.	Heap sort

#include<stdio.h>
#include<conio.h>
int i, j;
int Arr[] = {1, 4, 2, 3, 6, 7, 4, 9};
int BubbleSort(int n,int A[]){
    int temp;
    printf("Bubble:\n");
    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < n-1-i; j++)
        {
            if(A[j]>A[j+1]){
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
        printf("%d\t", A[i]);
    }
}
InsertionSort(int n, int A[]){
    int temp;
    printf("\nInsertion:\n");
    for ( i = 0; i < n; i++)
    {
        temp = A[i];
        j = i - 1;
        while((temp<A[j])&&j>=0)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = temp;
        printf("%d\t", A[i]);
    }
    
}
SelectionSort(int n, int A[]){
    printf("\nSelection:\n");
    for ( i = 0; i < n; i++)
    {
        int least = A[i];
        int index = i;
        for ( j = 0; j < n; j++)
        {
            if(A[j]<least)
            {
                least = A[j];
                index = j;
            }
        }
        if (i!=index)
        {
            int temp = A[i];
            A[i] = A[index];
            A[index] = temp;
        }
    }

    for ( i = 0; i < n; i++)
    {
         printf("%d\t", A[i]);
    }
    

}
int QuickSort(int A,int l,int r){
    int p;
    if(l<r){
        p = partion(A, l, r);
        QuickSort(A, l, p - 1);
        QuickSort(A, p+1, r);
        
    }
}


int main(){
    int n = 8;
    BubbleSort(n, Arr);
    InsertionSort(n, Arr);
    SelectionSort(n, Arr);
}

