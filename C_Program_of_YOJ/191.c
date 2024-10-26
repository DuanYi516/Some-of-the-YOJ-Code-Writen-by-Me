/*期末考试结束后，计算机系将要为每个同学计算该学期的学分。某学生本学期获得的学分为
他所有及格（>= 60分）课程的学分之和。
现在，请你编写一个程序来计算某班学生的学分，并按学分从多到少输出学生的学号和学分。
输入格式
　　第一行为两个整数N，M（1<=N<=50，1<=M<=10），N表示该班学生的人数，M表示本学期的
课程数。
　　第二行有M个空格隔开的正整数，分别为M门课程相应的学分数（<=10）。
　　随后有N行，每行有M+1个空格隔开的非负整数（<= 100），描述一个学生的信息，依次为
学号和M门课程的得分。
输出格式
　　共有N行，按照学分从高到少每行输出一名学生的学分信息（若学分相同，则学号小的先输出
），即学号和学分，其间用一个空格隔开。*/
#include<stdio.h>
struct type_stu{
    int id[4];
    int classes[10];
    int score;
};
int main(){
    int N,M;scanf("%d %d",&N,&M);
    int point[10];
    for(int i=0;i<M;i++)scanf("%d",&point[i]);
    struct type_stu my_students[50];
    for(int i=0;i<N;i++){
        scanf("%d",&my_students[i].id);
        my_students[i].score=0;
        for(int j=0;j<M;j++){
            scanf("%d",&my_students[i].classes[j]);
            if(my_students[i].classes[j]>=60){
                my_students[i].score+=point[j];
            }
        }
    }
    for(int start=0;start<N;start++){
        int id_max=start;
        for(int i=start+1;i<N;i++){
            if(my_students[i].score>my_students[id_max].score||
            (my_students[i].score==my_students[id_max].score&&my_students[i].id<my_students[id_max].id)
            ){
                id_max=i;
            }
        }
        struct type_stu temp;
        temp=my_students[id_max];
        my_students[id_max]=my_students[start];
        my_students[start]=temp;
    }
    for(int i=0;i<N;i++)printf("%d %d\n",*my_students[i].id,my_students[i].score);
    return 0;
}