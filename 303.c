// #include<stdio.h>
// int main(){
//     float price;
//     int n;
//     scanf("%f %d",&price,&n);
//     if(n==1)printf("%.2f",price);
//     else if(n==2)printf("%.2f",1.6*price);
//     else if(n>=3&&n<=5)printf("%.2f",n*0.7*price);
//     else printf("%.2f",5*0.7*price+(n-5)*price*1.1);
//     return 0;
// }
#include<stdio.h>
int main(){
    int ld=0,lzw=0;
    while ( !feof(stdin) ){
        int a;
        scanf("%d",&a);
        if(a==0){ld+=1;}
        else{lzw+=1;}
        if(ld>=21||lzw>=21){
            if(ld-lzw=1){printf("0");break;}
            else printf("1");break;
        }
    }
    return 0;
}