// #include<stdio.h>
// int desk[8][8]={0};
// int count=0;
// int eight_queen(int col){
//     int i,j;
//     if(col==8){count+=1;return count;}
//     for(i=0;i<8;i++){
//         if(desk[i][col]==0){
//             desk[i][col]=-1;
//             for(j=1;j<8-col;j++){
//                 desk[i][col+j]=1;
//                 if (i + j < 8) desk[i + j][col + j] = 1; // 右下对角线
//                 if (i - j >= 0) desk[i - j][col + j] = 1; // 右上对角线
//             }
//             eight_queen(col+1);
//             // 回溯，移除皇后并恢复棋盘状态
//             for (j = 1; j < 8 - col; j++) {
//                 desk[i][col + j] = 0;
//                 if (i + j < 8) desk[i + j][col + j] = 0;
//                 if (i - j >= 0) desk[i - j][col + j] = 0;
//             }
//             desk[i][col] = 0;
//         }
//     }
// }
// int main(){
//     eight_queen(0);
//     printf("%d",count);
//     return 0;
// }


#include<stdio.h>

int desk[8][8] = {0};
int count = 0;

int eight_queen(int col) {
    int i, j;
    if (col == 8) {
        count += 1;
        return count;
    }
    for (i = 0; i < 8; i++) {
        if (desk[i][col] == 0) {
            // 放置皇后
            desk[i][col] = -1;
            // 更新棋盘状态
            for (j = 1; j < 8 - col; j++) {
                desk[i][col + j] += 1; // 同一行
                /*在这个版本中，我们使用自加和自减操作来更新和恢复棋盘状态。
                这是因为直接赋值 1 和 0 会覆盖之前的状态，导致错误的结果。
                通过使用自加和自减操作，我们可以正确地维护棋盘状态，
                确保每次递归调用和回溯时棋盘状态都是正确的。这样可以得到正确的解。*/
                if (i + j < 8) desk[i + j][col + j] += 1; // 右下对角线
                if (i - j >= 0) desk[i - j][col + j] += 1; // 右上对角线
            }
            // 递归调用
            eight_queen(col + 1);
            // 回溯，移除皇后并恢复棋盘状态
            for (j = 1; j < 8 - col; j++) {
                desk[i][col + j] -= 1;
                if (i + j < 8) desk[i + j][col + j] -= 1;
                if (i - j >= 0) desk[i - j][col + j] -= 1;
            }
            desk[i][col] = 0;
        }
    }
    return count;
}

int main() {
    
    eight_queen(0);
    printf("%d", count);
    return 0;
}


// #include <stdio.h>

// int count = 0;
// int chess[8][8]={0};

// int notDanger( int row, int col )
// {
// 	int i,k;
// 	// 判断列方向
// 	for( i=0; i < 8; i++ )
// 	{
// 		if( chess[i][col]==1 )
// 		{return 0;}
// 	}
// 	// 判断左对角线 
// 	for( i=row, k=col; i>=0 && k>=0; i--, k-- )
// 	{
// 		if(chess[i][k]==1  )
// 		{return 0;}
// 	}
// 	// 判断右对角线 
// 	for( i=row, k=col; i>=0 && k<8; i--, k++ )
// 	{
// 		if(chess[i][k]==1  )
// 		{
// 			return 0;
// 		}
// 	}
// 	return 1;
// }

// void Print()          //打印结果 
// {
// 	int row,col;
// 	printf("第 %d 种\n", count+1);
// 		for( row=0; row < 8; row++ )
// 		{
// 			for( col=0; col< 8; col++ )
// 			{
// 				if(chess[row][col]==1)        //皇后用‘0’表示
// 				{
// 					printf("0 ");
// 				}
// 				else
// 				{
// 					printf("# ");
// 				}
// 			}
// 			printf("\n");
// 		}
// 		printf("\n");
// }

// void EightQueen( int row )
// {
// 	int col;
// 	if( row>7 )                       //如果遍历完八行都找到放置皇后的位置则打印
// 	{
// 		Print();                       //打印八皇后的解 
// 		count++;
// 		return ;
// 	}

// 	for( col=0; col < 8; col++ )        //回溯，递归
// 	{
// 		if( notDanger( row, col ) )    // 判断是否危险
// 		{
// 			chess[row][col]=1;
// 			EightQueen(row+1);
			
// 			chess[row][col]=0;           //清零，以免回溯时出现脏数据
// 		}
// 	}
// }

// int main()
// {
// 	EightQueen(0);        
// 	printf("总共有 %d 种解决方法!\n\n", count);
// 	return 0;
// }

