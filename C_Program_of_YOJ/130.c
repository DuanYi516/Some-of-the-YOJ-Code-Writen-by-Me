#include<stdio.h>
int main(){
    int N,new[1024];scanf("%d",&N);
    for(int i=0;i<N;i++)scanf("%d",&new[i]);
    for(int n=1;n<N;n=n*2){
        int wave[N];
        for(int i=0;i<N;i++){wave[i]=new[i];}
        for(int i=0;i<n;i++){
            wave[2*i] = (new[i]+new[i+n])/2;
            wave[2*i+1]=(new[i]-new[i+n])/2;
        }
        for(int i=0;i<N;i++){new[i]=wave[i];}
    }
    for(int i=0;i<N;i++){printf("%d ",new[i]);}
    return 0;
}