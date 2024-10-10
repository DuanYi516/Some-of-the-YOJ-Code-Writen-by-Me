#include<stdio.h>
int main(){
    int n;scanf("%d",&n);
    int matrix[100][100];
    for(int i=0;i<n;i++){
        if(i%2==1){
            for(int j=0;j<i;j++){
                matrix[j][i]=i*i+1+j;
            } //down
            for(int j=0;j<1+i;j++){
                matrix[i][i-j]=i*i+i+1+j;
            } //left    
        }
        else{
            for(int j=0;j<i;j++){
                matrix[i][j]=i*i+1+j;
            } //right
            for(int j=0;j<i+1;j++){
                matrix[i-j][i]=i*i+i+1+j;
            } //up
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}