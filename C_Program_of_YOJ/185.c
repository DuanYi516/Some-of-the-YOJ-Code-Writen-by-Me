/*　给定一个正整数a，用迭代法求出a的平方根并输出迭代次数。迭代公式如下： X[n+1]=1/2(X[n]+a/X[n])
要求前后两次求出的x的差绝对值小于10^-5，迭代初值取a/2。
【输入格式】
　　输入数据一行, 包含一个整数a（2 <= a <= 2^31-1）。
【输出格式】
　　共2行。
　　第一行一个数x，表示a的平方根，保留6位小数。
　　第二行一个数t，表示迭代次数。*/
#include<stdio.h>
#include<math.h>
int main(){
    unsigned int a;scanf("%u",&a);
    double X[100]={0};
    X[0]=a/2.0;
    int i=0;
    double error=1;
    while(error>1e-5){
        i++;
        X[i]=(X[i-1]+a/X[i-1])/2;
        error=fabs(X[i]-X[i-1]);
    }
    printf("%.6lf\n%d",X[i],i);
}