#include<stdio.h>
void record_cross(int ground[200][200], int n, int m, int row, int col, char result[9]) {
    int count = 0;
    if(row - 1 >= 0 && ground[row - 1][col] ==1|| ground[row-1][col] == 2)result[count++] = 'w';
    if(row + 1 < n && ground[row + 1][col] ==1|| ground[row+1][col] == 2)result[count++] = 'x';
    if(col - 1 >= 0 && ground[row][col - 1] ==1|| ground[row][col-1] == 2)result[count++] = 'a';
    if(col + 1 < m && ground[row][col + 1] ==1|| ground[row][col+1] == 2)result[count++] = 'd';
    result[count] = '\0';
}
void get_size(int ground[200][200], int row, int col, int n, int m, int *my_info, int count) {
    char cross_result[5];
    record_cross(ground, n, m, row, col, cross_result);
        if(ground[row][col]==2){my_info[count]=1;}
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
            if (ground[new_row][new_col] == 1|| ground[new_row][new_col] == 2) {
                
                if(ground[row][col]==2||ground[new_row][new_col] == 2){
                    my_info[count]=1;
                }
                ground[new_row][new_col] = 0;
                ground[row][col] = 0;
                get_size(ground, new_row, new_col, n, m, my_info, count);
            }
        }
    }
}

int main(){
    int n,m;
    int count = 0;
    int my_info[200];
    for(int i=0;i<50;i++)my_info[i]=0;
    scanf("%d %d", &n, &m);
    char rtn = getchar();
    int ground[200][200];
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++) {
            scanf("%d", &ground[row][col]);
        }
        char rtn = getchar();
    }
    int res=0;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++) {
            int input = ground[row][col];
            if (input == 1 ||input == 2) {
                
                get_size(ground, row, col, n, m, my_info, count);
                
                if(my_info[count]){
                    res++;
                }
                count++;
            }
        }
    }
    printf("%d",res);
    return 0;
}