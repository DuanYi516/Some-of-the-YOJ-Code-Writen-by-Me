#include<stdio.h>
int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    int min=(a>b)?a:b;
    for(int i=min;i<=a*b;i++){
        if(i%a==0&&i%b==0){
            printf("%d",i);
            break;
        }
    }
}