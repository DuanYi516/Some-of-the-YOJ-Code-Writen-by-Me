#include<stdio.h>
#include <stdlib.h>
int main(){
    char isbn[13];
    scanf("%s",isbn);
    char end=isbn[12];
    char yi[2]={isbn[0],'\0'};int yi_num=atoi(yi)*1;
    char er[2]={isbn[2],'\0'};int er_num=atoi(er)*2;
    char san[2]={isbn[3],'\0'};int san_num=atoi(san)*3;
    char si[2]={isbn[4],'\0'};int si_num=atoi(si)*4;
    char wu[2]={isbn[6],'\0'};int wu_num=atoi(wu)*5;
    char lu[2]={isbn[7],'\0'};int lu_num=atoi(lu)*6;
    char qi[2]={isbn[8],'\0'};int qi_num=atoi(qi)*7;
    char ba[2]={isbn[9],'\0'};int ba_num=atoi(ba)*8;
    char jiu[2]={isbn[10],'\0'};int jiu_num=atoi(jiu)*9;
    int result=(yi_num+er_num+san_num+si_num+wu_num+lu_num+qi_num+ba_num+jiu_num)%11;
    char calc[1];
    itoa(result,calc,10);
    if(calc[0]>10)calc[0]="X";
    if(calc[0]==end)printf("Right");
    else{for(int i=0;i<12;i++){printf("%s",isbn[i]);}
        printf("%s",calc[0]);}
    return 0;
}