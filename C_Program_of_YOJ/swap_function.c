#include<stdio.h>
void swap(int s[],int n);
int min_i(int s[],int n);
int main(){
    // 自定义数组s、其长度n
    int s[10]={3,6,1,10,2,9,4,7,5,8};
    int n=10;

    swap(s,n);
    for(int i=0;i<n;i++)printf("%d ",s[i]);

    return 0;
}
void swap(int s[],int n){
    int id_min;
    int flag=0;
    for(int i=0;i<n-1;i++){if(s[i]<=s[i+1])flag+=1;} //判断是否全部升序
    if(flag!=n-1){
        id_min=min_i(s,n);
        int temp=s[0];
        s[0]=s[id_min];
        s[id_min]=temp;  // 以上4行是在交换当前数组的首项与最小项
        swap(s+1,n-1);
    }
}
int min_i(int s[],int n){
    int min_i=0;
    for(int i=1;i<n;i++){if(s[i]>s[min_i]){min_i=i;}} //换成“s[i]<s[min_i]”就是从大到小
    return min_i;
}