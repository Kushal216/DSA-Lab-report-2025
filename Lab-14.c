// Write a program to implement linear search.
#include <stdio.h>
#include <conio.h>
int i;
LinerSearch(int key, int n, int Arr[]) {
  int temp=0;
  for ( i = 0; i < n; i++)
  {
    if (key == Arr[i]) {
      printf("%d is found in array.",key);
      temp = 1;
      break;
    }
  }
  if (temp != 1) {
    printf("%d is not found in array.",key);
  }
}


int main() {
    int A[] = {1, 2, 4, 6, 5, 9, 11};
    int size = sizeof(A) / sizeof(A[0]);
    int key;
    printf("Enter the number to search in the array:");
    scanf("%d",&key);

  LinerSearch(key, size, A );
}
