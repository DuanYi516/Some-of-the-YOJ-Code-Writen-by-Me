#include <stdio.h>
int is_bad(int col,int row,int image[100][100][3]);
int main(){
    int n,m;scanf("%d %d",&n,&m);
    int image[100][100][3];
    for(int row=0;row<n;row++){
        for(int col=0;col<m;col++){
            char r,g,b,nul;
            scanf("%c%c%d%c",&r,&nul,&image[row][col][0],&nul);
            scanf("%c%c%d%c",&r,&nul,&image[row][col][1],&nul);
            scanf("%c%c%d%c",&r,&nul,&image[row][col][2],&nul);
        }
    }
    int copy_image[100][100][3];
    for(int col=0;col<n;col++){for(int row=0;row<m;row++){for(int c=0;c<3;c++){copy_image[col][row][c]=image[col][row][c];}}}
    
    int ROUND=((n>m)?n+1:m+1);
    for(int i=0;i<ROUND;i++){
        for(int col=0;col<n;col++){
            for(int row=0;row<m;row++){
                if(is_bad(col,row,copy_image)){
                    for(int channel=0;channel<3;channel++){
                        int l,r,u,d,c=channel;
                        u=(col-1>=0)&&(1-is_bad(col-1,row,copy_image));
                        d=(col+1<n)&&(1-is_bad(col+1,row,copy_image));
                        l=(row-1>=0)&&(1-is_bad(col,row-1,copy_image));
                        r=(row+1<m)&&(1-is_bad(col,row+1,copy_image));
                        if(u+d+l+r!=0){
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
                }
            }  
        }
        for(int col=0;col<n;col++){for(int row=0;row<m;row++){for(int c=0;c<3;c++){copy_image[col][row][c]=image[col][row][c];}}}
    }
    
    for(int col=0;col<n;col++){
        for(int row=0;row<m;row++){
            printf("R %d G %d B %d ",image[col][row][0],image[col][row][1],image[col][row][2]);
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