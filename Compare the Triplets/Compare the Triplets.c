#include <stdio.h>

int main() {
    int a[8];
    scanf("%d %d %d", &a[0], &a[1], &a[2]);
    scanf("%d %d %d", &a[3], &a[4], &a[5]);
    for(int i = 0; i < 3; i++) {
        if( a[i] > a[3+i] ) {
            a[6]++;
        }
        else if( a[i] < a[3+i] ) {
            a[7]++;
        }
    }
    printf("%d %d", a[6], a[7]);
    return 0;
}
