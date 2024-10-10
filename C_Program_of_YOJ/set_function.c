#include<stdio.h>
#include<math.h>
int *Set(int len,int num[],int set[]);
int not_in(int num[],int I,int len,int set[],int lenset);
int main(){
    //换成自定义的数组
    int len=7,num[7]={2,1,1,1,3,7,6};
    int set[7];
    //开始操作
    int *s=Set(len,num,set);
    int lenset;
    for(int i=0;i<len;i++){
        if(s[i]!=0)set[i]=s[i];
        else {lenset=i;break;}
    }
    for(int i=0;i<lenset;i++){printf("%d ",set[i]);} //输出2 1 3 7 6
}
int *Set(int len,int num[],int set[]){
    int lenset=0;
    for(int i=0;i<len;i++){
        if(not_in(num,i,len,set,lenset)){
            set[lenset]=num[i];
            lenset+=1;
        }
    }
    set[lenset]=0; //标志结束，方便接下来得知lenset
    return (int*)set;
}
int not_in(int num[],int I,int len,int set[],int lenset){
    //输入I，遍历每一个set里面的值，看看是否存在过了
    int flag=0;
    for(int i=0;i<lenset;i++){if(num[I]!=set[i])flag+=1;}
    if(flag==lenset)return 1;
    else return 0;
}