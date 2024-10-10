#include<stdio.h>
#include<math.h>
int find(int x);
int main (){
    int num;
    scanf("%d",&num);
    for(int a2=1;a2<=(int)num/4;a2++){
        // printf("%d * %d , a=%d,b=%d\n",find(2*a2+1),find(num-2*a2+1),2*a2+1,num-2*a2-1);
        if(find(2*a2+1)*find(num-2*a2-1)){
            printf("%d=%d+%d",num,2*a2+1,num-2*a2-1);
            break;
        }
    }
    return 0;
}
int find(int x){
    int end=sqrt(x);
    for(int i=2;i<=end;i++){if(x%i==0)return 0;}
    return 1;
}