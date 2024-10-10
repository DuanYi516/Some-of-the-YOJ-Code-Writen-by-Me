#include<stdio.h>
#include <math.h>
#define PI 3.1412
float my_cos(float theta,float epsilon);
int main(){
    float theta,epsilon;
    // scanf("%d %d",theta,epsilon);
    printf("\n%f\n",my_cos(2*PI-5,0.001));
    return 0;
}
int jiecheng(int n){return (n==1)?1:n*jiecheng(n-1);}
float my_cos(float theta,float epsilon){
    float error=0;
    float rough=1;
    float exact=cosf(theta);
    for(int i=1;i<15;i++){//error<epsilon
        int fuhao;
        fuhao=(i%2==0)?1:-1;
        rough+= fuhao*pow(theta,2*i)/jiecheng(2*i);
        // printf("%f/%d=%f\n",pow(theta,2*i),jiecheng(2*i),pow(theta,2*i)/jiecheng(2*i));
        error=fabs(rough-exact);
        printf("error=%.2f,rough=%f\n  x^2k=%.f,2k!=%d\n",error,rough,pow(theta,2*i),jiecheng(2*i));
    }
    return rough;
}