#include<stdio.h>
#include<math.h>
int* wheel(int x,int* meiwei);
int main(){
    int a,b;
        scanf("%d %d",&a,&b);
        int reslut=0;
        for(int i=0;i<=b-a;i++){
            int n=a+i;
            int sq_n=n*n;
            
            int* n_m;
            int n_meiwei[10000];
            n_m=wheel(n,n_meiwei);

            int n_len=0;
            while (n_meiwei[n_len] != -1) {n_len++;}
            int* sq_n_m;
            int sq_n_meiwei[10000];
            sq_n_m=wheel(sq_n,sq_n_meiwei);
            int flag=0;

            for(int j=0;j<n_len;j++){
                if(n_m[j]==sq_n_m[j]){flag+=1;}
            }
            if(flag==n_len){reslut+=n;}
        }
        printf("%d\n",reslut);    
    return 0;
}
int* wheel(int x,int* meiwei){
    int len=0;
    for(int i=1;i<10;i++){
        int weishu=(x%(int)pow(10,i))/(int)pow(10,i-1);
        x-=weishu*(int)pow(10,i-1);
        meiwei[i-1]=weishu;
        len=i;
        if(x==0)break;
    }
    meiwei[len]=-1;
    return meiwei;
}
