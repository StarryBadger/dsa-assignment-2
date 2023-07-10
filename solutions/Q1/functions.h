#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_
typedef struct StackInfo
{
    char StackElems[10010];
    int Top;
    int MaxElems;
} StackInfo;
typedef StackInfo *Stack;

Stack StackInit();
void Push(Stack, int);
int Pop(Stack);
int IsEmpty(const Stack S);
int IsFull(const Stack S);
int isPalindrome(char *str, int length);
int isBalanced(char *str, int length);
int findLength(char *);
#endif