#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char** split_string(char*);

int digits(int i)
{
    int n = 0;
    while(i!=0)
    {
        i /= 10;
        n++;
    }
    return n;
}
int power(int i)
{
    int r = 1;
    while(i--)
        r *= 10;
    return r;
}
int reverse(int i)
{
    int d = digits(i), r = 0;
    for(d -= 1; i != 0; i /= 10, d--)
        r += (i%10)*power(d);
    return r;
}
int beautifulDays(int i, int j, int k)
{
    float checkf, check;
    int ri, n = 0;
    for(; i <= j; i++)
    {
        ri = reverse(i)-i;
        if(ri<0)
            ri *= -1;
        checkf = (float) ri/k;
        check = ri/k;
        if(checkf-check==0)
            n++;
    }
    return n;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char** ijk = split_string(readline());

    char* i_endptr;
    char* i_str = ijk[0];
    int i = strtol(i_str, &i_endptr, 10);

    if (i_endptr == i_str || *i_endptr != '\0') { exit(EXIT_FAILURE); }

    char* j_endptr;
    char* j_str = ijk[1];
    int j = strtol(j_str, &j_endptr, 10);

    if (j_endptr == j_str || *j_endptr != '\0') { exit(EXIT_FAILURE); }

    char* k_endptr;
    char* k_str = ijk[2];
    int k = strtol(k_str, &k_endptr, 10);

    if (k_endptr == k_str || *k_endptr != '\0') { exit(EXIT_FAILURE); }

    int result = beautifulDays(i, j, k);

    fprintf(fptr, "%d\n", result);

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) { break; }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data) { break; }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length);

    return data;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);
        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}
