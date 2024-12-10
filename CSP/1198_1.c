#include<stdio.h>
 int main(){
    int n,m;scanf("%d %d",&n,&m);
    int info[1000][10];
    for (int str=0;str<n;str++){
        for (int pack=0;pack<m;pack++){
            scanf("%d",&info[str][pack]);
        }
    }
    int res[1000]={0};
    for(int i=0;i<n;i++)res[i]=0;
    for(int str=0;str<n;str++){
        int is_find=0;
        for(int wnt=0;wnt<n;wnt++){
            if(wnt==str)continue;
            int is_wnt=1;
            for(int pack=0;pack<m;pack++){
                if(info[wnt][pack]<=info[str][pack]){
                    is_wnt=0;
                    break;
                }
            }
            if (is_wnt) {
                res[str]=wnt+1;
                is_find=1;
                break;
            }    
        }
    }
    for(int i=0;i<n;i++)printf("%d\n",res[i]);
    return 0;
 }