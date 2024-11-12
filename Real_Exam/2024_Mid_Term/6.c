/*
4 4
1 1 0 1
1 0 0 1
1 1 c 0
1 1 0 1
abc
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct type_win{
    int start_row;int start_col;
    int end_row;int end_col;
    int remain;
};

int main(){
    int m,n;scanf("%d %d",&m,&n);
    int board[700][700];

    int all_remain=0;
    for(int row=0;row<m;row++){
        for(int col=0;col<n;col++){
            char input;
            scanf("%s",&input);  // 0: ok;  1: obstale   
            if(input-'0'<2){board[row][col]=input-'0';}
            else board[row][col]=input;
            if(input=='0'){all_remain++;}
        }
    }
    
    char word[2000];scanf("%s",word);
    int LEN=strlen(word);
    struct type_win shu_win[700];
    struct type_win hen_win[700];
    int hen_count=0;
    int shu_count=0;
    char reverse_word[2000],copy_word[2000];
    strcpy(copy_word,word);
    for(int i=0;i<LEN;i++){
        reverse_word[i]=copy_word[LEN-i-1];
    }
    reverse_word[LEN]='\0';
    // 横着填入正
    for(int row=0;row<m;row++){
        for(int start=0;start<n-LEN+1;start++){
            int ok_left=board[row][start-1]==1||start==0;
            int ok_right=board[row][start+LEN]==1||start+LEN==n;
            if(ok_left&&ok_right){     // side_ok
                int num_same;
                int flag=0;
                for(int i=0;i<LEN;i++){
                    if(board[row][start+i]==0||board[row][start+i]==word[i]){ // innner_ok
                        flag++;
                    }
                if(flag==LEN){
                    hen_win[hen_count].start_row=row;
                    hen_win[hen_count].start_col=start;
                    hen_win[hen_count].end_row=row;
                    hen_win[hen_count].end_col=start+LEN-1;
                    if(board[row][start+i]==word[i]){
                        num_same++;
                    }
                    hen_win[hen_count].remain=all_remain+num_same-LEN;
                    hen_count++;
                    }
                }
            }
        }
    }
    //横着填入倒
    for(int row=0;row<m;row++){
        for(int start=0;start<n-LEN+1;start++){
            int ok_left=board[row][start-1]==1||start==0;
            int ok_right=board[row][start+LEN]==1||start+LEN==n;
            if(ok_left&&ok_right){     // side_ok
                int num_same;
                int flag=0;
                for(int i=0;i<LEN;i++){
                    if(board[row][start+i]==0||board[row][start+i]==reverse_word[i]){ // innner_ok
                        flag++;
                    }
                if(flag==LEN){
                    hen_win[hen_count].start_row=row;
                    hen_win[hen_count].end_col=start;
                    hen_win[hen_count].end_row=row;
                    hen_win[hen_count].start_col=start+LEN-1;
                    if(board[row][start+i]==reverse_word[i]){
                        num_same++;
                    }
                    hen_win[hen_count].remain=all_remain+num_same-LEN;
                    hen_count++;
                    }
                }
            }
        }
    }
    
    //竖着填入正
    for(int col=0;col<n;col++){
        for(int start=0;start<n-LEN+1;start++){
            int ok_up=start==0||board[start-1][col]==1;
            int ok_down=start+LEN==m||board[start+LEN][col]==1;
            if(ok_up&&ok_down){     // side_ok
                int num_same=0;
                int flag=0;
                for(int i=start;i<LEN;i++){
                    if(board[start+i][col]==0||board[start+i][col]==word[i]){ // innner_ok
                        flag++;
                    }
                if(flag==LEN){
                        shu_win[shu_count].start_col=col;
                        shu_win[shu_count].start_row=start;
                        shu_win[shu_count].end_col=col;
                        shu_win[shu_count].end_row=start+LEN-1;
                        if(board[start+i][col]==word[i]){
                            num_same++;
                        }
                        shu_win[shu_count].remain=all_remain+num_same-LEN;
                        shu_count++;
                    }
                }
            }
        }
    }
    //竖着填入dao
    for(int col=0;col<n;col++){
        for(int start=0;start<n-LEN+1;start++){
            int ok_up=start==0||board[start-1][col]==1;
            int ok_down=start+LEN==m||board[start+LEN][col]==1;
            if(ok_up&&ok_down){     // side_ok
                int num_same=0;
                int flag=0;
                for(int i=start;i<LEN;i++){
                    if(board[start+i][col]==0||board[start+i][col]==reverse_word[i]){ // innner_ok
                        flag++;
                    }
                if(flag==LEN){
                        shu_win[shu_count].start_col=col;
                        shu_win[shu_count].end_row=start;
                        shu_win[shu_count].end_col=col;
                        shu_win[shu_count].start_row=start+LEN-1;
                        if(board[start+i][col]==reverse_word[i]){
                            num_same++;
                        }
                        shu_win[shu_count].remain=all_remain+num_same-LEN;
                        shu_count++;
                    }
                }
            }
        }
    }

    if(hen_count==0&&shu_count==0)printf("No");
    else if(shu_count>0){
        int max_i=0;
        for(int i=1;i<shu_count;i++){
            if(shu_win[i].remain>shu_win[max_i].remain){
                max_i=i;
            }
        }
        printf("%d %d\n%d %d",shu_win[max_i].start_row,shu_win[max_i].start_col,shu_win[max_i].end_row,shu_win[max_i].end_col);
    }
    else if(hen_count>0){
        int max_i=0;
        for(int i=1;i<hen_count;i++){
            if(shu_win[i].remain>hen_win[max_i].remain){
                max_i=i;
            }
        }
        printf("%d %d\n%d %d",hen_win[max_i].start_row,hen_win[max_i].start_col,hen_win[max_i].end_row,hen_win[max_i].end_col);
    }
    return 0;
}