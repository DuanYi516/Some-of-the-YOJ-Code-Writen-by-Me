#include<stdio.h>
int not_in(int num,int a[6]);
int main(){
    int a[6]={2,1,3,3,1,1};
    int already[6],len_already=0;
    int count[6]={0};
    for(int i=0;i<6;i++){
        if(not_in(a[i],already)){
            already[len_already]=a[i];
            count[len_already]++;
            len_already++;
        }
        else{
            for(int j=0;;j++){
                if(a[i]==already[j]){
                    count[j]++;
                    break;
                }
            }
        }
    }
    for(int i=0;i<len_already;i++)printf("%d",count[i]);
    return 0;
}
int not_in(int num,int a[6]){
    for(int i=0;i<6;i++){
        if(num==a[i]){
            return 0;
        }
    }
    return 1;
}