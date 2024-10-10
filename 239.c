#include<stdio.h>
#include<string.h>
int main(){
    char n[100]="3144657";
    int k=3;
    //scanf("%c %d",&n,&k);
    int len_n=strlen(n);
    int n_arr[10];
    for(int i=0;i<len_n;i++){
        n_arr[i]=n[i]-48;
        //printf("%d ",n[i]);
    }
    //printf("\n");
    for(int i=0;i<len_n;i++)printf("%d ",n_arr[i]);
    return 0;
}