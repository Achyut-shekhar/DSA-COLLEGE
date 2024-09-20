
#include <stdio.h>
#include <stdlib.h>
typedef struct circular
{
    int pro, time;
    struct circular *next;
} cl;

cl *insert(cl *);
void display(cl *);
void calculate(cl *, int);
void main()
{
    int cputime;
    printf("---INPUT---\n");
    printf("ENTER THE TIME TAKEN BY CPU TO COMPLETE 1 PROCESS : ");
    scanf("%d", &cputime);
    cl *ptr = NULL;
    ptr = insert(ptr);
    display(ptr);
    calculate(ptr, cputime);
}

cl *insert(cl *last)
{
    int choice = 1;
    cl *p = NULL;
    while (choice == 1)
    {
        p = (cl *)malloc(sizeof(cl));
        printf("\nENTER PROCESS NUMBER : ");
        scanf("%d", &p->pro);
        printf("\nENTER TIME PROCESS WILL TAKE : ");
        scanf("%d", &p->time);
        if (last == NULL)
        {
            last = p;
            last->next = last;
        }
        else
        {
            p->next = last->next;
            last->next = p;
            last = p;
        }
        printf("\nEnter 0 for exit: ");
        scanf("%d", &choice);
    }
    return last->next;
}

void display(cl *f)
{
    cl *p = f;
    printf("---OUTPUT---\n");
    do
    {
        printf("\n PROCESS : %d ", p->pro);
        printf("\n TIME : %d ", p->time);
        p = p->next;
    } while (p != f);
}

void calculate(cl *ptr, int t)
{
    int ctr = 0;
    cl *p = NULL;
    p = ptr->next;
    while (p->next != ptr)
    {
        p = p->next;
    }
    while (ptr != ptr->next)
    {
        do
        {
            ctr++;
            if (ptr->time <= t)
            {
                cl *f = ptr;
                printf("\n PROCESS %d COMPLETED IN %d ns\n", ptr->pro, ctr * t);
                p->next = ptr->next;
                ptr = ptr->next;
                free(f);
                if (p == ptr)
                {
                    break;
                }   
            }
            else
            {
                ptr->time = ptr->time - t;
                p = ptr;
                ptr = ptr->next;
            }
        } while (ptr != p->next);
    }
    ctr = (ptr->time + (ctr * t));
    printf("\n PROCESS %d COMPLETED IN %d ns\n", ptr->pro, ctr);
    printf("TOTAL TIME TAKEN : %d ns", ctr);
    free(ptr);
}
