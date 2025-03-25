// Write a recursive program to find GCD of two integers.
#include <stdio.h>
#include<conio.h>


int gcd(int a, int b) {
    if (b == 0)
        return a; 
    return gcd(b, a % b); 
}
int main() {
    int x, y;
    printf("Enter two +ve numbers: ");
    label:
    scanf("%d %d", &x, &y);
    if (x<0||y<0)
    {
        printf("Please enter Valid numbers: ");
        goto label;
    }
    printf("GCD of %d and %d is %d\n", x, y, gcd(x, y));
    printf("\n\nProgram By: KUSHAL DHAKAL");
    return 0;
}

