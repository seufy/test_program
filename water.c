/*
 * There  is an array  of Wood Bar
 * The value of each element stands for the Height of wood bar
 * We need to calculate how much water can this wood array store if it rained ^-^
 *
 */
#include <stdio.h>
#include <stdlib.h>

//unsigned char pool[] = {0,2,4,2,5,6,3,4,2,1,0,0,0,1};
unsigned char pool[] = {0,1,0,3,2,1,0,2,0,3};
#define P_SZ (sizeof(pool)/sizeof(pool[0]))
unsigned char tmp[P_SZ+2];
unsigned char flag;
unsigned int sum=0;

unsigned int water_sum(void)
{
	unsigned int sum=0;
	unsigned char i;
	signed char start=-1;
	signed char end=-1;

	tmp[0] =1;
	tmp[P_SZ+1] = 1;
	for(i=1;i<P_SZ+1;i++)
	{
		if(tmp[i] == 0) sum++;

		if(tmp[i] == 1){
			if (start < 0)
			{
				start =i;
			}else{
				end = i;
			}
		}

	}

	if((start>=1)&&(end>=1)){
		sum = sum - (start-1)-(P_SZ-end);

	}else{
		sum = 0;
	}
	
return sum;

}

char  empty(void)
{
	char i;
	for(i=1;i<P_SZ+1;i++){
		if(tmp[i] == 1) return 1;
	}

	return 0;

}

void main(void)
{
 int i;

do{
for(i=0;i<P_SZ;i++)
{
	if(pool[i] > 0)
	{
		pool[i]-=1;
		tmp[i+1]=1;
	}else{
		tmp[i+1]=0;
	}
}  
 sum += water_sum();




}while(empty()==1);


printf("%d\n",sum);

}
