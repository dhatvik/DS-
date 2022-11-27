#include<stdio.h>

#define SIZE 5


void enQueue();
void deQueue();
void display();

int myCQ[SIZE]; //Array implementation of Circular Queues


int front = -1;
int rear = -1;


int element;

int main()
{
    int choice;
   
    while(1){
        printf("\n****** CIRCULAR Q MENU ******\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:enQueue();
            break;
            case 2: deQueue();
            break;
            case 3: display();
            break;
            case 4: exit(0);
            default: printf("\nPlease select the correct choice!!!\n");
        }
    }
}
void enQueue()
{
    printf("\nEnter the value to be inserted:  ");
    scanf("%d",&element);
    
    printf("\n ***In enQueue entry*** front %d rear %d", front, rear); /*These statements are for your understanding to note the values of "front" and "rear". Use for tracing in record book*/
    
    if((front == 0 && rear == SIZE - 1) || (front == rear+1))
    printf("\nSorry - Circular Queue is Full, therefore Insertion not possible!\n");
    
    else
    {
        if(rear == SIZE-1 && front != 0) //Note difference with "(front == 0 && rear == SIZE - 1)" which means Q is FULL!
        rear = -1;
        
        //NOTE: "rear" is pre-incremented. It always points to current array index for enqueing
        myCQ[++rear] = element;
        printf("\nInserted %d Successfully!\n", myCQ[rear]);
        
        //Very first case, when Q is initially empty 
        if(front == -1)
        front = 0;
    }//end else
    
    printf("\n ***In enQueue exit*** front %d rear %d", front, rear); /*These statements are for your understanding to note the values of "front" and "rear". Use for tracing in record book */
}//end enQueue

void deQueue()
{
    printf("\n ***In deQueue entry*** front %d rear %d", front, rear); /*These statements are for your understanding to note the values of "front" and "rear". Use for tracing in record book */
    
    if(front == -1 && rear == -1)
    printf("\nCircular Queue is Empty. Therefore deletion is not possible!\n");
    
    else
    {
        
        element = myCQ[front++];
     
        printf("\nDeleted element is : %d\n",element);
        
        
        if(front-1 == rear)
        front = rear = -1;
        
        
        if(front == SIZE )
            front = 0;
    }//end else
    
    printf("\n ***In deQueue exit*** front %d rear %d", front, rear);/*These statements are for your understanding to note the values of "front" and "rear". Use for tracing in record book */
}//end deQueue

void display()
{
    if(front == -1)
    printf("\nCircular Queue is Empty!\n");
    else
    {
        int i;
        printf("\nCircular Queue Elements are : \n");
        if(front <= rear)
        {
            /* This is the condition when first enQueue happens, then deQueue. Meaning enQueue & deQueue donot happen parallely. This means "front <= rear" always. */
            for (i=front; i <= rear; i++)
            printf("%d\t",myCQ[i]);
        }
        else
        {
            /* This is the condition when "front > rear". This happens when enQueue and deQueue happens parallely. */
            
            for (i = 0;i <= rear; i++) /*Start from the beginning of the Circular Queue which was deQueued meaning "rear" was re-initialized to "-1" and print the elements inserted. */
            printf("%d\t",myCQ[i]);
            
            for (i = front;i <= SIZE - 1; i++) /*Start from the position of "front" when previous deQueing stopped */
            printf("%d\t", myCQ[i]);
            
            
        }
    }
}//end display
