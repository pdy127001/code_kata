#include <stdio.h>
#include <stdlib.h>

int solution(int order[], size_t order_len) {
    int *stack = (int*)malloc(sizeof(int) * order_len);
    int top = -1;
    int current = 1;
    int idx = 0;
    int count = 0;

    while (current <= order_len) {
        stack[++top] = current++;

        while (top >= 0 && stack[top] == order[idx]) {
            top--;
            idx++;
            count++;
        }
    }

    while (top >= 0 && stack[top] == order[idx]) {
        top--;
        idx++;
        count++;
    }

    free(stack);
    return count;
}