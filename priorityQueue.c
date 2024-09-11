#include<stdio.h>
int enque(int priorityque[],int r)
{ int priority;int value;
  
  if(r>=100-1)
  {
    printf("overflow");
  }
  else{
    r+=2;
    printf("input the priority and value");
  scanf("%d %d",&priority,&value);
  priorityque[r]=priority;
  priorityque[r+1]=value;
  }
  return r;
}
int deque(int priorityque[],int f,int r)
{ int i;
    if(f>r){
      printf("queue underflow\n");
      return r;
    }
    int minpriority=priorityque[f];
    int minIndex=f;
    //find minimum priority element in the queue
    for(i=f;i<=r;i+=2)
    {
      if(priorityque[i]<minpriority)
      {
        minpriority=priorityque[i];
        minIndex=i;
      }
    }
    printf("\ndequeued element with priority %d value is %d\n",priorityque[minIndex],priorityque[minIndex+1]);

    //shifting of all the element to remove the dequed element
    for(i=minIndex;i<r;i+=2)
    {
      priorityque[i]=priorityque[i+2];
      priorityque[i+1]=priorityque[i+3];
    }
    r-=2;
    return r;
}
void display(int priorityque[],int f,int r)
{ int i;
  if (f > r) {
        printf("Queue is empty\n");
        return;
    }

    printf("Priority Queue:\n");
    for (i = f; i <= r; i +=2) {
        printf("Priority: %d, Value: %d\n", priorityque[i], priorityque[i + 1]);
    }
}
  


int main()
{ int priorityque[100],f=0,r=-2;
 int ch;
   do{
    printf("\n1-enque\n2-deque\n3-display");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:
       r=enque(priorityque,r);
       break;
      case 2:
       r=deque(priorityque,f,r);
       break;
       case 3:
       display(priorityque,f,r);
       break;
    }
   }while(ch<=4);
}