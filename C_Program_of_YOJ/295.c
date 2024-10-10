#include <stdio.h>
#include <stdlib.h>
#include <math.h>
float *sigmoid(float x[],int dim);
void dot(float a[16],float b[16],int m,int d,float*dot_res);

float *sigmoid(float x[],int dim){
    float *sigmd =(float *)malloc(dim * sizeof(float));
    if (sigmd == NULL) {fprintf(stderr, "Memory allocation failed\n");exit(1);}

    for(int i=0;i<dim;i++){sigmd[i]=(double)exp((double)x[i])/(1+(double)exp(x[i]));}
    return sigmd;
}
void dot(float a[16],float b[16],int m,int d,float*dot_res){
    for(int i=0;i<d;i++){
        float sum=0;
        for(int j=0;j<m;j++){sum+=a[j]*b[i*m+j];}
        dot_res[i]=sum;
    }
}
int main(){
    int m,d,n;
    float x[16],W[16*16],V[16*16];
    scanf("%d %d %d",&m,&d,&n);
    for(int i=0;i<m;i++){scanf("%f",&x[i]);}
    for(int i=0;i<m*d;i++){scanf("%f",&W[i]);}
    for(int i=0;i<n*d;i++){scanf("%f",&V[i]);}
    //first layer
    float W_tx[16];
    dot(x,W,m,d,(float*)W_tx);
    float *s_W_tx=sigmoid(W_tx,d);
    //second layer
    float V_th[n];
    dot((float*)s_W_tx,(float*)V,d,n,V_th);
    float *s_V_th=sigmoid(V_th,n);
    
    for(int i=0;i<n;i++){printf("%.2f ",s_V_th[i]);}
    return 0;
}