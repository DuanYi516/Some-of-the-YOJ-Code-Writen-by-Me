#include<stdio.h>
int max(int a,int b){
    return (a>b)?a:b;
}
int main(){
    int n;scanf("%d",&n);
    int range_list[100][2];
    for(int i=0;i<n;i++){
        scanf("%d %d",&range_list[i][0],&range_list[i][1]);
    }
    for(int i=0;i<n;i++){
        for(int cur=i+1;cur<n;cur++){
            if(range_list[cur][0]<range_list[i][0]){
                int tmp1=range_list[cur][0];
                int tmp2=range_list[cur][1];
                range_list[cur][0]=range_list[i][0];
                range_list[cur][1]=range_list[i][1];
                range_list[i][0]=tmp1;
                range_list[i][1]=tmp2;
            }
        }
    }
    int res[100][2],res_count=0;
    res[0][0]=range_list[0][0];
    res[0][1]=range_list[0][1];

    for(int i=1;i<n;i++){
        if(range_list[i][0]<res[res_count][1]){
            res[res_count][1]=max(range_list[i][1],res[res_count][1]);
        }else{
            res_count++;
            res[res_count][0]=range_list[i][0];
            res[res_count][1]=range_list[i][1];
        }
    }
    for(int i=0;i<res_count+1;i++){
        printf("%d %d\n",res[i][0],res[i][1]);
    }
    return 0; 
    
}