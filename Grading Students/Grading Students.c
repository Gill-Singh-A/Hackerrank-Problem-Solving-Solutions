#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, *grades;
    scanf("%d", &n);
    grades = (int*) malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) {
        scanf("%d", (grades+i));
    }
    for(int i = 0; i < n; i++) {
        if( *(grades+i) < 38 ) {
            goto e;
        } else if( 5 - (*(grades+i) % 5) < 3 ) {
            *(grades+i) += 5 - (*(grades+i)%5);
        }
        e:;
    }
    for(int i = 0; i < n; i++) {
        printf("%d\n", *(grades+i));
    }
}
