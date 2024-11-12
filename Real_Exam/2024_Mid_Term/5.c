/*
高考的科目包括语文、数学、英语（这三科各科满分100分），以及自选的3个科目（满分300分）。高考结束以后，每位同学都有一个具体的位次。位次的确定规则如下：
（1）按照总分从高到低排序。
（2）如果总分相同，按照语文成绩从高到低排序。
（3）如果总分和语文成绩相同，按照数学成绩从高到低排序。
（4）如果总分和语文成绩、数学成绩都相同，按照英语成绩从高到低排序。
（5）如果总分和语文成绩、数学成绩、英语成绩都相同，意味着自选的3个科目成绩相同。
（6）当总分和语文成绩、数学成绩、英语成绩、自选的3个科目成绩都相同，为同分考生，位次相同。

已知处于某个位次段的学生的成绩，请确定某位同学的位次。
在考虑同分考生的情况下，位次的确定规则如下表所示（以单个成绩为例）。后续位次以到达目前为止，分配的位次连续递增，进行赋值。比如前两位同学成绩相同为99，位次都为1，第三个同学成绩更低为88，则位次为2。

成绩  99 | 99 | 88 | 77
位次  1  | 1  | 2  | 3  


【输入格式】

若干行。第一行，输入整数N，表示有N个学生，N<=100。
后续各行，输入各个同学的学号以及各个科目的成绩，即语文、数学、英语、自选3科目的总分等。学号、语文、数学、英语、3科目的总分等，都是一个整数。
最后一行有两个数，分别是本组学生的第一名的位次，以及某个学生的学号。

【输出格式】
输出为一行，请把最后输入的学号，对应的学生的位次给出来。

【输入样例1】
3
101 80 80 80 250
102 90 90 90 270
103 90 90 90 270
285 101

【输出样例1】
286*/
#include<stdio.h>
struct type_info{
    int id;int china;int math;int english;int other;
    int total;
    int abs_rank;
};

int main(){
    int N;scanf("%d",&N);
    struct type_info my_stus[100];
    for(int i=0;i<N;i++){
        scanf("%d %d %d %d %d",&my_stus[i].id,&my_stus[i].china,&my_stus[i].math,&my_stus[i].english,&my_stus[i].other);
        my_stus[i].total=my_stus[i].china+my_stus[i].math+my_stus[i].english+my_stus[i].other;
    }
    for(int start=0;start<N;start++){
        for(int i=start+1;i<N;i++){
            if(my_stus[i].total>my_stus[start].total || 
            (my_stus[i].total==my_stus[start].total&&my_stus[i].china>my_stus[start].china)||
            (my_stus[i].total==my_stus[start].total&&my_stus[i].china==my_stus[start].china&&my_stus[i].math>my_stus[start].math)||
            (my_stus[i].total==my_stus[start].total&&my_stus[i].china==my_stus[start].china&&my_stus[i].math==my_stus[start].math&&my_stus[i].english>my_stus[start].english)){
                struct type_info temp;
                temp=my_stus[i];
                my_stus[i]=my_stus[start];
                my_stus[start]=temp;
            }
        }
    }
    int rank=0;
    my_stus[0].abs_rank=rank;
    for(int i=1;i<N;i++){
        if(my_stus[i].total==my_stus[i-1].total&&my_stus[i].china==my_stus[i-1].china&&my_stus[i].math==my_stus[i-1].math&&my_stus[i].english==my_stus[i-1].english){
            my_stus[i].abs_rank=rank;
        }
        else{ 
            rank++;
            my_stus[i].abs_rank=rank;           
        }
    }
    int one_real_rank,  DY_id;scanf("%d %d",&one_real_rank,&DY_id);
    for(int i=0;i<N;i++){
        if(my_stus[i].id==DY_id){
            printf("%d",one_real_rank+my_stus[i].abs_rank);
        }
    }
    return 0;
}