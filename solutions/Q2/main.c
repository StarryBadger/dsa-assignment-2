#include<stdio.h>
#include<stdlib.h>
#include"functions.h"
int main()
{
    Queue Q = InitQue();
    int t;
    char operation[10];
    scanf("%d", &t);
    while (t--)
    {
        scanf("%s", operation);
        int oper = operation[4] - '0';
        if (oper == 1)
        {
            int n = 0;
            scanf("%d", &n);
            Push(Q, n);
        }
        else if (oper == 2)
        {
            int deletedElement = Pop(Q);
            printf("%d\n", deletedElement);
        }
        else if (oper == 3)
        {
            int n = 0;
            scanf("%d", &n);
            Inject(Q, n);
        }
        else if (oper == 4)
        {
            int deletedElement = popRear(Q);
            printf("%d\n", deletedElement);
        }
        else if (oper == 5)
        {
            Print(Q);
        }
        else if (oper == 6)
        {
            PrintReverse(Q);
        }
        else if (oper == 7)
        {
            int position;
            scanf("%d", &position);
            int found = findElem(Q, position);
            printf("%d\n", found);
        }
        else if (oper == 8)
        {
            int n = 0;
            scanf("%d", &n);
            removeKElems(Q, n);
        }
    }
}