// Write a program to implement binary search.
#include <stdio.h>
#include <conio.h>
int i, j;
int BinarySearch(int A[], int l, int r, int key)
{
    int m, flag = 0;
    if (l <= r)
    {
        m = (l + r) / 2;
        if (key == A[m])
            flag = m;
        else if (key < A[m])
            return BinarySearch(A, l, m - 1, key);
        else
            return BinarySearch(A, m + 1, r, key);
    }
    else
        return flag;
}
int main()
{
    printf("Linear Search Algorithm\n");
    // int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // int size = sizeof(arr) / sizeof(arr[0]);
    int key, temp, flag, n,arr[100];
    printf("Enter the number of elements in array: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf(" Enter the value of Key: ");
    scanf("%d", &key);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    flag = BinarySearch(arr, 0, n - 1, key);
    if (flag == 0)
        printf("%d is not found in array.", key);
    else
    {
        printf("%d is found in array at position %d.", key, flag + 1);
    }
    printf("\n\n Program By: KUSHAL DHAKAL");
    getch();
}
