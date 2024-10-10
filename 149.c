#include<stdio.h>
int main(){
    int a[5][5],b[5][5];
    int N,P,M;
    scanf("%d %d %d",&N,&P,&M);
    for(int i=0;i<N;i++){for(int j=0;j<P;j++){scanf("%d",&a[i][j]);}}
    for(int i=0;i<P;i++){for(int j=0;j<M;j++){scanf("%d",&b[i][j]);}}
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            int sum=0;
            for(int k=0;k<P;k++){sum+=a[i][k]*b[k][j];}
            printf("%d ",sum);
        }
        printf("\n");
    }
    return 0;
}