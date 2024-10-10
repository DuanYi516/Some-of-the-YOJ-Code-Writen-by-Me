/*选择排序实际是对“冒泡法”的优化算法：每次只需一次交换就可以将一个元素放到正确的位置。
对于当前数组，通过一次扫描，查找数组中的最小元素。然后将最小元素与当前数组中第一个元素交换。
对从二个元素开始到最后元素结束的这个子数组重复这个过程。执行n-1遍后有序。这种排序与冒泡排序相似，
对于n个元素的数组，要n-1遍，对每个子数组，要用n-1次比较以求得最小值。当处理包含一个元素的子数组时，
数组已经排序完毕。编写递归程序，完成这个算法。 

输入格式

　　第一行：一个整数n（n<=100）
　　第二行：n个整数a[i]（保证a[i]在int范围内）

输出格式

　　按倒序（从最后一步到第一步）输出若干次交换步骤，以 i<->j:当前数组 的形式输出，i和j表示进行交换的两个元素在当前数组中的下标（从1开始，j是当前找到的最小元素的下标），每个步骤占一行；（如果a[i]本来就在正确的位置，则不需要交换）
　　紧接一行：以Total steps:tot 的形式输出，tot表示总的交换次数；
　　最后一行：以Right order:正确序列 的形式输出。*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void swap(int *a,int n,int N);
int count=0;
char write[99][210];
int main(){
    int n;scanf("%d",&n);int N=n;
    int *a=malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){scanf("%d",&a[i]);}

    // int n=15,a[15]={3,2,1,4,5,15,14,13,12,11,10,6,7,8,9};
    // int N=n;
    swap(a,n,N);
    for(int i=1;i<=count;i++){printf("%s\n", write[count-i]);}
    printf("Total steps:%d",count);
    printf("\nRight order:");
    for(int i=0;i<n;i++){printf("%d ",a[i]);}
    return 0;
}
void swap(int *a,int n,int N){
    if(n>1){
        int id_min=0;
        for(int i=1;i<n;i++){id_min=(a[i]<a[id_min])?i:id_min;}
        if(id_min>0){
            int temp=a[id_min];
            a[id_min]=a[0];
            a[0]=temp;
            char left[40],right[40];
            sprintf(left,"%d",N-n+1);
            sprintf(right,"%d",N-n+1+id_min);
            strcpy(write[count],left);
            strcat(write[count],"<->");
            strcat(write[count],right);
            strcat(write[count],":");
            for(int i=0;i<N;i++){
            char value[4];
            sprintf(value,"%d ",a[i+n-N]);
            strcat(write[count],value);
            }
            count++;
            swap(a+1,n-1,N);
            // printf("%d<->%d:",N-n+1,N-n+1+id_min);
            // for(int i=0;i<N;i++){printf("%d ",a[i+n-N]);}
            // printf("\n");
        }
        else
        swap(a+1,n-1,N);
    }
}