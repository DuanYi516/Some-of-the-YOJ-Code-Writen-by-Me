#include<stdio.h>
int MAX_LEN=0;
void record_cross(int hill[50][50], int n, int m, int row, int col, char result[5]) {
    int count = 0;
    int height = hill[row][col];
    if(row - 1 >= 0 && hill[row - 1][col] < height)result[count++] = 'u';
    if(row + 1 < n && hill[row + 1][col] < height)result[count++] = 'd';
    if(col - 1 >= 0 && hill[row][col - 1] < height)result[count++] = 'l';
    if(col + 1 < m && hill[row][col + 1] < height)result[count++] = 'r';
    result[count] = '\0';
}
void skiting(int hill[50][50],int N,int M,int row,int col,int len){
    char cross_result[5];
    record_cross(hill,N,M,row,col,cross_result);
    if(cross_result[0]=='\0'&&len>MAX_LEN){
        MAX_LEN=len;  
    }else{
        for(int i=0;cross_result[i]!='\0';i++){
            int drct = cross_result[i];
            int new_row=row,new_col=col;
            if(drct=='u')new_row--;            
            else if(drct=='d')new_row++;           
            else if(drct=='l')new_col--;           
            else if(drct=='r')new_col++;
            skiting(hill,N,M,new_row,new_col,len+1); // 递归
        }
    }
}
int main(){
    int N,M;
    scanf("%d %d",&N,&M);
    int hill[50][50];
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            scanf("%d",&hill[i][j]);
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            skiting(hill,N,M,i,j,0);
        }
    }
    printf("%d",MAX_LEN+1);
    return 0;
}