#include<stdio.h>
int main(){
    int F;
    scanf("%d",&F);
    float C;
    C = (F - 32)*5;
    printf("%.2f",C/9);
    return 0;
}