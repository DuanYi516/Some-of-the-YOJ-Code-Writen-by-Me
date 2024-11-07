#include<stdio.h>
#include<math.h>
unsigned int f(unsigned int a,unsigned int b, unsigned int c, unsigned int d, unsigned int e,unsigned int x);
unsigned int main(){
    unsigned int n,k;scanf("%d %d",&n,&k);
    unsigned int record1[100]={0},record2[100]={0},score1=0,score2=0;
    for (unsigned int round = 0; round < n; round++){
        unsigned int a,b,c,d,e,x;scanf("%d %d %d %d %d %x",&a,&b,&c,&d,&e,&x);
        unsigned int ans1,ans2;scanf("%d %d",&ans1,&ans2);
        if(ans1==f(a,b,c,d,e,x)){record1[round]=1;score1++;}
        if(ans2==f(a,b,c,d,e,x)){record2[round]=1;score2++;}
    }
    
    unsigned int flat1=1;
    for(unsigned int round = 0; round < n-1; round++){
        if(record1[round]==record1[round+1]){flat1++;}
        if(flat1>k){score1++;flat1=0;}
    }
    unsigned int flat2=1;
    for(unsigned int round = 0; round < n-1; round++){
        if(record2[round]==record2[round+1]){flat2++;}
        if(flat2>k){score1++;flat2=0;}
    }
    printf("%d %d",score1,score2);
    return 0;
}
unsigned int f(unsigned int a,unsigned int b, unsigned int c, unsigned int d, unsigned int e,unsigned int x){
    unsigned int res=a*x*x*x*x+b*x*x*x+c*x*x+d*x+e;
    return res;
}