#include<stdio.h>
#include<math.h>
double power(double base, int exponent);
int main(){
    int N;
    scanf("%d",&N);
    int len=0;
    for(int i=1;i<10;i++){if(N%(int)pow(10,i)==N){len=i;break;}}
    int fuhao=1;
    if(N<0)fuhao=-1;
    N=abs(N);
    int new=0;
    int half=len/2;
    int remain=len-half;
    for(int i=1;i<=len;i++){
        new+=(N%(int)pow(10,i))*(float)power(10,len+1-2*i);
        N-=N%(int)pow(10,i);
    }
    printf("%d",fuhao*new);
    return 0;
}
double power(double base, int exponent) {
    double result = 1.0;
    int positiveExponent = exponent > 0 ? exponent : -exponent;
    for(int i = 0; i < positiveExponent; i++) {
        result *= base;
    }
    return exponent > 0 ? result : 1.0 / result;
}