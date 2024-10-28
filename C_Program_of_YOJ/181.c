/*  f(1)=1
    f(2)=1 
    f(n)=(A*f(n-1)+B*f(n-2)) mod 7. 
    给你A,B和n,你要算出f(n)的值
    提示：mod 表示求模运算，A mod B 表示A除以B的余数

输入格式
　　一行，包括包含3个整数A,B和n(1<=a,b<=100,1<=n<=10000)。*/
#include<stdio.h>
int f(int A,int B,int n,int his[10000]);
int main(){
    int A,B,n;scanf("%d %d %d",&A,&B,&n);
    int his[10000]={0};
    printf("%d",f(A,B,n,his));
    return 0;
}
int f(int A,int B,int n,int his[10000]){
    if(n==1||n==2){return 1;}
    else {
        if(his[n]!=0)return his[n];        
        int res=(A*f(A,B,n-1,his)+B*f(A,B,n-2,his))%7;
        his[n]=res;
        return res;
        }
}