#include <stdio.h>
#include <stdlib.h>
int MAX = 10000005, MIN = -10000005;
typedef struct TreeNode *Tree;
typedef struct TreeNode *PtrToNode;
struct TreeNode
{
    long long int Key;
    PtrToNode Left;
    PtrToNode Right;
    int Min;
    int Max;
};

typedef struct QueInfo
{
    int elementCount;
    int elementMax;
    int front;
    int rear;
    PtrToNode QArr[1000000];
} QueInfo;
typedef QueInfo *Queue;

long long int PrefixSum, MaxSale;

Queue Initialize()
{
    Queue Q = (Queue)malloc(sizeof(QueInfo));
    Q->elementMax = 1000000;
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
PtrToNode MakeNode(int e, int minVal, int maxVal)
{
    PtrToNode T = (PtrToNode)malloc(sizeof(struct TreeNode));
    T->Key = e;
    T->Left = NULL;
    T->Right = NULL;
    T->Min = minVal;
    T->Max = maxVal;
    return T;
}
void ModifyBST(Tree T)
{
    if (T != NULL)
    {
        ModifyBST(T->Left);
        PrefixSum = PrefixSum + T->Key;
        MaxSale = MaxSale + PrefixSum;
        T->Key = PrefixSum;
        ModifyBST(T->Right);
    }
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
        printf("%lld ", Curr->Key);
    }
}
PtrToNode ListToBST(int n, int *arr)
{
    Tree T = MakeNode(arr[0], MIN, MAX);
    Queue Q = Initialize();
    Enque(Q, T);
    for (int i = 1; i < n;)
    {
        PtrToNode Parent = Deque(Q);
        if (arr[i] > Parent->Min && arr[i] < Parent->Max)
        {
            if (arr[i] < Parent->Key && arr[i]>Parent->Min)
            {
                Parent->Left = MakeNode(arr[i], Parent->Min, Parent->Key);
                Enque(Q, Parent->Left);
                i++;
                if (i >= n)
                    break;
            }
            if (arr[i] > Parent->Key && arr[i]<Parent->Max)
            {
                Parent->Right = MakeNode(arr[i], Parent->Key, Parent->Max);
                Enque(Q, Parent->Right);
                i++;
                if (i >= n)
                    break;
            }
        }
    }
    return T;
}
    int main()
{
    int n;
    PrefixSum = 0;
    MaxSale = 0;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    PtrToNode T = ListToBST(n, arr);
    ModifyBST(T);
    Levelorder(T);
    printf("\n");
    printf("%lld", MaxSale);
    printf("\n");
}