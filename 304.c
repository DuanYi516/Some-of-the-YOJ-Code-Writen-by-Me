/*编写一个程序计算整数区间[a, b]内，其个位数是n，且能被k整除的m位正整数共有多少个。

【输入格式】

输入只有一行，输入5个整数a、b、n、k、m，空格分隔，其中：1≤a≤b≤1,000,000，且0≤n, k, m≤9。

【输出格式】

输出一行，为符合要求的整数个数。*/
#include<stdio.h>
#include<math.h>
int wei(int i);
int main(){
    int a,b,n,k,m;
    scanf("%d %d %d %d %d",&a,&b,&n,&k,&m);
    int count=0;
    for(int i=a;i<=b;i++){
        if(i%10==n&&wei(i)==m&&i%k==0)count+=1;
        }
    printf("%d",count);
}
int wei(int i){
    int count=0;
    for(int k=1;k<10;k++){
        if(i!=0){
            i-=i%(int)pow(10,k);
            count++;
        }
        else break;
    }
    return count;
}