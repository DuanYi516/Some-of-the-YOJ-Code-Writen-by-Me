/*输入格式
　　输入2行，第一行为输入n，表示学生的总人数。n为整数，取值范围是：1≤n≤200。
　　第二行共n个数，数据之间用一个空格分隔，最后以回车结尾。
数据为学生每天用于学习程序设计的时间t。t为整数，以分钟为单位。
输出格式
　　输出一行，共有3个数数，依次是最长时间、最短时间和平均时间，两个整数之间以一个空格分隔，回车结束。
时间都是以分钟为单位，输出时间数据按四舍五入保留整数。*/
#include<stdio.h>
int main(){
    int n;
    int time[200];
    int sum,max=0,min=10086;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&time[i]);
        sum+=time[i];
        if(time[i]<min){min=time[i];}
        if(time[i]>max){max=time[i];}
    }
    float avg=(float)sum/n;
    int int_avg;
    int_avg=sum/n;
    int add=0;
    printf("%f,%d,%f\n",avg,int_avg,avg*10-int_avg*10);
    if(avg*10-int_avg*10>=5){add=1;}
    printf("%d,%d,%d",max,min,int_avg+add);
    return 0;
}