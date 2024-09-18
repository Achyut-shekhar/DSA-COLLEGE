#include <stdio.h>
#include <stdlib.h>

typedef struct Process
{
    int id;
    int time;
    struct Process *next;
} Process;

Process *createProcess(int id, int time)
{
    Process *newProcess = (Process *)malloc(sizeof(Process));
    newProcess->id = id;
    newProcess->time = time;
    newProcess->next = NULL;
    return newProcess;
}

Process *createProcessList(int n)
{
    Process *head = NULL;
    Process *temp = NULL;
    for (int i = 1; i <= n; i++)
    {
        int time;
        printf("Enter time for process %d: ", i);
        scanf("%d", &time);
        Process *newProcess = createProcess(i, time);
        if (head == NULL)
        {
            head = newProcess;
            temp = head;
        }
        else
        {
            temp->next = newProcess;
            temp = newProcess;
        }
    }
    temp->next = head;
    return head;
}

void timeSharing(Process *head, int n)
{
    Process *temp = head;
    int timeSlot = 10;
    while (n > 0)
    {
        if (temp->time > 0)
        {
            printf("Process %d is running for %d ns\n", temp->id, timeSlot);
            temp->time -= timeSlot;
        }
        if (temp->time <= 0)
        {
            printf("Process %d is completed.\n", temp->id);
            n--;
        }
        temp = temp->next;
    }
}

int main()
{
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    Process *processList = createProcessList(n);
    timeSharing(processList, n);

    return 0;
}


