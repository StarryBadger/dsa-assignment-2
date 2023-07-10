#include<stdio.h>
#include<stdlib.h>
#include"functions.h"
Queue InitQue()
{
    PtrNode TmpCell = malloc(sizeof(Node));
    TmpCell->Element = 0;
    TmpCell->NextNode = TmpCell;
    TmpCell->PrevNode = TmpCell;
    Queue NewQue = malloc(sizeof(QueueInfo));
    NewQue->LL = TmpCell;
    NewQue->elemCount = 0;
    return NewQue;
}

void Push(Queue head, int val)
{
    PtrNode TmpCell = malloc(sizeof(Node));
    TmpCell->Element = val;
    TmpCell->NextNode = head->LL;
    TmpCell->PrevNode = head->LL->PrevNode;
    PtrNode Temp = head->LL->PrevNode;
    head->LL->PrevNode = TmpCell;
    Temp->NextNode = TmpCell;
    head->elemCount += 1;
}

int Pop(Queue head)
{
    if (head->elemCount == 0)
        return -1;
    PtrNode TmpCell = head->LL->NextNode;
    TmpCell->NextNode->PrevNode = head->LL;
    head->LL->NextNode = TmpCell->NextNode;
    int delElem = TmpCell->Element;
    free(TmpCell);
    --head->elemCount;
    return delElem;
}

void Inject(Queue head, int val)
{
    PtrNode TmpCell = malloc(sizeof(Node));
    TmpCell->Element = val;
    TmpCell->NextNode = head->LL->NextNode;
    TmpCell->PrevNode = head->LL;
    head->LL->NextNode->PrevNode = TmpCell;
    head->LL->NextNode = TmpCell;
    head->elemCount += 1;
}

int popRear(Queue head)
{
    if (head->elemCount == 0)
        return -1;
    PtrNode TmpCell = head->LL->PrevNode;
    head->LL->PrevNode = head->LL->PrevNode->PrevNode;
    TmpCell->PrevNode->NextNode = head->LL;
    int delElem = TmpCell->Element;
    free(TmpCell);
    --head->elemCount;
    return delElem;
}

void Print(Queue head)
{
    if (head->elemCount == 0)
    {
        printf("-1\n");
        return;
    }
    PtrNode First = head->LL;
    head->LL = head->LL->NextNode;
    while (head->LL != First)
    {
        printf("%d ", head->LL->Element);
        head->LL = head->LL->NextNode;
    }
    printf("\n");
}

void PrintReverse(Queue head)
{

    if (head->elemCount == 0)
    {
        printf("-1\n");
        return;
    }
    PtrNode First = head->LL;
    head->LL = head->LL->PrevNode;
    while (head->LL != First)
    {
        printf("%d ", head->LL->Element);
        head->LL = head->LL->PrevNode;
    }
    printf("\n");
}


int findElem(Queue head, int pos)
{
    PtrNode Hello = head->LL;
    if (pos > head->elemCount || pos < 1)
        return -1;
    while (pos--)
    {
        Hello = Hello->NextNode;
    }
    return Hello->Element;
}

void removeKElems(Queue head, int k)
{
    if (head->elemCount == 0)
        return;
    if (k > head->elemCount)
        k = head->elemCount;
    while (k--)
    {
        Pop(head);
    }
}