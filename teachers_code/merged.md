## 201130-三重循环出快餐.txt
```c
#include <stdio.h>

enum ZhuShi { rice, noodles, steamed_bread}; //米饭、面条、馒头
enum ShuCai { cabbage, potato, spinach}; //卷心菜、土豆、菠菜
enum Roucai { drumstick, duckleg, beef, pork}; //鸡腿，鸭腿，牛肉，猪肉

void show (ZhuShi  zhushi, ShuCai shucai, Roucai roucai)
{
     printf("{");

     if (zhushi == rice) printf("rice ");
     else if (zhushi == noodles) printf("noodles ");
     else if (zhushi == steamed_bread) printf("steamed_bread ");

     if (shucai == cabbage) printf("cabbage ");
     else if (shucai == potato) printf("potato ");
     else if (shucai == spinach) printf("spinach ");

     if (roucai == drumstick) printf("drumstick");
     else if (roucai == duckleg) printf("duckleg");
     else if (roucai == beef) printf("beef");
     else if (roucai == pork) printf("pork");

     printf("}\n");
}

int main()
{
     int  zhushi;
     int  shucai;
     int  roucai;

    for( zhushi = rice; zhushi <=steamed_bread; zhushi++ )
    {
         for( shucai= cabbage; shucai<=spinach; shucai++ )
          {
                for( roucai= drumstick; roucai<=pork; roucai++ )
                {
                      //得到一份便当
                     show ((ZhuShi)zhushi, (ShuCai)shucai, (Roucai)roucai);// zhushi, shucai, roucai
                }
          }
    }

    return 0;
}
```

## 210101-100000个字符串动态内存申请.txt
```c
5
head 3
I am
Happy
today.
Are
you?


5
tail 3
I am
Happy
today.
Are
you?

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
 5
head 3
I am
Happy
today.
Are
you?
 */

int main(int argc, char **argv)
{
 int n;
 char head_or_tail[30];
 int top_n;


 scanf("%d", &n);
 scanf("%s%d", head_or_tail, &top_n);

    //
 char*  name_list[100000];
 int i;
 for(i=0; i<n; i++)
  name_list[i] = (char*)malloc(201);
    //
 char wuyong[32];//取得换行
 gets(wuyong);//取得换行
 
 for(i=0; i<n; i++)
  gets(name_list[i]);

    //
 //for(i=0; i<n; i++)
 // puts(name_list[i]);


    if (strcmp( "head", head_or_tail) == 0)
 {
  for(i=0;i<top_n;i++)
  {
   puts(name_list[i]);
  }
  
 }
 else if (strcmp( "tail", head_or_tail) == 0)
 {
  //5里的3个
  // 2 3 4
  for(i=n-top_n;i<n; i++)
   puts(name_list[i]);
 }
 
 return 0;
}
```

## 210101-100000个字符串动态内存申请0.txt
```c
内存的动态申请
// ----------------------
管理10万个字符串，每个字符串200个字符。
int main ()
{
     char s[100000][201];
    //这回突破栈段的空间限制，程序运行不了
}

// ----------------------

int main ()
{
     char* s[100000];

     int i;
     for(i=0; i< 100000; i++)
        s[i] = (char* ) malloc( 201);

     for(i=0; i< 100000; i++)
          gets( s[i]);
     .............
     for( i=0; i<100000; i++)
          puts( s[i]);

      for(i=0; i< 100000; i++)
        free( (void*) s[i]);

     return 0;

}
```

## 210101-2整除3整除包含4.txt
```c
#include   <stdio.h>
#define N    10000
// 注意把N开到够大

int main()
{
     // 1 50 2 3 4
     // 应该输出 24 42 48

     // 1
     int left,right;
     int one, two;
     int digit;
     scanf("%d %d %d %d %d", &left, &right, &one, &two, &digit);

     // 2
     int  a[N] ;  
     int  b[N];
     for(i=0; i<N; i++)
        { a[i]=0; b[i] = 0;};

     // 3
     int step = one;
     while (1)
     {
     if( step>=left)
    a[step] = 1;
         
         step += step;
         if (step>right) 
             break;
    }

     step = two;
     while (1)
     {
       if( step>=left)
    b[step] = 1;
         step += step;
         if (step>right) 
             break;
    }

     // 4
     for (i=0; i< N; i++)
     {
         if (a[i] ==1 && b[i] ==1)
        {
               //判断有没有digit
              int has_shuzi = 0;
              int xx=i;
              while(1)
              {
                   if (xx==0) break;
                   int mowei = xx%10;
                   if ( mowei == digit) { has_shuzi=1;break};
                   xx = xx/10;
              }
             if (has_shuzi) printf("%d\n", i);

        }// if
     }// for

}
```

## 210101-long long.txt
```c
1，64bit整数
 long long
 unsigned long long

int main()
{
    long long  aa;
    scanf("%lld", &aa);
    printf("%lld\n", aa);

    unsigned long long bb;
    scanf("%llu", &bb);
    printf("%llu\n", bb);

    return  0;
}
```

## 210101-YOJ奖金（档位）.txt
```c
#include <stdio.h>

int main(int argc, char **argv)
{
 // 1
 int m;
 scanf("%d",&m);
 
 int i;
 int fenjie[100];double bilv[100];
 for(i=0;i<m;i++)
 {
  scanf("%d%lf", &fenjie[i], &bilv[i]);
 }
 
 double jine;
 scanf("%lf", &jine);
 
 // 2
 if (jine <0)
 {
  printf("NO");
  return 0;
 }
 
 int dangwei=0;
 for (i=0; i<m;i++)
 {
  if (jine < fenjie[i])
  {
   dangwei=i;
   break;
  }
  if (fenjie[i] == -1)
  {
   dangwei=i;
   fenjie[i] = jine;
   break;
  }
 }
 
 // 3
 double sum = 0;
 for(i=0;i<dangwei;i++)
 {
  if (i==0 )
   sum = sum + (fenjie[i]-0)*bilv[i];
  else 
   sum = sum + (fenjie[i] - fenjie[i-1])*bilv[i];
 }
 
 if(dangwei==0)
      sum = sum+(jine-0)*bilv[0];
else
     sum = sum+ (jine-fenjie[dangwei-1])*bilv[dangwei];
 
 printf("%.2lf", sum);
 
 return 0;
}
```

## 210101-不定数量的身份证（动态内存申请）.txt
```c
内存的动态申请
          管理若干身份证


struct IDCard
{
     char id[20];
     IDCard* next;
};

int main()
{
     IDCard* new_node = (IDCard*) malloc( sizeof( IDCard));
     gets( new_node->id);
    
     IDCard* head = NULL;
     while(1)
     {
            if ( strcmp( new_node->id, "-1")
            {   free( new_node); break;}

            if (head ==NULL)
            {   head = new_node; new_node->next=NULL;}
            else
            {  IDCard* old_head = head;
                new_node->next = old_head; 
                head=new_node};

           new_node = (IDCard*) malloc( sizeof( IDCard));
           gets( new_node->id);
      }

      ................
      
      IDCard* p = head;
      while(p!=NULL)
     {
           IDCard* temp = p;
           p = p->next;
 
            free( temp);
      }
}
```

## 210101-切割单词、保留切割单词.txt
```c
字符串切割单词后、找个地方保存
 

 char str[200];
 int word_start;
 int word_end;
 
 int word_count = 0;
 char word_list[100][100];
 
 // 每次拿到一个词，找地方保存去
 int ww;
 for(ww=word_start; ww<=word_end; ww++)
 {
     word_list[word_count][ww - word_start]=  str[ww];//345 -> 012
 }
 word_list[word_count] [ end-start+1] = '\0';
 word_count++;

 这怎么理解，用小麻雀
 比如start =3, end=5，总共三个字符，占用012下标，应该把下标3置为\0

```

## 210101-字符串-大整数加法.txt
```c
5，设计：大整数加法，超过整数int范围
    char a[501];
 char b[501];
 char c[502];//c有可能多1位
 
 gets(a);
 gets(b);
 ...
    int n= strlen(a);//a,b长度相等，都有n位，下标为0,...,n-1，第n位为\0
 int i;
 int jinwei=0;
 c[n+1]='\0';//c可能多1位，下标从0,1,...,n，第n+1位为\0
 for(i=n-1; i>=0;i--)
 {
      int shu1 = a[i] - '0';// '0', '1','2','3',.....
   int shu2 = b[i] - '0';// 
   
  int he = shu1 + shu2 + jinwei;
  if ( he >=10)
  {
      jinwei =1;
   he = he %10;
   c[i+1] = '0'+he; //'0', '1','2','3',.....
  }
  else
  {
      c[i+1]='0'+he; //'0', '1','2','3',.....
   jinwei=0;
  }
 }
 if( jinwei >0 )
     c[0] = '1';
 else
     c[0] = '0'
 
 案例:
 5555
 3333

 8989
 8787
 
    如果长度不等，那么短的那个左边填零。
 333
 55555
 变成
 00333
 55555
```

## 210101-数组-寻找众数1.txt
```c
6，寻找众数
 微信里面
 
 从数据入手，从小麻雀入手

// --------------------------------------------------------------------------------
#include <stdio.h>

int main()
{
     int n;
     int a[100];

    // 1，输入n和n个数
    scanf("%d", &n);
    int i;
    for(i=0; i<n; i++)
         scanf("%d", &a[i]);


    // 2，找出每个数值的个数，做一个对照表
    if (n == 1)
    {
        printf( "%d\n", a[0];
        return 0;
    }

    // n>=2
    int duizhao[100][2];

    int count =1;
    duizhao[0][0] = a[0];//数值
    duizhao[0][1] = 1; //个数

    for (i=1;i<n;i++)
    {
        int cur_data = a[i];
   
       // 去对照比表查
       // 如果有，个数++
       // 如果没有，末尾新增一个（对照表的行数count长了），个数1

       int  j;
       int found =0;//假设找不到
       for(j=0; j< count; j++)
       {
             if (cur_data == duizhao[j][0])
              {  duizhao[j][1]++;  
                 found=1;
                 break;}
       }
       if ( found==0)
       { duizao[count][0] = cur_data; 
         duizhao[count][1] = 1;
         count ++;}
    }

    // 3，找到个数最大的那个，记住他，输出他
    int max_value = duizhao[0][0];
    int max_count = duizhao[0][1];
    int max_i = 0;

    for (i=1; i<n;i++)
    {
         if ( duizhao[i][1] > max_count )
         {max_value =duizhao[i][0];
          max_count = duizhao[i][1];
          max_i  = i;
         }
    }

    pintf( "%d\n", max_value);

    return 0;
}
```

## 210101-数组-寻找众数2.txt
```c
要找众数，而且是值大的那个，那么可以用排序
#include <stdio.h>

int main()
{
    int count;
    duizhao[100][2];

    count = 4;
duizhao[0][0] = 11;
duizhao[0][1] = 2;

duizhao[1][0] =12;
duizhao[1][1] =1;

duizhao[2][0] =13;
duizhao[2][1]=2;

duizhao[3][0]=15;
duizhao[3][1]=1;



    // sort，第一排序标准，个数
    // 个数相同，那么第二排序表述是数值
    //按照从高到低排序
    int range = count;
    int i;
    for(range = count; range>=2; range--)
    {
        for(i=0; i<range-1; i++)
        {
            if( duizhao[i][1] < duizhao[i+1][1] || 
               duizhao[i][1] == duizhao[i+1][1] &&duizhao[i][0] < duizhao[i+1][0])
            {
                 int temp =duizhao[i][0]; duizhao[i][0] =duizhao[i+1][0]; duizhao[i+1][0] = temp;
                 temp =duizhao[i][1]; duizhao[i][1] =duizhao[i+1][1]; duizhao[i+1][1] = temp;
            }
         }
     }
   

    return 0;
}
```

## 210101-数组的下标访问、指针访问.txt
```c
#include <stdio.h>

int main()
{
    int a[10];

    for( i =0; i<10; i++)
       scanf("%d", &a[i]);
    for( i =0; i<10; i++)
       printf("%d", a[i]);

    int* p=a;
    for( i =0; i<10; i++)
       scanf("%d", p+i);
    for( i =0; i<10; i++)
       printf("%d", *(p+i));

    int* p=a;
    for( i =0; i<10; i++)
    {
       scanf("%d", p);   p++;
     }
     p  =a ;
    for( i =0; i<10; i++)
     {
       printf("%d", *p);   p++;
     }

    int* p=a;
    for( p=a; p < a+10; p++)
    {
       scanf("%d", p);
     }
    for( p=a; p < a+10; p++)
    {
       printf("%d", *p);  
     } 



    for( i =0; i<10; i++)
       printf("%d", p[i]);


    return 0;
}
```

## 210101-计数统计（simple）.txt
```c
计数统计
	动态增长的数组-用于登记

程序逻辑


int a[100];

int n;
scanf("%d", &n);// 输入一个n


int i; 
for(i=0; i<n; i++)
     scanf("%d", &a[i]); //输入n个元素到数组a


//开始进行计数统计
// 对照表，value对应num
int count=0;
int value[100];
int num[100]

for(i=0; i<n; i++)
{
     int the_value = a[i];

     int index = -1;
     int found = 0;
     int j;
    // 先查找
     for(j = 0; j< count; j++)
      {
         	 if ( the_value == value[j] )
          	{	
		 index = j; 
		found=1; 
		break;
	}
      }

     //看找到，找不到
      if ( found == 1)
     { 
	 num[index] ++; 
     }
      else // found ==0
      {
	count++; 

	value[count-1] = the_value; 
	num[count-1]=1;
       }

}

//完成计数统计后，可以输出每个值的个数

```

## 211221-YOJ椰子.txt
```c
#include <stdio.h>

int try_one_m( int n, int m)
{
	int i;
	int nn = n;
	//1到m天
	for( i=1; i<=m;i++)
	{
		int shang  = nn/m;
		int yushu = nn%m;
		if (yushu !=1)
			return 0;
		nn = nn - shang -1;		
	}
	
	// 最后一天
	if (nn %m == 0)
		return 1;
	else 
		return 0;		
}

int main(int argc, char **argv)
{
	int count = 0;
	int a[100];
	
	while(1)
	{
		int n;
		scanf( "%d", &n);
		
		if ( n==0)
			break;
		count++;
		a[count-1] = n;
	}
	
	int i;
	for(i=0; i<count; i++)
	{
		int n = a[i];
			
		int m;
		int found=0;
		for ( m=n-1; m>=1; m--)
		{
			if (try_one_m( n, m) == 1)
			{
				found =1;
				printf("%d\n", m);
				break;
			}
		}
		if (found==0)
			printf("no solution\n");


```

## 211221-函数与递归-fx递归.txt
```c
#include <stdio.h>

int f( int n)
{
    int ret;
    if ( n == 1)
       ret = 1;
    else if ( n==2)
       ret = 2;
    else
       ret = f( n-1) + 2* f(n-2);

   return ret;
}

int main()
{
    int ret = f(3);
    printf("%d\n", ret);

    return 0;

};

```

## 211221-递归-分配教室.txt
```c
6  10 20 30 40 50 60
4  30 40 50 60 
2 3 4 5




#include <stdio.h>


void show ( int n_class, int class_2_room[20])
{
  int i;
  for (i=0; i< n_class-1; i++)
     printf( "%d ", class_2_room[i]);
  printf("%d\n", class_2_room[ n_class-1]);
}

void show_partial( cur_class, class_2_room)
{
  int i;
  for (i=0; i< cur_class-1; i++)
     printf( "%d ", class_2_room[i]);
  printf("%d\n", class_2_room[ cur_class-1]);
}


int check_diff_room( int n_class, int class_2_room[20])
{
    // 0和[]比较
    // 1和[0]比较
    // 2和[0，1]比较
    // ...
    // n_class-1和[0,1,...,n_class-2]比较
    int i;
    int j;
    for( i=0; i<= n_class-1; i++)
   {
       for (j=0; j<=i-1;j++)
          if ( class_2_room[i] == class_2_room[j])
                return 0;
   }
   return 1;
}



int check_rongliang(int n_class, int class_2_room[20],
                      int renshu_class[20],
                      int n_room, int rongliang_room[20])
{  //              class   0 1 2 3
   // class_2_room  2 3 4 5

   // 扫过每个班的安排的教室jiaoshi
   // 得到班级的人数renshu
   // 得到教室的容量jiaoshi_rongliang
   // 班级人数要小于教室容量
   int i;
   for(i=0; i<= n_class-1; i++)
  {
     int jiaoshi = class_2_room[i];
     int renshu  = renshu_class[i];
     int jiaoshi_rongliang = rongliang_room[ jiaoshi];

     if ( renshu > jiaoshi_rongliang)
       return 0;
   }
   return 1;
};




void try_fenpei(int  cur_class, int class_2_room[20],
               int  n_class, int renshu_class[20], 
                int n_room, int rongliang_room[20])
{
    // 给当前班级 cur_class，尝试分配各个教室0，1，..., n_room-1
    // 如果，已经处理到n_class-1
    //         要检查class_2_room里面的n_class个分配，两两教室不同
    //         检查给班级分配的教室，容量大于班级人数
    //如果，没有处理到n_class-1
    //         请递归处理cur_class+1
    int i;
    for( i=0; i< n_room;  i++)
    {
           class_2_room[ cur_class]  = i;
           show_partial( cur_class, class_2_room);
           if (cur_class == n_class-1)
           {
              int check1 = check_diff_room( n_class, class_2_room);
              int check2 = check_rongliang( n_class, class_2_room,
                      renshu_class,
                      n_room, rongliang_room);

              if ( check1 ==1 && check2 == 1)
                   show (n_class, class_2_room);
           }
           else 
              try_fenpei( cur_class+1,class_2_room,//下一个班级
                n_class, renshu_class, 
                n_room, rongliang_room);
    }
}

int main()
{  int i;

   int n_room;
   int rongliang_room[20];
    scanf("%d", &n_room);
    for(i=0; i< n_room; i++)
         scanf("%d", &rongliang_room[i]);

   int n_class;
   int renshu_class[20];
    scanf("%d", &n_class);
    for(i=0; i< n_class; i++)
         scanf("%d", &renshu_class[i]);

    int cur_class = 0;
    int class_2_room[ 20];
    try_fenpei( cur_class,class_2_room,
                n_class, renshu_class, 
                n_room, rongliang_room);

    return 0;
}
              
```

## 211224-YOJ摘桃子.txt
```c
#include <stdio.h>
int max_value = 0;

void go(int a[4][4],int cur_row, int cur_col, int cur_value)
{
	// for 0到1走法
    // 尝试，0走上/1走右上
	// 不能走，什么都不做
	// 能走，走，计算new_row, new_col, new_value
	//       如果那是0，3位置，判断new_value和max_value,适时修改max_value
	//       如果那不是0,3位置，递归go( new_row, new_col, new_value
	int zoufa;
	for(zoufa=0; zoufa<2; zoufa++)
	{
		int new_row;
		int new_col;
		int new_value;
		if (zoufa == 0)
		{
			new_row = cur_row-1;
			new_col = cur_col;
		}
		else if( zoufa==1)
		{
			new_row = cur_row-1;
			new_col = cur_col +1;
		}
		
		if( new_row>=0 && new_row<=3 &&new_col>=0 && new_col<=3 &&
		  a[new_row][new_col] >0)
		  {
			  // 能走
			  new_value = cur_value +a[new_row][new_col];
			  
			  if( new_row == 0 && new_col == 3)
			  {
				  if (new_value>max_value)max_value = new_value;
			  }
			  else
			  {
				  go( a, new_row, new_col, new_value);
			  }
		  }
		  else
		  {
			  // do nothing
		  }
		
	}
	
}


int main(int argc, char **argv)
{
	int a[4][4] = {
		{0,0,0,1},
		{0,0,2,3},
		{0,4,6,5},
		{2,8,5,7}
	};
	
	int cur_row =3;
	int cur_col = 1;
	int cur_value = 8;
	go(a, cur_row, cur_col, cur_value);
	
	printf("max value for %d %d is %d\n", cur_row, cur_col, max_value);
	
	return 0;
}

```

## 211224-YOJ椰子2.txt
```c
## 221018-YOJ奖金.txt
```c
#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);

	int i;
	int fenjie[100];
	double bilv[100];
	int jine;

	for(i=0; i<n; i++)
		scanf("%d%lf", &fenjie[i], &bilv[i]);

	scanf("%d", & jine);

	// case <0
	if ( jine<0)
	{
		printf("NO\n");
		return 0;
	}

	double jj;
	if ( n==1)
	{
		jj = jine * bilv[0];
		printf("%.2lf\n", jj);
		return 0;
	}

	//  case 左边的左

	if ( jine <= fenjie[0] )
	{
		jj = jine * bilv[0];
		printf("%.2lf\n", jj);
		return 0;
	}

// case右边之后
	if ( jine > fenjie[ n-2])
	{
		jj = 0.0;
		jj  = jj + fenjie[0] * bilv[0];
		for( i=1; i<= n-2; i++)
		{
			jj  = jj +(fenjie[i] - fenjie[i-1]) * bilv[i];
		}

		jj = jj  +( jine- fenjie[n-2]) * bilv[n-1];

		printf("%.2lf\n", jj);
		return 0;
	}

	// case 落在中间
	int dangwei ;
	for( i=0; i<= n-1; i++)
	{
		if ( jine < fenjie[i])
		{
			dangwei = i-1;
			break;
		}
	}

	// 0下标档处理掉
	// 1下标到dangwei下标，处理掉
	// 在把jine比挡位下标多余的部分处理掉
	if(1)
	{
		jj = 0.0;
		jj  = jj + fenjie[0] * bilv[0];
		for( i=1; i<=dangwei; i++)
		{
			jj  = jj +(fenjie[i] - fenjie[i-1]) * bilv[i];
		}

		jj = jj  +( jine- fenjie[dangwei]) * bilv[dangwei+1];
		printf("%.2lf\n", jj);
		return 0;

	}

	return 0;

}

```

## 221027-YOJ刷题.txt
```c

#include <stdio.h>

int main()
{
	// input
	int n;
	scanf("%d", &n);

	int timu[100];
	int i;
	for( i=0; i<n ; i++)
		scanf( "%d", &timu[i]);

	int m, k;
	scanf("%d%d", &m, &k);

	int sno[100];
	int done[100];

	for( i=0; i< m; i++)
	{
		scanf("%d", &sno[i]);

		// 扫描他做的题，看看是否在老师要求里，适当计数
		done[i] = 0;

		int p;
		scanf("%d", &p);
		int j;
		for( j=0; j< p; j++)
		{
			int done_timu;
			scanf("%d", &done_timu);

			int found = 0;
			int cha;
			for( cha=0; cha<n; cha++)
				if( timu[ cha] == done_timu)
				{
					found=1;
					break;
				}
			if ( found == 1) done[i] = done[i] +1;
		}
	}
	// count finished

	// sort
	// sno  done  m
	// done 从大到小，sno从小到大
	int range;
	for( range = m; range >=2; range--)
	{
		int temp;
		for(i=0; i<= range-2; i++)
		{
			if ( done[i] > done[i+1])
			{}// do nothing
			else if ( done[i] == done[i+1])
			{
				if ( sno[i] > sno[i+1])
				{
					temp = sno[i];
					sno[i] =sno[i+1];
					sno[i+1]=temp;
					temp = done[i];
					done[i] =done[i+1];
					done[i+1]=temp;
				}
				else if  ( sno[i] == sno[i+1]) {} // do nothing
				else if  ( sno[i] < sno[i+1]) {} // do nothing
			}
			else if ( done[i] < done[i+1])
			{
				temp = sno[i];
				sno[i] =sno[i+1];
				sno[i+1]=temp;
				temp = done[i];
				done[i] =done[i+1];
				done[i+1]=temp;
			}
		}
	}

	// paiming
	int paiming[100];

	int pm = 1;
	paiming[0] =1;
	
	for( i=1; i<= m-1; i++)
		// 做题数量跟上一个一样
		// 做题数量跟上一个不一样
	{
		if( done[i] == done[i-1])
		{
			paiming[i] = paiming[i-1];
		}
		             else if ( done[i] != done[i-1])
		{
			pm = pm +1;
			paiming[i] = pm;
		}
	}


	//shouji
	int shouji[100];
	int kk =0;
	for( i=0 ; i<=m-1; i++)
		if ( paiming[i] <= k)
		{
			shouji[i] = sno[i];
		kk = kk +1;
		}


	//output
	for(i=0; i<=kk-2; i++)
		printf("%d ", shouji[i]);
	printf("%d\n", shouji[ kk-1]);

	return 0;
}

```

## 221101-139统计最大、最小、平均.txt
```c
#include <stdio.h>
#include <string.h>
int main()
{
    int n;
    scanf("%d", &n);
    
    int i;
    int a[200];
    for(i=0; i< n; i++)
        scanf("%d", &a[i]);
        
    //
    int zuida = a[0];
    int zuixiao = a[0];
    double sum=0.0;
    for(i=0; i<n; i++)
    {
        sum  = sum + a[i];
        if (a[i] > zuida) zuida = a[i];
        if (a[i] < zuixiao)zuixiao = a[i];
    }
        
    double pingjun = sum/n;
    printf("%d %d %.0f\n", zuida, zuixiao, pingjun);
    
    return 0;
}

```

## 221101-YOJ椰子.txt
```c
#include <stdio.h>
#include <math.h>

int main(int argc, char **argv)
{

	int nn  = 25;//a[i];
	int old_nn = nn;

	int nn_root = sqrt( nn);//5
	int m;
	
	int found =0;// for 找到没有
	
	for ( m = nn_root; m>=2; m--)// 5 4 3 2 尝试
	{
		int zhege_ok  = 1;
		
		int j;
		nn =old_nn;
		
		for( j =0; j< m; j++)// 做m次
		{
			nn = nn-1;
			if ( nn % m != 0)
			{
				zhege_ok =0;
				break;
			}
			else
			{
			    int mm = nn/m;
			    nn = nn - mm;
			}
		}
		if ( nn %m != 0) zhege_ok = 0;

		if ( zhege_ok == 1)
		{
			found = 1;
			printf("%d\n", m);

			break;
		}

	}
	if ( found == 0)
        printf( "no solution\n");

	return 0;
}

```

## 221108-YOJ椰子函数.txt
```c
#include <stdio.h>
#include <math.h>

// are_you_ok
int are_you_ok( int n, int m)
{
	//行的返回1
	//不行返回0
	int ok =1;
	int i;
	int nn = n;

	for (i=1; i<=m; i++)
	{
		nn = nn-1;
		if ( nn%m == 0)
		{
			int shang = nn/m;
			nn = nn-shang;
		}
		else
		{
			ok=0;
			return ok;
		}
	}

	if ( nn%m != 0)
		ok = 0;
	return ok;
}

#define NOT_FOUND -1

// panduan
int panduan( int n)
{
	// 25
	// 检查5 4 3 2行不行
	int root = sqrt( n);
	int i;
	for( i=root; i>=2; i--)
	{
		int ok = are_you_ok( n, i);
		if ( ok == 1)
			return i;
	}

	return NOT_FOUND;
}

// main
int main()
{
	int a[20];
	int count=0;
	while(1)
	{
		int one;
		scanf("%d", &one);
		if ( one ==0) break;
		
		count = count +1;
		a[count-1] = one;
	}

	//
	int i;
	for( i=0; i< count; i++)
	{
		int n = a[i];
		int ret = panduan( n);
		if ( ret == NOT_FOUND)
			printf("no solution\n");
		else
			printf("%d\n", ret);
	}

	return 0;
}

```

## 221110-平行四边形cpp.txt
```c
#include <stdio.h>

int main(int argc, char **argv)
{
	int x0,y0;
	int x1,y1;
	int x2,y2;

	scanf("%d%d", &x0, &y0);
	scanf("%d%d", &x1, &y1);
	scanf("%d%d", &x2, &y2);

	printf("3\n");

	// point0
	int delta_x = x0-x2;
	int delta_y = y0-y2;

	int new_x = x1+delta_x;
	int new_y = y1+delta_y;
	printf("%d %d\n", new_x, new_y);

	// point1
	delta_x = x0-x1;
	delta_y = y0-y1;
	new_x = x2+delta_x;
	new_y = y2+delta_y;
	printf("%d %d\n", new_x, new_y);


	// point2
	delta_x = x1-x0;
	delta_y = y1-y0;
	new_x = x2+delta_x;
	new_y = y2+delta_y;
	printf("%d %d\n", new_x, new_y);



	return 0;
}

```

## 221117-小于N的个数、大于N的个数.txt
```c
小于N的个数、大于N的个数




#include <stdio.h>

int main() {

 int n, a, d = 0, s = 0;
 scanf("%d", &n);

 while (a != 0) {
  scanf("%d", &a);
  if (a > n)
   d++;
  else if (a <= n && a > 0)
   s++;
 }

 printf("%d %d", s, d);
// printf("%d", d);

 return 0;
}
```

## 221117-小于N的个数、大于N的个数2.txt
```c
#include <stdio.h>

int main()
{
    int fenjie;
    int count1 = 0;
    int count2 = 0;

    scanf("%d", &fenjie);
    while(1)
    {
        int shuzhi = 0;
        scanf("%d", &shuzhi);

        if(shuzhi == 0)
            break;

        if(shuzhi <= fenjie)
            count1++;
        else if(shuzhi > fenjie)
            count2++;
    }
    printf("%d %d\n", count1, count2);

    return 0;
}
```

## 221122-分书、及时检查.txt
```c
分书、及时检查

#include <stdio.h>

// show
void show(int fenpei_book[5])
{
    printf("%d %d %d %d %d\n", //
    fenpei_book[0], fenpei_book[1], fenpei_book[2], //
    fenpei_book[3], fenpei_book[4]);
}

// check_so_far
int check_so_far(int cur_person, int book, int fenpei_book[5])
{
    // 0号person, 和[]下标fenpei_book检查
    // 1号person, 和[0]下标fenpei_book检查
    // 2号person, 和[0 1]下标fenpei_book检查
    // 3号person, 和[0 1 2 ]下标fenpei_book检查
    // 4号person, 和[0 1 2 3]下标fenpei_book检查

    int i;
    for(i = 0; i <= cur_person - 1; i++)
    {
        int index = i;
        int book_you = fenpei_book[index];
        if(book_you == book)
            return 1;//用过了
    }

    return 0;//没用过
}

// fenshu
void fenshu(int cur_person, int fenpei_book[5], int like[5][5])
{
    int book;
    for(book = 0; book <= 4; book++)
    {
        int xihuan_ma = like[cur_person][book];
        if(xihuan_ma)
        {
            if(check_so_far(cur_person, book, fenpei_book) == 0)//没用过
            {
                fenpei_book[cur_person] = book;

                if(cur_person == 4)
                    show(fenpei_book);
                else
                    fenshu(cur_person + 1, fenpei_book, like);
            } // check so far
        }     // xihuan ma
    }         // for book
};

//main
int main()
{
    int like[5][5] = { 0, 0, 1, 1, 0, 
    1, 1, 0, 0, 1,
    0, 1, 1, 0, 1, 
    0, 0, 0, 1, 0, 
    0, 1, 0, 0, 1 };

    int fenpei_book[5] = { -1, -1, -1, -1, -1 };

    int cur_person = 0;
    fenshu(cur_person, fenpei_book, like);

    return 0;
}

```

## 221129-147为班级分配教室.txt
```c
147为本机分配教室

#include <stdio.h>
int main()
{
    int jiaoshi[9] = { 0, 120, 40, 85, 50, 100, 140, 70, 100 };

    int banji1, banji2, banji3, banji4;
    scanf("%d%d%d%d", &banji1, &banji2, &banji3,& banji4);

    //
    int has_solution = 0;

    int i, j, k, l;
    for(i = 1; i <= 8; i++)
        for(j = 1; j <= 8; j++)
            for(k = 1; k <= 8; k++)
                for(l = 1; l <= 8; l++)
                {
                    if(i != j && i != k && i != l && //
                        j != k && j != l &&          //
                        k != l)                      //两两不等
                    {
                        if(banji1 <= jiaoshi[i] &&  //
                            banji2 <= jiaoshi[j] && //
                            banji3 <= jiaoshi[k] && //
                            banji4 <= jiaoshi[l] )
                        {
                            printf("%d %d %d %d\n", i, j, k, l);
                            has_solution = 1;
                        }
                    }
                }

    if(has_solution == 0)
        printf("-1\n");

    return 0;
}


```

## 231026-YOJ193登记、计数、查找（最大，最小、排序).txt
```c
#include <stdio.h>
/*
输入样例
	7 4
	7 7 2 7
输出样例
	7
*/

int main()
{
	// input
	int n,m;
	scanf("%d%d", &n, &m);

	// 构造的票表格
	int no[10000];
	int votes[10000];
	int i;
	for(i=0; i<10000; i++)votes[i] = 0;
	int count = 0;

	for (i=0; i<m; i++)
	{
		int cur_no;
		scanf("%d", &cur_no);

		// find in table
		int j;
		int found =0;
		int found_index = -1;
		for(j=0; j<count; j++)
		{
			if ( cur_no == no[j])
			{
				found = 1;
				found_index = j;
				break;
			}
		}

		// found or ont found
		//  在票表里找到，得票加一
		//  ...找不到，增加这个人作为新的表条目，得票为1
		if ( found == 1)
		{
			votes[ found_index ] += 1;
		}
		else
		{
			count = count +1;
			no[ count-1] = cur_no;
			votes[ count - 1] = 1;
		}
	}

	// output
	int ban_shu = m/2;
	int j;
	int youren_chaoguo_banshu = 0;
	for (j=0; j<count; j++)
	{
		if ( votes[j] > ban_shu)
		{
			printf("%d\n", no[j]);
			youren_chaoguo_banshu = 1;
			break;
		}
	}

	if (youren_chaoguo_banshu == 0)
		printf("-1\n");

	return 0;
}

```

## 231102-成绩单-多标准排序.txt
```c
6
sun 	59 	61
zhang 	60 	60
li 	79 	81
su 	80 	80
qian 	91 	89
zhao  	90 	90

0. n<=20，姓名长度<=30
1. 按照总分进行排序
2. 如果总分一样
    那么按照语文进行排序

#include <stdio.h>
#include <math.h>
#include <string.h>

#define SMALL 1e-3

int main()
{
	// input
	int n;
	scanf("%d", &n);

	char xingming[20][31];// 最多20人，姓名长度<=30
	float yuwen[20];
	float shuxue[20];
	float zongfen[20];
	int i;
	for (i=0; i<n; i++)
	{
		scanf("%s%f%f", xingming[i], &yuwen[i], &shuxue[i]);
		zongfen[i] = yuwen[i] + shuxue[i];
	}

	// sort
	int range;
	for(range=n; range>=2; range--)
	{
		for(i=0; i<= range-2; i++)
		{
			// 按照总分，从大到小排序
			// 总分一样，则按照语文，从大到小排序
			if ( fabs( zongfen[i] - zongfen[i+1]) <= SMALL) //两个总分相等
			{
				if ( fabs( yuwen[i] - yuwen[i+1]) <= SMALL) //两个语文相等
				{}
				else if (yuwen[i] >yuwen[i+1])
				{}
				else // yuwen[i] <yuwen[i+1]
				{
					char str[30];
					strcpy( str, xingming[i]);
					strcpy( xingming[i], xingming[i+1]);
					strcpy( xingming[i+1], str);
					
					float temp;
					temp = yuwen[i];
					yuwen[i] = yuwen[i+1];
					yuwen[i+1] = temp;
					
					temp = shuxue[i];
					shuxue[i] = shuxue[i+1];
					shuxue[i+1] = temp;
					
					temp = zongfen[i];
					zongfen[i] = zongfen[i+1];
					zongfen[i+1] = temp;
				}
			}
			else if (zongfen[i] > zongfen[i+1])
			{}
			else // zongfen[i] < zongfen[i+1]
			{
				char str[30];
				strcpy( str, xingming[i]);
				strcpy( xingming[i], xingming[i+1]);
				strcpy( xingming[i+1], str);
				
				float temp;
				temp = yuwen[i];
				yuwen[i] = yuwen[i+1];
				yuwen[i+1] = temp;
				
				temp = shuxue[i];
				shuxue[i] = shuxue[i+1];
				shuxue[i+1] = temp;
				
				temp = zongfen[i];
				zongfen[i] = zongfen[i+1];
				zongfen[i+1] = temp;

			}  // if
		}   // for i
	}// for range

	// output
	for(i=0; i<n; i++)
		printf("%s %.0f %.0f\n", xingming[i], yuwen[i], shuxue[i]);

	return 0;
}

```

## 231102-查找、计数、排序.txt
```c
10
zhang zhang li li zhang zhang zhang zhao zhao zhang

0. N<=20，N个名字
1. 请统计每人得票数
2.按照得票数，输出前3位候选人
（如果不够3位，输出所有候选人
如果有并列的，继续输出）

#include <stdio.h>
#include <string.h>

int main()
{
        int n;
        scanf("%d", &n);

       int i;
       char cur_name[31];
       char name_list[20];
       int  vote_list[20];
       int count = 0;
       for(i=0; i<n; i++)
       {
           scanf("%s", cur_name);

            // 拿到某个名字，去票表里面查找
            // 有的话，票数加一
            //没有的话，加一个人，票数为1

            int j;
             int found = 0;  int found_index = -1;
            for( j = 0; j<= count-1; j++)
               if ( strcmp( cur_name, name_list[j]) == 0) 
                 { 
                          found = 1; found_index = j;
                          break;
                 }
          if ( found == 1)
          {    vote_list[found_index] += 1; }
          else // found == 0
          {
                  count += 1;
                 strcpy( name_list[count-1] , cur_name);
                 vote_list[count-1] = 1;
          }
       }// for

      // sort
      int range;
      for(range=n; range>=2; range--)//@FIX 改为count
      for( i=0; i<=range-2; i++)
      {
          if ( vote_list[i] < vote_list[i+1] )
          {
                 char str[31];
                 strcpy(  str, name_list[i]);
                 strcpy(  name_list[i], name_list[i+1]);
                 strcpy(  name_list[i+1], str);
                 
                  int temp;
                  temp = vote_list[i];
                   vote_list[i] = vote_list[i+1];
                   vote_list[i+1] = temp;
          }
      }

    // output
     if ( n<=3)// 1 2 3
     {
         for(i=0; i<n; i++)
                  printf("%s %d\n", name_list[i], vote_list[i]);
     }
     else // 
     {
        for(i=0; i<3; i++)
                  printf("%s %d\n", name_list[i], vote_list[i]);
        int disange_depaioshu = vote_list[2];
        i  = 3;
        while( vote_list[i] == disange_depaioshu )
                 { 
                     if ( i>=n) break; //@FIX 这句话挪到i++后 if( i>=count) break;
                   printf("%s %d\n", name_list[i], vote_list[i]);
                   i++}
     }

     return 0;
         
}
```

## 231103-790二维矩形区域查找.txt
```c
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int i;
    int px[100000];
    int py[100000];
    for(i = 0; i < n; i++) {
        scanf("%d%d", &px[i], &py[i]);
    }

    int x0[100000];
    int x1[100000];
    int y0[100000];
    int y1[100000];
    int q;
    scanf("%d", &q);
    for(i = 0; i < q; i++) {
        scanf("%d%d%d%d", &x0[i], &x1[i], &y0[i], &y1[i]);
    }

    //
    int count[100000];
    for(i = 0; i < q; i++)
        count[i] = 0;

    int j;
    for(i = 0; i < n; i++) {
        for(j = 0; j < q; j++)
            if(px[i] >= x0[j] && px[i] <= x1[j] && py[i] >= y0[j] && py[i] <= y1[j])
                count[j] = count[j] + 1;
    }

    for(i = 0; i < q; i++)
        printf("%d\n", count[i]);

    return 0;
}
```

## 231107-字符串-大整数相加2.txt
```c
1.回顾strcmp
str1[200] = "33333333333333333333333333333333333";
str2[200] = "99999999999999999999999999999999999";
if (str1 < str2) //错的

if (strcmp( str1, str2) <0) 

-1<0按照字典序"33333333333333333333333333333333333"在"99999999999999999999999999999999999"
前面
	33333333333333333333333333333333333
	99999999999999999999999999999999999


2.两个字符串如何判断大小	
if (strcmp( str1, str2) <0) 


3.不等长的字符串，如何处理
char str1[100] = "999876";
char str2[100] = "33";
char str3[100];
int i;
int diff = strlen( str1) - strlen(str2);   // 6 - 2 = 4
for( i=0; i<  diff; i++)   // 0 1 2 3 
   str3[i] = '0';
for( i=0; i< strlen(str2); i++)  // 4+0  4+1    <- 0 1 
   str3[diff+i] = str2[i];
int last = strlen(str1);
str3[ last ] = '\0'; // 0 1 2 3 4 5 分别是00033，现在在6下标下加一个\0


4.如何开始考虑各种情况
（1）999 + 333	已经ok
（2）333 + 999	本质上就是（1）
（3）999 - 333	自己写一个
		203-188，注意有借位情况，有左边为0情况
（4）333-999	转换为999-333，然后注意负号


5. coverage涵盖

   char str1[100];
   char str2[100];
   char op[10];
   gets(op);
   gets(str1);
   gets(str2);
   
   char str1_new[100];
   char str2_new[100];
/*
+  
-999
-333
*/
if ( str1[0] == '+' || str1[0] >='1' && str1[0] <='9) 
    sign1 = +1;
if ( str1[0] == '1') 
    sign1  = -1;


if ( op[0] == '+' )
{

}
else if ( op[0] == '-')
{
}



5.展开各种情况（考虑所有情况）
+
	正正	999/333  	已经ok			333/999已经ok
	正负	999/-333   已经ok			333/-999转换为999-333
	负负  	-999/-333 用加法999+333注意负号		-333/-999用加法注意负号
	负正	-999/333	用减法注意负号		-333/999用减法

-
	正正	999/333  	用减法			333/999	用减法，注意负号
	正负	999/-333   转换为999+333		333/-999转换为333+999
	负负  	-999/-333 即333-999，转换为999-333注意负号	-333/-999即999-333
	负正	-999/333	即-999-333，转换为999+333注意负号	-333/999即-333-999，转换为333+999注意负号





#include <stdio.h>
#include <string.h>
/*

5437
2456
       7893
9873
2435
        12308

*/
int main()
{
     char str1[100 +1]; // 整数的数字个数为100，字符串末尾还得有一个\0
     char str2[100 +1];
     char str3[100 +1];
 
     gets( str1);
     gets( str2);
 
     int n = strlen(str1);

     // 从右边开始，取得字符，转换数字，加起来，注意进位
     int i;
     int jinwei=0;
     for( i= n-1;  i>=0; i--)
     {
            char zifu1 = str1[i];
            char zifu2 = str2[i];

            int shuzi1 = zifu1 - '0';
            int shuzi2 = zifu2 - '0';
            int jiaqilai = shuzi1 + shuzi2  + jinwei;

            //注意，加完了以后，可能有进位到下一步计算
            if( jiaqilai >=10)
             {
                jinwei  = 1;
                jiaqilai = jiaqilai -10;
                str3[i] = '0' + jiaqilai;
              }
             else
             {
                jinwei = 0;
                 str3[i] = '0' + jiaqilai;
             }
     }

     str3[n] = '\0'; // very important

     if ( jinwei ==1)
    {
          printf("%c", '1');
          puts(str3);
     }
    else
    { puts(str3);}

     return 0;   
}
```

## 231108-YOJ181奇怪的数列、递归与递推.txt
```c
## 231113-298被x和y整除且含数字z.txt
```c
#include <stdio.h>

int main()
{
    int a, b, x, y, z;
    scanf("%d%d%d%d%d", &a, &b,  &x, &y, &z);

    int n;
    int found_one_from_a2b =0;
    
    for (n=a; n<=b; n++)
    {
        // n
        // 能够被x和y整除，且某一位上含有z的整数

        if ( n %x !=0  || n%y!=0)
            continue;

        // 看某一位上是否有z
        int baohan_z = 0;
        int nn =n;
        while(1)
        {
            int shang = nn/10;
            int yu = nn%10;
            
            if (yu == z)
            {
                baohan_z =1;
                break;
            }

            if (shang == 0) break;

            nn = shang;
        }// while
        
        if (baohan_z == 0)
            continue;
        else
        {
            found_one_from_a2b  =1;
            printf("%d\n", n);
        }
    }// for n

    if (found_one_from_a2b ==0)
        printf("No\n");

    return 0;
}

```

## 231113-make kuohao括号.txt
```c
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <string>

// make_kuohao
void make_kuohao( std::string cur_str)
{
    if (cur_str.length() == 6)
        printf("%s\n", cur_str.c_str());
    else
    {
        std::string str_temp1 = "()";
        str_temp1 = str_temp1 + cur_str;

        std::string str_temp2 = "(";
        str_temp2 = str_temp2 + cur_str;
        str_temp2 = str_temp2 + ")";

        std::string str_temp3 = cur_str;
        str_temp3 = str_temp3 + "()";

        if(strcmp(str_temp1.c_str(), str_temp2.c_str() ) == 0)
        {}
        else
            make_kuohao(str_temp2);

        if(strcmp(str_temp1.c_str(), str_temp3.c_str() ) == 0)
        {}
        else
            make_kuohao(str_temp3);

        make_kuohao(str_temp1);

    }// not length ==6
}

int main()
{
    std::string cur_str = "";
    make_kuohao(cur_str);

    return 0;
}

```

## 231116-117摘桃子.txt
```c
#include <stdio.h>

int max_path_length = 0;
int path_count = 0;
// show_path
void show_path( int n, int step, int path_value[100])
{
    printf("path so far: ");
    int i;
    for(i=0; i<=step; i++)
        printf("%d ",path_value[i]);

    printf("\n");
}

#define DEBUG 1

// zhai_taozi
void zhai_taozi( int n, int step, //
                 int row, int col, int path_value[100], int pan_mian[100][100])
{
    path_value[step] = pan_mian[row][col];

    if ( row==0)
    {
        // 计算长度，和max_path_length 比较
        int i;
        int length = 0;
        for( i =0; i<=n-1; i++)
            length += path_value[i];
        path_count++;
        if (DEBUG)
        {
            //show_path(n, step, path_value);

            printf("one full path length #%d: %d\n",path_count, length );
        }

        if (length > max_path_length )
            max_path_length = length ;
    }
    else
    {
        int a;
        for (a=0; a<2; a++)
        {
            // a==0尝试往左上
            // a==1尝试往上

            if(a==0)
            {
                if( row-1>=0 && col-1>=0)
                    if (pan_mian[row-1] [col-1] != 0)
                        zhai_taozi(n, step+1, row-1, col-1, path_value, pan_mian);

            }
            else if (a==1)
            {
                if( row-1>=0 && col>=0)
                    if (pan_mian[row-1] [col] != 0)
                        zhai_taozi(n, step+1, row-1, col, path_value, pan_mian);
            }
        }// for
    }//else
}

// main
int main()
{
    // input
    int n;
    scanf("%d", &n);

    int pan_mian[100][100];
    int i;
    int j;

    for (i=0; i<=n-1; i++)
        for(j=0; j<=n-1; j++)
            pan_mian[i][j] = 0;

    for (i=0; i<=n-1; i++)
        for(j=0; j<=i; j++)
            scanf("%d", &pan_mian[i][j]);

    // zhai_taozi
    int path_value[100];
    int step = 0;
    i = n-1;

    for(j = 0; j<= n-1; j++) // n-1行，j列
        zhai_taozi(n, step, i, j, path_value, pan_mian);

    // output
    printf("%d\n", max_path_length );

    return 0;
}

```

## 231117-maximum overlapping interval.txt
```c
#include <stdio.h>
/*
input
3
1 2
2 4
3 6

output
2
*/
#define N 10000
int main()
{
    // input
    int n;
    scanf("%d", &n);

    int begin[100];
    int end[100];
    int i;
    for(i = 0; i< n; i++)
        scanf("%d%d", &begin[i], &end[i]);

    // project
    int heng_zhou[N];
    for(i=0; i<N; i++)
        heng_zhou[i] = 0;
    int j;
    for( i=0; i<n; i++)
        for(j=begin[i]; j<=end[i]; j++)
            heng_zhou[j] += 1;

    // find max
    int max_value = heng_zhou[0];
    int max_index = 0;
    for( j=0; j<N; j++)
        if (heng_zhou[j] >max_value)
        {
            max_value = heng_zhou[j];
            max_index = j;
        }

    // output
    printf("%d\n", max_value);

    return 0;
}

```

## 231121-分书new.txt
```c
#include <stdio.h>

// like
// 喜欢矩阵
// 5个人（行）0，1，2，3，4
// 5本书（列）0，1，2，3，4
const int like[5][5] = { 
	{ 0, 0, 1, 1, 0 },
	{ 1, 1, 0, 0, 1 }, 
	{ 0, 1, 1, 0, 1 }, 
	{ 0, 0, 0, 1, 0 },
	{ 0, 1, 0, 0, 1 } };

// show
void show(int solutions, int the_person[5], int the_book[5])
{
    printf("--------\n");
    printf("solution no: %d\n", solutions);
    int i;
    for(i = 0; i < 5; i++)
        printf("[%d: %d] ", the_person[i], the_book[i]);
    printf("\n");
}

// five_person_no_conflict
int five_person_no_conflict(int the_person[5], int the_book[5])
{
    // book数组
    // 0 []
    // 1 [0]
    // 2 [0，1]
    // 3 [0，1，2]
    // 4 [0，1，2，3]
    int i, j;
    for(i = 0; i <= 4; i++)
    {
        int you_book = the_book[i];
        for(j = 0; j <= i - 1; j++)
        {
            int my_book = the_book[j];
            if(you_book == my_book)
                return 0;
        }
    }

    return 1;
}

// show_jubu
void show_jubu( int cur_person, int the_person[5] , int the_book[5])
{
    printf("--------\n");
    printf("jubu panmian\n");
    int i;
    for(i = 0; i <= cur_person; i++)
        printf("[person %d: book %d] ", the_person[i], the_book[i]);
    printf("\n");
}

int solutions = 0;

// try_fenshu
void try_fenshu(int cur_person, int the_person[5], int the_book[5])
{
    //  为cur_person分书
    //  尝试 0、1、2、3、4这些书
    //  如果能够安排（这个人喜欢这本书），就安排
    //            已经安排到第四个（看看盘面是否有冲突，没有冲突就是一个方案）
    //            还没有安排到第四个（安排下一个人）
    //  *如果都不能够安排（这个人尝试完0-4），就退出本层递归调用，回溯上一个人（for下一本书）
    int book;
    for(book = 0; book < 5; book++)
    {
        if( like[cur_person][book] ==1)
            {
                the_book[cur_person] = book;
                printf( "give book %d to person %d\n", book, cur_person);
	show_jubu( cur_person, the_person, the_book);
                if(cur_person == 4)
                {
                    if(five_person_no_conflict(the_person, the_book) == 1)
                    {
                        solutions++;
                        show(solutions, the_person, the_book);
                    }
                }
                else
                    try_fenshu(cur_person + 1, the_person, the_book);
            }
    }
}

// main
int main()
{
    int the_person[5] = { 0, 1, 2, 3, 4 };
    int the_book[5] = { -1, -1, -1, -1, -1 };

    int cur_person = 0;
    try_fenshu(cur_person, the_person, the_book);

    return 0;
}

```

## 231121-问号填充数字.txt
```c
问号填充数字

#include <stdio.h>
#include <string.h>

int count = 0;

void  try_put_number( int n, int cur_char,//
                      char str_me_old[200], char str_me_new[200], char str_you_old[100] )
{
    // 如果str_me_old的cur_char下标的当前字符
    // 为数字
    //  ------ 拷贝str_me_old数字字符到str_me_new
    //  ------ 如果已经到n-1个字符，用'\0'封死str_me_new，比较str_me_old，str_you_old，大于的话，count++
    //  ------ 如果没有到n-1个字符，那么递归处理cur_char+1字符
    //   为问号
    //   ------ 为str_me_new的cur_char下标，for尝试'0'-'9'字符
    //   ------ 如果已经到n-1个字符，用'\0'封死str_me_new，比较str_me_old，str_you_old，大于的话，count++
    //   ------ 如果没有到n-1个字符，那么递归处理cur_char+1字符

    char cc = str_me_old[cur_char];
    if (cc == '?')//问号
    {
        char c;
        for ( c='0'; c<='9'; c++)
        {
            str_me_new[cur_char] = c;
            if ( cur_char == n-1)
            {
                str_me_new[n] = '\0';
                puts( str_me_new);
                if (strcmp( str_me_new, str_you_old) >0) count++;
            }
            else
                try_put_number( n, cur_char+1,  str_me_old, str_me_new, str_you_old );
        }
    }
    else if ( cc>= '0' && cc<='9')//数字字符
    {
        str_me_new[ cur_char] = str_me_old[cur_char] ;

        if ( cur_char == n-1)
        {
            str_me_new[n] = '\0';
            puts( str_me_new);
            if (strcmp( str_me_new, str_you_old) >0) count++;
        }
        else
            try_put_number( n, cur_char+1,  str_me_old, str_me_new, str_you_old );
    }
}

int main()
{
    char str_me_old[200] = "3?32?5";
    char str_me_new[200];
    char str_you_old[200] = "299999";

    {
        count = 0;
        int n= strlen( str_me_old);
        int cur_char = 0;
        try_put_number( n, cur_char,  str_me_old, str_me_new, str_you_old );
        printf("%d\n", count);
    }

    {
        strcpy(str_me_old, "3??5??");
        strcpy(str_you_old, "299999");

        count = 0;
        int n= strlen( str_me_old);
        int cur_char = 0;
        try_put_number( n, cur_char,  str_me_old, str_me_new, str_you_old );
        printf("%d\n", count);
    }

    return 0;
}

```

## 231128-122迷宫.txt
```c
#include <stdio.h>

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

int found = 0;

// show_panmian
void show_panmian(int n, int m, int a[9][9])
{
    int i;
    int j;
    for(i=0; i<n; i++)
    {
        for( j=0; j<m; j++)
            printf("%d", a[i][j]);

        printf("\n");
    }

    printf("----------\n");
}

// try_walk
void try_walk(int cur_row, int cur_col, int n, int m, int a[9][9])
{
    // 如果 cur_row==n-1 并且cur_col== m-1
    //       设定 found =1，返回
    //  否则尝试上，右，下，左方向
    //       如果从下层回溯回来，已经有found == 1，不用尝试其他方向，直接返回
    //       old_row , old_col ->new_row, new_col
    //       如果new_row, new_col坐标有效、并且这个地方为1
    //            当前位置old_row , old_col设置为走过0
    //            走下去
    //            回溯回来设置为1

    if (cur_row == n-1 && cur_col == m-1)
    {
        found =1;
        return;
    }

    int action;
    for( action = UP; action <= LEFT; action ++)
    {
        if (found == 1) return;

        int old_row = cur_row;
        int old_col = cur_col;

        int new_row;
        int new_col;

        if ( action == UP )
        {
            new_row= cur_row -1;
            new_col = cur_col;
        }
        if ( action == RIGHT )
        {
            new_row= cur_row;
            new_col = cur_col+1;
        }
        if ( action == DOWN )
        {
            new_row= cur_row+1;
            new_col = cur_col;
        }
        if ( action == LEFT )
        {
            new_row= cur_row;
            new_col = cur_col-1;
        }

        if ( new_row >=0 && new_row<=n-1 &&//
                new_col >=0 && new_col <=m-1)
        {
            if (a[new_row][new_col] == 1)
            {
                a[old_row][old_col ]  = 2;//走过了，不能再走
                show_panmian(n,m, a);

                try_walk(new_row, new_col, n, m,a);

                a[old_row][old_col ]  = 1;//回溯
            }
        }// if
    }//for
}

int main()
{
    // input
    int n,m;
    scanf("%d%d", &n, &m);

    int i,j;
    int a[9][9];
    for (i=0; i<n; i++)
        for( j=0; j<m; j++)
            scanf("%d", &a[i][j]);

    //
    try_walk(0,0,n,m, a );

    if (found==0)
        printf("NO\n");
    else
        printf("YES\n");

    return 0;
}

```

## 231128-247问号填充数字.txt
```c
247问号填充数字

#include <stdio.h>
#include <string.h>
/*
36?1?8
236428
#
*/

int count=0;

void try_kuohao( int index, char str_me[200], char str_you[200])
{
        // i下标是数字
	// 往下递归，i+1
        // i下标不是数字
        //     是\0
       //       比较strme stryou，strme大的话，count++
       //     是?
	// 尝试把问号改为0-9，继续递归
	// 注意回到本层递归的时候，把刚才改为0-9的问号恢复问好
        
 

    char c = str_me[index];

    if ( c >= '0' && c<='9')
    {
        try_kuohao(index+1, str_me, str_you);
    }
    else if (c == '?')
    {
        char newc;
        for (newc = '0'; newc<='9'; newc++)
        {
            str_me[index] = newc;
            // show ste_me
            //puts(str_me);
            
            try_kuohao(index+1, str_me, str_you);

            str_me[index] = '?';
            //puts(str_me);
        }
        
    }
    else if (c=='\0')
    {
        if ( strcmp(str_me, str_you) >0 )
        count = count+1;
    }
}

// main
int main(int argc, char **argv)
{   
    char str_me[200];
    char str_you[200];
    
    while(1)
    {
        scanf("%s", str_me);
        if (strcmp( str_me,"#") == 0)
            break;
            
        scanf("%s", str_you);
        
        //
        int index = 0;
        count = 0;
        try_kuohao( index, str_me, str_you);
        printf("%d\n", count);
        
    }
    
    
	return 0;
}

```

## 231128集合划分问题（c语言输出集合数目以及不同的集合）.txt
```c
https://blog.csdn.net/m0_52275819/article/details/120517288
```

## 231129-YOJ124递归、优化.txt
```c

// ----------------------------------------------------------------------------------------------------

	
1，从盘面各个位置，开始找最长路径，修改all max length

max length = 0
2，当从某个位置开始（row, col, panmian, 当前总长）

	尝试上下左右走
               		如果有一个方向能够走(坐标有效，并且数值较小）
                     		 递归走下去（new row, new col, panmian, 当前总长：  总长 = 总长+1步骤）

	如果都不能走
  			 那么当前总长，与this max length比较

5 5
1 2 3 4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9

25

#include <stdio.h>

int max_length = 0;

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

#define _DEBUG 0

// my_try
void my_try( int i, int j, int R, int C, int panmian[50][50], int cur_length)
{
    int can_go_from_here = 0;// true

    int dir;
    for(dir=UP; dir<= LEFT; dir++)
    {
        int newi;
        int newj;
        if (dir == UP)
        {
            newi = i-1;
            newj = j;
        }
        if (dir == RIGHT )
        {
            newi = i;
            newj = j+1;

        }
        if (dir == DOWN )
        {
            newi = i+1;
            newj = j;
        }
        if (dir == LEFT  )
        {
            newi = i;
            newj = j-1;
        }

        if (newi >=0 && newi<= R-1 && newj >=0 && newj<=C-1)
        {
            if (panmian[ newi] [newj] < panmian[i][j])
            {
                can_go_from_here =1;

                if (_DEBUG)
                    printf("new i=%d, newj=%d\n", newi, newj);
                my_try( newi, newj, R, C, panmian, cur_length +1);
            }
        } // if
    }// for

    if (can_go_from_here  ==0)
        if (cur_length >max_length )
        {
            if (_DEBUG)
                printf("cur_length = %d\n", cur_length );
            max_length  = cur_length ;
        }
}

// main
int main()
{
    int R;
    int C;
    scanf("%d%d", &R, &C);

    int panmian[50][50];
    int i;
    int j;
    for(i=0; i<R; i++)
        for(j=0; j<C; j++)
            scanf("%d", &panmian[i][j]);
    //
    //  from any point as beginning
    for(i=0; i<R; i++)
        for(j=0; j<C; j++)
        {
            int cur_length = 1;

            if (_DEBUG)
                printf("try from begin row=%d col=%d\n", i,j);

            my_try( i, j, R,C, panmian, cur_length);
        }

    printf("%d\n", max_length);
    return 0;
}


    //如果这个单元计算过length，直接返回*

    // 如果上下左右，四个单元格，坐标有效情况下，没有更小的单元格
    //      返回1
    // 上下左右，四个单元格，坐标有效情况下，有值小的单元格
    //      分别计算length，用递归
    //      取max
    //      max+加1给maxi,maxj单元格(也就是表示maxi,maxj计算过)


#include <stdio.h>

int max_length = 0;

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3
void show( int R, int C, int panmian[50][50], int length[50][50])
{
	printf("\n\n");
	int i,j;

	for(i=0; i<R; i++)
	{
		for(j=0; j<C; j++)
			printf("%d ", panmian[i][j]);
		printf("\n");
	}

	printf("\n");

	for(i=0; i<R; i++)
	{
		for(j=0; j<C; j++)
			printf("%d ", length[i][j]);
		printf("\n");
	}

	printf("\n");

}

// my_try
int my_try(int i, int j, int R, int C, int panmian[50][50], int length[50][50])
{
	//如果这个单元计算过length，直接返回

	// 如果上下左右，四个单元格，坐标有效，没有更小的单元格
	//      返回1
	// 上下左右，四个单元格，坐标有效，有值小的单元格
	//      分别计算length，用递归
	//      取max
	//      加1给maxi,maxj单元格(设置maxi,maxj计算过)
//printf("we want to know len of %d %d\n", i, j);

	if ( length[i][j] != 0)
		return length [i][j];

	int can_go_from_here = 0;// true

	int max_child_length = 0;

	int dir;
	for(dir=UP; dir<= LEFT; dir++)
	{
		int newi;
		int newj;
		if (dir == UP)
		{
			newi = i-1;
			newj = j;
		}
		if (dir == RIGHT )
		{
			newi = i;
			newj = j+1;

		}
		if (dir == DOWN )
		{
			newi = i+1;
			newj = j;
		}
		if (dir == LEFT  )
		{
			newi = i;
			newj = j-1;
		}

		if (newi >=0 && newi<= R-1 && newj >=0 && newj<=C-1)
		{
			if (panmian[ newi] [newj] < panmian[i][j])
			{
				can_go_from_here =1;

//printf("we recursivly do %d %d for %d %d\n",newi,newj, i, j);

				int child_length = my_try( newi, newj, R, C, panmian, length);
				if (child_length > max_child_length)
					max_child_length = child_length;
			}
		} // if
	}// for

	if( can_go_from_here == 0)
	{
		length[i][j] = 1;
		return length[i][j];
	}
	else//can_go_from_here == 0
	{
		length[i][j] = max_child_length+1;

		//( R,C,panmian, length);

		return length[i][j];
	}
}

// main
int main()
{
	int R;
	int C;
	scanf("%d%d", &R, &C);

	int panmian[50][50];
	int i;
	int j;
	for(i=0; i<R; i++)
		for(j=0; j<C; j++)
			scanf("%d", &panmian[i][j]);

	int length[50][50];
	for(i=0; i<R; i++)
		for(j=0; j<C; j++)
			length[i][j] = 0;

	//
	int maxi = 0;
	int maxj = 0;

	for(i=0; i<R; i++)
		for(j=0; j<C; j++)
		{
			// from any point
			// avoid redundancy computation
			my_try( i, j, R, C, panmian, length);
		}

	//show( R,C,panmian, length);

	max_length = 0;
	for(i=0; i<R; i++)
		for(j=0; j<C; j++)
			if ( length[i][j] >max_length)
				max_length = length[i][j];
				
	printf("%d\n", max_length);

	return 0;
}


```

## 231129-棍子原先的长度为6打碎.txt
```c
// ----------------------------------------------------------------------------------------------------

有个长度6，尝试处理长度6，以它作为棍子原先长度
component 	5 1 5 2 1 2 5 1 2
use_or_not	0 0 0 0 0 0 0 0 0
		1 1 2 3 2 3  4 4 3

	尝试构造和为6的子集（子集编号no，当前子集的和，目标长度6）

	    	如果found==1，则直接返回
	    	当前子集的总和大于6
			do nothing，回溯到上一层级调用，进行其他尝试
	    	当前子集的总和为6
			如果没有剩下的配件，那么找到一种分配方案found=1，返回
			如果还有剩下的配件
				newno =no+1
				newno 子集的和为0
				递归（component ， use_or_not， newno , newno 的和，目标长度6）

	    	当前子集的总和小于6
			如果没有剩下的配件，返回（回溯到上一层级调用，进行其他尝试）
			如果有剩下的配件
				no不变
				尝试没有用过的配件index
					use_or_not[ index] = no // use
					修改当前子集总和
					向下递归（component ， use_or_not，no, 当前子集的和）
			                 	从下面回溯回到这里的时候，use_or_not[ index] = 0// not use
	
#include <stdio.h>

/*
5
5 1 2 2 2
9
5 1 5 2 1 2 5 1 2
*/

int found = 0;

// show
void show( int n, int component[100], int ifusing[100])
{
    int i;
    for(i=0; i<n; i++)
        printf("%d ",  component[i]);
    printf("\n");
    for(i=0; i<n; i++)
        printf("%d ",  ifusing[i]);
    printf("\n----------\n");
}

// try_huafen
void try_huafen( int n, int component[100], int used, int ifusing[100],//
                 int ziji_no, int ziji_sum, int target_len )
{
    if (found == 1) return;

    if ( ziji_sum > target_len)
    {
        // do nothing, back track to upper level call
    }
    else if (ziji_sum == target_len)
    {
        if ( used == n)
        {
            found = 1;
            return;
        }
        else // used <n
        {
            int ziji_no_new = ziji_no+1;
            int ziji_sum_new = 0;

            try_huafen( n, component, used, ifusing,//
                        ziji_no_new, ziji_sum_new, target_len );
        }
    }
    else//ziji_sum < target_len
    {
        if ( used == n)
        {
            // do nothing, back track to upper level call
        }
        else// used < n
        {
            int k;
            for(k=0; k<n; k++)
            {
                if ( ifusing[k] == 0)// not used
                {
                    ifusing[k] = ziji_no;//used

                    show(n, component, ifusing);

                    // used 多了1个
                    // ziji_sum + component[k]
                    try_huafen( n, component, used+1, ifusing,//
                                ziji_no, ziji_sum + component[k], target_len );

                    ifusing[k] = 0;
                }// if
            }// for
        }// used < n
    }// //ziji_sum < target_len
}

// main
int main()
{
    // input
    int n;
    int component[100];

    scanf("%d", &n);
    int i;
    for(i=0; i<n; i++)
        scanf("%d", &component[i]);

    int ifusing[100];
    for(i=0; i<n; i++)
        ifusing[i] = 0;// not use

    //
    found = 0;

    int used = 0;

    int ziji_no = 1;
    int ziji_sum = 0;
    int target_len = 6;

    try_huafen( n, component, used, ifusing,//
                ziji_no, ziji_sum, target_len );

    if (found==1)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
	
```

## 231206-YOJ127超级细菌.txt
```c
#include <stdio.h>
#include <string.h>

/*
f       fn                              sum_till_fn
1       1                               1
2       5 = 2*2+1                  6 = 1+5
3       15 = 3*3+6              21 = 6+15
4       37 = 4*4 +21            58 = 21+37
.....
 * n=1000 303cols
 * n=10000 3012cols
*/

#define LEN 5000
#define N 10000
#define DEBUG_ALL 1

// show
void show( char fn[ LEN+1])
{
    // 下标0到LEN-1是正常字符，下标LEN为\0
    int first_not_zero;
    for( first_not_zero = 0; first_not_zero<=LEN-1; first_not_zero++ )
        if ( fn[first_not_zero] != '0')
            break;
    printf("%s", fn+first_not_zero);
}

// show_number
void show_number( int n, char fn[ LEN+1], char sum_till_fn[LEN+1] )
{
    if (DEBUG_ALL)
    {
        printf("%d: fn ", n);
        show(fn );
        printf("; sum_till_fn ");
        show(sum_till_fn );
        printf("\n", n);
    }
    else
        printf("%d\n", n);

}

// make_num_str
void make_num_str( int n_pingfang, char pingfang_str[LEN+1])
{
    int index = LEN-1;  // 下标0到LEN-1是正常字符，下标LEN为\0
    int nn = n_pingfang;
    while(1)
    {
        int yushu =  nn%10;
        char cc = '0'+yushu -0;
        pingfang_str[index] = cc;

        index --;
        nn = nn/10;
        if (nn == 0)
            break;
    }// while
    return;
}

// add_2_str
void add_2_str( char str1[LEN+1],   //
                char str2[LEN+1], char str3[LEN+1])
{
    int first_not_zero1;
    for( first_not_zero1 = 0; first_not_zero1<=LEN-1; first_not_zero1++ )
        if ( str1[first_not_zero1] != '0')
            break;

    int first_not_zero2;
    for( first_not_zero2 = 0; first_not_zero2<=LEN-1; first_not_zero2++ )
        if ( str2[first_not_zero2] != '0')
            break;
    int min_first_not_zero = first_not_zero1;
    if (first_not_zero2<min_first_not_zero )
        min_first_not_zero = first_not_zero2;

    int index = LEN-1;  // 下标0到LEN-1是正常字符，下标LEN为\0
    int jinwei = 0;
    while(1)
    {
        char zifu1 = str1[index];
        char zifu2 = str2[index];

        int shuzi1 = zifu1 - '0';
        int shuzi2 = zifu2 - '0';

        int jiaqilai = shuzi1 + shuzi2  + jinwei;

        //注意，加完了以后，可能有进位到下一步计算
        if( jiaqilai >=10)
        {
            jinwei  = 1;
            jiaqilai = jiaqilai -10;
            str3[index] = '0' + jiaqilai;
        }
        else
        {
            jinwei = 0;
            str3[index] = '0' + jiaqilai;
        }

        index --;
        if (index <0)
            break;
        if (index < min_first_not_zero-1)
            break;
    }// while

    return;
}

// init_all_zero
 void init_all_zero( char fn[LEN+1])
 {
     int i;
    for(i=0; i<=LEN-1; i++) // 0 - LEN-1是正常字符，LEN位置为\0
        fn[i] = '0';
    fn[LEN] = '\0';
 }
 
// fn_new
void fn_new()
{
    int n=1;

    char fn[ LEN+1]; // 0 - LEN-1是正常字符，LEN位置为\0
    init_all_zero(fn);
    fn[LEN-1] = '1';

    char sum_till_fn[LEN+1];
    init_all_zero(sum_till_fn);
    sum_till_fn[LEN-1] = '1';

    show_number(  n, fn, sum_till_fn);

    char n_pingfang_str[LEN+1];
    init_all_zero(n_pingfang_str);

    char new_fn[LEN+1];
    init_all_zero(new_fn);

    char new_sum_till_fn[LEN+1];
    init_all_zero(new_sum_till_fn);

    while( n<=N-1)
    {
        n ++;
        unsigned int n_pingfang = n*n;

        make_num_str( n_pingfang, n_pingfang_str);

        add_2_str( n_pingfang_str, sum_till_fn, new_fn);
        add_2_str(sum_till_fn,  new_fn, new_sum_till_fn);

        if ( n<= N-1)
            if ( n%5000 ==0)
                printf("processing %d\n", n );
            else
            {}
        else
            show_number(n, new_fn,new_sum_till_fn );

        strcpy(fn, new_fn);
        strcpy(sum_till_fn, new_sum_till_fn);
    }// while
    return;
}

// fn
void fn()
{
    unsigned int n=1;

    unsigned int fn = 1;
    unsigned int sum_till_fn = 1;
    printf("%d fn %d; sum_till_fn %d\n", n, fn, sum_till_fn );

    while( n<=N-1)
    {
        n ++;
        unsigned int n_pingfang = n*n;

        unsigned int new_fn = n*n + sum_till_fn ;
        unsigned   int new_sum_till_fn =  sum_till_fn+ new_fn;

        if ( n<= N-1)
            if ( n%5000 ==0)
                printf("processing %d\n", n );
            else
            {}
        else
            printf("%d fn %d; sum_till_fn %d\n", n, new_fn, new_sum_till_fn );

        fn = new_fn;
        sum_till_fn  = new_sum_till_fn;
    }
    return;
}

// main
int main()
{
    //fn();
    fn_new();

    return 0;
}

```

## 231212-字符串sprintf&sscanf.txt
```c
int a = 39; 
printf( "%03d", a);
//屏幕上打印，039




int b;
scanf("%d", &b);
// 键盘上输入26，那么b就得到26这个值




用户输入a m n，请按照总宽度为m,小数点后有效数字个数为n
打印这个浮点数

double a;
int m;
int n;

scanf("%lf", &a);
scanf("%d%d", &m, &n);
// m n 是  10 3
// 我们希望用m和n构造一个临时的格式串%10.3lf
char my_format[80];
sprintf(my_format, "%%%d.%dlf", m, n);    
// m=10, n=3的时候 ，my_format变成 %10.3lf
printf(my_format, a); // 以my_format %10.3lf格式，打印a
// 3.33456   ->     3.335




sscanf
char yuan_shuju[80] = "56 77 999.999";
int a;
int b;
double c;
sscanf(yuan_shuju, "%d%d%lf", &a, &b, &c);

```

## 231213-YOJ126.txt
```c
#include <stdio.h>

#define ZOU_GUO -200

#define ZUO_ZOU 0
#define YOU_ZOU 1
#define XIA_ZOU 2

int max_value = 0;

// show
void show( int panmian[8][8], int n, int m, int value_till_i_j)
{
	int i, j;

	for(i = 0; i <= n - 1; i++)
	{
		for(j = 0; j <= m - 1; j++)
		{
			printf("%d ", panmian[i][j]);
		}
		printf("\n");
	}
	printf( "the value is %d\n", value_till_i_j);

}

// try_walk
void try_walk(int i, int j, int n, int m, int value_till_now, int panmian[8][8])
{
	// 如果已经到达n-1 m-1
	// ......和max_value比较看看，value_till_now更大的话，改动max_value
	// 如果没有到达 n-1 m-1
	// 	.....尝试左走、右走、下走
	// 	.........如果能走：行坐标在范围之内，列坐标在范围之内，从没走过，
	//  ................递归调用 newi, newj , n, m, value_till_now + ..., panmian
	// ..........如果不能走，do nothing


	if(i == n - 1 && j == m - 1)
	{
		if(value_till_now > max_value)
			max_value = value_till_now;
	}
	else
	{
		int aa;
		for(aa = ZUO_ZOU; aa <= XIA_ZOU; aa++)
		{
			int newi;
			int newj;

			if(aa == ZUO_ZOU)
			{
				newi = i;
				newj = j - 1;
			}
			if(aa == YOU_ZOU)
			{
				newi = i;
				newj = j + 1;
			}
			if(aa == XIA_ZOU)
			{
				newi = i + 1;
				newj = j;
			}

			if(newi >= 0 && newi <= n - 1 && newj >= 0 && newj <= m - 1)
				if (panmian[newi][newj] != ZOU_GUO)
				{
					int old_value = panmian[i][j];
					panmian[i][j] = ZOU_GUO;

					show( panmian, n,m,value_till_now);

					printf("\n\nform %d,%d to %d,%d\n", i, j, newi, newj);

					try_walk(newi, newj, n, m, value_till_now +panmian[newi][newj] , panmian);

					panmian[i][j] =old_value;
				}
		}// for aa
	}// else
}

// main
int main()
{
	int n;
	int m;
	scanf("%d%d", &n, &m);

	int i;
	int j;
	int panmian[8][8];
	for(i = 0; i <= n - 1; i++)
	{
		for(j = 0; j <= m - 1; j++)
		{
			scanf("%d", &panmian[i][j]);
		}
	}

	//  从0  0走到n-1  m-1，注意走过不能走，注意行列下标有效
	// 可以左走、右走、下走
	int value_till_now = panmian[0][0];
	try_walk(0, 0, n, m, value_till_now, panmian);

	printf("%d\n", max_value);

	return 0;
}

```

## 231219-merge sort身份证列表TOP10.txt
```c
#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <memory.h>
#include <time.h>

// ShenFenZheng
struct ShenFenZheng// @FIXME
{
    char all[19]; //18位身份证+\0
    char riqi[9]; //8位日期+\0
};

// show
void show( ShenFenZheng* p, int count)
{
    // 0到count-1
    int i;
    for(i = 0; i<=count-1; i++)
    {
        printf("%s: %s\n", p[i].all, p[i].riqi);//......
    }
}

// merge_sort
void merge_sort(ShenFenZheng* p, int left, int right, ShenFenZheng* temp)
{
    if ( left >= right)//1个元素
        return;

    if (left +1 == right)//2个元素
    {
        if ( strcmp( p[left].riqi, p[right].riqi) >0) //日期 left > right// @FIXME
        {
            ShenFenZheng tt = p[left];
            p[left] = p[right];
            p[right] = tt;
        }
    }

    int middle = (left+right)/2;// 3个以上的元素

    // left 到middle
    // middle +1到right
    merge_sort( p, left, middle, temp);//递归处理左半部
    merge_sort( p, middle+1,right, temp); //递归处理右半部

    //左右半部已经处理好，合并左右半部，利用temp

    int head1= left;
    int tail1= middle;		//左半部的左右

    int head2= middle+ 1;
    int tail2= right;		//右半部的左右

    int i = left;// temp数组的下标

    //准备拷贝
    while (head1 <= tail1 && head2 <= tail2)
    {
        if (strcmp( p[head1].riqi, p[head2].riqi )<= 0)// @FIXME
        {
            temp[i] = p[head1];
            head1++;
        }
        else
        {
            temp[i] = p[head2];
            head2++;
        }

        i++;
    }

    //拷贝剩下部分
    while ( head1 <= tail1)
    {
        temp[i] = p[head1 ];
        head1 ++;
        i++;
    }

    while (head2 <= tail2)
    {
        temp[i] = p[head2];
        head2++;
        i++;
    }

    //copy from temp to p
    for (i = left; i <= right; i++)
    {
        p[i] = temp[i];
    }
}

// show_time
void show_time( clock_t start, clock_t end)
{
    double duration = (double)(end - start) //
                      / CLOCKS_PER_SEC * 1000; // 计算持续时间并转化为毫秒
    printf("Duration in milliseconds: %f\n", duration);
}

// init_shenfenzheng
void init_shenfenzheng( ShenFenZheng* pa)// @FIXME
{
    // 110108197709050043
    //             19770905

    int i;
    pa->all[18] = '\0';
    for(i=0; i<=17; i++)
    {
        int num = rand() % 10;
        pa->all[i] = '0'+ num;
    }

    pa->riqi[8] = '\0';
    for( i=0; i<=7; i++)
        pa->riqi[i] = pa->all[6+i ];
}

// init_shenfenzheng_list
void init_shenfenzheng_list( ShenFenZheng* pa, int count)// @FIXME
{
    int i;
    for( i = 0; i<count; i++)
        init_shenfenzheng( pa+i);//结构pa[i]   结构指针pa+i
}

#define N 10

// main
int main()
{
    ShenFenZheng* pa =
(ShenFenZheng*) malloc( N * sizeof(ShenFenZheng));// @FIXME

    ShenFenZheng* ptemp =
(ShenFenZheng*) malloc( N * sizeof(ShenFenZheng));// @FIXME

    init_shenfenzheng_list( pa, N);// @FIXME

    N<=100?  show( pa, N):   show( pa, 10);

    clock_t start = clock(); // 记录起始时间点
    merge_sort(pa, 0, N-1, ptemp);//0和N-1表示左右
    clock_t end = clock(); // 记录结束时间点
    show_time( start, end);

    N<=100?  show( pa, N):   show( pa, 10);

	free( (void*)pa);
	free( (void*)ptemp);

    return 0;
}

```

## 231220-输入字符矩阵（无用字符）.txt
```c

#include  <stdio.h>

void show( int a[100][100], int n, int m)
{
    for(i=0; i<n; i++)
    {
    for(j=0; j<m; j++)
    {
        printf("%c", a[i][j]);
    }
    printf("\n");
   }

   printf("\n");
}

int main()
{
    char a[100][100];
    int n, m;

    scanf("%d%d", &n, &m);

    int i,j;

    char wuyong;
    scanf("%c", & wuyong);

    for(i=0; i<n; i++)
    {
    for(j=0; j<m; j++)
    {
        scanf("%c", & a[i][j]);
    }
        scanf("%c", & wuyong);
}

    show( a, n, m);

    return 0;
}
```

## 231223-函数与递归-8皇后.txt
```c
4，八皇后问题，边检查，边安排

#include <stdio.h>

#define TRUE 1
#define FALSE 0

int count = 0;

//check_this_with_before
int check_this_with_before(int cur_queen, int row[8], int col[8])
{
    // 0号和前面[]，不同行，不同列，斜线，反斜线
    // 1号和前面[0]，不同行，不同列，斜线，反斜线
    // 2号和前面[0,1]，不同行，不同列，斜线，反斜线
    // ...
    // 7号和[0,1,2,3,4,5,6]，不同行，不同列，斜线，反斜线

    int queen_no = cur_queen;
    int my_row = row[queen_no];
    int my_col = col[queen_no];

    int  i;
    for(i=0; i<=cur_queen-1; i++) // 0, ..., cur_queen-1
    {
        //同行或者同列，返回0
        //斜线、反斜线也检查
        if ( row[i] == my_row )  return FALSE;
        if ( col[i] == my_col)   return FALSE;
        if( row[i] - col[i] == my_row-my_col) return FALSE;
        if ( row[i] +col[i] === my_row+my_col) return FALSE;
    }
    return TRUE;
}


// show
void show(int row[8], int col[8])
{
    char panmian[8][8] = 
    { {'O','O','O','O','O','O','O','O'},
{'O','O','O','O','O','O','O','O'},
{'O','O','O','O','O','O','O','O'},
{'O','O','O','O','O','O','O','O'},
{'O','O','O','O','O','O','O','O'},
{'O','O','O','O','O','O','O','O'},
{'O','O','O','O','O','O','O','O'},
{'O','O','O','O','O','O','O','O'}};

    int i, j;
    for(i=0; i<8; i++)
        panmian[  row[i]  ]   [ col[i] ] = 'X';

    for(i=0; i<8; ++i)
    {
        for(j=0; j<8; ++j)
        {
            printf("%c", panmian[i][j]);
        }
        printf("\n");
    }
}

// queen   0 1 2 3 4  5 6 7 
void queen( int queen_no, int row[8], int col[8] )
{
    int i;
    for(i=0; i< 8; i++)
    {
        col[queen_no] = i;
        
        if (check_this_with_before(queen_no, row, col) == TRUE)
        {
            if (queen_no==7)
            {
                count++;
                show(row, col);
                printf("----------\n");
            }
            else
            {
                queen(queen_no+1, row, col);
            }// if queen_no
        }// if check
    }//for
}

// main
int main(int argc, char **argv)
{
    // 0，1，2,...,7皇后分别在0，1，2,...7行
    // 只是每个皇后的列可以调整
    int row[8] = {0,1,2,3,4,5,6,7};
    int col[8] = {-1,-1,-1,-1,-1,-1,-1,-1};

    queen(0, row, col);

    printf("total solutions %d\n", count);

    return 0;
}
```

## 240816-ackerman simple.txt
```c
#include <stdio.h>

// ackerman_func
int ackerman_func(int m, int n)
{
    printf("calling(%d %d)\n", m, n);

    if (m == 0)
        return n+1;

    if (m!=0 && n==0)
    {
        return ackerman_func(m-1, 1);
    }//case2

    if (m!=0 && n!=0)
    {
        int temp = ackerman_func(m,n-1);
        return ackerman_func( m-1, temp);
    }//case 3
}

// main
int main()
{
    int m=3;
    int n=1;

    int ret = ackerman_func(m,n);
    printf("ack(%d,%d) is %d\n", m, n, ret);

    return 0;
}

```

## 240816-ackerman函数.txt
```c
#include <stdio.h>

// 输出结果比对 https://blog.csdn.net/html_finder/article/details/125928848

#define M 5
#define N  20

#define TRUE 1
#define FALSE 0

// ackerman_func
void ackerman_func(int m, int n,
                   int ackerman_value[M][N],
                   int has_value[M][N])
{
    if (m == 0)
    {
        ackerman_value[m][n] = n+1;
        has_value[m][n] = TRUE;
        return;
    }//case1

    if (m!=0 && n==0)
    {
        if ( has_value[m-1][1] == FALSE)
            ackerman_func(m-1,1, ackerman_value,has_value);

        ackerman_value[m][n] = ackerman_value[m-1][1];
        has_value[m][n] =  has_value[m-1][1];
        return;
    }//case2

    if (m!=0 && n!=0)
    {
        //先算(m,n-1)
        if ( has_value[m][n-1] == FALSE)
            ackerman_func(m,n-1, ackerman_value,has_value);

        //算过之后，如果有值，就继续算，否则不继续算
        if ( has_value[m][n-1] ==TRUE)
        {
            int new_n = ackerman_value[m][n-1];

            if( new_n >=0 && new_n <=N-1)//坐标有效m-1,new_n，计算并且传导到m,n
            {
                if (has_value[m-1][new_n] == FALSE)
                    ackerman_func(m-1, new_n, ackerman_value,has_value);

                ackerman_value[m][n] = ackerman_value[m-1][new_n];
                has_value[m][n] =  has_value[m-1][new_n];
            }
        }
    }//case 3
}

// main
int main()
{
    int ackerman_value[M][N];
    int has_value[M][N]; //是否计算过

    int i,j;
    // init
    for(i=0; i<M; i++)// 0到M-1
        for(j=0; j<N; j++)// 0到N-1
        {
            ackerman_value[i][j] = 0;
            has_value[i][j] = FALSE;
        }

    // calculate
    for(i=0; i<M; i++)
        for(j=0; j<N; j++)
        {
            ackerman_func( i, j, ackerman_value,has_value);
        }

    // output
    for(i=0; i<M; i++)
    {
        for(j=0; j<N; j++)
        {
            if (has_value[i][j] == TRUE)
                printf("(%d,%d)%d ",i,j,ackerman_value[i][j]);
        }
        printf("\n");
    }

    return 0;
}

```

## merged.txt
```c
## 201130-三重循环出快餐.txt
```c
#include <stdio.h>

enum ZhuShi { rice, noodles, steamed_bread}; //米饭、面条、馒头
enum ShuCai { cabbage, potato, spinach}; //卷心菜、土豆、菠菜
enum Roucai { drumstick, duckleg, beef, pork}; //鸡腿，鸭腿，牛肉，猪肉

void show (ZhuShi  zhushi, ShuCai shucai, Roucai roucai)
{
     printf("{");

     if (zhushi == rice) printf("rice ");
     else if (zhushi == noodles) printf("noodles ");
     else if (zhushi == steamed_bread) printf("steamed_bread ");

     if (shucai == cabbage) printf("cabbage ");
     else if (shucai == potato) printf("potato ");
     else if (shucai == spinach) printf("spinach ");

     if (roucai == drumstick) printf("drumstick");
     else if (roucai == duckleg) printf("duckleg");
     else if (roucai == beef) printf("beef");
     else if (roucai == pork) printf("pork");

     printf("}\n");
}

int main()
{
     int  zhushi;
     int  shucai;
     int  roucai;

    for( zhushi = rice; zhushi <=steamed_bread; zhushi++ )
    {
         for( shucai= cabbage; shucai<=spinach; shucai++ )
          {
                for( roucai= drumstick; roucai<=pork; roucai++ )
                {
                      //得到一份便当
                     show ((ZhuShi)zhushi, (ShuCai)shucai, (Roucai)roucai);// zhushi, shucai, roucai
                }
          }
    }

    return 0;
}
```

## 210101-100000个字符串动态内存申请.txt
```c
5
head 3
I am
Happy
today.
Are
you?


5
tail 3
I am
Happy
today.
Are
you?

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
 5
head 3
I am
Happy
today.
Are
you?
 */

int main(int argc, char **argv)
{
 int n;
 char head_or_tail[30];
 int top_n;


 scanf("%d", &n);
 scanf("%s%d", head_or_tail, &top_n);

    //
 char*  name_list[100000];
 int i;
 for(i=0; i<n; i++)
  name_list[i] = (char*)malloc(201);
    //
 char wuyong[32];//取得换行
 gets(wuyong);//取得换行
 
 for(i=0; i<n; i++)
  gets(name_list[i]);

    //
 //for(i=0; i<n; i++)
 // puts(name_list[i]);


    if (strcmp( "head", head_or_tail) == 0)
 {
  for(i=0;i<top_n;i++)
  {
   puts(name_list[i]);
  }
  
 }
 else if (strcmp( "tail", head_or_tail) == 0)
 {
  //5里的3个
  // 2 3 4
  for(i=n-top_n;i<n; i++)
   puts(name_list[i]);
 }
 
 return 0;
}
```

## 210101-100000个字符串动态内存申请0.txt
```c
内存的动态申请
// ----------------------
管理10万个字符串，每个字符串200个字符。
int main ()
{
     char s[100000][201];
    //这回突破栈段的空间限制，程序运行不了
}

// ----------------------

int main ()
{
     char* s[100000];

     int i;
     for(i=0; i< 100000; i++)
        s[i] = (char* ) malloc( 201);

     for(i=0; i< 100000; i++)
          gets( s[i]);
     .............
     for( i=0; i<100000; i++)
          puts( s[i]);

      for(i=0; i< 100000; i++)
        free( (void*) s[i]);

     return 0;

}
```

## 210101-2整除3整除包含4.txt
```c
#include   <stdio.h>
#define N    10000
// 注意把N开到够大

int main()
{
     // 1 50 2 3 4
     // 应该输出 24 42 48

     // 1
     int left,right;
     int one, two;
     int digit;
     scanf("%d %d %d %d %d", &left, &right, &one, &two, &digit);

     // 2
     int  a[N] ;  
     int  b[N];
     for(i=0; i<N; i++)
        { a[i]=0; b[i] = 0;};

     // 3
     int step = one;
     while (1)
     {
     if( step>=left)
    a[step] = 1;
         
         step += step;
         if (step>right) 
             break;
    }

     step = two;
     while (1)
     {
       if( step>=left)
    b[step] = 1;
         step += step;
         if (step>right) 
             break;
    }

     // 4
     for (i=0; i< N; i++)
     {
         if (a[i] ==1 && b[i] ==1)
        {
               //判断有没有digit
              int has_shuzi = 0;
              int xx=i;
              while(1)
              {
                   if (xx==0) break;
                   int mowei = xx%10;
                   if ( mowei == digit) { has_shuzi=1;break};
                   xx = xx/10;
              }
             if (has_shuzi) printf("%d\n", i);

        }// if
     }// for

}
```

## 210101-long long.txt
```c
1，64bit整数
 long long
 unsigned long long

int main()
{
    long long  aa;
    scanf("%lld", &aa);
    printf("%lld\n", aa);

    unsigned long long bb;
    scanf("%llu", &bb);
    printf("%llu\n", bb);

    return  0;
}
```

## 210101-YOJ奖金（档位）.txt
```c
#include <stdio.h>

int main(int argc, char **argv)
{
 // 1
 int m;
 scanf("%d",&m);
 
 int i;
 int fenjie[100];double bilv[100];
 for(i=0;i<m;i++)
 {
  scanf("%d%lf", &fenjie[i], &bilv[i]);
 }
 
 double jine;
 scanf("%lf", &jine);
 
 // 2
 if (jine <0)
 {
  printf("NO");
  return 0;
 }
 
 int dangwei=0;
 for (i=0; i<m;i++)
 {
  if (jine < fenjie[i])
  {
   dangwei=i;
   break;
  }
  if (fenjie[i] == -1)
  {
   dangwei=i;
   fenjie[i] = jine;
   break;
  }
 }
 
 // 3
 double sum = 0;
 for(i=0;i<dangwei;i++)
 {
  if (i==0 )
   sum = sum + (fenjie[i]-0)*bilv[i];
  else 
   sum = sum + (fenjie[i] - fenjie[i-1])*bilv[i];
 }
 
 if(dangwei==0)
      sum = sum+(jine-0)*bilv[0];
else
     sum = sum+ (jine-fenjie[dangwei-1])*bilv[dangwei];
 
 printf("%.2lf", sum);
 
 return 0;
}
```

## 210101-不定数量的身份证（动态内存申请）.txt
```c
内存的动态申请
          管理若干身份证


struct IDCard
{
     char id[20];
     IDCard* next;
};

int main()
{
     IDCard* new_node = (IDCard*) malloc( sizeof( IDCard));
     gets( new_node->id);
    
     IDCard* head = NULL;
     while(1)
     {
            if ( strcmp( new_node->id, "-1")
            {   free( new_node); break;}

            if (head ==NULL)
            {   head = new_node; new_node->next=NULL;}
            else
            {  IDCard* old_head = head;
                new_node->next = old_head; 
                head=new_node};

           new_node = (IDCard*) malloc( sizeof( IDCard));
           gets( new_node->id);
      }

      ................
      
      IDCard* p = head;
      while(p!=NULL)
     {
           IDCard* temp = p;
           p = p->next;
 
            free( temp);
      }
}
```

## 210101-切割单词、保留切割单词.txt
```c
字符串切割单词后、找个地方保存
 

 char str[200];
 int word_start;
 int word_end;
 
 int word_count = 0;
 char word_list[100][100];
 
 // 每次拿到一个词，找地方保存去
 int ww;
 for(ww=word_start; ww<=word_end; ww++)
 {
     word_list[word_count][ww - word_start]=  str[ww];//345 -> 012
 }
 word_list[word_count] [ end-start+1] = '\0';
 word_count++;

 这怎么理解，用小麻雀
 比如start =3, end=5，总共三个字符，占用012下标，应该把下标3置为\0

```

## 210101-字符串-大整数加法.txt
```c
5，设计：大整数加法，超过整数int范围
    char a[501];
 char b[501];
 char c[502];//c有可能多1位
 
 gets(a);
 gets(b);
 ...
    int n= strlen(a);//a,b长度相等，都有n位，下标为0,...,n-1，第n位为\0
 int i;
 int jinwei=0;
 c[n+1]='\0';//c可能多1位，下标从0,1,...,n，第n+1位为\0
 for(i=n-1; i>=0;i--)
 {
      int shu1 = a[i] - '0';// '0', '1','2','3',.....
   int shu2 = b[i] - '0';// 
   
  int he = shu1 + shu2 + jinwei;
  if ( he >=10)
  {
      jinwei =1;
   he = he %10;
   c[i+1] = '0'+he; //'0', '1','2','3',.....
  }
  else
  {
      c[i+1]='0'+he; //'0', '1','2','3',.....
   jinwei=0;
  }
 }
 if( jinwei >0 )
     c[0] = '1';
 else
     c[0] = '0'
 
 案例:
 5555
 3333

 8989
 8787
 
    如果长度不等，那么短的那个左边填零。
 333
 55555
 变成
 00333
 55555
```

## 210101-数组-寻找众数1.txt
```c
6，寻找众数
 微信里面
 
 从数据入手，从小麻雀入手

// --------------------------------------------------------------------------------
#include <stdio.h>

int main()
{
     int n;
     int a[100];

    // 1，输入n和n个数
    scanf("%d", &n);
    int i;
    for(i=0; i<n; i++)
         scanf("%d", &a[i]);


    // 2，找出每个数值的个数，做一个对照表
    if (n == 1)
    {
        printf( "%d\n", a[0];
        return 0;
    }

    // n>=2
    int duizhao[100][2];

    int count =1;
    duizhao[0][0] = a[0];//数值
    duizhao[0][1] = 1; //个数

    for (i=1;i<n;i++)
    {
        int cur_data = a[i];
   
       // 去对照比表查
       // 如果有，个数++
       // 如果没有，末尾新增一个（对照表的行数count长了），个数1

       int  j;
       int found =0;//假设找不到
       for(j=0; j< count; j++)
       {
             if (cur_data == duizhao[j][0])
              {  duizhao[j][1]++;  
                 found=1;
                 break;}
       }
       if ( found==0)
       { duizao[count][0] = cur_data; 
         duizhao[count][1] = 1;
         count ++;}
    }

    // 3，找到个数最大的那个，记住他，输出他
    int max_value = duizhao[0][0];
    int max_count = duizhao[0][1];
    int max_i = 0;

    for (i=1; i<n;i++)
    {
         if ( duizhao[i][1] > max_count )
         {max_value =duizhao[i][0];
          max_count = duizhao[i][1];
          max_i  = i;
         }
    }

    pintf( "%d\n", max_value);

    return 0;
}
```

## 210101-数组-寻找众数2.txt
```c
要找众数，而且是值大的那个，那么可以用排序
#include <stdio.h>

int main()
{
    int count;
    duizhao[100][2];

    count = 4;
duizhao[0][0] = 11;
duizhao[0][1] = 2;

duizhao[1][0] =12;
duizhao[1][1] =1;

duizhao[2][0] =13;
duizhao[2][1]=2;

duizhao[3][0]=15;
duizhao[3][1]=1;



    // sort，第一排序标准，个数
    // 个数相同，那么第二排序表述是数值
    //按照从高到低排序
    int range = count;
    int i;
    for(range = count; range>=2; range--)
    {
        for(i=0; i<range-1; i++)
        {
            if( duizhao[i][1] < duizhao[i+1][1] || 
               duizhao[i][1] == duizhao[i+1][1] &&duizhao[i][0] < duizhao[i+1][0])
            {
                 int temp =duizhao[i][0]; duizhao[i][0] =duizhao[i+1][0]; duizhao[i+1][0] = temp;
                 temp =duizhao[i][1]; duizhao[i][1] =duizhao[i+1][1]; duizhao[i+1][1] = temp;
            }
         }
     }
   

    return 0;
}
```

## 210101-数组的下标访问、指针访问.txt
```c
#include <stdio.h>

int main()
{
    int a[10];

    for( i =0; i<10; i++)
       scanf("%d", &a[i]);
    for( i =0; i<10; i++)
       printf("%d", a[i]);

    int* p=a;
    for( i =0; i<10; i++)
       scanf("%d", p+i);
    for( i =0; i<10; i++)
       printf("%d", *(p+i));

    int* p=a;
    for( i =0; i<10; i++)
    {
       scanf("%d", p);   p++;
     }
     p  =a ;
    for( i =0; i<10; i++)
     {
       printf("%d", *p);   p++;
     }

    int* p=a;
    for( p=a; p < a+10; p++)
    {
       scanf("%d", p);
     }
    for( p=a; p < a+10; p++)
    {
       printf("%d", *p);  
     } 



    for( i =0; i<10; i++)
       printf("%d", p[i]);


    return 0;
}
```

## 210101-计数统计（simple）.txt
```c
计数统计
	动态增长的数组-用于登记

程序逻辑


int a[100];

int n;
scanf("%d", &n);// 输入一个n


int i; 
for(i=0; i<n; i++)
     scanf("%d", &a[i]); //输入n个元素到数组a


//开始进行计数统计
// 对照表，value对应num
int count=0;
int value[100];
int num[100]

for(i=0; i<n; i++)
{
     int the_value = a[i];

     int index = -1;
     int found = 0;
     int j;
    // 先查找
     for(j = 0; j< count; j++)
      {
         	 if ( the_value == value[j] )
          	{	
		 index = j; 
		found=1; 
		break;
	}
      }

     //看找到，找不到
      if ( found == 1)
     { 
	 num[index] ++; 
     }
      else // found ==0
      {
	count++; 

	value[count-1] = the_value; 
	num[count-1]=1;
       }

}

//完成计数统计后，可以输出每个值的个数

```

## 211221-YOJ椰子.txt
```c
#include <stdio.h>

int try_one_m( int n, int m)
{
	int i;
	int nn = n;
	//1到m天
	for( i=1; i<=m;i++)
	{
		int shang  = nn/m;
		int yushu = nn%m;
		if (yushu !=1)
			return 0;
		nn = nn - shang -1;		
	}
	
	// 最后一天
	if (nn %m == 0)
		return 1;
	else 
		return 0;		
}

int main(int argc, char **argv)
{
	int count = 0;
	int a[100];
	
	while(1)
	{
		int n;
		scanf( "%d", &n);
		
		if ( n==0)
			break;
		count++;
		a[count-1] = n;
	}
	
	int i;
	for(i=0; i<count; i++)
	{
		int n = a[i];
			
		int m;
		int found=0;
		for ( m=n-1; m>=1; m--)
		{
			if (try_one_m( n, m) == 1)
			{
				found =1;
				printf("%d\n", m);
				break;
			}
		}
		if (found==0)
			printf("no solution\n");


```

## 211221-函数与递归-fx递归.txt
```c
#include <stdio.h>

int f( int n)
{
    int ret;
    if ( n == 1)
       ret = 1;
    else if ( n==2)
       ret = 2;
    else
       ret = f( n-1) + 2* f(n-2);

   return ret;
}

int main()
{
    int ret = f(3);
    printf("%d\n", ret);

    return 0;

};

```

## 211221-递归-分配教室.txt
```c
6  10 20 30 40 50 60
4  30 40 50 60 
2 3 4 5




#include <stdio.h>


void show ( int n_class, int class_2_room[20])
{
  int i;
  for (i=0; i< n_class-1; i++)
     printf( "%d ", class_2_room[i]);
  printf("%d\n", class_2_room[ n_class-1]);
}

void show_partial( cur_class, class_2_room)
{
  int i;
  for (i=0; i< cur_class-1; i++)
     printf( "%d ", class_2_room[i]);
  printf("%d\n", class_2_room[ cur_class-1]);
}


int check_diff_room( int n_class, int class_2_room[20])
{
    // 0和[]比较
    // 1和[0]比较
    // 2和[0，1]比较
    // ...
    // n_class-1和[0,1,...,n_class-2]比较
    int i;
    int j;
    for( i=0; i<= n_class-1; i++)
   {
       for (j=0; j<=i-1;j++)
          if ( class_2_room[i] == class_2_room[j])
                return 0;
   }
   return 1;
}



int check_rongliang(int n_class, int class_2_room[20],
                      int renshu_class[20],
                      int n_room, int rongliang_room[20])
{  //              class   0 1 2 3
   // class_2_room  2 3 4 5

   // 扫过每个班的安排的教室jiaoshi
   // 得到班级的人数renshu
   // 得到教室的容量jiaoshi_rongliang
   // 班级人数要小于教室容量
   int i;
   for(i=0; i<= n_class-1; i++)
  {
     int jiaoshi = class_2_room[i];
     int renshu  = renshu_class[i];
     int jiaoshi_rongliang = rongliang_room[ jiaoshi];

     if ( renshu > jiaoshi_rongliang)
       return 0;
   }
   return 1;
};




void try_fenpei(int  cur_class, int class_2_room[20],
               int  n_class, int renshu_class[20], 
                int n_room, int rongliang_room[20])
{
    // 给当前班级 cur_class，尝试分配各个教室0，1，..., n_room-1
    // 如果，已经处理到n_class-1
    //         要检查class_2_room里面的n_class个分配，两两教室不同
    //         检查给班级分配的教室，容量大于班级人数
    //如果，没有处理到n_class-1
    //         请递归处理cur_class+1
    int i;
    for( i=0; i< n_room;  i++)
    {
           class_2_room[ cur_class]  = i;
           show_partial( cur_class, class_2_room);
           if (cur_class == n_class-1)
           {
              int check1 = check_diff_room( n_class, class_2_room);
              int check2 = check_rongliang( n_class, class_2_room,
                      renshu_class,
                      n_room, rongliang_room);

              if ( check1 ==1 && check2 == 1)
                   show (n_class, class_2_room);
           }
           else 
              try_fenpei( cur_class+1,class_2_room,//下一个班级
                n_class, renshu_class, 
                n_room, rongliang_room);
    }
}

int main()
{  int i;

   int n_room;
   int rongliang_room[20];
    scanf("%d", &n_room);
    for(i=0; i< n_room; i++)
         scanf("%d", &rongliang_room[i]);

   int n_class;
   int renshu_class[20];
    scanf("%d", &n_class);
    for(i=0; i< n_class; i++)
         scanf("%d", &renshu_class[i]);

    int cur_class = 0;
    int class_2_room[ 20];
    try_fenpei( cur_class,class_2_room,
                n_class, renshu_class, 
                n_room, rongliang_room);

    return 0;
}
              
```

## 211224-YOJ摘桃子.txt
```c
#include <stdio.h>
int max_value = 0;

void go(int a[4][4],int cur_row, int cur_col, int cur_value)
{
	// for 0到1走法
    // 尝试，0走上/1走右上
	// 不能走，什么都不做
	// 能走，走，计算new_row, new_col, new_value
	//       如果那是0，3位置，判断new_value和max_value,适时修改max_value
	//       如果那不是0,3位置，递归go( new_row, new_col, new_value
	int zoufa;
	for(zoufa=0; zoufa<2; zoufa++)
	{
		int new_row;
		int new_col;
		int new_value;
		if (zoufa == 0)
		{
			new_row = cur_row-1;
			new_col = cur_col;
		}
		else if( zoufa==1)
		{
			new_row = cur_row-1;
			new_col = cur_col +1;
		}
		
		if( new_row>=0 && new_row<=3 &&new_col>=0 && new_col<=3 &&
		  a[new_row][new_col] >0)
		  {
			  // 能走
			  new_value = cur_value +a[new_row][new_col];
			  
			  if( new_row == 0 && new_col == 3)
			  {
				  if (new_value>max_value)max_value = new_value;
			  }
			  else
			  {
				  go( a, new_row, new_col, new_value);
			  }
		  }
		  else
		  {
			  // do nothing
		  }
		
	}
	
}


int main(int argc, char **argv)
{
	int a[4][4] = {
		{0,0,0,1},
		{0,0,2,3},
		{0,4,6,5},
		{2,8,5,7}
	};
	
	int cur_row =3;
	int cur_col = 1;
	int cur_value = 8;
	go(a, cur_row, cur_col, cur_value);
	
	printf("max value for %d %d is %d\n", cur_row, cur_col, max_value);
	
	return 0;
}

```

## 211224-YOJ椰子2.txt
```c
## 221018-YOJ奖金.txt
```c
#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);

	int i;
	int fenjie[100];
	double bilv[100];
	int jine;

	for(i=0; i<n; i++)
		scanf("%d%lf", &fenjie[i], &bilv[i]);

	scanf("%d", & jine);

	// case <0
	if ( jine<0)
	{
		printf("NO\n");
		return 0;
	}

	double jj;
	if ( n==1)
	{
		jj = jine * bilv[0];
		printf("%.2lf\n", jj);
		return 0;
	}

	//  case 左边的左

	if ( jine <= fenjie[0] )
	{
		jj = jine * bilv[0];
		printf("%.2lf\n", jj);
		return 0;
	}

// case右边之后
	if ( jine > fenjie[ n-2])
	{
		jj = 0.0;
		jj  = jj + fenjie[0] * bilv[0];
		for( i=1; i<= n-2; i++)
		{
			jj  = jj +(fenjie[i] - fenjie[i-1]) * bilv[i];
		}

		jj = jj  +( jine- fenjie[n-2]) * bilv[n-1];

		printf("%.2lf\n", jj);
		return 0;
	}

	// case 落在中间
	int dangwei ;
	for( i=0; i<= n-1; i++)
	{
		if ( jine < fenjie[i])
		{
			dangwei = i-1;
			break;
		}
	}

	// 0下标档处理掉
	// 1下标到dangwei下标，处理掉
	// 在把jine比挡位下标多余的部分处理掉
	if(1)
	{
		jj = 0.0;
		jj  = jj + fenjie[0] * bilv[0];
		for( i=1; i<=dangwei; i++)
		{
			jj  = jj +(fenjie[i] - fenjie[i-1]) * bilv[i];
		}

		jj = jj  +( jine- fenjie[dangwei]) * bilv[dangwei+1];
		printf("%.2lf\n", jj);
		return 0;

	}

	return 0;

}

```

## 221027-YOJ刷题.txt
```c

#include <stdio.h>

int main()
{
	// input
	int n;
	scanf("%d", &n);

	int timu[100];
	int i;
	for( i=0; i<n ; i++)
		scanf( "%d", &timu[i]);

	int m, k;
	scanf("%d%d", &m, &k);

	int sno[100];
	int done[100];

	for( i=0; i< m; i++)
	{
		scanf("%d", &sno[i]);

		// 扫描他做的题，看看是否在老师要求里，适当计数
		done[i] = 0;

		int p;
		scanf("%d", &p);
		int j;
		for( j=0; j< p; j++)
		{
			int done_timu;
			scanf("%d", &done_timu);

			int found = 0;
			int cha;
			for( cha=0; cha<n; cha++)
				if( timu[ cha] == done_timu)
				{
					found=1;
					break;
				}
			if ( found == 1) done[i] = done[i] +1;
		}
	}
	// count finished

	// sort
	// sno  done  m
	// done 从大到小，sno从小到大
	int range;
	for( range = m; range >=2; range--)
	{
		int temp;
		for(i=0; i<= range-2; i++)
		{
			if ( done[i] > done[i+1])
			{}// do nothing
			else if ( done[i] == done[i+1])
			{
				if ( sno[i] > sno[i+1])
				{
					temp = sno[i];
					sno[i] =sno[i+1];
					sno[i+1]=temp;
					temp = done[i];
					done[i] =done[i+1];
					done[i+1]=temp;
				}
				else if  ( sno[i] == sno[i+1]) {} // do nothing
				else if  ( sno[i] < sno[i+1]) {} // do nothing
			}
			else if ( done[i] < done[i+1])
			{
				temp = sno[i];
				sno[i] =sno[i+1];
				sno[i+1]=temp;
				temp = done[i];
				done[i] =done[i+1];
				done[i+1]=temp;
			}
		}
	}

	// paiming
	int paiming[100];

	int pm = 1;
	paiming[0] =1;
	
	for( i=1; i<= m-1; i++)
		// 做题数量跟上一个一样
		// 做题数量跟上一个不一样
	{
		if( done[i] == done[i-1])
		{
			paiming[i] = paiming[i-1];
		}
		             else if ( done[i] != done[i-1])
		{
			pm = pm +1;
			paiming[i] = pm;
		}
	}


	//shouji
	int shouji[100];
	int kk =0;
	for( i=0 ; i<=m-1; i++)
		if ( paiming[i] <= k)
		{
			shouji[i] = sno[i];
		kk = kk +1;
		}


	//output
	for(i=0; i<=kk-2; i++)
		printf("%d ", shouji[i]);
	printf("%d\n", shouji[ kk-1]);

	return 0;
}

```

## 221101-139统计最大、最小、平均.txt
```c
#include <stdio.h>
#include <string.h>
int main()
{
    int n;
    scanf("%d", &n);
    
    int i;
    int a[200];
    for(i=0; i< n; i++)
        scanf("%d", &a[i]);
        
    //
    int zuida = a[0];
    int zuixiao = a[0];
    double sum=0.0;
    for(i=0; i<n; i++)
    {
        sum  = sum + a[i];
        if (a[i] > zuida) zuida = a[i];
        if (a[i] < zuixiao)zuixiao = a[i];
    }
        
    double pingjun = sum/n;
    printf("%d %d %.0f\n", zuida, zuixiao, pingjun);
    
    return 0;
}

```

## 221101-YOJ椰子.txt
```c
#include <stdio.h>
#include <math.h>

int main(int argc, char **argv)
{

	int nn  = 25;//a[i];
	int old_nn = nn;

	int nn_root = sqrt( nn);//5
	int m;
	
	int found =0;// for 找到没有
	
	for ( m = nn_root; m>=2; m--)// 5 4 3 2 尝试
	{
		int zhege_ok  = 1;
		
		int j;
		nn =old_nn;
		
		for( j =0; j< m; j++)// 做m次
		{
			nn = nn-1;
			if ( nn % m != 0)
			{
				zhege_ok =0;
				break;
			}
			else
			{
			    int mm = nn/m;
			    nn = nn - mm;
			}
		}
		if ( nn %m != 0) zhege_ok = 0;

		if ( zhege_ok == 1)
		{
			found = 1;
			printf("%d\n", m);

			break;
		}

	}
	if ( found == 0)
        printf( "no solution\n");

	return 0;
}

```

## 221108-YOJ椰子函数.txt
```c
#include <stdio.h>
#include <math.h>

// are_you_ok
int are_you_ok( int n, int m)
{
	//行的返回1
	//不行返回0
	int ok =1;
	int i;
	int nn = n;

	for (i=1; i<=m; i++)
	{
		nn = nn-1;
		if ( nn%m == 0)
		{
			int shang = nn/m;
			nn = nn-shang;
		}
		else
		{
			ok=0;
			return ok;
		}
	}

	if ( nn%m != 0)
		ok = 0;
	return ok;
}

#define NOT_FOUND -1

// panduan
int panduan( int n)
{
	// 25
	// 检查5 4 3 2行不行
	int root = sqrt( n);
	int i;
	for( i=root; i>=2; i--)
	{
		int ok = are_you_ok( n, i);
		if ( ok == 1)
			return i;
	}

	return NOT_FOUND;
}

// main
int main()
{
	int a[20];
	int count=0;
	while(1)
	{
		int one;
		scanf("%d", &one);
		if ( one ==0) break;
		
		count = count +1;
		a[count-1] = one;
	}

	//
	int i;
	for( i=0; i< count; i++)
	{
		int n = a[i];
		int ret = panduan( n);
		if ( ret == NOT_FOUND)
			printf("no solution\n");
		else
			printf("%d\n", ret);
	}

	return 0;
}

```

## 221110-平行四边形cpp.txt
```c
#include <stdio.h>

int main(int argc, char **argv)
{
	int x0,y0;
	int x1,y1;
	int x2,y2;

	scanf("%d%d", &x0, &y0);
	scanf("%d%d", &x1, &y1);
	scanf("%d%d", &x2, &y2);

	printf("3\n");

	// point0
	int delta_x = x0-x2;
	int delta_y = y0-y2;

	int new_x = x1+delta_x;
	int new_y = y1+delta_y;
	printf("%d %d\n", new_x, new_y);

	// point1
	delta_x = x0-x1;
	delta_y = y0-y1;
	new_x = x2+delta_x;
	new_y = y2+delta_y;
	printf("%d %d\n", new_x, new_y);


	// point2
	delta_x = x1-x0;
	delta_y = y1-y0;
	new_x = x2+delta_x;
	new_y = y2+delta_y;
	printf("%d %d\n", new_x, new_y);



	return 0;
}

```

## 221117-小于N的个数、大于N的个数.txt
```c
小于N的个数、大于N的个数




#include <stdio.h>

int main() {

 int n, a, d = 0, s = 0;
 scanf("%d", &n);

 while (a != 0) {
  scanf("%d", &a);
  if (a > n)
   d++;
  else if (a <= n && a > 0)
   s++;
 }

 printf("%d %d", s, d);
// printf("%d", d);

 return 0;
}
```

## 221117-小于N的个数、大于N的个数2.txt
```c
#include <stdio.h>

int main()
{
    int fenjie;
    int count1 = 0;
    int count2 = 0;

    scanf("%d", &fenjie);
    while(1)
    {
        int shuzhi = 0;
        scanf("%d", &shuzhi);

        if(shuzhi == 0)
            break;

        if(shuzhi <= fenjie)
            count1++;
        else if(shuzhi > fenjie)
            count2++;
    }
    printf("%d %d\n", count1, count2);

    return 0;
}
```

## 221122-分书、及时检查.txt
```c
分书、及时检查

#include <stdio.h>

// show
void show(int fenpei_book[5])
{
    printf("%d %d %d %d %d\n", //
    fenpei_book[0], fenpei_book[1], fenpei_book[2], //
    fenpei_book[3], fenpei_book[4]);
}

// check_so_far
int check_so_far(int cur_person, int book, int fenpei_book[5])
{
    // 0号person, 和[]下标fenpei_book检查
    // 1号person, 和[0]下标fenpei_book检查
    // 2号person, 和[0 1]下标fenpei_book检查
    // 3号person, 和[0 1 2 ]下标fenpei_book检查
    // 4号person, 和[0 1 2 3]下标fenpei_book检查

    int i;
    for(i = 0; i <= cur_person - 1; i++)
    {
        int index = i;
        int book_you = fenpei_book[index];
        if(book_you == book)
            return 1;//用过了
    }

    return 0;//没用过
}

// fenshu
void fenshu(int cur_person, int fenpei_book[5], int like[5][5])
{
    int book;
    for(book = 0; book <= 4; book++)
    {
        int xihuan_ma = like[cur_person][book];
        if(xihuan_ma)
        {
            if(check_so_far(cur_person, book, fenpei_book) == 0)//没用过
            {
                fenpei_book[cur_person] = book;

                if(cur_person == 4)
                    show(fenpei_book);
                else
                    fenshu(cur_person + 1, fenpei_book, like);
            } // check so far
        }     // xihuan ma
    }         // for book
};

//main
int main()
{
    int like[5][5] = { 0, 0, 1, 1, 0, 
    1, 1, 0, 0, 1,
    0, 1, 1, 0, 1, 
    0, 0, 0, 1, 0, 
    0, 1, 0, 0, 1 };

    int fenpei_book[5] = { -1, -1, -1, -1, -1 };

    int cur_person = 0;
    fenshu(cur_person, fenpei_book, like);

    return 0;
}

```

## 221129-147为班级分配教室.txt
```c
147为本机分配教室

#include <stdio.h>
int main()
{
    int jiaoshi[9] = { 0, 120, 40, 85, 50, 100, 140, 70, 100 };

    int banji1, banji2, banji3, banji4;
    scanf("%d%d%d%d", &banji1, &banji2, &banji3,& banji4);

    //
    int has_solution = 0;

    int i, j, k, l;
    for(i = 1; i <= 8; i++)
        for(j = 1; j <= 8; j++)
            for(k = 1; k <= 8; k++)
                for(l = 1; l <= 8; l++)
                {
                    if(i != j && i != k && i != l && //
                        j != k && j != l &&          //
                        k != l)                      //两两不等
                    {
                        if(banji1 <= jiaoshi[i] &&  //
                            banji2 <= jiaoshi[j] && //
                            banji3 <= jiaoshi[k] && //
                            banji4 <= jiaoshi[l] )
                        {
                            printf("%d %d %d %d\n", i, j, k, l);
                            has_solution = 1;
                        }
                    }
                }

    if(has_solution == 0)
        printf("-1\n");

    return 0;
}


```

## 231026-YOJ193登记、计数、查找（最大，最小、排序).txt
```c
#include <stdio.h>
/*
输入样例
	7 4
	7 7 2 7
输出样例
	7
*/

int main()
{
	// input
	int n,m;
	scanf("%d%d", &n, &m);

	// 构造的票表格
	int no[10000];
	int votes[10000];
	int i;
	for(i=0; i<10000; i++)votes[i] = 0;
	int count = 0;

	for (i=0; i<m; i++)
	{
		int cur_no;
		scanf("%d", &cur_no);

		// find in table
		int j;
		int found =0;
		int found_index = -1;
		for(j=0; j<count; j++)
		{
			if ( cur_no == no[j])
			{
				found = 1;
				found_index = j;
				break;
			}
		}

		// found or ont found
		//  在票表里找到，得票加一
		//  ...找不到，增加这个人作为新的表条目，得票为1
		if ( found == 1)
		{
			votes[ found_index ] += 1;
		}
		else
		{
			count = count +1;
			no[ count-1] = cur_no;
			votes[ count - 1] = 1;
		}
	}

	// output
	int ban_shu = m/2;
	int j;
	int youren_chaoguo_banshu = 0;
	for (j=0; j<count; j++)
	{
		if ( votes[j] > ban_shu)
		{
			printf("%d\n", no[j]);
			youren_chaoguo_banshu = 1;
			break;
		}
	}

	if (youren_chaoguo_banshu == 0)
		printf("-1\n");

	return 0;
}

```

## 231102-成绩单-多标准排序.txt
```c
6
sun 	59 	61
zhang 	60 	60
li 	79 	81
su 	80 	80
qian 	91 	89
zhao  	90 	90

0. n<=20，姓名长度<=30
1. 按照总分进行排序
2. 如果总分一样
    那么按照语文进行排序

#include <stdio.h>
#include <math.h>
#include <string.h>

#define SMALL 1e-3

int main()
{
	// input
	int n;
	scanf("%d", &n);

	char xingming[20][31];// 最多20人，姓名长度<=30
	float yuwen[20];
	float shuxue[20];
	float zongfen[20];
	int i;
	for (i=0; i<n; i++)
	{
		scanf("%s%f%f", xingming[i], &yuwen[i], &shuxue[i]);
		zongfen[i] = yuwen[i] + shuxue[i];
	}

	// sort
	int range;
	for(range=n; range>=2; range--)
	{
		for(i=0; i<= range-2; i++)
		{
			// 按照总分，从大到小排序
			// 总分一样，则按照语文，从大到小排序
			if ( fabs( zongfen[i] - zongfen[i+1]) <= SMALL) //两个总分相等
			{
				if ( fabs( yuwen[i] - yuwen[i+1]) <= SMALL) //两个语文相等
				{}
				else if (yuwen[i] >yuwen[i+1])
				{}
				else // yuwen[i] <yuwen[i+1]
				{
					char str[30];
					strcpy( str, xingming[i]);
					strcpy( xingming[i], xingming[i+1]);
					strcpy( xingming[i+1], str);
					
					float temp;
					temp = yuwen[i];
					yuwen[i] = yuwen[i+1];
					yuwen[i+1] = temp;
					
					temp = shuxue[i];
					shuxue[i] = shuxue[i+1];
					shuxue[i+1] = temp;
					
					temp = zongfen[i];
					zongfen[i] = zongfen[i+1];
					zongfen[i+1] = temp;
				}
			}
			else if (zongfen[i] > zongfen[i+1])
			{}
			else // zongfen[i] < zongfen[i+1]
			{
				char str[30];
				strcpy( str, xingming[i]);
				strcpy( xingming[i], xingming[i+1]);
				strcpy( xingming[i+1], str);
				
				float temp;
				temp = yuwen[i];
				yuwen[i] = yuwen[i+1];
				yuwen[i+1] = temp;
				
				temp = shuxue[i];
				shuxue[i] = shuxue[i+1];
				shuxue[i+1] = temp;
				
				temp = zongfen[i];
				zongfen[i] = zongfen[i+1];
				zongfen[i+1] = temp;

			}  // if
		}   // for i
	}// for range

	// output
	for(i=0; i<n; i++)
		printf("%s %.0f %.0f\n", xingming[i], yuwen[i], shuxue[i]);

	return 0;
}

```

## 231102-查找、计数、排序.txt
```c
10
zhang zhang li li zhang zhang zhang zhao zhao zhang

0. N<=20，N个名字
1. 请统计每人得票数
2.按照得票数，输出前3位候选人
（如果不够3位，输出所有候选人
如果有并列的，继续输出）

#include <stdio.h>
#include <string.h>

int main()
{
        int n;
        scanf("%d", &n);

       int i;
       char cur_name[31];
       char name_list[20];
       int  vote_list[20];
       int count = 0;
       for(i=0; i<n; i++)
       {
           scanf("%s", cur_name);

            // 拿到某个名字，去票表里面查找
            // 有的话，票数加一
            //没有的话，加一个人，票数为1

            int j;
             int found = 0;  int found_index = -1;
            for( j = 0; j<= count-1; j++)
               if ( strcmp( cur_name, name_list[j]) == 0) 
                 { 
                          found = 1; found_index = j;
                          break;
                 }
          if ( found == 1)
          {    vote_list[found_index] += 1; }
          else // found == 0
          {
                  count += 1;
                 strcpy( name_list[count-1] , cur_name);
                 vote_list[count-1] = 1;
          }
       }// for

      // sort
      int range;
      for(range=n; range>=2; range--)//@FIX 改为count
      for( i=0; i<=range-2; i++)
      {
          if ( vote_list[i] < vote_list[i+1] )
          {
                 char str[31];
                 strcpy(  str, name_list[i]);
                 strcpy(  name_list[i], name_list[i+1]);
                 strcpy(  name_list[i+1], str);
                 
                  int temp;
                  temp = vote_list[i];
                   vote_list[i] = vote_list[i+1];
                   vote_list[i+1] = temp;
          }
      }

    // output
     if ( n<=3)// 1 2 3
     {
         for(i=0; i<n; i++)
                  printf("%s %d\n", name_list[i], vote_list[i]);
     }
     else // 
     {
        for(i=0; i<3; i++)
                  printf("%s %d\n", name_list[i], vote_list[i]);
        int disange_depaioshu = vote_list[2];
        i  = 3;
        while( vote_list[i] == disange_depaioshu )
                 { 
                     if ( i>=n) break; //@FIX 这句话挪到i++后 if( i>=count) break;
                   printf("%s %d\n", name_list[i], vote_list[i]);
                   i++}
     }

     return 0;
         
}
```

## 231103-790二维矩形区域查找.txt
```c
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int i;
    int px[100000];
    int py[100000];
    for(i = 0; i < n; i++) {
        scanf("%d%d", &px[i], &py[i]);
    }

    int x0[100000];
    int x1[100000];
    int y0[100000];
    int y1[100000];
    int q;
    scanf("%d", &q);
    for(i = 0; i < q; i++) {
        scanf("%d%d%d%d", &x0[i], &x1[i], &y0[i], &y1[i]);
    }

    //
    int count[100000];
    for(i = 0; i < q; i++)
        count[i] = 0;

    int j;
    for(i = 0; i < n; i++) {
        for(j = 0; j < q; j++)
            if(px[i] >= x0[j] && px[i] <= x1[j] && py[i] >= y0[j] && py[i] <= y1[j])
                count[j] = count[j] + 1;
    }

    for(i = 0; i < q; i++)
        printf("%d\n", count[i]);

    return 0;
}
```

## 231107-字符串-大整数相加2.txt
```c
1.回顾strcmp
str1[200] = "33333333333333333333333333333333333";
str2[200] = "99999999999999999999999999999999999";
if (str1 < str2) //错的

if (strcmp( str1, str2) <0) 

-1<0按照字典序"33333333333333333333333333333333333"在"99999999999999999999999999999999999"
前面
	33333333333333333333333333333333333
	99999999999999999999999999999999999


2.两个字符串如何判断大小	
if (strcmp( str1, str2) <0) 


3.不等长的字符串，如何处理
char str1[100] = "999876";
char str2[100] = "33";
char str3[100];
int i;
int diff = strlen( str1) - strlen(str2);   // 6 - 2 = 4
for( i=0; i<  diff; i++)   // 0 1 2 3 
   str3[i] = '0';
for( i=0; i< strlen(str2); i++)  // 4+0  4+1    <- 0 1 
   str3[diff+i] = str2[i];
int last = strlen(str1);
str3[ last ] = '\0'; // 0 1 2 3 4 5 分别是00033，现在在6下标下加一个\0


4.如何开始考虑各种情况
（1）999 + 333	已经ok
（2）333 + 999	本质上就是（1）
（3）999 - 333	自己写一个
		203-188，注意有借位情况，有左边为0情况
（4）333-999	转换为999-333，然后注意负号


5. coverage涵盖

   char str1[100];
   char str2[100];
   char op[10];
   gets(op);
   gets(str1);
   gets(str2);
   
   char str1_new[100];
   char str2_new[100];
/*
+  
-999
-333
*/
if ( str1[0] == '+' || str1[0] >='1' && str1[0] <='9) 
    sign1 = +1;
if ( str1[0] == '1') 
    sign1  = -1;


if ( op[0] == '+' )
{

}
else if ( op[0] == '-')
{
}



5.展开各种情况（考虑所有情况）
+
	正正	999/333  	已经ok			333/999已经ok
	正负	999/-333   已经ok			333/-999转换为999-333
	负负  	-999/-333 用加法999+333注意负号		-333/-999用加法注意负号
	负正	-999/333	用减法注意负号		-333/999用减法

-
	正正	999/333  	用减法			333/999	用减法，注意负号
	正负	999/-333   转换为999+333		333/-999转换为333+999
	负负  	-999/-333 即333-999，转换为999-333注意负号	-333/-999即999-333
	负正	-999/333	即-999-333，转换为999+333注意负号	-333/999即-333-999，转换为333+999注意负号





#include <stdio.h>
#include <string.h>
/*

5437
2456
       7893
9873
2435
        12308

*/
int main()
{
     char str1[100 +1]; // 整数的数字个数为100，字符串末尾还得有一个\0
     char str2[100 +1];
     char str3[100 +1];
 
     gets( str1);
     gets( str2);
 
     int n = strlen(str1);

     // 从右边开始，取得字符，转换数字，加起来，注意进位
     int i;
     int jinwei=0;
     for( i= n-1;  i>=0; i--)
     {
            char zifu1 = str1[i];
            char zifu2 = str2[i];

            int shuzi1 = zifu1 - '0';
            int shuzi2 = zifu2 - '0';
            int jiaqilai = shuzi1 + shuzi2  + jinwei;

            //注意，加完了以后，可能有进位到下一步计算
            if( jiaqilai >=10)
             {
                jinwei  = 1;
                jiaqilai = jiaqilai -10;
                str3[i] = '0' + jiaqilai;
              }
             else
             {
                jinwei = 0;
                 str3[i] = '0' + jiaqilai;
             }
     }

     str3[n] = '\0'; // very important

     if ( jinwei ==1)
    {
          printf("%c", '1');
          puts(str3);
     }
    else
    { puts(str3);}

     return 0;   
}
```

## 231108-YOJ181奇怪的数列、递归与递推.txt
```c
## 231113-298被x和y整除且含数字z.txt
```c
#include <stdio.h>

int main()
{
    int a, b, x, y, z;
    scanf("%d%d%d%d%d", &a, &b,  &x, &y, &z);

    int n;
    int found_one_from_a2b =0;
    
    for (n=a; n<=b; n++)
    {
        // n
        // 能够被x和y整除，且某一位上含有z的整数

        if ( n %x !=0  || n%y!=0)
            continue;

        // 看某一位上是否有z
        int baohan_z = 0;
        int nn =n;
        while(1)
        {
            int shang = nn/10;
            int yu = nn%10;
            
            if (yu == z)
            {
                baohan_z =1;
                break;
            }

            if (shang == 0) break;

            nn = shang;
        }// while
        
        if (baohan_z == 0)
            continue;
        else
        {
            found_one_from_a2b  =1;
            printf("%d\n", n);
        }
    }// for n

    if (found_one_from_a2b ==0)
        printf("No\n");

    return 0;
}

```

## 231113-make kuohao括号.txt
```c
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <string>

// make_kuohao
void make_kuohao( std::string cur_str)
{
    if (cur_str.length() == 6)
        printf("%s\n", cur_str.c_str());
    else
    {
        std::string str_temp1 = "()";
        str_temp1 = str_temp1 + cur_str;

        std::string str_temp2 = "(";
        str_temp2 = str_temp2 + cur_str;
        str_temp2 = str_temp2 + ")";

        std::string str_temp3 = cur_str;
        str_temp3 = str_temp3 + "()";

        if(strcmp(str_temp1.c_str(), str_temp2.c_str() ) == 0)
        {}
        else
            make_kuohao(str_temp2);

        if(strcmp(str_temp1.c_str(), str_temp3.c_str() ) == 0)
        {}
        else
            make_kuohao(str_temp3);

        make_kuohao(str_temp1);

    }// not length ==6
}

int main()
{
    std::string cur_str = "";
    make_kuohao(cur_str);

    return 0;
}

```

## 231116-117摘桃子.txt
```c
#include <stdio.h>

int max_path_length = 0;
int path_count = 0;
// show_path
void show_path( int n, int step, int path_value[100])
{
    printf("path so far: ");
    int i;
    for(i=0; i<=step; i++)
        printf("%d ",path_value[i]);

    printf("\n");
}

#define DEBUG 1

// zhai_taozi
void zhai_taozi( int n, int step, //
                 int row, int col, int path_value[100], int pan_mian[100][100])
{
    path_value[step] = pan_mian[row][col];

    if ( row==0)
    {
        // 计算长度，和max_path_length 比较
        int i;
        int length = 0;
        for( i =0; i<=n-1; i++)
            length += path_value[i];
        path_count++;
        if (DEBUG)
        {
            //show_path(n, step, path_value);

            printf("one full path length #%d: %d\n",path_count, length );
        }

        if (length > max_path_length )
            max_path_length = length ;
    }
    else
    {
        int a;
        for (a=0; a<2; a++)
        {
            // a==0尝试往左上
            // a==1尝试往上

            if(a==0)
            {
                if( row-1>=0 && col-1>=0)
                    if (pan_mian[row-1] [col-1] != 0)
                        zhai_taozi(n, step+1, row-1, col-1, path_value, pan_mian);

            }
            else if (a==1)
            {
                if( row-1>=0 && col>=0)
                    if (pan_mian[row-1] [col] != 0)
                        zhai_taozi(n, step+1, row-1, col, path_value, pan_mian);
            }
        }// for
    }//else
}

// main
int main()
{
    // input
    int n;
    scanf("%d", &n);

    int pan_mian[100][100];
    int i;
    int j;

    for (i=0; i<=n-1; i++)
        for(j=0; j<=n-1; j++)
            pan_mian[i][j] = 0;

    for (i=0; i<=n-1; i++)
        for(j=0; j<=i; j++)
            scanf("%d", &pan_mian[i][j]);

    // zhai_taozi
    int path_value[100];
    int step = 0;
    i = n-1;

    for(j = 0; j<= n-1; j++) // n-1行，j列
        zhai_taozi(n, step, i, j, path_value, pan_mian);

    // output
    printf("%d\n", max_path_length );

    return 0;
}

```

## 231117-maximum overlapping interval.txt
```c
#include <stdio.h>
/*
input
3
1 2
2 4
3 6

output
2
*/
#define N 10000
int main()
{
    // input
    int n;
    scanf("%d", &n);

    int begin[100];
    int end[100];
    int i;
    for(i = 0; i< n; i++)
        scanf("%d%d", &begin[i], &end[i]);

    // project
    int heng_zhou[N];
    for(i=0; i<N; i++)
        heng_zhou[i] = 0;
    int j;
    for( i=0; i<n; i++)
        for(j=begin[i]; j<=end[i]; j++)
            heng_zhou[j] += 1;

    // find max
    int max_value = heng_zhou[0];
    int max_index = 0;
    for( j=0; j<N; j++)
        if (heng_zhou[j] >max_value)
        {
            max_value = heng_zhou[j];
            max_index = j;
        }

    // output
    printf("%d\n", max_value);

    return 0;
}

```

## 231121-分书new.txt
```c
#include <stdio.h>

// like
// 喜欢矩阵
// 5个人（行）0，1，2，3，4
// 5本书（列）0，1，2，3，4
const int like[5][5] = { 
	{ 0, 0, 1, 1, 0 },
	{ 1, 1, 0, 0, 1 }, 
	{ 0, 1, 1, 0, 1 }, 
	{ 0, 0, 0, 1, 0 },
	{ 0, 1, 0, 0, 1 } };

// show
void show(int solutions, int the_person[5], int the_book[5])
{
    printf("--------\n");
    printf("solution no: %d\n", solutions);
    int i;
    for(i = 0; i < 5; i++)
        printf("[%d: %d] ", the_person[i], the_book[i]);
    printf("\n");
}

// five_person_no_conflict
int five_person_no_conflict(int the_person[5], int the_book[5])
{
    // book数组
    // 0 []
    // 1 [0]
    // 2 [0，1]
    // 3 [0，1，2]
    // 4 [0，1，2，3]
    int i, j;
    for(i = 0; i <= 4; i++)
    {
        int you_book = the_book[i];
        for(j = 0; j <= i - 1; j++)
        {
            int my_book = the_book[j];
            if(you_book == my_book)
                return 0;
        }
    }

    return 1;
}

// show_jubu
void show_jubu( int cur_person, int the_person[5] , int the_book[5])
{
    printf("--------\n");
    printf("jubu panmian\n");
    int i;
    for(i = 0; i <= cur_person; i++)
        printf("[person %d: book %d] ", the_person[i], the_book[i]);
    printf("\n");
}

int solutions = 0;

// try_fenshu
void try_fenshu(int cur_person, int the_person[5], int the_book[5])
{
    //  为cur_person分书
    //  尝试 0、1、2、3、4这些书
    //  如果能够安排（这个人喜欢这本书），就安排
    //            已经安排到第四个（看看盘面是否有冲突，没有冲突就是一个方案）
    //            还没有安排到第四个（安排下一个人）
    //  *如果都不能够安排（这个人尝试完0-4），就退出本层递归调用，回溯上一个人（for下一本书）
    int book;
    for(book = 0; book < 5; book++)
    {
        if( like[cur_person][book] ==1)
            {
                the_book[cur_person] = book;
                printf( "give book %d to person %d\n", book, cur_person);
	show_jubu( cur_person, the_person, the_book);
                if(cur_person == 4)
                {
                    if(five_person_no_conflict(the_person, the_book) == 1)
                    {
                        solutions++;
                        show(solutions, the_person, the_book);
                    }
                }
                else
                    try_fenshu(cur_person + 1, the_person, the_book);
            }
    }
}

// main
int main()
{
    int the_person[5] = { 0, 1, 2, 3, 4 };
    int the_book[5] = { -1, -1, -1, -1, -1 };

    int cur_person = 0;
    try_fenshu(cur_person, the_person, the_book);

    return 0;
}

```

## 231121-问号填充数字.txt
```c
问号填充数字

#include <stdio.h>
#include <string.h>

int count = 0;

void  try_put_number( int n, int cur_char,//
                      char str_me_old[200], char str_me_new[200], char str_you_old[100] )
{
    // 如果str_me_old的cur_char下标的当前字符
    // 为数字
    //  ------ 拷贝str_me_old数字字符到str_me_new
    //  ------ 如果已经到n-1个字符，用'\0'封死str_me_new，比较str_me_old，str_you_old，大于的话，count++
    //  ------ 如果没有到n-1个字符，那么递归处理cur_char+1字符
    //   为问号
    //   ------ 为str_me_new的cur_char下标，for尝试'0'-'9'字符
    //   ------ 如果已经到n-1个字符，用'\0'封死str_me_new，比较str_me_old，str_you_old，大于的话，count++
    //   ------ 如果没有到n-1个字符，那么递归处理cur_char+1字符

    char cc = str_me_old[cur_char];
    if (cc == '?')//问号
    {
        char c;
        for ( c='0'; c<='9'; c++)
        {
            str_me_new[cur_char] = c;
            if ( cur_char == n-1)
            {
                str_me_new[n] = '\0';
                puts( str_me_new);
                if (strcmp( str_me_new, str_you_old) >0) count++;
            }
            else
                try_put_number( n, cur_char+1,  str_me_old, str_me_new, str_you_old );
        }
    }
    else if ( cc>= '0' && cc<='9')//数字字符
    {
        str_me_new[ cur_char] = str_me_old[cur_char] ;

        if ( cur_char == n-1)
        {
            str_me_new[n] = '\0';
            puts( str_me_new);
            if (strcmp( str_me_new, str_you_old) >0) count++;
        }
        else
            try_put_number( n, cur_char+1,  str_me_old, str_me_new, str_you_old );
    }
}

int main()
{
    char str_me_old[200] = "3?32?5";
    char str_me_new[200];
    char str_you_old[200] = "299999";

    {
        count = 0;
        int n= strlen( str_me_old);
        int cur_char = 0;
        try_put_number( n, cur_char,  str_me_old, str_me_new, str_you_old );
        printf("%d\n", count);
    }

    {
        strcpy(str_me_old, "3??5??");
        strcpy(str_you_old, "299999");

        count = 0;
        int n= strlen( str_me_old);
        int cur_char = 0;
        try_put_number( n, cur_char,  str_me_old, str_me_new, str_you_old );
        printf("%d\n", count);
    }

    return 0;
}

```

## 231128-122迷宫.txt
```c
#include <stdio.h>

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

int found = 0;

// show_panmian
void show_panmian(int n, int m, int a[9][9])
{
    int i;
    int j;
    for(i=0; i<n; i++)
    {
        for( j=0; j<m; j++)
            printf("%d", a[i][j]);

        printf("\n");
    }

    printf("----------\n");
}

// try_walk
void try_walk(int cur_row, int cur_col, int n, int m, int a[9][9])
{
    // 如果 cur_row==n-1 并且cur_col== m-1
    //       设定 found =1，返回
    //  否则尝试上，右，下，左方向
    //       如果从下层回溯回来，已经有found == 1，不用尝试其他方向，直接返回
    //       old_row , old_col ->new_row, new_col
    //       如果new_row, new_col坐标有效、并且这个地方为1
    //            当前位置old_row , old_col设置为走过0
    //            走下去
    //            回溯回来设置为1

    if (cur_row == n-1 && cur_col == m-1)
    {
        found =1;
        return;
    }

    int action;
    for( action = UP; action <= LEFT; action ++)
    {
        if (found == 1) return;

        int old_row = cur_row;
        int old_col = cur_col;

        int new_row;
        int new_col;

        if ( action == UP )
        {
            new_row= cur_row -1;
            new_col = cur_col;
        }
        if ( action == RIGHT )
        {
            new_row= cur_row;
            new_col = cur_col+1;
        }
        if ( action == DOWN )
        {
            new_row= cur_row+1;
            new_col = cur_col;
        }
        if ( action == LEFT )
        {
            new_row= cur_row;
            new_col = cur_col-1;
        }

        if ( new_row >=0 && new_row<=n-1 &&//
                new_col >=0 && new_col <=m-1)
        {
            if (a[new_row][new_col] == 1)
            {
                a[old_row][old_col ]  = 2;//走过了，不能再走
                show_panmian(n,m, a);

                try_walk(new_row, new_col, n, m,a);

                a[old_row][old_col ]  = 1;//回溯
            }
        }// if
    }//for
}

int main()
{
    // input
    int n,m;
    scanf("%d%d", &n, &m);

    int i,j;
    int a[9][9];
    for (i=0; i<n; i++)
        for( j=0; j<m; j++)
            scanf("%d", &a[i][j]);

    //
    try_walk(0,0,n,m, a );

    if (found==0)
        printf("NO\n");
    else
        printf("YES\n");

    return 0;
}

```

## 231128-247问号填充数字.txt
```c
247问号填充数字

#include <stdio.h>
#include <string.h>
/*
36?1?8
236428
#
*/

int count=0;

void try_kuohao( int index, char str_me[200], char str_you[200])
{
        // i下标是数字
	// 往下递归，i+1
        // i下标不是数字
        //     是\0
       //       比较strme stryou，strme大的话，count++
       //     是?
	// 尝试把问号改为0-9，继续递归
	// 注意回到本层递归的时候，把刚才改为0-9的问号恢复问好
        
 

    char c = str_me[index];

    if ( c >= '0' && c<='9')
    {
        try_kuohao(index+1, str_me, str_you);
    }
    else if (c == '?')
    {
        char newc;
        for (newc = '0'; newc<='9'; newc++)
        {
            str_me[index] = newc;
            // show ste_me
            //puts(str_me);
            
            try_kuohao(index+1, str_me, str_you);

            str_me[index] = '?';
            //puts(str_me);
        }
        
    }
    else if (c=='\0')
    {
        if ( strcmp(str_me, str_you) >0 )
        count = count+1;
    }
}

// main
int main(int argc, char **argv)
{   
    char str_me[200];
    char str_you[200];
    
    while(1)
    {
        scanf("%s", str_me);
        if (strcmp( str_me,"#") == 0)
            break;
            
        scanf("%s", str_you);
        
        //
        int index = 0;
        count = 0;
        try_kuohao( index, str_me, str_you);
        printf("%d\n", count);
        
    }
    
    
	return 0;
}

```

## 231128集合划分问题（c语言输出集合数目以及不同的集合）.txt
```c
https://blog.csdn.net/m0_52275819/article/details/120517288
```

## 231129-YOJ124递归、优化.txt
```c

// ----------------------------------------------------------------------------------------------------

	
1，从盘面各个位置，开始找最长路径，修改all max length

max length = 0
2，当从某个位置开始（row, col, panmian, 当前总长）

	尝试上下左右走
               		如果有一个方向能够走(坐标有效，并且数值较小）
                     		 递归走下去（new row, new col, panmian, 当前总长：  总长 = 总长+1步骤）

	如果都不能走
  			 那么当前总长，与this max length比较

5 5
1 2 3 4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9

25

#include <stdio.h>

int max_length = 0;

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

#define _DEBUG 0

// my_try
void my_try( int i, int j, int R, int C, int panmian[50][50], int cur_length)
{
    int can_go_from_here = 0;// true

    int dir;
    for(dir=UP; dir<= LEFT; dir++)
    {
        int newi;
        int newj;
        if (dir == UP)
        {
            newi = i-1;
            newj = j;
        }
        if (dir == RIGHT )
        {
            newi = i;
            newj = j+1;

        }
        if (dir == DOWN )
        {
            newi = i+1;
            newj = j;
        }
        if (dir == LEFT  )
        {
            newi = i;
            newj = j-1;
        }

        if (newi >=0 && newi<= R-1 && newj >=0 && newj<=C-1)
        {
            if (panmian[ newi] [newj] < panmian[i][j])
            {
                can_go_from_here =1;

                if (_DEBUG)
                    printf("new i=%d, newj=%d\n", newi, newj);
                my_try( newi, newj, R, C, panmian, cur_length +1);
            }
        } // if
    }// for

    if (can_go_from_here  ==0)
        if (cur_length >max_length )
        {
            if (_DEBUG)
                printf("cur_length = %d\n", cur_length );
            max_length  = cur_length ;
        }
}

// main
int main()
{
    int R;
    int C;
    scanf("%d%d", &R, &C);

    int panmian[50][50];
    int i;
    int j;
    for(i=0; i<R; i++)
        for(j=0; j<C; j++)
            scanf("%d", &panmian[i][j]);
    //
    //  from any point as beginning
    for(i=0; i<R; i++)
        for(j=0; j<C; j++)
        {
            int cur_length = 1;

            if (_DEBUG)
                printf("try from begin row=%d col=%d\n", i,j);

            my_try( i, j, R,C, panmian, cur_length);
        }

    printf("%d\n", max_length);
    return 0;
}


    //如果这个单元计算过length，直接返回*

    // 如果上下左右，四个单元格，坐标有效情况下，没有更小的单元格
    //      返回1
    // 上下左右，四个单元格，坐标有效情况下，有值小的单元格
    //      分别计算length，用递归
    //      取max
    //      max+加1给maxi,maxj单元格(也就是表示maxi,maxj计算过)


#include <stdio.h>

int max_length = 0;

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3
void show( int R, int C, int panmian[50][50], int length[50][50])
{
	printf("\n\n");
	int i,j;

	for(i=0; i<R; i++)
	{
		for(j=0; j<C; j++)
			printf("%d ", panmian[i][j]);
		printf("\n");
	}

	printf("\n");

	for(i=0; i<R; i++)
	{
		for(j=0; j<C; j++)
			printf("%d ", length[i][j]);
		printf("\n");
	}

	printf("\n");

}

// my_try
int my_try(int i, int j, int R, int C, int panmian[50][50], int length[50][50])
{
	//如果这个单元计算过length，直接返回

	// 如果上下左右，四个单元格，坐标有效，没有更小的单元格
	//      返回1
	// 上下左右，四个单元格，坐标有效，有值小的单元格
	//      分别计算length，用递归
	//      取max
	//      加1给maxi,maxj单元格(设置maxi,maxj计算过)
//printf("we want to know len of %d %d\n", i, j);

	if ( length[i][j] != 0)
		return length [i][j];

	int can_go_from_here = 0;// true

	int max_child_length = 0;

	int dir;
	for(dir=UP; dir<= LEFT; dir++)
	{
		int newi;
		int newj;
		if (dir == UP)
		{
			newi = i-1;
			newj = j;
		}
		if (dir == RIGHT )
		{
			newi = i;
			newj = j+1;

		}
		if (dir == DOWN )
		{
			newi = i+1;
			newj = j;
		}
		if (dir == LEFT  )
		{
			newi = i;
			newj = j-1;
		}

		if (newi >=0 && newi<= R-1 && newj >=0 && newj<=C-1)
		{
			if (panmian[ newi] [newj] < panmian[i][j])
			{
				can_go_from_here =1;

//printf("we recursivly do %d %d for %d %d\n",newi,newj, i, j);

				int child_length = my_try( newi, newj, R, C, panmian, length);
				if (child_length > max_child_length)
					max_child_length = child_length;
			}
		} // if
	}// for

	if( can_go_from_here == 0)
	{
		length[i][j] = 1;
		return length[i][j];
	}
	else//can_go_from_here == 0
	{
		length[i][j] = max_child_length+1;

		//( R,C,panmian, length);

		return length[i][j];
	}
}

// main
int main()
{
	int R;
	int C;
	scanf("%d%d", &R, &C);

	int panmian[50][50];
	int i;
	int j;
	for(i=0; i<R; i++)
		for(j=0; j<C; j++)
			scanf("%d", &panmian[i][j]);

	int length[50][50];
	for(i=0; i<R; i++)
		for(j=0; j<C; j++)
			length[i][j] = 0;

	//
	int maxi = 0;
	int maxj = 0;

	for(i=0; i<R; i++)
		for(j=0; j<C; j++)
		{
			// from any point
			// avoid redundancy computation
			my_try( i, j, R, C, panmian, length);
		}

	//show( R,C,panmian, length);

	max_length = 0;
	for(i=0; i<R; i++)
		for(j=0; j<C; j++)
			if ( length[i][j] >max_length)
				max_length = length[i][j];
				
	printf("%d\n", max_length);

	return 0;
}


```

## 231129-棍子原先的长度为6打碎.txt
```c
// ----------------------------------------------------------------------------------------------------

有个长度6，尝试处理长度6，以它作为棍子原先长度
component 	5 1 5 2 1 2 5 1 2
use_or_not	0 0 0 0 0 0 0 0 0
		1 1 2 3 2 3  4 4 3

	尝试构造和为6的子集（子集编号no，当前子集的和，目标长度6）

	    	如果found==1，则直接返回
	    	当前子集的总和大于6
			do nothing，回溯到上一层级调用，进行其他尝试
	    	当前子集的总和为6
			如果没有剩下的配件，那么找到一种分配方案found=1，返回
			如果还有剩下的配件
				newno =no+1
				newno 子集的和为0
				递归（component ， use_or_not， newno , newno 的和，目标长度6）

	    	当前子集的总和小于6
			如果没有剩下的配件，返回（回溯到上一层级调用，进行其他尝试）
			如果有剩下的配件
				no不变
				尝试没有用过的配件index
					use_or_not[ index] = no // use
					修改当前子集总和
					向下递归（component ， use_or_not，no, 当前子集的和）
			                 	从下面回溯回到这里的时候，use_or_not[ index] = 0// not use
	
#include <stdio.h>

/*
5
5 1 2 2 2
9
5 1 5 2 1 2 5 1 2
*/

int found = 0;

// show
void show( int n, int component[100], int ifusing[100])
{
    int i;
    for(i=0; i<n; i++)
        printf("%d ",  component[i]);
    printf("\n");
    for(i=0; i<n; i++)
        printf("%d ",  ifusing[i]);
    printf("\n----------\n");
}

// try_huafen
void try_huafen( int n, int component[100], int used, int ifusing[100],//
                 int ziji_no, int ziji_sum, int target_len )
{
    if (found == 1) return;

    if ( ziji_sum > target_len)
    {
        // do nothing, back track to upper level call
    }
    else if (ziji_sum == target_len)
    {
        if ( used == n)
        {
            found = 1;
            return;
        }
        else // used <n
        {
            int ziji_no_new = ziji_no+1;
            int ziji_sum_new = 0;

            try_huafen( n, component, used, ifusing,//
                        ziji_no_new, ziji_sum_new, target_len );
        }
    }
    else//ziji_sum < target_len
    {
        if ( used == n)
        {
            // do nothing, back track to upper level call
        }
        else// used < n
        {
            int k;
            for(k=0; k<n; k++)
            {
                if ( ifusing[k] == 0)// not used
                {
                    ifusing[k] = ziji_no;//used

                    show(n, component, ifusing);

                    // used 多了1个
                    // ziji_sum + component[k]
                    try_huafen( n, component, used+1, ifusing,//
                                ziji_no, ziji_sum + component[k], target_len );

                    ifusing[k] = 0;
                }// if
            }// for
        }// used < n
    }// //ziji_sum < target_len
}

// main
int main()
{
    // input
    int n;
    int component[100];

    scanf("%d", &n);
    int i;
    for(i=0; i<n; i++)
        scanf("%d", &component[i]);

    int ifusing[100];
    for(i=0; i<n; i++)
        ifusing[i] = 0;// not use

    //
    found = 0;

    int used = 0;

    int ziji_no = 1;
    int ziji_sum = 0;
    int target_len = 6;

    try_huafen( n, component, used, ifusing,//
                ziji_no, ziji_sum, target_len );

    if (found==1)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
	
```

## 231206-YOJ127超级细菌.txt
```c
#include <stdio.h>
#include <string.h>

/*
f       fn                              sum_till_fn
1       1                               1
2       5 = 2*2+1                  6 = 1+5
3       15 = 3*3+6              21 = 6+15
4       37 = 4*4 +21            58 = 21+37
.....
 * n=1000 303cols
 * n=10000 3012cols
*/

#define LEN 5000
#define N 10000
#define DEBUG_ALL 1

// show
void show( char fn[ LEN+1])
{
    // 下标0到LEN-1是正常字符，下标LEN为\0
    int first_not_zero;
    for( first_not_zero = 0; first_not_zero<=LEN-1; first_not_zero++ )
        if ( fn[first_not_zero] != '0')
            break;
    printf("%s", fn+first_not_zero);
}

// show_number
void show_number( int n, char fn[ LEN+1], char sum_till_fn[LEN+1] )
{
    if (DEBUG_ALL)
    {
        printf("%d: fn ", n);
        show(fn );
        printf("; sum_till_fn ");
        show(sum_till_fn );
        printf("\n", n);
    }
    else
        printf("%d\n", n);

}

// make_num_str
void make_num_str( int n_pingfang, char pingfang_str[LEN+1])
{
    int index = LEN-1;  // 下标0到LEN-1是正常字符，下标LEN为\0
    int nn = n_pingfang;
    while(1)
    {
        int yushu =  nn%10;
        char cc = '0'+yushu -0;
        pingfang_str[index] = cc;

        index --;
        nn = nn/10;
        if (nn == 0)
            break;
    }// while
    return;
}

// add_2_str
void add_2_str( char str1[LEN+1],   //
                char str2[LEN+1], char str3[LEN+1])
{
    int first_not_zero1;
    for( first_not_zero1 = 0; first_not_zero1<=LEN-1; first_not_zero1++ )
        if ( str1[first_not_zero1] != '0')
            break;

    int first_not_zero2;
    for( first_not_zero2 = 0; first_not_zero2<=LEN-1; first_not_zero2++ )
        if ( str2[first_not_zero2] != '0')
            break;
    int min_first_not_zero = first_not_zero1;
    if (first_not_zero2<min_first_not_zero )
        min_first_not_zero = first_not_zero2;

    int index = LEN-1;  // 下标0到LEN-1是正常字符，下标LEN为\0
    int jinwei = 0;
    while(1)
    {
        char zifu1 = str1[index];
        char zifu2 = str2[index];

        int shuzi1 = zifu1 - '0';
        int shuzi2 = zifu2 - '0';

        int jiaqilai = shuzi1 + shuzi2  + jinwei;

        //注意，加完了以后，可能有进位到下一步计算
        if( jiaqilai >=10)
        {
            jinwei  = 1;
            jiaqilai = jiaqilai -10;
            str3[index] = '0' + jiaqilai;
        }
        else
        {
            jinwei = 0;
            str3[index] = '0' + jiaqilai;
        }

        index --;
        if (index <0)
            break;
        if (index < min_first_not_zero-1)
            break;
    }// while

    return;
}

// init_all_zero
 void init_all_zero( char fn[LEN+1])
 {
     int i;
    for(i=0; i<=LEN-1; i++) // 0 - LEN-1是正常字符，LEN位置为\0
        fn[i] = '0';
    fn[LEN] = '\0';
 }
 
// fn_new
void fn_new()
{
    int n=1;

    char fn[ LEN+1]; // 0 - LEN-1是正常字符，LEN位置为\0
    init_all_zero(fn);
    fn[LEN-1] = '1';

    char sum_till_fn[LEN+1];
    init_all_zero(sum_till_fn);
    sum_till_fn[LEN-1] = '1';

    show_number(  n, fn, sum_till_fn);

    char n_pingfang_str[LEN+1];
    init_all_zero(n_pingfang_str);

    char new_fn[LEN+1];
    init_all_zero(new_fn);

    char new_sum_till_fn[LEN+1];
    init_all_zero(new_sum_till_fn);

    while( n<=N-1)
    {
        n ++;
        unsigned int n_pingfang = n*n;

        make_num_str( n_pingfang, n_pingfang_str);

        add_2_str( n_pingfang_str, sum_till_fn, new_fn);
        add_2_str(sum_till_fn,  new_fn, new_sum_till_fn);

        if ( n<= N-1)
            if ( n%5000 ==0)
                printf("processing %d\n", n );
            else
            {}
        else
            show_number(n, new_fn,new_sum_till_fn );

        strcpy(fn, new_fn);
        strcpy(sum_till_fn, new_sum_till_fn);
    }// while
    return;
}

// fn
void fn()
{
    unsigned int n=1;

    unsigned int fn = 1;
    unsigned int sum_till_fn = 1;
    printf("%d fn %d; sum_till_fn %d\n", n, fn, sum_till_fn );

    while( n<=N-1)
    {
        n ++;
        unsigned int n_pingfang = n*n;

        unsigned int new_fn = n*n + sum_till_fn ;
        unsigned   int new_sum_till_fn =  sum_till_fn+ new_fn;

        if ( n<= N-1)
            if ( n%5000 ==0)
                printf("processing %d\n", n );
            else
            {}
        else
            printf("%d fn %d; sum_till_fn %d\n", n, new_fn, new_sum_till_fn );

        fn = new_fn;
        sum_till_fn  = new_sum_till_fn;
    }
    return;
}

// main
int main()
{
    //fn();
    fn_new();

    return 0;
}

```

## 231212-字符串sprintf&sscanf.txt
```c
int a = 39; 
printf( "%03d", a);
//屏幕上打印，039




int b;
scanf("%d", &b);
// 键盘上输入26，那么b就得到26这个值




用户输入a m n，请按照总宽度为m,小数点后有效数字个数为n
打印这个浮点数

double a;
int m;
int n;

scanf("%lf", &a);
scanf("%d%d", &m, &n);
// m n 是  10 3
// 我们希望用m和n构造一个临时的格式串%10.3lf
char my_format[80];
sprintf(my_format, "%%%d.%dlf", m, n);    
// m=10, n=3的时候 ，my_format变成 %10.3lf
printf(my_format, a); // 以my_format %10.3lf格式，打印a
// 3.33456   ->     3.335




sscanf
char yuan_shuju[80] = "56 77 999.999";
int a;
int b;
double c;
sscanf(yuan_shuju, "%d%d%lf", &a, &b, &c);

```

## 231213-YOJ126.txt
```c
#include <stdio.h>

#define ZOU_GUO -200

#define ZUO_ZOU 0
#define YOU_ZOU 1
#define XIA_ZOU 2

int max_value = 0;

// show
void show( int panmian[8][8], int n, int m, int value_till_i_j)
{
	int i, j;

	for(i = 0; i <= n - 1; i++)
	{
		for(j = 0; j <= m - 1; j++)
		{
			printf("%d ", panmian[i][j]);
		}
		printf("\n");
	}
	printf( "the value is %d\n", value_till_i_j);

}

// try_walk
void try_walk(int i, int j, int n, int m, int value_till_now, int panmian[8][8])
{
	// 如果已经到达n-1 m-1
	// ......和max_value比较看看，value_till_now更大的话，改动max_value
	// 如果没有到达 n-1 m-1
	// 	.....尝试左走、右走、下走
	// 	.........如果能走：行坐标在范围之内，列坐标在范围之内，从没走过，
	//  ................递归调用 newi, newj , n, m, value_till_now + ..., panmian
	// ..........如果不能走，do nothing


	if(i == n - 1 && j == m - 1)
	{
		if(value_till_now > max_value)
			max_value = value_till_now;
	}
	else
	{
		int aa;
		for(aa = ZUO_ZOU; aa <= XIA_ZOU; aa++)
		{
			int newi;
			int newj;

			if(aa == ZUO_ZOU)
			{
				newi = i;
				newj = j - 1;
			}
			if(aa == YOU_ZOU)
			{
				newi = i;
				newj = j + 1;
			}
			if(aa == XIA_ZOU)
			{
				newi = i + 1;
				newj = j;
			}

			if(newi >= 0 && newi <= n - 1 && newj >= 0 && newj <= m - 1)
				if (panmian[newi][newj] != ZOU_GUO)
				{
					int old_value = panmian[i][j];
					panmian[i][j] = ZOU_GUO;

					show( panmian, n,m,value_till_now);

					printf("\n\nform %d,%d to %d,%d\n", i, j, newi, newj);

					try_walk(newi, newj, n, m, value_till_now +panmian[newi][newj] , panmian);

					panmian[i][j] =old_value;
				}
		}// for aa
	}// else
}

// main
int main()
{
	int n;
	int m;
	scanf("%d%d", &n, &m);

	int i;
	int j;
	int panmian[8][8];
	for(i = 0; i <= n - 1; i++)
	{
		for(j = 0; j <= m - 1; j++)
		{
			scanf("%d", &panmian[i][j]);
		}
	}

	//  从0  0走到n-1  m-1，注意走过不能走，注意行列下标有效
	// 可以左走、右走、下走
	int value_till_now = panmian[0][0];
	try_walk(0, 0, n, m, value_till_now, panmian);

	printf("%d\n", max_value);

	return 0;
}

```

## 231219-merge sort身份证列表TOP10.txt
```c

```

