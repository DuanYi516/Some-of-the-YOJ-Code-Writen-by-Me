#include<stdio.h>
int count=0;
int N;
int is_safe(int board[100][100],int col,int row){
    for(int i=1;col-i>=0;i++){
        if(board[row][col-i]==1){
            return 0;
        }
    }
    for(int i=1;col-i>=0,row-i>=0;i++){
        if(board[row-i][col-i]==1){
            return 0;
        }
    }
    for(int i=1;col-i>=0,row+i<N;i++){
        if(board[row+i][col-i]==1){
            return 0;
        }
    } 
    return 1;
}
void solve(int board[100][100],int col,int N){
    if(col==N){
        count++;
        // printf("Solution %d\n",count);
        // for(int i=0;i<N;i++){
        //     for(int j=0;j<N;j++){
        //         printf("%d ",board[i][j]);
        //     }
        //     printf("\n");
        // }
        // printf("\n");
    }else{
        for(int row=0;row<N;row++){
            if(is_safe(board,col,row)){
                board[row][col]=1;
                solve(board,col+1,N);
                board[row][col]=0;
            }
        }
    }
}

int main(){
    scanf("%d",&N);
    int board[100][100]={0};
    int col=0;
    solve(board,col,N);
    printf("%d",count);
    return 0;
}