#include<stdio.h>
#include<math.h>
struct type_loc{
    int x;int y;
    int dis;
};
int clac_dis2(int x,int y){
    return x*x+y*y;
}
int main(){
    struct type_loc tar_loc;scanf("%d %d",&tar_loc.x,&tar_loc.y);
    int N;scanf("%d",&N);
    struct type_loc all_locs[100];
    int min_dis=10000;
    for(int i=0;i<N;i++){
        scanf("%d %d",&all_locs[i].x,&all_locs[i].y);
        int dis=clac_dis2(tar_loc.x-all_locs[i].x,tar_loc.y-all_locs[i].y);
        all_locs[i].dis=dis;
    }
    for(int start=0;start<N;start++){
        for(int i=start+1;i<N;i++){
            if(all_locs[i].dis<all_locs[start].dis){
                struct type_loc temp;
                temp=all_locs[i];
                all_locs[i]=all_locs[start];
                all_locs[start]=temp;
            }
        }
    }
    for(int i=0;i<3;i++){
        printf("%d %d\n",all_locs[i].x,all_locs[i].y);
    }
    return 0;
}