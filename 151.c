#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int min_wave(int *arr,int day,int revenue);
int main(){
    int n;scanf("%d",&n);
    int* arr = malloc(sizeof(int) * n);
    if(arr == NULL){perror("fun_name");return 1;}
    scanf("%d",&arr[0]);int res=arr[0];
    for(int day=1;day<n;day++){
        scanf("%d",&arr[day]);
        res+=min_wave(arr,day,arr[day]);
    }
    printf("%d",res);
    free(arr);
    arr = NULL;
    return 0;
}
int min_wave(int *arr,int day,int revenue){
    int min=arr[0];
    for(int i=0;i<day;i++){
        min=(fabs(arr[i]-revenue)<min)?fabs(arr[i]-revenue):min;
    }
    return min;
}