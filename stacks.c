#include <stdio.h>

#define SIZE 50
int stack_arr[SIZE];
int top = -1;

void push(int c)
{
    if(top!= SIZE-1)
        stack_arr[++top]=c;
    else
        printf("Stack Overflow\n");
}

int pop()
{
    if(top!=-1)
        return stack_arr[top--];
    else
    {
        printf("Stack Underflow\n");
        return NULL;
    }
        
}

void display()
{
    int i;
    printf("Stack is:\n---Top------\n");
    for( i=top;i>=0;i--)
        printf("%d\n",stack_arr[i]);
    printf("---Bottom---\n");
}

void main()
{
    int ch,elem;

    do
    {
        printf("\n1.Push Element to Stack\n2.Pop Element from Stack\n3.Display Stack\n0.Exit Program\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter element to push:");
                    scanf("%d",&elem);
                    push(elem);
                    break;

            case 2: elem=pop();
                    if(elem != NULL)
                        printf("Popped Element:%d\n",elem);
                    break;
            
            case 3: display();
                    break;

            case 0: printf("Exited Program\n");
                    break;

            default:printf("Invalid Input! Please try again!\n");

        }
    }while(ch);
}