#include <stdio.h>
#include <stdlib.h>
#define MAX 50
int queue_array[MAX];
int rear = -1;
int front = -1;

void insert(int ele)
{

    if (rear == MAX - 1)
        printf("Queue Overflow \n");
    else
    {
        if (front == -1)
        {
            front = 0;
        }

        rear = rear + 1;
        queue_array[rear] = ele;
    }
}
int delete ()
{
    if (front == -1 || front > rear)
    {
        printf("Queue Underflow \n");
        return NULL;
    }
    else
    {
        return(queue_array[front++]);
    }
}
void display()
{
    int i;
    if (front == -1)
        printf("Queue is empty \n");
    else
    {
        printf("Queue is : \n");
        for (i = front; i <= rear; i++)
            printf("%d ", queue_array[i]);
        printf("\n");
    }
}
void main()
{
    int ch,elem;

    do
    {
        printf("\n1.Insert Element to queue\n2.Delete Element from queue\n3.Display Queue\n0.Exit program\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter element to insert:");
                    scanf("%d",&elem);
                    insert(elem);
                    break;

            case 2: elem=delete();
                    if(elem != NULL)
                        printf("Deleted Element:%d\n",elem);
                    break;
            
            case 3: display();
                    break;

            case 0: printf("Exited Program\n");
                    break;

            default:printf("Invalid Input! Please try again!\n");
        }
    }while(ch);
}