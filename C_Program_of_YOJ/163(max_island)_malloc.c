#include <stdio.h>
#include <stdlib.h>

struct type_info {
    int size;
    int locs[200];
};

void record_cross(int **ground, int n, int m, int row, int col, char result[9]) {
    int count = 0;
    if (row - 1 >= 0 && ground[row - 1][col] == 'I') result[count++] = 'w';
    if (row + 1 < n && ground[row + 1][col] == 'I') result[count++] = 'x';
    if (col - 1 >= 0 && ground[row][col - 1] == 'I') result[count++] = 'a';
    if (col + 1 < m && ground[row][col + 1] == 'I') result[count++] = 'd';
    if (col + 1 < m && row + 1 < n && ground[row + 1][col + 1] == 'I') result[count++] = 'c';
    if (col - 1 >= 0 && row + 1 < n && ground[row + 1][col - 1] == 'I') result[count++] = 'z';
    if (col + 1 < m && row - 1 >= 0 && ground[row - 1][col + 1] == 'I') result[count++] = 'e';
    if (col - 1 >= 0 && row - 1 >= 0 && ground[row - 1][col - 1] == 'I') result[count++] = 'q';
    result[count] = '\0';
}

void get_size(int **ground, int row, int col, int n, int m, struct type_info *my_info, int count) {
    char cross_result[9];
    record_cross(ground, n, m, row, col, cross_result);
    if (cross_result[0] == '\0') {
        return;
    } else {
        for (int i = 0; cross_result[i] != '\0'; i++) {
            char drct = cross_result[i];
            int new_row = row, new_col = col;
            if (drct == 'w') new_row--;
            else if (drct == 'x') new_row++;
            else if (drct == 'a') new_col--;
            else if (drct == 'd') new_col++;
            else if (drct == 'c') {
                new_row++;
                new_col++;
            } else if (drct == 'z') {
                new_row++;
                new_col--;
            } else if (drct == 'q') {
                new_row--;
                new_col--;
            } else if (drct == 'e') {
                new_row--;
                new_col++;
            }
            if (ground[new_row][new_col] == 'I') {
                ground[new_row][new_col] = '.';
                my_info[count].size++;
                my_info[count].locs[my_info[count].size] = 100 * new_row + new_col;
                get_size(ground, new_row, new_col, n, m, my_info, count);
            }
        }
    }
}

int main() {
    int count = 0;
    struct type_info my_info[50];
    for (int i = 0; i < 50; i++) {
        my_info[i].size = 0;
    }
    int n, m;
    scanf("%d %d", &n, &m);
    getchar(); // 读取并丢弃换行符

    int **ground = (int **)malloc(n * sizeof(int *));
    if (ground == NULL) {
        fprintf(stderr, "内存分配失败\n");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        ground[i] = (int *)malloc(m * sizeof(int));
        if (ground[i] == NULL) {
            fprintf(stderr, "内存分配失败\n");
            return 1;
        }
    }

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++) {
            ground[row][col] = getchar();
        }
        getchar(); // 读取并丢弃每行末尾的换行符
    }

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++) {
            char input = ground[row][col];
            if (input == 'I') {
                my_info[count].locs[my_info[count].size] = 100 * row + col;
                ground[row][col] = '.';
                get_size(ground, row, col, n, m, my_info, count);
                count++;
            }
        }
    }

    int MAX = 0;
    for (int il = 0; il < count; il++) {
        if (my_info[il].size > MAX) {
            MAX = my_info[il].size;
        }
    }
    MAX = count == 0 ? -1 : MAX;
    printf("%d %d", count, 1 + MAX);

    for (int i = 0; i < n; i++) {
        free(ground[i]);
    }
    free(ground);
    return 0;
}