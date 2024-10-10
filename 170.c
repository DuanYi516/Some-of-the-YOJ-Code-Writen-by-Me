#include<stdio.h>
int main(){
    int ld=0,lzw=0;
    while ( !feof(stdin) ){
        int a;
        scanf("%d",&a);
        if(a==0){ld+=1;}
        else{lzw+=1;}
        if(ld>=21||lzw>=21){
            if(ld-lzw>=1){printf("0");break;}
            else if(lzw-ld>=1){printf("0");break;}
        }
    }
    return 0;
}