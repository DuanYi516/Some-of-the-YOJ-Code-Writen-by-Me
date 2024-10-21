#include<stdio.h>
#include<stdlib.h>
int main(){
    int ld=0,lzw=0;
    while (1){
        int a;
        if(a==0){ld+=1;}
        else{lzw+=1;}
        if(ld>=21&& ld-lzw>=1){printf("0");break;}
        if(lzw>=21&& lzw-ld>=1){printf("1");break;}
        if(ld>=21||lzw>21){
            if(ld-lzw>1){printf("0");break;}
            else if(lzw-ld>1){printf("1");break;}
        }
    }
    return 0;
}