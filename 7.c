// #include <stdio.h>
// #include <math.h>
// int main()
// {
//     int a, b, c;
//     scanf("%d %d %d", &a, &b, &c);
//     float q = (a + b + c) / 2; 
//     float s = sqrt(q * (q - a) * (q - b) * (q - c)); 
//     int rough;
//     s=100*s+1;
//     rough=(int)s;
//     printf("%.2f\n",(float)rough/100);
//     return 0;
// }
// #include<stdio.h>
// int main(){
//     int a,b,c;
//     scanf("%d,%d,%d",&a,&b,&c);
//     if(a>b){
//         a=a+b; 
//         b=a-b;
//         a=a-b;
//     }
//     if(b>c){
//         b=b+c; 
//         c=b-c;
//         b=b-c;
//     }
//     if(a>b){
//         a=a+b; 
//         b=a-b;
//         a=a-b;
//     }
//     printf("%d,%d,%d",a,b,c);
//     return 0;

// }
#include<stdio.h>
int* twoSum(int* nums, int numsSize, int target, int* returnSize);
int main(){
    int nums[3] = {3,2,4}, target = 6;
    int returnSize[2];
    printf("%d %d",*twoSum(nums,3,target,returnSize),*(twoSum(nums,3,target,returnSize)+1));
    return 0;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    
    return returnSize;
};