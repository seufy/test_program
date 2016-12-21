/*
 *there is two ordered array: A and B
 *combine them into one array C with the same order
 *
 */
#include <stdio.h>
#include <stdlib.h>

unsigned char arr1[] = {3,5,8,12,45,52,77,81,90};
unsigned char arr2[]= {1,5,8,12,15,19,56,75};

#define ARR1_LEN	(sizeof(arr1)/sizeof(arr1[0]))
#define ARR2_LEN	(sizeof(arr2)/sizeof(arr2[0]))

unsigned char arr3[ARR1_LEN+ARR2_LEN+1];


unsigned char select_element(unsigned char type,unsigned char flag){
	static unsigned char i=0;
	static unsigned char j=0;

	if(type==1){
		if(flag ==1) i++;
		if(i<ARR1_LEN){return arr1[i];}
        }else{
		if(flag ==1) j++;
		if(i<ARR2_LEN){return arr2[j];}
         }
	
}

void main(void)
{
	unsigned char tmp1,tmp2,i;
	
	for(i=0;i<(ARR1_LEN+ARR2_LEN);i++)
	{
	      tmp1 = select_element(1,0);// promt
	      tmp2 = select_element(2,0);// promt
	      if(tmp1 < tmp2){
	      		select_element(1,1);
		   arr3[i] = tmp1;
		}else{
	      		select_element(2,1);
		   arr3[i] = tmp2;

		}
	      
	printf("%d,",arr3[i]);
	}
	
}





