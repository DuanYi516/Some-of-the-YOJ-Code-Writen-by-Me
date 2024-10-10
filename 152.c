#include<stdio.h>
#include <stdlib.h>
#include<string.h>
int max(char*input,int len_in);
int power(int x,int n);
int b_to_10(int b,char *x,int len_x);
int main(){
    int T;scanf("%d",&T);
    int res_list[100];
    for(int i=0;i<T;i++){
        char *p,*q,*r;
        char input[1000000];
        scanf(" %[^\n]", input); // 读取整行输入，包括空格
        // 使用 strtok 分割字符串
        p = strtok(input, " ");
        q = strtok(NULL, " ");
        r = strtok(NULL, " ");
        
        int len_p=strlen(p),len_q=strlen(q),len_r=strlen(r);
        int min_b=1+max(input,len_p+len_q+len_r);
        res_list[i]=0;
        for(int b=min_b;b<100;b++){  //给定每一个b进制，转换成10进制
            int p_10=b_to_10(b,p,len_p);
            int q_10=b_to_10(b,q,len_q);
            int r_10=b_to_10(b,r,len_r);
            if(p_10*q_10==r_10){
                res_list[i]=b;
                break;
            }
        }    
    }
    for(int i=0;i<T;i++)printf("%d\n",res_list[i]);
    return 0;
}
int max(char*input,int len_in){
    int mx=input[0];
    for(int i=1;i<len_in+2;i++){mx=(input[i]>mx)?input[i]:mx;}
    return mx-48;
}
int b_to_10(int b,char *x,int len_x){
    int res=0;
    for(int i=0;i<len_x;i++){res+=(x[i]-48)*power(b,(len_x-i-1));}
    return res;
}
int power(int x,int n){
    int res=1;
    for(int i=0;i<n;i++)res*=x;
    return res;
}