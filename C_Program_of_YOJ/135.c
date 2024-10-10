#include<stdio.h>
#include<math.h>
#include<stdlib.h>
void swap(int sort[1000][2],int N);
int min_i(int sort[1000][2],int N);
int main(){
    FILE *file = fopen("error_135_ck1.in", "r");
    if (file == NULL) {perror("无法打开文件");return 1;}
    int N;
    fscanf(file,"%d",&N);
    char ids[1000][19];   // 0~18:身份证，
    int sort[1000][2];// 0：原本序数，1：日期大小，2：排序后序数
    for(int mem=0;mem<N;mem++){
        sort[mem][0]=mem;
        char id[19];fscanf(file,"%s",&id);
        for(int num=0;num<18;num++){
            ids[mem][num]=id[num];
            if(num>=6&&num<=13){
                //printf("%d ",ids[mem][num]-48);
                //printf("%d ",(int)pow(10,13-num));
                sort[mem][1]+=(ids[mem][num]-48)*(int)pow(10,13-num);
            }
        }
        //printf("\n");
    }
    swap(sort,N);
    for(int i=0;i<N;i++){
        int mem=sort[i][0];
        //printf("%d : ",mem);
        for(int j=0;j<18;j++){printf("%c",ids[mem][j]);}
        printf("\n");}
    return 0;
}
void swap(int sort[1000][2],int N){
    int id_min;
    int flag=0;
    for(int i=0;i<N-1;i++){if(sort[i][1]<=sort[i+1][1])flag+=1;} //判断是否全部升序
    if(flag!=N-1){
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
    for(int i=1;i<N;i++){if(sort[i][1]>sort[min_i][1]){min_i=i;}} //换成“s[i]<s[min_i]”就是从大到小
    return min_i;
}