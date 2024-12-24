#include <stdio.h>

int main(){
	int bottle,n;scanf("%d %d",&bottle,&n);
	int remain=0;
	int add=bottle;
	if(bottle<n){
		printf("%d",bottle);
	}else{
		while(bottle>3){
			remain = (bottle%n); //1  1  0  1
			bottle/=n; //33    11   4  1
			add+=bottle; //133  144   148  149
			bottle+=remain; //34  12   4  5  2
		}
		printf("%d",add);
	}
	return 0;
}