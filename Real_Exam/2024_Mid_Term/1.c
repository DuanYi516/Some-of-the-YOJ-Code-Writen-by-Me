/*【问题描述】
磅（英语：pound）是英国与美国所使用的英制质量单位，简写是lb。历史上经过多年的演变，英制质量系统对磅也产生许多不同的定义。
最普遍被使用的定义是国际体重磅（国际磅），一磅等于453.59237克，此定义在1958年被美国以及其他英联邦会员国承认；
换算回来，一千克（kg）等于2.20462262磅（lb）。英国在1963年开始，依据度量衡法案的规定，改用国际磅的定义。
请编写一个程序，实现磅与公斤的互换，即输入公斤值转换为英磅值输出，输入英磅值转换为公斤值输出。

【输入格式】
输入只有一行，为一个数值w（1≤ w ≤10,000,000），及其后紧跟的重量单位缩写lb或kg。
【输出格式】
重转换结果，一个数值，精度保留小数点后3位，及其后紧跟的重量单位缩写lb或kg。
【输入样例1】
1kg
【输出样例1】
2.205lb
【输入样例2】
1lb
【输出样例2】

0.454kg*/
#include<stdio.h>
#include<string.h>
int main(){
    float weight;scanf("%f",&weight);
    char unit[3];scanf("%s",unit);
    if(strcmp(unit,"kg")==0)printf("%.3flb",weight*2.20462262);
    else if(strcmp(unit,"lb")==0)printf("%.3fkg",weight*0.45359237);
    return 0;
}