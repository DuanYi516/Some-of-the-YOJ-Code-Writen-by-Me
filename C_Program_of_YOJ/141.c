#include<stdio.h>
struct type_loc{
    int row;
    int col;
};

int main(){
    // int m,n;
    // scanf("%d %d",&m,&n);
    // int matrix[100][100];
    // for(int i=0;i<m;i++){for(int j=0;j<n;j++)scanf("%d",&matrix[i][j]);}
    int m=4,n=6;
    int matrix[4][6]={
        {1,7,4,0,9,4},
        {0,7,0,4,5,5},
        {1,7,1,1,0,0},
        {0,7,2,0,0,0},
    };
    int max_sum=0,row_max_sum=0,col_max_sum=0;
    struct type_loc my_best_loc[1000];int count=0;
    for(int row=0;row<m;row++){
        for(int col=0;col<n;col++){
            int add=(row>0)*matrix[row-1][col]+
                    (row+1<m)*matrix[row+1][col]+
                    (col>0)*matrix[row][col-1]+
                    (col+1<n)*matrix[row][col+1]+
                    matrix[row][col];
            if(add>max_sum){
                max_sum=add;
                my_best_loc[0].row=row;
                my_best_loc[0].col=col;
                count=1;
            }
            else if(add==max_sum){
                my_best_loc[count].row=row;
                my_best_loc[count].col=col;
                count++;
            }
        }
    }
    printf("%d ",max_sum);
    printf("%d\n",count);
    for(int i=0;i<count;i++)printf("%d %d\n",my_best_loc[i].row,my_best_loc[i].col);
    
    return 0;
}