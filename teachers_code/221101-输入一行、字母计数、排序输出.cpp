输入一行、字母计数、排序输出

#include <stdio.h>
#include <string.h>

int main()
{
	char str[200];
	gets( str);

	int len = strlen( str);
	if ( len <= 0 )
	{
		printf("None\n");
		return 0;
	}

	int i;
	char zimu[27] = "abcdefghijklmnopqrstuvwxyz";
	int jishu[26];
	for(i=0; i<=25; i++) jishu[i]= 0;

	for( i=0; i<= len-1; i++)
	{
		char cc = str[i];
		if ( cc>= 'a' && cc<= 'z')
		{
			int xiabiao = cc-'a';
			jishu[ xiabiao] =  jishu[ xiabiao] +1;
		}
		if ( cc>= 'A' && cc<= 'Z')
		{
			int xiabiao = cc-'A';
			jishu[ xiabiao] =  jishu[ xiabiao] +1;
		}
	}

	//
	int range ;
	for( range = 26; range >=2; range--)
	{
		for( i=0; i<= range-2; i++)
		{
			if ( jishu[i] > jishu[i+1])
			{
			}
			else if ( jishu[i] == jishu[i+1])
			{
				if (zimu[i] > zimu[i+1])
				{
					int temp_c = zimu[i];
					zimu[i] = zimu[i+1];
					zimu[i+1] = temp_c;
					int temp_i = jishu[i];
					jishu[i] = jishu[i+1];
					jishu[i+1] = temp_i;
				}
				else if (zimu[i] == zimu[i+1])
				{}
				else if (zimu[i] < zimu[i+1])
				{}

			}
			else if ( jishu[i] < jishu[i+1])
			{
				int temp_c = zimu[i];
				zimu[i] = zimu[i+1];
				zimu[i+1] = temp_c;
				int temp_i = jishu[i];
				jishu[i] = jishu[i+1];
				jishu[i+1] = temp_i;
			}

		}// for i
	}// for range

	for(i=0; i<=25; i++)
	{
		printf("%c %d\n", zimu[i], jishu[i]);
	}

}
