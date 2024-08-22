#include<stdio.h>
#define max 100
#include<string.h>
void push(char[],char,int *);
int pop(char[],int *);
int pred(char);
int main()
{ char stack[max],infix[max],postfix[max];
char ch,x,c;
int i=0,top=0,pos=0,l;
   printf("\n input the infix: -\t");
   fgets(infix,100,stdin);
   l=strlen(infix);
   infix[l-1]=')';
   stack[0]='(';
 while(infix[i]!='\0')
   {   char c=infix[i];
       if((c>='a'&&c<='z')||(c>='A'&&c<='Z'))
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
            //pop(stack,&top);
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
                    i++;
   }
 postfix[pos]='\0';
 printf("%s",postfix);

}


  void push(char stack [],char c,int *top)
  {
       stack[++(*top)] = c;
         
         }
         
  int pop(char stack[],int *top)
  {   return stack[(*top)--];
      }
      
 int pred(char c)
 {  if(c=='^')
      return (4);
    else if(c=='*'||c=='/')
      return (3);
    else if(c=='+'||c=='-')
      return (2);
      else
        return (1);
        }
         
  
                  
               
