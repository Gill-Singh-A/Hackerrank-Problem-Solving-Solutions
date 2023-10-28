#include <stdio.h>

int main()
{
    int n, *score;
    int m[4];
    scanf("%d", &n);
    score = (int*) malloc(n * sizeof(int));
    m[2] = 0;
    m[3] = 0;
    for(int i = 0; i < n; i++)
    {
        scanf("%d ", score + i);
        if( i == 0 )
        {
            m[0] = *(score + i);
            m[1] = m[0];
        }
        else if( m[0] < *(score + i) )
        {
            m[0] = *(score + i);
            m[2]++;
        }
        else if( m[1] > *(score + i) )
        {
            m[1] = *(score + i);
            m[3]++;   
        }
    }
    printf("%d %d", m[2], m[3]);
}
