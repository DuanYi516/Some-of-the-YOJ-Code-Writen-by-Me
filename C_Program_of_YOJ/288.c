/*编程输出两个字符串的差。

两个字符串S1、S2的差定义如下：S1和S2的按字典序比较大小。
若S1和S2相等，则输出为0；若它们不相等，则输出其第一个不同字符的ASCII码的差值，
且如果S1>S2，则差值为正；如果S1<S2，则差值为负。

输入格式
　　共2行，第1行是字符串S1，第2行是字符串S2。注意：
输入数据保证每一个字符串不是另一个的前缀，且长度在100以内。*/
#include<stdio.h>
#include<string.h>
int main(){
    char s1[100],s2[100];
    gets(s1);gets(s2);
    if(strcmp(s1,s2)==0){printf("0");}
    else{
        for(int i=0;i<strlen(s1);i++){
            if(s1[i]!=s2[i]){printf("%d",s1[i]-s2[i]);break;}
        }
    }
    return 0;
}