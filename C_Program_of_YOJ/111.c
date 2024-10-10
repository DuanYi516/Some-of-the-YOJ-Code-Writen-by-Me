#include <stdio.h>
int find(int n);
int judge(int m, int n, int history);
int main(){
    int each[20]; // 储存每一次输入的值
    for (int i = 0; i < 20; i++){
        scanf("%d", &each[i]);
        if (each[i] == 0)break;
    }

    for (int i = 0; each[i] != 0; i++){
        int result = find(each[i]);
        if (result == 10086)printf("no solution\n");
        else printf("%d\n", result);
    }
    return 0;
}
int find(int n){
    // 查找输入的n存不存在满足要求的m，存在输出m，否则输出10086
    for (int m = 2; m < 10; m++){
        if (judge(m, n, 0))return m;
    }
    return 10086;
}
int judge(int m, int n, int history){
    // 输入m，n检测是否符合要求，可以就返回1，不可以就返回0
    if (history < m){ // 前m天
        if ((n - 1) % m == 0){
            n = (n - 1) * (m - 1) / m;
            history += 1;
            return judge(m, n, history); // 递归
        }
        else return 0;
    }
    else{ // 第m+1天
        if (n % m == 0)return 1;
        else return 0;
    }
}