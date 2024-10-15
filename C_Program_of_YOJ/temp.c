#include<stdio.h>
#include<math.h>
int right(int num,int game[3]);
int main(){
    int N=4;//scanf("%d",&N);
    int game[10][3]={
        {1484, 2, 1},
{4218 ,2,1},
{5774 ,2 ,2},
{1251 ,3 ,0},
    };
    //for(int i;i<N;i++){scanf("%d %d %d",&game[i][0],&game[i][1],&game[i][2]);}
    int res;
    for(int num=5114;num<10000;num++){
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
    // num=5114,game[0]=1484
    int in=0,loc=0;int not_used[4]={1,1,1,1};
    for(int i=0;i<4;i++){
        int num_single=(num%(int)pow(10,4-i))/(int)pow(10,3-i); // 1
        
        for(int j=0;j<4;j++){
            int guess_single=(game[0]%(int)pow(10,4-j))/(int)pow(10,3-j);
            if(not_used[j]){
                
                if(num_single==guess_single){
                    not_used[j]=0;
                    in++;
                    if(j==i){loc++;}                  
                    
                }
            }
        }
    }
    if(in==game[1]&&loc==game[2]){return 1;}
    else return 0;
}