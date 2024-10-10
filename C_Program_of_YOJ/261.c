#include<stdio.h>
int power(int x,int n);
int main(){
    int x,n;
    scanf("%d %d",&x,&n);
    printf("%d",power(x,n));
    return 0;
}
int power(int x,int n){
    int res=1;
    for(int i=0;i<n;i++){
        res*=x;
    }
    return res;
}