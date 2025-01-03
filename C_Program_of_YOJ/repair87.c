#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

void transposeImage(int ori_image[MAX_SIZE][MAX_SIZE][3], int image[MAX_SIZE][MAX_SIZE][3], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < 3; k++) {
                image[j][i][k] = ori_image[i][j][k];
            }
        }
    }
}
int is_bad(int col,int row,int image[100][100][3]);
int main() {
    FILE *file = fopen("E:\\04ComputerSience\\C_Program_learning\\yoj\\in_out_for_Debug\\error_87_ck9.in", "r");
    // FILE *file = fopen("E:\\04ComputerSience\\C_Program_learning\\yoj\\in_out_for_Debug\\error_87_ck9.out", "r");

    if (file == NULL) {perror("无法打开文件");return 1;}
    int on,om;
    fscanf(file,"%d %d",&on,&om);
    int ori_image[100][100][3];
    for(int row=0;row<on;row++){
        for(int col=0;col<om;col++){
            char r,g,b,nul;
            fscanf(file,"%c%c%d%c",&r,&nul,&ori_image[row][col][0],&nul);
            fscanf(file,"%c%c%d%c",&r,&nul,&ori_image[row][col][1],&nul);
            fscanf(file,"%c%c%d%c",&r,&nul,&ori_image[row][col][2],&nul);
        }
    }
    int image[MAX_SIZE][MAX_SIZE][3];
    transposeImage(ori_image, image, on, om);
    int n=om,m=on;
    printf("origin image:\n");
    for(int col=0;col<n;col++){
        for(int row=0;row<m;row++){
            // printf("R %d G %d B %d ",image[col][row][0],image[col][row][1],image[col][row][2]);
            printf("[%3d,%3d,%3d],",image[col][row][0],image[col][row][1],image[col][row][2]);
        }
        printf("]\n[");
    }

    int copy_image[100][100][3];
    //for(int col=0;col<n;col++){for(int row=0;row<m;row++){for(int c=0;c<3;c++){copy_image[col][row][c]=image[col][row][c];}}}
    
    int ROUND=((n>m)?n+1:m+1);
    // printf("%d",is_bad(1,1,image));
    int record[22]={0};
    for(int i=0;i<ROUND;i++){
        for(int col=0;col<n;col++){for(int row=0;row<m;row++){for(int c=0;c<3;c++){copy_image[col][row][c]=image[col][row][c];}}}
        for(int col=0;col<n;col++){
            for(int row=0;row<m;row++){
                if(is_bad(col,row,copy_image)){
                    //printf("坏点(%d,%d)\n",col,row);
                    int l,r,u,d;
                    u=(col-1>=0)&&(1-is_bad(col-1,row,copy_image));
                    d=(col+1<n)&&(1-is_bad(col+1,row,copy_image));
                    l=(row-1>=0)&&(1-is_bad(col,row-1,copy_image));
                    r=(row+1<m)&&(1-is_bad(col,row+1,copy_image));
                    for(int channel=0;channel<3;channel++){
                        int c=channel;
                        //printf("  通道%d，上%d下%d左%d右%d\n",1+c,u,d,l,r);
                        if(u+d+l+r!=0){
                            record[col]+=1;
                            int son=u*copy_image[col-1][row][c]+\
                                            d*copy_image[col+1][row][c]+\
                                            l*copy_image[col][row-1][c]+\
                                            r*copy_image[col][row+1][c];
                            int mom=u+d+l+r;
                            if(son%mom==0){image[col][row][c]=son/mom;}
                            else
                            {image[col][row][c]=son/mom+1;}
                        }
                    }
                    //printf("修复%d行%d列，上%d下%d左%d右%d\n",col+1,1+row,u,d,l,r);
                }
            }  
        }
        for(int col=0;col<n;col++){for(int row=0;row<m;row++){for(int c=0;c<3;c++){copy_image[col][row][c]=image[col][row][c];}}}
        for(int col=0;col<n;col++){
        for(int row=0;row<m;row++){
            // printf("R %d G %d B %d ",image[col][row][0],image[col][row][1],image[col][row][2]);
            //printf("(%3d %3d %3d) ",image[col][row][0],image[col][row][1],image[col][row][2]);
        }
        //printf("\n");
    }
    }
    printf("\nok:\n");
    for(int col=0;col<n;col++){
        for(int row=0;row<m;row++){
            // printf("R %d G %d B %d ",image[col][row][0],image[col][row][1],image[col][row][2]);
            // printf("(%3d %3d %3d) ",image[col][row][0],image[col][row][1],image[col][row][2]);
            printf("[%3d,%3d,%3d],",image[col][row][0],image[col][row][1],image[col][row][2]);

        }
        printf("]\n[");
    }
    
    fclose(file);

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
// #include <stdio.h>

// int main() {
//     int image[100][100][3] = {
//         {{10, 20, 30}, {10, 20, 30}, {10, 20, 30}, {200, 255, 255}, {10, 20, 30}},
//         {{10, 20, 30}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {200, 255, 255}},
//         {{10, 20, 30}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {10, 20, 30}},
//         {{10, 20, 30}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {10, 20, 30}},
//         {{10, 20, 30}, {10, 20, 30}, {10, 20, 30}, {10, 20, 30}, {10, 20, 30}}
//     };

//     // 打印图像的 RGB 值
//     for (int i = 0; i < 5; i++) { // 假设图像大小为 5x5
//         for (int j = 0; j < 5; j++) {
//             printf("R %d G %d B %d ", image[i][j][0], image[i][j][1], image[i][j][2]);
//         }
//         printf("\n");
//     }

//     return 0;
// }