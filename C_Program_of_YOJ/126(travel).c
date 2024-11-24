#include<stdio.h>
int MAX_VALUE=-516;
int not_in(int row,int col,int* path,int path_len){
    for(int i=0;i<path_len-1;i++){
        if(path[i]==row*10+col)return 0;
    }
    return 1;
}
void record_cross(int map[8][8], int n, int m, int row, int col, char* result,int* path,int path_len) {
    int count = 0;
    // if(row - 1 >= 0 && not_in(row-1,col,path,path_len))result[count++] = 'u';
    if(row + 1 < n && not_in(row+1,col,path,path_len))result[count++] = 'd';
    if(col - 1 >= 0 && not_in(row,col-1,path,path_len))result[count++] = 'l';
    if(col + 1 < m && not_in(row,col+1,path,path_len))result[count++] = 'r';
    result[count] = 'A';
}

void risk(int map[8][8],int n,int m,int row,int col,int value,int* path,int path_len){
    char cross_result[4];
    record_cross(map,n,m,row,col,cross_result,path,path_len);
    if(row==n-1&&col==m-1&&value>MAX_VALUE){
        MAX_VALUE=value;
        // for(int i=0;i<path_len;i++){
        //     printf("%d-",path[i]);
        // }
        // printf(">%d\n",value);
    }else{
        for(int i=0;cross_result[i]!='A';i++){
            char drct = cross_result[i];
            int new_row=row,new_col=col;
            // if(drct=='u')new_row--;            
            if(drct=='d')new_row++;           
            else if(drct=='l')new_col--;           
            else if(drct=='r')new_col++;
            path[path_len++]=10*new_row+new_col;
            value+=map[new_row][new_col];
            risk(map,n,m,new_row,new_col,value,path,path_len); //递归
            path[path_len--]=-1;  //回溯
            value-=map[new_row][new_col];
        }
    }
}
int main(){
    int n,m;scanf("%d %d",&n,&m);
    int map[8][8];
    int path[8*8]={-1};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&map[i][j]);
        }
    }
    path[0]=0;
    risk(map,n,m,0,0,map[0][0],path,1);
    printf("%d",MAX_VALUE);
    return 0;
}