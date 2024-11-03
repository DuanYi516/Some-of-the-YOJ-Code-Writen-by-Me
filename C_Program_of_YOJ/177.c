/*输入格式
　　包含n+1行。 　　第1行2个整数n（1≤n≤180）和k(3≤k≤9)，其中n表示有n个同学想要去拜访。 　　
    接下来的n行，每行一个整数a，表示一个学号。输入数据保证学号是信息学院大一新生的正规学号，且不存在相同的学号。

输出格式
　　包含m+1行，第1行一个整数m，表示可以去拜访冯神的学生人数；接下来m行，每行一个整数，表示可以去膜拜冯神的同学的学号。
注意：按照从小大的顺序输出学号。
输入样例
3 3
2013202476
2013202477
2013202478*/
#include<stdio.h>
#include<string.h>
int main(){
    int n,k;scanf("%d %d",&n,&k);
    char ids[180][11],ok_ids[180][11];
    int count=0;
    for(int i=0;i<n;i++){
        scanf("%s",&ids[i]);
        int sum=0;
        for(int num=0;num<10;num++){sum+=ids[i][num]-48;}
        if(sum%k==0){strcpy(ok_ids[count++],ids[i]);}
    }
    
    for(int start=0;start<count;start++){
        int min_i=start;
        for(int i=start+1;i<count;i++){
            min_i=(strcmp(ok_ids[i],ok_ids[min_i])<0)?i:min_i;
        }
        char temp[11];
        strcpy(temp,ok_ids[min_i]);
        strcpy(ok_ids[min_i],ok_ids[start]);
        strcpy(ok_ids[start],temp);   
    }
    printf("%d\n",count);
    for(int i=0;i<count;i++)puts(ok_ids[i]);
    return 0;
}