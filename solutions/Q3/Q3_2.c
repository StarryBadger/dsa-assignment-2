#include <stdio.h>
#include <stdlib.h>
typedef struct TreeNode *Tree;
typedef struct TreeNode *PtrToNode;
int preCurr;
struct TreeNode
{
    int Key;
    PtrToNode Left;
    PtrToNode Right;
};
typedef struct QueInfo
{
    int elementCount;
    int elementMax;
    int front;
    int rear;
    PtrToNode QArr[2000];
} QueInfo;
typedef QueInfo *Queue;

Queue Initialize()
{
    Queue Q = (Queue)malloc(sizeof(QueInfo));
    Q->elementMax = 2000;
    Q->front = 0;
    Q->rear = -1;
    Q->elementCount = 0;
    return Q;
}
int isFull(Queue head)
{
    if (head->elementCount >= head->elementMax)
        return 1;
    return 0;
}
int isEmpty(Queue head)
{
    if (head->elementCount < 1)
        return 1;
    return 0;
}
void Enque(Queue head, PtrToNode val)
{
    if (!isFull(head))
    {
        head->rear = (head->rear + 1) % (head->elementMax);
        head->QArr[head->rear] = val;
        head->elementCount += 1;
    }
}
PtrToNode Deque(Queue head)
{
    if (isEmpty(head))
        return NULL;
    PtrToNode e = head->QArr[head->front];
    head->front = (head->front + 1) % (head->elementMax);
    head->elementCount -= 1;
    return e;
}
PtrToNode MakeNode(int e)
{
    PtrToNode T = (PtrToNode)malloc(sizeof(struct TreeNode));
    T->Key = e;
    T->Left = NULL;
    T->Right = NULL;
    return T;
}
void Levelorder(Tree T)
{
    if (T == NULL)
        return;
    Queue Q = Initialize();
    Enque(Q, T);
    while (!isEmpty(Q))
    {
        PtrToNode Curr = Deque(Q);
        if (Curr->Left != NULL)
            Enque(Q, Curr->Left);
        if (Curr->Right != NULL)
            Enque(Q, Curr->Right);
        printf("%d ", Curr->Key);
    }
}

Tree Create(int *arrIn, int *arrPre, int inL, int inR)
{
    if (inL > inR)
        return NULL;
    PtrToNode T = MakeNode(arrPre[preCurr]);
    ++preCurr;
    if (inR == inL)
        return T;
    int pos=0;
    for (int i = inL; i <= inR; i++)
    {
        if (arrIn[i] == T->Key)
        {
            pos = i;
            break;
        }
    }
    T->Left = Create(arrIn, arrPre, inL, pos - 1);
    T->Right = Create(arrIn, arrPre, pos + 1, inR);
    return T;
}
int main()
{
    int t, n;
    scanf("%d", &t);
    while (t--)
    {
        preCurr=0;
        scanf("%d", &n);
        Tree T = NULL;
        int arrPreorder[n];
        int arrInorder[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arrInorder[i]);
        }
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arrPreorder[i]);
        }
        T = Create(arrInorder, arrPreorder, 0, n - 1);
        Levelorder(T);
        printf("\n");
    }
}