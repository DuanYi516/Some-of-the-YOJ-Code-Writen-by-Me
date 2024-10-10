#include<stdio.h>
#include <stdlib.h>
void backtrack(int *path,int *choice,int path_size,int choice_size,int max,int* result);
int contain(int*path,int path_size,int the_choice);
int main(){
    FILE *file = fopen("E:/04ComputerSience/C_Program_learning/yoj/error_117_ck2.in", "r");
    if (file == NULL) {perror("无法打开文件");return 1;}
    int n;fscanf(file,"%d",&n);
    int tree[100][100];
    for(int i=0;i<n;i++){for(int j=0;j<i+1;j++){fscanf(file,"%d",&tree[i][j]);}}
    int max=0,result[1]={99990};
    int path[20]={0};
    backtrack(path,tree,0,n,max,result);
    printf("%d",result[0]);
    return 0;

}

void backtrack(int *path,int *choice,int path_size,int choice_size,int max,int *result){
    
    if(path_size==choice_size){
        result[0]=(max>result[0])?max:result[0];
        for(int i=0;i<choice_size;i++){printf("%c->",path[i]);}
        printf("\n");
    }
    
    for(int i=0;i<choice_size;i++){
        if(contain(path,path_size,choice[i]))continue;
        path[path_size++]=choice[i];
        max+=choice[i];
        backtrack(path,choice,path_size,choice_size,max,result);
        path[--path_size]=0;
        max-=choice[i];
    }
    //return result;
}
int contain(int*path,int path_size,int the_choice){
    for(int i=0;i<path_size;i++){
        if(path[i]==the_choice)return 1;
    }
    return 0;
}
