#include<stdio.h>
int main(){
    int n;scanf("%d",&n);
    int dis[50]={0},remain[50]={0},change[50]={0},time[50]={0};
    for(int i=1;i<=n;i++)scanf("%d",&dis[i]);
    for(int i=1;i<=n;i++)scanf("%d",&remain[i]);
    for(int i=1;i<=n;i++)scanf("%d",&change[i]);
    for(int i=1;i<=n;i++)scanf("%d",&time[i]);
    int res=0;
    dis[0]=100000000;
    for(int i=1;i<=n;i++){
        if(remain[i]*10+time[i]*change[i]>0){
            res=(dis[i]<dis[res])?i:res;
        }
    }
    printf("%d",res);
}
