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

int minimumNumber(int n, char* password)
{
    int len = strlen(password), r = 4;
    _Bool req[4] = {0};
    for(int i = 0; i < len; i++)
    {
        if(*(password+i)>47&&*(password+i)<58)
            req[0] = 1;
        else if(*(password+i)>96&&*(password+i)<123)
            req[1] = 1;
        else if(*(password+i)>64&&*(password+i)<91)
            req[2] = 1;
        else
            req[3] = 1;
    }
    for(int i = 0; i < 4; i++)
        if(req[i])
            r--;
    return ((6-len)>r)?6-len:r;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* n_endptr;
    char* n_str = readline();
    int n = strtol(n_str, &n_endptr, 10);

    if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

    char* password = readline();

    int answer = minimumNumber(n, password);

    fprintf(fptr, "%d\n", answer);

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
