#include<stdio.h>
int main(){
    int N;scanf("%d",&N);
    int tree[100][100];
    for(int i=0;i<N;i++){for(int j=0;j<i+1;j++){scanf("%d",&tree[i][j]);}}
    
    int record[100][100];
    for(int i=0;i<N;i++){record[N-1][i]=tree[N-1][i];} //copy一下
    for(int floor=N-1;floor>=0;floor--){
        for(int fruit=0;fruit<floor;fruit++){
            int max=(record[floor][fruit],record[floor][fruit+1])?record[floor][fruit]:record[floor][fruit+1];
            record[floor-1][fruit]=max+tree[floor-1][fruit];
        }
    }
    printf("%d",record[0][0]);
    return 0;
}