/*输入格式

　　输入第一行为一个正整数N(1<=N<=10)，表示在这段对话中共有N次问答（不允许出现重复问答）。
在接下来的N行中，每行三个整数A,B,C。游戏者猜这个四位数为A，然后计算机回答猜对了B个数字，
其中C个在正确的位置上。

输出格式

　　一行，如果根据这段对话能确定这个四位数，则输出这个四位数，若不能，则输出"Not sure"。*/

#include<stdio.h>
#include<math.h>
int right(int num,int game[3]);
int main(){
    int N;scanf("%d",&N);
    int game[10][3];
    for(int i=0;i<N;i++){scanf("%d %d %d",&game[i][0],&game[i][1],&game[i][2]);}
    int res;
    for(int num=0;num<10000;num++){
        int whether_continue=0;
        int flag=0;
        for(int i=0;i<N;i++){
            if(right(num,game[i])){
                flag++;
            }
            else {whether_continue=1;break;}
        }
        if(flag==N){
            res=num;
            break;}
    }
    if(res!=0)printf("%d",res);
    else printf("Not sure");
    return 0;
}
int right(int num,int game[3]){
    int not_used[4]={1,1,1,1};
    int in=0,loc=0;
    for(int i=0;i<4;i++){
        int num_single=(num%(int)pow(10,4-i))/(int)pow(10,3-i);
        
        for(int j=0;j<4;j++){
            int guess_single=(game[0]%(int)pow(10,4-j))/(int)pow(10,3-j);
            if(not_used[j]){
                if(num_single==guess_single){
                    in++;
                    if(j==i){loc++;}
                    not_used[j]=0;
                    break;
                }
            }
        }
    }
    if(in==game[1]&&loc==game[2]){return 1;}
    else return 0;
}