#include<stdio.h>
struct type_info{
    int size;
    int locs[100];
};
int have_in(int row,int col,struct type_info *my_info,int c){
    int central=100*row+col;
    for(int i=0;i<my_info[c].size;i++){
        if(central-1==my_info[c].locs[i])return 1;
        else if(central+1==my_info[c].locs[i])return 1;
        else if(central-100==my_info[c].locs[i])return 1;
        else if(central+100==my_info[c].locs[i])return 1;
        else if(central-99==my_info[c].locs[i])return 1;
        else if(central+99==my_info[c].locs[i])return 1;
        else if(central-101==my_info[c].locs[i])return 1;
        else if(central+101==my_info[c].locs[i])return 1;
    }
    return 0;
}
int main(){
    int count=0;
    struct type_info my_info[2500];
    for(int i=0;i<2500;i++){
        my_info[i].size=0;
    }
    // int n,m;scanf("%d %d",&n,&m);
    int n=10,m=12;
    int grid[100][100]={
{'.','.','.','.','.','.','.','.','.','.','.','.'},
{'.','I','I','.','.','.','.','.','.','.','I','.'},
{'.','I','I','I','.','.','.','.','.','I','.','.'},
{'.','I','.','.','.','.','.','.','I','I','.','.'},
{'.','.','.','.','.','.','.','.','.','.','.','.'},
{'.','.','.','.','.','I','I','I','I','.','.','.'},
{'.','.','.','.','.','.','I','I','.','.','.','.'},
{'.','.','.','.','I','I','I','I','.','.','.','.'},
{'.','.','.','.','.','I','I','I','.','.','.','.'},
{'.','.','.','.','.','.','.','.','.','.','.','.'}
    };
    for(int row=0;row<n;row++){
        // char rtn=getchar();
        for(int col=0;col<m;col++){
            // char input=getchar();
            char input=grid[row][col];
            if(input=='I'){
                int find_belond=0;
                for(int c=0;c<count;c++){
                    int cur_size=my_info[c].size;
                    for(int s=0;s<cur_size;s++){
                        if(have_in(row,col,my_info,c)){
                            find_belond=1;
                            my_info[c].locs[my_info[c].size++]=100*row+col;
                            break;
                        }
                    }
                }
                if(!find_belond){
                    my_info[count++].locs[my_info[count-1].size++]=100*row+col;
                }
            }
        }
    }
    int MAX;
    int rvs_count=0;
    struct type_info rvs_my_info[2500];
    for(int i=0;i<2500;i++){
        rvs_my_info[i].size=0;
    }
for(int row=n-1;row>=0;row--){
    // char rtn=getchar();
    for(int col=m-1;col>=0;col--){
        // char input=getchar();
        char input=grid[row][col];
        if(input=='I'){
            int find_belond=0;
            for(int c=0;c<rvs_count;c++){
                int cur_size=rvs_my_info[c].size;
                for(int s=0;s<cur_size;s++){
                    if(have_in(row,col,rvs_my_info,c)){
                        find_belond=1;
                        rvs_my_info[c].locs[rvs_my_info[c].size++]=100*row+col;
                        break;
                    }
                }
            }
            if(!find_belond){
                rvs_my_info[rvs_count++].locs[rvs_my_info[rvs_count-1].size++]=100*row+col;
            }
        }
    }
}
int rvs_MAX;
for(int il=0;il<rvs_count;il++){
    if(rvs_my_info[il].size>MAX){
        rvs_MAX=rvs_my_info[il].size;
    }
}
    for(int il=0;il<count;il++){
        if(my_info[il].size>MAX){
            MAX=my_info[il].size;
        }
    }
    printf("%d %d",count,MAX);
    return 0;
}