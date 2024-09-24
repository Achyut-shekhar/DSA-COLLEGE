#include<stdio.h>
#define max 100
#include<math.h>
#include<string.h>
void push(int [],int,int *);
int pop(int [],int *);
int  main()
{
    int stack[max],i=0,x,y,val,top=-1,res;
    char post[max],ch;
    printf("\n enter the postfix:-");
    fgets(post,max,stdin);
    while(post[i]!='\0'&&post[i]!='\n')
    {
        ch=post[i++];
        if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))
        {
            printf("\ninput the value operant %c:-\t",ch);
            scanf("%d",&val);
            push(stack,val,&top);
        }
        else 
        {
            x=pop(stack,&top);
            y=pop(stack,&top);
            if(ch=='^')
            {
                
                push(stack,(int)pow(y,x),&top);
            }
            else if(ch=='/')
            {
                
                push(stack,y/x,&top);
            }
            else if(ch=='+')
            {
                
                push(stack,y+x,&top);
            }
            else if(ch=='-')
            {
                
                push(stack,y-x,&top);
            }
            else if(ch=='*')
            {
                
                push(stack,y*x,&top);
            }
        }
        
    }
    printf("\nthe result of the value is:-\t%d",stack[top]);
    return 0;
}

void push(int stack[],int x,int *top)
{
   if(*top==max-1)
		puts("Stack overflow");
	else
		stack[++(*top)]=x;
}
int pop(int stack[],int *top)
{
    if(*top==-1)
		puts("Underflow");
	else 
		return stack[(*top)--];
}