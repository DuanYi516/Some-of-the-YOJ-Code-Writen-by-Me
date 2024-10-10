#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void swap(int **sort, int N);
int min_i(int **sort, int N);

int main() {
    FILE *file = fopen("error_135_ck0.in", "r");
    if (file == NULL) {
        perror("无法打开文件");
        return 1;
    }

    int N;
    fscanf(file, "%d", &N);

    // 动态分配 ids 数组
    char **ids = (char **)malloc(N * sizeof(char *));
    for (int i = 0; i < N; i++) {
        ids[i] = (char *)malloc(19 * sizeof(char));
    }

    // 动态分配 sort 数组
    int **sort = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
        sort[i] = (int *)malloc(2 * sizeof(int));
        sort[i][0] = i;
        sort[i][1] = 0;
    }

    for (int mem = 0; mem < N; mem++) {
        char id[19];
        fscanf(file, "%s", id);
        for (int num = 0; num < 18; num++) {
            ids[mem][num] = id[num];
            if (num >= 6 && num <= 13) {
                sort[mem][1] += (ids[mem][num] - '0') * (int)pow(10, 13 - num);
            }
        }
    }

    swap(sort, N);

    for (int i = 0; i < N; i++) {
        int mem = sort[i][0];
        for (int j = 0; j < 18; j++) {
            printf("%c", ids[mem][j]);
        }
        printf("\n");
    }

    // 释放动态分配的内存
    for (int i = 0; i < N; i++) {
        free(ids[i]);
        free(sort[i]);
    }
    free(ids);
    free(sort);

    fclose(file);
    return 0;
}

void swap(int **sort, int N) {
    int id_min;
    int flag = 0;
    for (int i = 0; i < N - 1; i++) {
        if (sort[i][1] <= sort[i + 1][1]) flag += 1;
    }
    if (flag != N - 1) {
        id_min = min_i(sort, N);
        int temp_1 = sort[0][1];
        sort[0][1] = sort[id_min][1];
        sort[id_min][1] = temp_1;
        int temp_0 = sort[0][0];
        sort[0][0] = sort[id_min][0];
        sort[id_min][0] = temp_0;
        swap(sort + 1, N - 1);
    }
}

int min_i(int **sort, int N) {
    int min_i = 0;
    for (int i = 1; i < N; i++) {
        if (sort[i][1] > sort[min_i][1]) {
            min_i = i;
        }
    }
    return min_i;
}