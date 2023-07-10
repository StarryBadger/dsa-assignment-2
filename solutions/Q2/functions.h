#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_
typedef struct Node
{
    int Element;
    struct Node *NextNode;
    struct Node *PrevNode;
} Node;
typedef Node *PtrNode;
typedef struct QueueInfo
{
    PtrNode LL;
    int elemCount;
} QueueInfo;
typedef QueueInfo *Queue;
Queue InitQue();
void Push(Queue head, int val);
int Pop(Queue head);
void Inject(Queue head, int val);
int popRear(Queue head);
void Print(Queue head);
void PrintReverse(Queue head);
int findElem(Queue head, int pos);
void removeKElems(Queue head, int k);
#endif