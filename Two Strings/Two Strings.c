#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* twoStrings(char* s1, char* s2)
{
    int f[26] = {0}, s[26] = {0}, i;
    for(i = 0; *(s1+i) && *(s2+i); i++)
    {
        (*(f+*(s1+i)-97))++;
        (*(s+*(s2+i)-97))++;
    }
    if(*(s1+i)==0&&*(s2+i)==0);
    else if(*(s2+i)==0)
        for(i += 1; *(s1+i); i++)
            (*(f+*(s1+i)-97))++;
    else
        for(i += 1; *(s2+i); i++)
            (*(s+*(s2+i)-97))++;
    for(int i = 0; i < 26; i++)
        if(*(f+i)>0&&*(s+i)>0)
            return "YES";
    return "NO";
}
int main()
{
    int n;
    char **s = (char**) malloc(2 * sizeof(char*));
    scanf("%d", &n);
    while(n--)
    {
        *s = malloc(100000);
        *(s+1) = malloc(100000);
        scanf("%s", *s);
        scanf("%s", *(s+1));
        printf("%s\n", twoStrings(*s, *(s+1)));
    }
    return 0;
}
