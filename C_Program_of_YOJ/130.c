#include<stdio.h>
#include<math.h>
int transformer(int new[],int n,int N);
int main(){
    // int n,new[1024];
    // scanf("%d",&n);
    // for(int i=0;i<n;i++){scanf("%d",&new[i]);}
    int N=16,new[16]={0,8,-2,14,-11,7,-7,15,-15,14,-3,16,-13,10,-5,0};
    transformer(new,1,N);
    for(int i=0;i<N;i++){printf("%d,",new[i]);}
}

int transformer(int new[],int n,int N){
    if(n<N){
        printf("%d : ",n);
        int wave[N];
        for(int i=0;i<N;i++){wave[i]=new[i];}
        for(int i=0;i<n;i++){
            int s=new[i],d=new[i+n];
            // printf(" s=%d,d=%d ",s,d);
            wave[2*i] = (s+d)/2;printf("w[%d]=%d,",2*i,wave[2*i]);
            wave[2*i+1]=(s-d)/2;printf("w[%d]=%d,",2*i+1,wave[2*i+1]);
        }
        printf("\n...");
        for(int i=0;i<8;i++){new[i]=wave[i];}
        for(int i=0;i<N;i++){printf("%d,",new[i]);}
        printf("\n");
        n=n*2;
        transformer(new,n,N);
    }
    else return 0;
}
// int N=16,new[16]={0,8,-2,14,-11,7,-7,15,-15,14,-3,16,-13,10,-5,0};