#include<stdio.h>
#include <stdlib.h>
    FILE *file = fopen("error_290_ck14.in", "r");
    if (file == NULL) {perror("无法打开文件");return 1;}
    
    int n;
    fscanf(file,"%d",&n);
    int basket[20][100];
    int num_all[20];
    int min_num=100,min_i=0;
    for(int i=0;i<n;i++){
        fscanf(file,"%d",&num_all[i]);
        if(num_all[i]<min_num){
            min_num=num_all[i];
            min_i=i;
        }
        for(int j=0;j<num_all[i];j++){
            fscanf(file,"%d",&basket[i][j]);
        }
        swap(basket[i],num_all[i]);
    }

    //遍历数量最小的用户basket[min_i]的所有商品
    int res_list[100],num_res=0;
    for(int g=0;g<min_num;g++){
        int count=1;
        for(int mem=0;mem<n;mem++){  //遍历剩下的人
            if(mem!=min_i){
                if(basket[mem][0]>basket[min_i][g])continue;
                for(int j=0;j<num_all[mem];j++){    //对于每一个剩下的人，遍历其所购商品
                    //if(basket[mem][j]>basket[min_i][g])
                    //printf("%d ",basket[mem][j]);
                    if(basket[mem][j]==basket[min_i][g]){
                        count+=1;
                        break;
                    }
                }
            //printf("\n");
            }
        }
        if(count==n){
            res_list[num_res]=basket[min_i][g];
            num_res+=1;
        }
    }
    if(num_res==0)printf("NO");
    else{
        swap(res_list,num_res);
        for(int i=0;i<num_res;i++){
            printf("%d ",res_list[i]);
        }
    }
    return 0;
}
void swap(int s[],int n){
    int id_min;
    int flag=0;
    for(int i=0;i<n-1;i++){if(s[i]<=s[i+1])flag+=1;} //判断是否全部升序
    if(flag!=n-1){
        id_min=min(s,n);
        int temp=s[0];
        s[0]=s[id_min];
        s[id_min]=temp;  // 以上4行是在交换当前数组的首项与最小项
        swap(s+1,n-1);
    }
}
int min(int s[],int n){
    int min_i=0;
    for(int i=1;i<n;i++){if(s[i]<s[min_i]){min_i=i;}} //换成“s[i]<s[min_i]”就是从大到小
    return min_i;
}