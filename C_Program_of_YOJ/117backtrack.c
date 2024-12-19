#include<stdio.h>
#include<stdlib.h>
void backtrack(int tree[100][100],int *path,int reslut,int floor,int N);
int MAX=0;
int main(){
    int N=7;
    int tree[100][100]={
        {11},
        {22,33},
        {44,55,66},
        {77,88,99,23},
        {11,22,33,44,55},
        {66,77,88,99,11,22},
        {33,44,55,66,77,88,99}
    };

    // FILE *file = fopen("error_117_ck3.in", "r");
    // if (file == NULL) {perror("无法打开文件");return 1;}
    // int N;fscanf(file,"%d",&N);
    // int tree[100][100];
    // for(int i=0;i<N;i++){for(int j=0;j<i+1;j++){fscanf(file,"%d",&tree[i][j]);}}

    int path[100]={0};
    int result=tree[0][0],floor=1;
    backtrack(tree,path,result,floor,N);
    printf("%d",MAX);

}
void backtrack(int tree[100][100],int *path,int reslut,int floor,int N){
    int f=floor;
    if(floor==N){
        for(int i=0;i<N;i++)printf("%d>",path[i]);
        printf("--%d\n",reslut);
        MAX=(reslut>MAX)?reslut:MAX;
        return;
    }  
    for(int loc=0;loc<2;loc++){
        reslut+=tree[f][path[f-1]+loc];
        path[f]=path[f-1]+loc;
        backtrack(tree,path,reslut,f+1,N);
        path[f]=0;
        reslut-=tree[f][path[f-1]];
    }
}