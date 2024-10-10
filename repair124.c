#include<stdio.h>
#include <stdlib.h>
int has_road(int x,int y,int h[100][100],int R,int C);
int main(){
    FILE *file = fopen("error_87_ck9.in", "r");
    if (file == NULL) {perror("无法打开文件");return 1;}
    int R,C;
    fscanf(file,"%d %d",&R,&C);
    int h[50][50];
    for(int i=0;i<R;i++){for(int j=0;j<C;j++){fscanf(file,"%d",&h[i][j]);}}
    // int R=5,C=5;
    // int h[100][100]={{1,2,3,4,5},
    //             {16,17,18,19,6},
    //             {15,24,25,20,7},
    //             {14,23,22,21,8},
    //             {13,12,11,10,9}
    //             };
    int h_max,x_max,y_max;
    h_max=h[0][0];
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(h[i][j]>h_max){
                h_max=h[i][j];
                x_max=i;y_max=j;
            }
        }
    }
    int count=1;
    int x=x_max,y=y_max;
    while(has_road(x,y,h,R,C)!=-1){
        int decision=has_road(x,y,h,R,C);
        switch (decision)
        {
        case 0:
            x--;
            break;
        case 1:
            x++;
            break;
        case 2:
            y--;
            break;
        case 3:
            y++;
            break;
        }
        count++;
    }
    printf("%d",count);
}
int has_road(int x,int y,int h[100][100],int R,int C){
    int d[4]={100,100,100,100},d_min=d[0];
    int decision;
    if(x>0&&h[x-1][y]<h[x][y]){
        d[0]=h[x][y]-h[x-1][y];
    }
    
    if(x+1<R&&h[x+1][y]<h[x][y]){
        d[1]=h[x][y]-h[x+1][y];
    }
    if(y>0&h[x][y-1]<h[x][y]){
        d[2]=h[x][y]-h[x][y-1];
    }
    if(y+1<C&&h[x][y+1]<h[x][y]){
        d[3]=h[x][y]-h[x][y+1];
    }
    for(int i=0;i<4;i++){
        if(d[i]<d_min){
            d_min=d[i];
            decision=i;
        }
    }
    if(d_min!=100)return decision;
    else return -1;
}