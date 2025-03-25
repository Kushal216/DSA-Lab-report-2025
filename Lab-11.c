// Write a program that uses functions to perform the following operations on singly linked list
// a)  Creation
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
NODE *start;
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
    printf("Linked List:\n"
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
    printf("Linked List:\n"
           "1.  Creation\n"
           "2. Insertion \n"
           "3. Deletion \n"
           "4. Traversal.\n"
           "5. Exit\n\n");
    printf("Enter your choice:");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("Linked List Sucessfully Created.\n");
        break;
    case 2:
        printf("Insertion on Linked List\n");
        printf("\t21. Insertion at beginning\n"
               "\t22. Insertion at specified position\n"
               "\t23. Insertion at end\n");
    Y_ins:
        printf("Enter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 21:
            printf("Enter the item for Insertion at beginning of the Linked List:");
            scanf("%d", &item);
            insert_at_beg(item);
            traverse(start);

            break;
        case 22:
            printf("Enter the item for Insertion at Specified Position of the Linked List:");
            scanf("%d", &item);
            insert_at_specific(item);
            traverse(start);
            break;
        case 23:
            printf("Enter the item for Insertion at end of the Linked List:");
            scanf("%d", &item);
            insert_at_end(item);
            traverse(start);

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
        printf("Deletation on Linked List\n");
        printf("\t31. Deletion at beginning\n"
               "\t32. Deletion at specified position\n"
               "\t33. Deletion at end\n");
    Y:
        printf("Enter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 31:
            printf("Deletion at beginning of the Linked List.\n");
            delete_at_beg();
            traverse(start);
            break;
        case 32:
            printf("Deletion at Specified Position of the Linked List.\n");
            delete_at_specific();
            traverse(start);
            break;
        case 33:
            printf("Deletion at end of the Linked List.\n");
            delete_at_end();
            traverse(start);
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
        printf("Displaying all items on Linked List\n");
        traverse(start);
        break;
    case 5:
        printf("Exiting from the Program...\n");
        break;
    default:
        printf("Your choice is wrong\n");
        break;
    }
    printf("\nDo you want to Preform other operation again(1 for Yes/0 for No)?");
    scanf("%d", &yn);
    if (yn == 1)
    {
        goto Yes;
    }
    printf("\n\n Program By: KUSHAL DHAKAL");
}

// Insert at Beginning
void insert_at_beg(int item)
{
    NODE *ptr;
    ptr = (NODE *)malloc(sizeof(NODE));
    ptr->data = item;
    if (ptr == NULL)
    {
        ptr->next = NULL;
    }
    else
    {
        ptr->next = start;
        start = ptr;
    }
}

// Insert at Specific Position
void insert_at_specific(int item)
{
    int i, pos;
    NODE *temp, *ptr;
    temp = start;
    printf("Enter the position of the node that you want to insert a new node:");
    scanf("%d", &pos);
    for (i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
        if (temp == NULL)
        {
            printf("There is less than %d elements.", pos);
            return;
        }
    }
    ptr = (NODE *)malloc(sizeof(NODE));
    ptr->next = temp->next;
    ptr->data = item;
    temp->next = ptr;
}

// Insert at end
void insert_at_end(int item)
{
    NODE *locat, *ptr;
    ptr = (NODE *)malloc(sizeof(NODE));
    ptr->data = item;
    ptr->next = NULL;
    if (start == NULL)
    {
        start = ptr;
    }
    else
    {
        locat = start;
        while (locat->next != NULL)
        {
            locat = locat->next;
        }
    }
    locat->next = ptr;
}

// deleting at Beginning
void delete_at_beg()
{
    NODE *temp;
    if (start == NULL)
    {
        printf("List is Empty.");
        return;
    }
    else
    {
        temp = start;
        printf("Deleted First element.........\n");
        start = temp->next;
    }
}

// Deleting at Specific Position
void delete_at_specific()
{
    int i, pos;
    NODE *temp, *ptr;
    if (start == NULL)
    {
        printf("List is Empty.");
        return;
    }
    else
    {
        temp = start;
        printf("Enter the position of the node that you want to delete a new node:");
        scanf("%d", &pos);
        for (i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        ptr = temp->next;
        temp->next = ptr->next;
        free(ptr);
        printf("Deleted %dth element.........\n", pos);
    }
}
// Deleting at end
void delete_at_end()
{
    NODE *temp, *ptr;
    if (start == NULL)
    {
        printf("List is Empty.");
        return;
    }
    else if (start->next == NULL)
    {
        ptr = start;
        start = NULL;
        free(ptr);
    }
    else
    {
        temp = start;
        while (temp->next->next != NULL)
            temp = temp->next;
        ptr = temp->next;
        temp->next = NULL;
        free(ptr);
        printf("Deleted Last element.........\n");
    }
}

// Displaying the items
void traverse()
{
    NODE *temp;
    if (start == NULL)
    {
        printf("List is Empty.");
        return;
    }
    temp = start;
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
}