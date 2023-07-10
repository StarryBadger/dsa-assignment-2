#include <stdio.h>
#include <stdlib.h>
typedef struct TreeNode *Tree;
typedef struct TreeNode *PtrToNode;
struct TreeNode
{
    int Key;
    PtrToNode Left;
    PtrToNode Right;
};

typedef struct StackInfo
{
    PtrToNode StackElems[100000];
    int Top;
    int MaxElems;
} StackInfo;
typedef StackInfo *Stack;

Stack StackInit()
{
    Stack S = malloc(sizeof(struct StackInfo));
    S->Top = -1;
    S->MaxElems = 100000;
    return S;
}
int IsEmpty(const Stack S)
{
    return (S->Top == -1);
}
int IsFull(const Stack S)
{
    return (S->Top == S->MaxElems);
}
void Push(Stack S, PtrToNode e)
{
    if (!IsFull(S))
    {
        S->Top = (S->Top) + 1;
        S->StackElems[S->Top] = e;
    }
}
PtrToNode Pop(Stack S)
{
    PtrToNode e = NULL;
    if (!IsEmpty(S))
    {
        e = S->StackElems[S->Top];
        S->Top = (S->Top) - 1;
    }
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
void Beautiful(Tree T)
{
    int flag = 0;
    if (T == NULL)
        return;
    Stack A = StackInit();
    Stack B = StackInit();
    Push(A,T);
    while (!IsEmpty(A) || !IsEmpty(B))
    {
        if (flag == 0)
        {
            while (!IsEmpty(A))
            {
                PtrToNode Curr = Pop(A);
                printf("%d ", Curr->Key);
                if (Curr->Left != NULL)
                    Push(B, Curr->Left);
                if (Curr->Right != NULL)
                    Push(B, Curr->Right);
            }
            flag = 1;
        }
        if (flag == 1)
        {
            while (!IsEmpty(B))
            {
                PtrToNode Curr = Pop(B);
                printf("%d ", Curr->Key);
                if (Curr->Right != NULL)
                    Push(A, Curr->Right);
                if (Curr->Left != NULL)
                    Push(A, Curr->Left);
            }
            flag = 0;
        }
    }
}

Tree Insert(Tree T, int x)
{
    if (T == NULL)
        T = MakeNode(x);
    else if (x < T->Key)
        T->Left = Insert(T->Left, x);
    else if (x > T->Key)
        T->Right = Insert(T->Right, x);
    return T;
}

int main()
{
    int t, n, x;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);

        Tree T = NULL;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &x);
            T = Insert(T, x);
        }
        Beautiful(T);
        printf("\n");
    }
}
