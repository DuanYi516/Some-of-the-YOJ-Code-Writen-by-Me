#include<stdio.h>
#include<math.h>
#include<stdlib.h>
void swap(int sort[1000][2],int N);
int min_i(int sort[1000][2],int N);
int main(){
    FILE *file = fopen("error_150_ck4.in", "r");
    if (file == NULL) {perror("无法打开文件");return 1;}
    int N;fscanf(file,"%d",&N); 
    int sort[1000][2];// 0：原本序数，1：分数
    for(int mem=0;mem<N;mem++){fscanf(file,"%d %d",&sort[mem][0],&sort[mem][1]);}
    swap(sort,N);
    int rank[1000];rank[0]=0;
    for(int i=0;i<N;i++){
        if(i>0&&sort[i][1]==sort[i-1][1])rank[i]=rank[i-1];
        else rank[i]=i;
        printf("%d %d %d\n",rank[i]+1,sort[i][0],sort[i][1]);
    }
    return 0;
}
void swap(int sort[1000][2],int N){
    int id_min;
    int flag=0;
    //for(int i=0;i<N;i++){if(sort[i][1]<=sort[i+1][1])flag+=1;} //判断是否全部升序
    if(flag++!=N){
        id_min=min_i(sort,N);
        int temp_1=sort[0][1];
        sort[0][1]=sort[id_min][1];
        sort[id_min][1]=temp_1;  // 以上4行是在交换当前数组的首项与最小项
        int temp_0=sort[0][0];
        sort[0][0]=sort[id_min][0];
        sort[id_min][0]=temp_0;
        swap(sort+1,N-1);
    }
}
int min_i(int sort[1000][2],int N){
    int min_i=0;
    for(int i=0;i<N;i++){
        if (sort[i][1] > sort[min_i][1] || (sort[i][1] == sort[min_i][1] && sort[i][0] <= sort[min_i][0])) {
            min_i = i;
        }
    } //换成“s[i]<s[min_i]”就是从大到小
    //printf("%d>%d\n",min_i,sort[min_i][0]);
    return min_i;
}

