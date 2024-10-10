/*利用控制台的这个特点，我们可以在控制台上绘制简单的图形。
下面给出了一个5*7的图形的例子：

    ABCDEFG
    BABCDEF
    CBABCDE
    DCBABCD
    EDCBABC
    找出这个图形的特点，给出n和m，绘制一个n*m的图形。

输入格式
　　输入包含两个数n, m，用一个空格分隔。1<=n,m<=24

输出格式　　
输出与上图类似的一个n*m的图形。*/
#include <stdio.h>
int main()
{
    int n,m;scanf("%d %d",&n,&m);
    //int n = 7, m = 3;
    for (int i = 0; i < n; i++){
        if (i < m){
            for (int j = 0; j < i; j++){
                printf("%c", i - j + 65);
            }
            for (int j = i; j < m; j++){
                printf("%c", j - i + 65);
            }
        }
        else
            for (int j = 0; j < m; j++){
                printf("%c", i-j+65);
            }
        printf("\n");
    }
    return 0;
}