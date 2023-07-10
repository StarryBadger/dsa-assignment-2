#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
int main()
{
    int t;
    char str[10010];
    scanf("%d", &t);
    while (t--)
    {
        scanf("%s", str);
        int length = findLength(str);
        int balanced = isBalanced(str, length);
        int palindromic = isPalindrome(str, length);
        if (palindromic)
        {
            if (balanced)
                printf("Balanced and Palindromic\n");
            else
                printf("Palindromic\n");
        }
        else
        {
            if (balanced)
                printf("Balanced\n");
            else
                printf("-1\n");
        }
    }
}
