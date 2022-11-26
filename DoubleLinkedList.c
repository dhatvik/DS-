#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int number;
    struct node *next;
}*head,*newNode,*tail,*searchptr,*pointer, *after, *before;

//after: To find the node to insert / delete after. That is: before = searchptr->next;
//before: To find the node to insert / delete before. That is after = searchptr->prev;
//newNode: Pointer to the new node created
//searchptr: Pointer having the address of the node whose number is searched
//pointer: Used in print function to start printing from the head
//tail: Always points to last node. tail->next is NULL
//head: Always points to beginning. head->prev = NULL

int count = 0;//To count the number of nodes created

/* Generic function to create a new node */
void createNewNode()
{
    int data;
    
    newNode =(struct node *)malloc(1*sizeof(struct node));
    newNode->prev = NULL;
    newNode->next = NULL;
    printf("\n Enter number to create new node : ");
    scanf("%d", &data);
    newNode->number = data;
    count++;
}

/*  TO insert at beginning */
void insertBegin()
{
    if (head == NULL)
    {
        createNewNode();
        head = newNode;
        tail = head;
    }
    else
    {
        createNewNode();
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}//end insertBegin

/* To insert at end */
void insertEnd()
{
    if (head == NULL)
    {
        createNewNode();
        head = newNode;
        tail = head;
    }
    else
    {
        createNewNode();
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}//end insertEnd

/* Function to insert before a number searched */
void insertBefore()
{
    after = searchptr->prev;
    
    if(searchptr == head)
    {
        printf("\n Inserting before the head node...");
        insertBegin();
    }
    else
    {
        if(searchptr == tail) printf("\n Inserting before tail node...");
        else printf("\n Inserting after %d and before %d", after->number, searchptr->number);
        createNewNode();
        searchptr->prev = newNode;
        newNode->next = searchptr;
        after->next = newNode;
        newNode->prev = after;
    }
    
}//end insertBefore

/* Function to insert after a number searched */
void insertAfter()
{
    before = searchptr->next;
    
    if(searchptr == tail)
    {
        printf("\n Inserting after the tail node...");
        insertEnd();
    }
    else
    {
        if(searchptr == head) printf("\n Inserting after head node...");
        else printf("\n Inserting after %d and before %d",searchptr->number, before->number);
        createNewNode();
        searchptr->next = newNode;
        newNode->prev = searchptr;
        before->prev = newNode;
        newNode->next = before;
    }
    
}//end insertBefore

/* Print from beginning */
void printAll()
{
    pointer = head;
    
    if (pointer == NULL)
    {
        printf("List empty to display \n");
        return;
    }
    printf("\n Linked list elements from begining : ");
    
    while (pointer->next != NULL)
    {
        printf(" %d ", pointer->number);
        pointer = pointer->next;
    }
    printf(" %d ", pointer->number);
}//end printAll

/* Search for a number*/
struct node * mysearch(int data)
{
    int position = 0;
    searchptr = head;
    
    if (searchptr == NULL)
    {
        printf("\n Error : List empty to search for data");
        return NULL;
    }
    
    while (searchptr != NULL)
    {
        if (searchptr->number == data)
        {
            printf("\n Data found in %d position ",position + 1);
            return searchptr;
        }
        else
            searchptr = searchptr->next;
        position++;
    }
    return NULL;
}//end mysearch

/* Function to
 --- delete node at beginning
 --- delete node for a given number
 --- delete node at end
 */
void deleteNode()
{
    pointer = head;

        if(searchptr == head)
        {
            head = searchptr->next;
            free(searchptr);
            return;
        }
        if(searchptr == tail)
        {
            tail = searchptr->prev;
            tail->next = NULL;
            free(searchptr);
            return;
        }
    
            before = searchptr->next;
            after = searchptr->prev;
            before->prev = after->next;
            after->next = before;
            free(searchptr);
            return; 
    
}//end deleteNode

int main()
{
    int ch;
    
    head = NULL;
    newNode = NULL;
    tail = NULL;
    searchptr = NULL;
    int data;
    
    printf("\n 1 - Insert at beginning of doubly linked list");
    printf("\n 2 - Insert at end of doubly linked list");
    printf("\n 3 - Insert before a number of doubly linked list");
    printf("\n 4 - Insert after a number of doubly linked list");
    printf("\n 5 - Search for a number in doubly linked list");
    printf("\n 6 - Delete a number in doubly linked list");
    printf("\n 7 - Display the doubly linked list");
    printf("\n -1 - Quit");
    
    while (1)
    {
        printf("\n Enter choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
                insertBegin();printAll();
                break;
            case 2:
                insertEnd();printAll();
                break;
            case 3:printf("\n Enter number to insert before : ");
                scanf("%d", &data);
                searchptr = mysearch(data);
                if(searchptr != NULL)
                {
                    insertBefore();printAll();
                }
                else printf("\n Number %d not found to insert before!!", data );
                break;
            case 4:
                printf("\n Enter number to insert after : ");
                scanf("%d", &data);
                searchptr = mysearch(data);
                if(searchptr != NULL)
                {
                    insertAfter();printAll();
                }
                else printf("\n Number %d not found to insert after!!", data );
                break;
            case 5:printf("\n Enter element to search : ");
                scanf("%d", &data);
                searchptr = mysearch(data);
                if(searchptr == NULL) printf("\n Number %d not found!!", data );
                else printf("\n %d number found!!",searchptr->number );
                break;
            case 6:
                printf("\n Enter number to delete: ");
                scanf("%d", &data);
                searchptr = mysearch(data);
                if(searchptr != NULL)
                {
                    deleteNode();printAll();
                }
                else printf("\n Number %d not found to delete!!", data );
                break;
            case 7:
                printAll();
                break;
            case -1:
                exit(0);
            default:
                printf("\n Wrong choice menu");
        }//end switch
    }//end while
}//end main


