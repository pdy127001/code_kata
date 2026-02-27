#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int compare(const void* a, const void* b)
{
    char* s1 = *(char**)a;
    char* s2 = *(char**)b;

    char ab[16];
    char ba[16];

    strcpy(ab, s1);
    strcat(ab, s2);

    strcpy(ba, s2);
    strcat(ba, s1);

    return strcmp(ba, ab);
}

char* solution(int numbers[], size_t numbers_len)
{
    char** strs = (char**)malloc(numbers_len * sizeof(char*));

    for (size_t i = 0; i < numbers_len; i++)
    {
        strs[i] = (char*)malloc(5);
        sprintf(strs[i], "%d", numbers[i]);
    }

    qsort(strs, numbers_len, sizeof(char*), compare);

    if (strcmp(strs[0], "0") == 0)
    {
        char* answer = (char*)malloc(2);
        strcpy(answer, "0");
        return answer;
    }

    int total_len = 1;
    for (size_t i = 0; i < numbers_len; i++)
        total_len += strlen(strs[i]);

    char* answer = (char*)malloc(total_len);
    answer[0] = '\0';

    for (size_t i = 0; i < numbers_len; i++)
        strcat(answer, strs[i]);

    return answer;
}