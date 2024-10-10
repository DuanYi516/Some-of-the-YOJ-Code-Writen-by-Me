#include<stdio.h>
int mutiple(int n);
int main(){
    int n;scanf("%d",&n);
    printf("%d",mutiple(n)%10000);
}
int mutiple(int n){
    int res[2][2]={{1,0},{0,1}};
    for(int i=0;i<n-1;i++){
        int temp1=res[0][0]%10000,temp2=res[0][1]%10000;
        res[0][0]+=res[1][0]%10000;
        res[0][1]+=res[1][1]%10000;
        res[1][0]=temp1%10000;
        res[1][1]=temp2%10000;
    }
    if(n==0)return 0;
    else return res[0][0];
}
