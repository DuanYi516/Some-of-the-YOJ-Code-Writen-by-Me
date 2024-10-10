#include<stdio.h>
int min(int*to,int*price);
int main(){
    int price[8]={100,200,500,1000,1000,600,600,2000};
    int toA[8]={200,20,10,1,50,20,50,8};
    int toB[8]={500,100,8,1,33,5,20,5};
    int toC[8]={999999,99999,100,99999,99999,50,10,10};
    int toD[8]={10000,10000,17,100,10000,5,7,10};
    int toE[8]={200,300,22,1,100,200,350,200};
    int toF[8]={500,99999,200,2000,50,100,200,30};
    int toG[8]={400,99999,100,1500,30,50,100,20};
    int toH[8]={1200,99999,3000,5000,70,400,1000,100};
    int enermy[8];
    for(int i=0;i<8;i++){scanf("%d",&enermy[i]);}//={100,100,100,100,100,100,100,100}
    int temp_cost1;
    temp_cost1=min(toA,price)*enermy[0];
    int temp_cost2;
    temp_cost2 = min(toB, price)*enermy[1];
    int temp_cost3;
    temp_cost3 = min(toC, price)*enermy[2];
    int temp_cost4;
    temp_cost4 = min(toD, price)*enermy[3];
    int temp_cost5;
    temp_cost5 = min(toE, price)*enermy[4];
    int temp_cost6;
    temp_cost6 = min(toF, price)*enermy[5];
    int temp_cost7;
    temp_cost7 = min(toG, price)*enermy[6];
    int temp_cost8;
    temp_cost8 = min(toH, price)*enermy[7];
    int all_cost=0;
    all_cost= temp_cost1 + temp_cost2 + temp_cost3 + temp_cost4 + temp_cost5 + temp_cost6 + temp_cost7 + temp_cost8;
    printf("%d",all_cost/100);
}
int min(int*to,int*price){
    int mini=to[0]*price[0];
    for(int i=0;i<8;i++){
        if(to[i]*price[i]<mini){mini=to[i]*price[i];}
    }
    return mini;
}