#include<stdio.h>
#include<math.h>
float *get_root(int a,int b,int c,float result[]);
float f(int a,int b,int c,int d,float x);
float bin_search(float left,float right,int a,int b,int c,int d);
int main(){
    int a,b,c,d;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    //int a=1,b=-2,c=-1,d=2;
    float result[2];
    float*r=get_root(a,b,c,result);
    float x_one=r[0],x_two=r[1];
    float x1_l,x1_r,x2_l,x2_r,x3_l,x3_r; //fabs(f(a,b,c,d,i-0.01))<1000&&fabs(f(a,b,c,d,i-0.01))<1000&&
    for(int i=-100;i<x_one;i++){if(f(a,b,c,d,i-0.01)*f(a,b,c,d,i+1.99)<0){x1_l=i-0.01;x1_r=i+1.99;break;}}
    for(int i=(int)x_one;i<x_two;i++){if(f(a,b,c,d,i-0.01)*f(a,b,c,d,i+1.99)<0){x2_l=i-0.01;x2_r=i+1.99;break;}}
    for(int i=(int)x_two;i<100;i++){if(f(a,b,c,d,i-0.01)*f(a,b,c,d,i+1.99)<0){x3_l=i-0.01;x3_r=i+1.99;break;}}
    float x1=bin_search(x1_l,x1_r,a,b,c,d);
    //printf("%f",x1);
    float x2=bin_search(x2_l,x2_r,a,b,c,d);
    float x3=bin_search(x3_l,x3_r,a,b,c,d);
    printf("%.2f %.2f %.2f",x1,x2,x3);
    return 0;
}
float f(int a,int b,int c,int d,float x){
    return a*pow(x,3)+b*pow(x,2)+c*x+d;
}
float *get_root(int a,int b,int c,float result[]){
    float deta=sqrt(4*b*b-12*a*c);
    float x_one=(-2*b-deta)/(6*a),x_two=(-2*b+deta)/(6*a);
    result[0]=x_one;result[1]=x_two;
    return result;
}
float bin_search(float left,float right,int a,int b,int c,int d){
    while (right-left>0.005)
    {
        float mid=(left+right)/2;
        float y_left=f(a,b,c,d,left);
        float y_right=f(a,b,c,d,right);
        float y_mid=f(a,b,c,d,mid);
        if(y_mid==0){right=mid;break;}
        if(y_left*y_mid<0)right=mid;
        else left=mid;
    }
    return right;
}