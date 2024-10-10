// 第一行：输入两个整数，中间用一个逗号隔开；
// 　　第二行：输入两个浮点数，中间用空格隔开；
// 　　第三行：输入两个字母，每个字母前面加一个空格，中间加一个逗号。
#include<stdio.h>
int main(){
    int n1,n2;
    float f1,f2;
    char c1,c2;
    scanf("%d,%d",&n1,&n2);
    scanf("%f %f",&f1,&f2);
    scanf(" %c, %c",&c1,&c2);
    printf("%d,%d\n",n1,n2);
    printf("%.1f %.1f\n",f1,f2);
    printf(" %c, %c\n",c1,c2);
    return 0;
}