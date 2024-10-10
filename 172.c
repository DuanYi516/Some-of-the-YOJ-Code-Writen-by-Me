#include <stdio.h>
int main() {
    int array[100];
    for (int i = 1; i <= 100; i++) {
        int fuhao = (i % 4 == 1||i % 4 == 2) ? 1 : -1; // 使用三元运算符控制符号
        array[i-1] = i * fuhao;
    }
    int m,n;
    scanf("%d %d",&m,&n);
    int result=0;
    for(int j=m-1;j<n;j++){
        result+=array[j];
    }
    printf("%d",result);
    return 0;
}