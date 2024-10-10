#include<stdio.h>
int main(){
    int score;
    scanf("%d",&score);
    int zero=0;
    // if(score<60){printf("%d",zero);return 0;}
    float full=4.0;
    if(score>90){printf("%.1f",full);return 0;}
    int temp=score-50;
    int gw=0,sw=0;
    for(int i=1;i<4;i++){
        if(temp-i*10-10<0){
            gw=temp-10*(i);
            sw=i;
            printf("yes\n");
            break;
        }
    }
    if(gw>=6)gw=7;
    else if(3<=gw&&gw<=5)gw=3;
    else gw=0;
    printf("%d.%d",sw,gw);
    return 0;
}