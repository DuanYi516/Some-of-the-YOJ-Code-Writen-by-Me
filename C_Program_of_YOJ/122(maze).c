/*给定一个由0（表示墙壁）和1（表示道路）的迷宫，请你判断进入迷宫后，仅通过横向和纵向的行走是否能从迷宫中走出来，
即能否从坐标（1，1）走到（n，m）。
输入格式
　　共n+1行。
　　第一行为两个数n，m（1≤n，m≤9），表示迷宫的长和宽。
　　第2行到第n+1行，每行m个数，为一个由0和1组成的n*m的矩阵，表示迷宫，其中0表示墙壁（不通），1表示道路
    （坐标（1，1）和坐标（n，m）处都为1）。

输出格式
　　仅一行。
　　若该迷宫存在从坐标（1，1）到坐标（n，m）的由数字1组成的通路，则输出YES，否则输出NO。*/
#include <stdio.h>
#include <string.h>
int FOUND = 0;
void record_cross(int maze[9][9], int n, int m, int row, int col, int towards, char result[4]) {
    int count = 0;
    if (towards != 3 && row - 1 >= 0 && maze[row - 1][col] == 1) {
        result[count++] = 1 + '0';
    }
    if (towards != 4 && col + 1 < m && maze[row][col + 1] == 1) {
        result[count++] = 2 + '0';
    }
    if (towards != 1 && row + 1 < n && maze[row + 1][col] == 1) {
        result[count++] = 3 + '0';
    }
    if (towards != 2 && col - 1 >= 0 && maze[row][col - 1] == 1) {
        result[count++] = 4 + '0';
    }
    result[count] = '\0';
}
void find(int maze[9][9], int n, int m, int cur_row, int cur_col, int cur_towards) {
    if (cur_row == n - 1 && cur_col == m - 1)
        FOUND = 1; // 找到了
    else {
        char cross_result[4];
        record_cross(maze, n, m, cur_row, cur_col, cur_towards, cross_result);
        for (int i = 0; i < strlen(cross_result); i++) {
            if (FOUND == 1)
                break; // 找到了就不找了
            int drct = cross_result[i] - '0';
            if (drct == 1 && cur_row - 1 >= 0) {
                cur_row--;
            } else if (drct == 2 && cur_col + 1 < m) {
                cur_col++;
            } else if (drct == 3 && cur_row + 1 < n) {
                cur_row++;
            } else if (drct == 4 && cur_col - 1 >= 0) {
                cur_col--;
            }
            
            find(maze, n, m, cur_row, cur_col, drct); // 递归

            if (drct == 1 && cur_row + 1 < n) {       // 回溯
                cur_row++;
            } else if (drct == 2 && cur_col - 1 >= 0) {
                cur_col--;
            } else if (drct == 3 && cur_row - 1 >= 0) {
                cur_row--;
            } else if (drct == 4 && cur_col + 1 < m) {
                cur_col++;
            }
        }
    }
    return;
}
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int maze[9][9];
    for(int row=0;row<n;row++){for(int col=0;col<m;col++){scanf("%d",&maze[row][col]);}}

    find(maze, n, m, 0, 0, 2);

    if (FOUND)  printf("YES");
    else printf("NO");
    return 0;
}
