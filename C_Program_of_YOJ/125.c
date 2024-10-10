#include<stdio.h>
int main(){
    // int n=4;
    // float matrix[9][9]={
    //     {4,-5,10,3},
    //     {1,-1,3,1},
    //     {2,-4,5,2},
    //     {-3,2,-7,-1}
    // };
    int n=4;float matrix[9][9];
    scanf("%d",&n);
    for(int i=0;i<n;i++){for(int j=0;j<n;j++){scanf("%f",&matrix[i][j]);}}

    for(int i=0;i<n-1;i++){
        if(matrix[i][i]==0){
            for(int l=i;l<n;l++){
                if(matrix[l][i]!=0)
                    for(int j=0;j<n;j++){matrix[i][j]+=matrix[l][j];}
                }
            }
        // printf("\n");
        for(int q=i+1;q<n;q++){float k;
            k=(float)matrix[q][i]/matrix[i][i];
            // printf("q=%d,i=%d\n",q,i);
            // printf("i=%d,k=%.2f=%.2f/%.2f\n",i,k,matrix[q][i],matrix[i][i]);
            for(int j=0;j<n;j++){
                matrix[q][j]=(float)matrix[q][j]-k*(float)matrix[i][j];}}

    }
    // for(int a=0;a<n;a++){
    //     for(int b=0;b<n;b++){printf("%.2f ",matrix[a][b]);}
    //     printf("\n");
    // }
    float result=1;
    for(int i=0;i<n;i++){
        if(matrix[i][i]==0)result=0;
        else {result=result*matrix[i][i];printf("%.2f*%.2f\n",result,matrix[i][i]);}
    }
    printf("%.0f",result);
    // printf("\n%f",(float)5/4);
    return 0;
}