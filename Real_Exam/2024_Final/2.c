#include<stdio.h>
#include<string.h>
int main(){
    float rate;scanf("%f",&rate);
    getchar();
    // char rtn[5];scanf("%s",rtn);
    float m; 
    char unit[4];
    scanf("%f%s",&m,unit);
    //scanf("");a
    
    if(strcmp(unit,"USD")==0){
        printf("%.2fRMB",m*rate);
    }else if(strcmp(unit,"RMB")==0){
        printf("%.2fUSD",m/rate);
    }else{
        printf("ERROR");
    }
    return 0;
}