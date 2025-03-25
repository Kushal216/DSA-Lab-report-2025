// Write a program to implement the hashing techniques.
#include <stdio.h>
#include <stdlib.h>

#define t_size 10 // Size of the hash table

int h_tab[t_size]; // Hash table
int EMPTY = -1;            // Marker for empty slots

// Hash function: simple modulo operation
int hashing(int key)
{
    return key % t_size;
}

// Insert function using linear probing
void insert(int key)
{
    int ind = hashing(key);

    // Linear probing in case of collision
    while (h_tab[ind] != EMPTY)
    {
        ind = (ind + 1) % t_size; // Move to the next slot
    }
    h_tab[ind] = key;
    printf("Element Inserted!!\n\n");
}

// Search function
int search(int key)
{
    int ind = hashing(key);
    int start = ind; // Keep track of original position

    while (h_tab[ind] != EMPTY)
    {
        if (h_tab[ind] == key)
            return ind; // Found key at ind
        ind = (ind + 1) % t_size;
        if (ind == start)
            break; // Stop if we complete one full cycle
    }
    return -1; // Not found
}

// Display function
void display()
{
    printf("\nHash Table:\n");
    for (int i = 0; i < t_size; i++)
    {
        if (h_tab[i] == EMPTY)
            printf("[%d] --> Empty\n", i);
        else
            printf("[%d] --> %d\n", i, h_tab[i]);
    }
}

// Main function
int main()
{
    // Initialize hash table with empty values
    for (int i = 0; i < t_size; i++)
        h_tab[i] = EMPTY;
    printf("Hashing Program with Linear Probing\n");
    int choice, key;
    while (choice != 4)
    {
        printf("Choose any one:-\n");
        printf("1) Insert element in Hash Table\n2) Search element in Hash Table\n3) Display the Hash Table\n4) Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element to be inserted: ");
            scanf("%d", &key);
            insert(key);
            break;
        case 2:
            printf("Enter which element to search: ");
            scanf("%d", &key);
            int ind = search(key);
            if (ind != -1)
                printf("Element %d found at ind %d\n\n", key, ind);
            else
                printf("Element %d not found\n\n", key);
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice! Try again.\n");
        }
    }
    printf("\n\n Program By: KUSHAL DHAKAL");
    return 0;
}