#include<stdio.h>
#include <string.h>
#include<stdlib.h>
int bin_search(int nums[],int n,int target,int count);
void swap(int s[],int n);
int min(int s[],int n);

int main(){
    int *nums,n,target;
    scanf("%d %d",&n,&target);
    nums = (int *)malloc(n * sizeof(int)); // 分配内存给数组a
    for(int i=0;i<n;i++){scanf("%d",&nums[i]);}
    swap(nums,n);
    int count=0;
    printf("%d\n",bin_search(nums,n,target,count));
    return 0;
}

int bin_search(int nums[],int n,int target,int count){
    int left=0,right=n-1;
    while (left<=right){
        int mid=(left+right)/2;
        count+=1;
        if( nums[mid]<target)left=mid+1;
        else if (nums[mid]==target){printf("%d\n",mid);return count;}
        else right=mid-1;   
    }
    if(nums[left]==target){printf("%d\n",left);return count;}
    else {printf("-1\n");return count;}
}
void swap(int s[],int n){
    int temp,id_m,id_head;
    int flag=0;
    for(int i=0;i<n-1;i++){if(s[i]<=s[i+1])flag+=1;}
    if(flag!=n-1){
        temp=min(s,n);
        for(int i=0;i<n;i++){if(s[i]==temp)id_m=i;}
        for(int i=0;i<n;i++){if(s[i]==s[0])id_head=i;}
        s[id_m]=s[0];
        s[0]=temp;
        swap(s+1,n-1);
    }
}
int min(int s[],int n){
    int min=s[0];
    for(int i=0;i<n;i++){if(s[i]<min)min=s[i];}
    return min;
}