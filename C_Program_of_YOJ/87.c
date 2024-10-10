#include <stdio.h>
int is_bad(int col,int row,int image[100][100][3]);
int main(){
    // int n,m;scanf("%d %d",&n,&m);
    // int image[100][100][3];
    // for(int row=0;row<n;row++){
    //     for(int col=0;col<m;col++){
    //         char r,g,b,nul;
    //         scanf("%c%c%d%c",&r,&nul,&image[row][col][0],&nul);
    //         scanf("%c%c%d%c",&r,&nul,&image[row][col][1],&nul);
    //         scanf("%c%c%d%c",&r,&nul,&image[row][col][2],&nul);
    //     }
    // }
    int n=5,m=5;
    int image[100][100][3]={
         {{10, 20, 30}, {10, 20, 30}, {10, 20, 30}, {200, 255, 255}, {10, 20, 30}},
         {{10, 20, 30}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {200, 255, 255}},
         {{10, 20, 30}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {10, 20, 30}},
         {{10, 20, 30}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {10, 20, 30}},
         {{10, 20, 30}, {10, 20, 30}, {10, 20, 30}, {10, 20, 30}, {10, 20, 30}}
     };

    int copy_image[100][100][3];
    for(int col=0;col<n;col++){for(int row=0;row<m;row++){for(int c=0;c<3;c++){copy_image[col][row][c]=image[col][row][c];}}}
    
    int ROUND=((n>m)?n+1:m+1);
    // printf("%d",is_bad(1,1,image));
    for(int i=0;i<ROUND;i++){
        for(int col=0;col<m;col++){
            for(int row=0;row<n;row++){
                if(is_bad(col,row,copy_image)){
                    // printf("坏点(%d,%d)\n",col,row);
                    for(int channel=0;channel<3;channel++){
                        int l,r,u,d,c=channel;
                        u=(col-1>=0)&&(1-is_bad(col-1,row,copy_image));
                        d=(col+1<n)&&(1-is_bad(col+1,row,copy_image));
                        l=(row-1>=0)&&(1-is_bad(col,row-1,copy_image));
                        r=(row+1<m)&&(1-is_bad(col,row+1,copy_image));
                        // printf("  通道%d，上%d下%d左%d右%d\n",1+c,u,d,l,r);
                        if(u+d+l+r!=0){
                        image[col][row][c]=0.5+(float)(u*copy_image[col-1][row][c]+\
                                        d*copy_image[col+1][row][c]+\
                                        l*copy_image[col][row-1][c]+\
                                        r*copy_image[col][row+1][c])/(u+d+l+r);
                        //printf("修复%d行%d列%d通道，上%d下%d左%d右%d\n",col+1,1+row,1+c,u,d,l,r);
                        }
                    }
                }
            }  
        }
        for(int col=0;col<n;col++){for(int row=0;row<m;row++){for(int c=0;c<3;c++){copy_image[col][row][c]=image[col][row][c];}}}
    }
    
    for(int col=0;col<n;col++){
        for(int row=0;row<m;row++){
            // printf("R %d G %d B %d ",image[col][row][0],image[col][row][1],image[col][row][2]);
            printf("(%3d %3d %3d) ",image[col][row][0],image[col][row][1],image[col][row][2]);
        }
        printf("\n");
    }
    return 0;
}
int is_bad(int col,int row,int image[100][100][3]){
    int count=0;
    for(int c=0;c<3;c++){
        if(image[col][row][c]==0)count+=1;
    }
    if(count==3)return 1;
    else return 0;
}
