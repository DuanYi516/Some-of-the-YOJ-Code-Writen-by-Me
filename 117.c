#include<stdio.h>
int main(){
    int n;scanf("%d",&n);
    int tree[100][100];
    for(int i=0;i<n;i++){for(int j=0;j<i+1;j++){scanf("%d",&tree[i][j]);}}

    /*  测试点2*/
    // int n=7;
    // int tree[100][100]={
    //     {11},
    //     {22,33},
    //     {44,55,66},
    //     {77,88,99,23},
    //     {11,22,33,44,55},
    //     {66,77,88,99,11,22},
    //     {33,44,55,66,77,88,99}
    // };
    /*测试点8 
    int n=3;
    int tree[3][3]={{1},{2,3},{4,6,5}};*/
    
    int path[100],res=tree[0][0];
    path[0]=0;
    for(int i=1;i<n;i++){
        if(tree[i][(int)path[i-1]]>tree[i][(int)path[i-1]+1]){
            path[i]=path[i-1];
        }
        else path[i]=path[i-1]+1;
        res+=tree[i][(int)path[i]];
        printf("%d->",path[i-1]);
    }
    printf("%d\n",path[n-1]);
    printf("%d",res);
}