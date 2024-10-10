/*信息组需要选一个组长。信息组一共有n个人，分别用1到n编号，其中m个人参与了投票。
得票数过半（票数大于m div 2）的人将被选为组长。
输入数据将告知这m个人分别将票投给了谁，请统计出谁将担任八中信息组的组长。
输入格式
第一行两个数n和m。
第二行有m个数，这些数都是不超过n的正整数，表明这m个人的选择。
输出格式
　　输出将被选为组长的人。如果没有人的票数过半，请输出-1。*/
#include<stdio.h>
int *Set(int len,int num[],int set[]);
int not_in(int num[],int I,int len,int set[],int lenset);
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    float judge=(float)m/2;
    int vote[10000];
    for(int i=0;i<m;i++){scanf("%d",&vote[i]);}
    int result=-1;
// 实现去重
    int set[m];
    int *s=Set(m,vote,set);
    int lenset;
    for(int i=0;i<m;i++){
        if(s[i]!=0)set[i]=s[i];
        else {lenset=i;break;}
    }
    int set_member[lenset];
    for(int i=0;i<lenset;i++){set_member[i]=set[i];}
// 处理去重后的结果
    for(int member=0;member<lenset;member++){
        int count=0;
        for(int vi=0;vi<m;vi++){
            if(vote[vi]==set_member[member]){count+=1;}
        }
        if(count>judge){result=set_member[member];break;}
    }
    printf("%d",result);
    return 0;
}
int *Set(int len,int num[],int set[]){
    int lenset=0;
    for(int i=0;i<len;i++){
        if(not_in(num,i,len,set,lenset)){
            set[lenset]=num[i];
            lenset+=1;
        }
    }
    set[lenset]=0;
    return (int*)set;
}
int not_in(int num[],int I,int len,int set[],int lenset){
    int flag=0;
    for(int i=0;i<lenset;i++){
if(num[I]!=set[i])flag+=1;}
    if(flag==lenset)return 1;
    else return 0;
}