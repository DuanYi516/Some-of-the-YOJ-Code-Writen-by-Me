#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int ai[100];
    int result=0;
    for(int i=0;i<n;i++){
        scanf("%d",&ai[i]);
        if(ai[i]>0){result+=ai[i];}
    }
    printf("%d",result);
    return 0;
}