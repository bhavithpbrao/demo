#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#define SIZE 50
char stack_arr[SIZE];
int top = -1;

void push(char c)
{
    stack_arr[++top]=c;
}

char pop()
{
    return stack_arr[top--];
}

bool isEmpty()
{
    if(top == -1)
        return true;
    else
        return false;
}

int priority(char sym)
{
    if(sym == '^')
        return (3);
    else if(sym == '*'||sym == '/'||sym == '%')
        return (2);
    else if(sym == '+'||sym == '-')
        return (1);
    else
        return (0);
}

void main()
 {
    char infix[50],postfix[50],elem,ch;
    int i=0,k=0;
    printf("Enter infix expression:");
    scanf("%s",infix);
    while((ch=infix[i++])!='\0')
    {
        //printf("ch:%c\nstack_arr:%s\npostfix:%s\n",ch,stack_arr,postfix);
        if(ch=='(')
            push(ch);
        else if(isalnum(ch))   
            postfix[k++]=ch;
        else if(ch==')')
        {
            while(stack_arr[top]!='(')
            {
                postfix[k++]=pop();
            }
            elem=pop();
        }
        else
        {
            while(priority(stack_arr[top])>=priority(ch))
                postfix[k++]=pop();
            push(ch);
        }
    } 
    
    //printf("ch:%c\nstack_arr:%s\npostfix:%s\n",ch,stack_arr,postfix);
    while(!isEmpty())
        postfix[k++]=pop();
    postfix[k]='\0';
    //printf("ch:%c\nstack_arr:%s\npostfix:%s\n",ch,stack_arr,postfix);
    printf("Postfix Expression:%s\n",postfix);  
 }