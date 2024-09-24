#include<stdio.h>
typedef struct link{
int data;
float m;
struct link *next;  //it is pointing to its own structure and it helps to save the address of the next node. 
}link;
link a,b,c;
int main()
{  
   link *p=NULL;
   
   a.data=10;
   a.m=2.5;
   a.next=&b;
   b.data=20;
   b.m=6.5;
   b.next=&c;
   c.data=30;
   c.m=7.5;
   c.next=NULL;
   p=&a;            //p is not the part od the structure. it is pointing to address of the first node which is holding the adress of its next node and as there is no node before a therefore
                  // need to save its address to a different pointer
   while(p!=NULL)
   { 
     printf("%d \t %f \n",p->data,p->m);
     p=p->next;
     }
}
   
