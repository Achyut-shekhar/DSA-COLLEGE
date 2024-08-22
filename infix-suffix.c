#include<stdio.h>
#define max 100
#include<string.h>
void push(char[],char,int *);
int pop(char[],int *);
int pred(char);
int main()
{ char stack[max],infix[max],postfix[max],ch,x,i,c,top=-1,pos=0,l;
   printf("\n input the infix: -\t");
   fgets(infix,100,stdin);
   l=strlen(infix);
   infix[l-1]=')';
   stack[0]='(';
   for(i=0;i!="/0";i++)
   {   infix[i]=c;
       if(c>="a"&&c<="z"||c>="A"&&c<="Z")
       {  postfix[pos]=c;
           pos++;
           }
           else if(c=='(')
           {  push(stack,c,&top);
           }
           else if(c==')')
           {  x=pop(stack,&top);
              while(x!='(')
              { postfix[pos]=x;
                pos++;
                x=pop(stack,&top);
                }
                }
                
           else{
                  while(pred(stack[top])>=pred(c))
                  { int x;
                  x=pop(stack,&top);
                    postfix[pos]=x;
                    pos++;
                    }
                    push(stack,c,&top);
                  }
                    
                  }
  }
  
  void push(char stack [],char c,int *top)
  {
      
         stack[*top]=c;
         (*top)++;
         }
  int pop(char stack[],int *top)
  {  int x;
      x=stack[*top];
      return x;
      }
      
 int pred(char c)
 {  if(c=='^')
      return 4;
    else if(c=='*'||c=='/')
      return 3;
    else if(c=='+'||c=='-')
      return 2;
      else
        return 1;
        }
         
  
                  
               
