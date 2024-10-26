#include<stdio.h>
int main(){
    int n;scanf("%d",&n);
    for(int i=0;i<n-1;i++)printf(" ");
    for(int i=0;i<n;i++)printf("*");
    printf("\n");
    for(int col=0;col<n-2;col++){
        for(int i=0;i<n-2-col;i++)printf(" ");
        printf("*");
        for(int i=0;i<n+2*col;i++)printf(" ");
        printf("*\n");
    }
    printf("*");
    for(int i=0;i<3*n-4;i++)printf(" ");
    printf("*\n");
    for(int col=n-3;col>=0;col--){
        for(int i=0;i<n-2-col;i++)printf(" ");
        printf("*");
        for(int i=0;i<n+2*col;i++)printf(" ");
        printf("*\n");
    }
    for(int i=0;i<n-1;i++)printf(" ");
    for(int i=0;i<n;i++)printf("*");
    printf("\n");
    return 0;
}