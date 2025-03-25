// Write a program that uses functions to perform the following operations on circular linked List
// a) Creation
// b) Insertion
// 	1) Insertion at beginning
// 	2) Insertion at specified position
// 	3) Insertion at end
// c) Deletion
// 	1) Deletion from the beginning
// 	2) Deletion from the specified position
// 	3) Deletion from the end
// d) Traversal.
// e) Exit
#include <stdio.h>
#include <conio.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *next;
};
typedef struct node NODE;
NODE *start = NULL;
void insert_at_beg(int);
void insert_at_specific(int);
void insert_at_end(int);
void delete_at_beg();
void delete_at_specific();
void delete_at_end();
void traverse();

int main()
{
    int choice, item, yn;
    printf("Circular Linked List:\n"
           "1.  Creation\n"
           "2. Insertion \n"
           "\ta. Insertion at beginning\n"
           "\tb. Insertion at specified position\n"
           "\tc. Insertion at end\n"
           "3. Deletion \n"
           "\ta. Deletion from the beginning\n"
           "\tb. Deletion from the specified position\n"
           "\tc. Deletion from the end\n"
           "4. Traversal.\n"
           "5. Exit\n\n");
Yes:
    printf("Enter your choice:");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("Circular Linked List Successfully Created.\n");
        break;
    case 2:
        printf("Insertion on Circular Linked List\n");
        printf("\t21. Insertion at beginning\n"
               "\t22. Insertion at specified position\n"
               "\t23. Insertion at end\n");
    Y_ins:
        printf("Enter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 21:
            printf("Enter the item for Insertion at beginning of the Circular Linked List:");
            scanf("%d", &item);
            insert_at_beg(item);
            traverse();
            break;
        case 22:
            printf("Enter the item for Insertion at Specified Position of the Circular Linked List:");
            scanf("%d", &item);
            insert_at_specific(item);
            traverse();
            break;
        case 23:
            printf("Enter the item for Insertion at end of the Circular Linked List:");
            scanf("%d", &item);
            insert_at_end(item);
            traverse();
            break;
        default:
            printf("Your choice is wrong\n");
            break;
        }
        printf("\nDo you want to Enter the value again(1 for Yes/0 for No)?");
        scanf("%d", &yn);
        if (yn == 1)
        {
            goto Y_ins;
        }
        break;
    case 3:
        printf("Deletion on Circular Linked List\n");
        printf("\t31. Deletion at beginning\n"
               "\t32. Deletion at specified position\n"
               "\t33. Deletion at end\n");
    Y:
        printf("Enter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 31:
            printf("Deletion at beginning of the Circular Linked List.\n");
            delete_at_beg();
            traverse();
            break;
        case 32:
            printf("Deletion at Specified Position of the Circular Linked List.\n");
            delete_at_specific();
            traverse();
            break;
        case 33:
            printf("Deletion at end of the Circular Linked List.\n");
            delete_at_end();
            traverse();
            break;
        default:
            printf("Your choice is wrong\n");
            break;
        }
        printf("\nDo you want to Delete the value again(1 for Yes/0 for No)?");
        scanf("%d", &yn);
        if (yn == 1)
        {
            goto Y;
        }
        break;
    case 4:
        printf("Displaying all items on Circular Linked List\n");
        traverse();
        break;
    case 5:
        printf("Exiting from the Program...\n");
        printf("\n\n Program By: KUSHAL DHAKAL");
        break;
    default:
        printf("Your choice is wrong\n");
        break;
    }
    printf("\nDo you want to Perform other operation again(1 for Yes/0 for No)?");
    scanf("%d", &yn);
    if (yn == 1)
    {
        goto Yes;
    }
}

// Insert at Beginning
void insert_at_beg(int item)
{
    NODE *ptr = (NODE *)malloc(sizeof(NODE));
    ptr->data = item;
    if (start == NULL)
    {
        start = ptr;
        ptr->next = start;
    }
    else
    {
        NODE *temp = start;
        while (temp->next != start)
            temp = temp->next;
        ptr->next = start;
        temp->next = ptr;
        start = ptr;
    }
}

// Insert at Specific Position
void insert_at_specific(int item)
{
    int pos, i;
    NODE *temp = start, *ptr;
    printf("Enter position: ");
    scanf("%d", &pos);
    ptr = (NODE *)malloc(sizeof(NODE));
    ptr->data = item;
    for (i = 1; i < pos - 1; i++)
        temp = temp->next;
    ptr->next = temp->next;
    temp->next = ptr;
}

// Insert at End
void insert_at_end(int item)
{
    insert_at_beg(item);
    start = start->next;
}

// Delete at Beginning
void delete_at_beg()
{
    NODE *temp = start;
    while (temp->next != start)
        temp = temp->next;
    temp->next = start->next;
    free(start);
    start = temp->next;
}

// Delete at Specific Position
void delete_at_specific()
{
    int pos, i;
    NODE *temp = start, *ptr;
    printf("Enter position: ");
    scanf("%d", &pos);
    for (i = 1; i < pos - 1; i++)
        temp = temp->next;
    ptr = temp->next;
    temp->next = ptr->next;
    free(ptr);
}

// Delete at End
void delete_at_end()
{
    NODE *temp = start;
    while (temp->next->next != start)
        temp = temp->next;
    free(temp->next);
    temp->next = start;
}

// Display List
void traverse()
{
    if (start == NULL)
    {
        printf("List is Empty.\n");
        return;
    }
    NODE *temp = start;
    do
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    } while (temp != start);
    printf("\n");
}
