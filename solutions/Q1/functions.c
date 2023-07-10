#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
Stack StackInit()
{
    Stack S = malloc(sizeof(struct StackInfo));
    S->Top = -1;
    S->MaxElems = 10010;
    return S;
}
void Push(Stack S, int e)
{
    if (!IsFull(S))
    {
        S->Top = (S->Top) + 1;
        S->StackElems[S->Top] = e;
    }
}
int Pop(Stack S)
{
    int e = -1;
    if (!IsEmpty(S))
    {
        e = S->StackElems[S->Top];
        S->Top = (S->Top) - 1;
    }
    return e;
}
int IsEmpty(const Stack S)
{
    return (S->Top == -1);
}
int IsFull(const Stack S)
{
    return (S->Top == S->MaxElems);
}
int isPalindrome(char *str, int length)
{
    int flag = 0;
    Stack Expression = StackInit();
    for (int i = 0; i < length; i++)
    {
        Push(Expression, str[i]);
    }
    for (int i = 0; i < length; i++)
    {
        if (Pop(Expression) != str[i])
        {
            flag = 1;
            break;
        }
    }
    return (!flag);
}
int isBalanced(char *str, int length)
{
    int flag = 0;
    char currCharacter;
    Stack Expression = StackInit();
    for (int i = 0; i < length; i++)
    {
        currCharacter = str[i];
        if (currCharacter == '(' || currCharacter == '[' || currCharacter == '{')
        {
            Push(Expression, currCharacter);
            flag = 1;
        }
        else if (currCharacter == ')' || currCharacter == ']' || currCharacter == '}')
        {
            if (Expression->Top == -1)
            {
                flag = 0;
                break;
            }
            char LastCharacter = Pop(Expression);
            if (!((LastCharacter == '(' && currCharacter == ')') || (LastCharacter == '{' && currCharacter == '}') || (LastCharacter == '[' && currCharacter == ']')))
            {
                flag = 0;
                break;
            }
        }
    }
    if (Expression->Top != -1)
        return 0;
    return flag;
}
int findLength(char *str)
{
    int count = 0;
    while (str[count] != '\0')
        count++;
    return count;
}