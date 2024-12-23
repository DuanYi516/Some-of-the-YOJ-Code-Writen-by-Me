#include <stdio.h>

void record_cross(int ground[100][100], int n, int m, int row, int col, char result[9]) {
    int count = 0;
    if(row - 1 >= 0 && ground[row - 1][col] =='I')result[count++] = 'w';
    if(row + 1 < n && ground[row + 1][col] =='I')result[count++] = 'x';
    if(col - 1 >= 0 && ground[row][col - 1] =='I')result[count++] = 'a';
    if(col + 1 < m && ground[row][col + 1] =='I')result[count++] = 'd';
    if(col + 1 < m && row + 1 < n && ground[row+1][col + 1] =='I')result[count++] = 'c';
    if(col - 1 >=0 && row + 1 < n && ground[row+1][col - 1] =='I')result[count++] = 'z';
    if(col + 1 < m && row - 1 >= 0 && ground[row-1][col + 1] =='I')result[count++] = 'e';
    if(col - 1 >=0 && row - 1 >= 0 && ground[row-1][col - 1] =='I')result[count++] = 'q';
    result[count] = '\0';
}
void get_size(int ground[100][100], int row, int col, int n, int m, int *my_info, int count) {
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
                my_info[count]++;get_size(ground, new_row, new_col, n, m, my_info, count);
            }
        }
    }
}
int main(){
    int count = 0;
    int my_info[50];
    for (int i = 0; i < 50; i++) {
        my_info[i] = 0;
    }
    int n, m;
    scanf("%d %d", &n, &m);
    char rtn = getchar();
    int ground[100][100];
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++) {
            scanf("%c", &ground[row][col]);
        }
        char rtn = getchar();
    }
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++) {
            char input = ground[row][col];
            if (input == 'I') {
                ground[row][col] = '.';
                get_size(ground, row, col, n, m, my_info, count);
                count++;
            }
        }
    }
    int MAX = 0;
    for (int il = 0; il < count; il++) {
        if (my_info[il] > MAX) {
            MAX = my_info[il];
        }
    }
    MAX=(count==0)?-1:MAX;
    printf("%d %d", count, 1 + MAX);
    return 0;
}