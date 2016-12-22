#include <stdio.h>
#include <stdlib.h>

int arr[] ={1,-2,3,10,-4,7,2,-5};

#define LEN	sizeof(arr)/sizeof(arr[0])


#define	VERSION_2

#if defined VERSION_1
void main(void)
{
  int max;
  int tmp;
  int i,j;

  for(i=0;i<LEN;i++)
  {
     tmp = 0;;
     for(j=i;j<LEN;j++)
     {
	tmp += arr[j];
        if(max < tmp){
          max = tmp;
       }	
     }
  }


    printf("%d\n",max);
}

#else
void main(void)
{
  int sum,max;
  int i;
  
  sum = max = arr[0];
  for(i = 1;i<LEN;i++)
  {
    if(sum<=0)
    {
      sum = arr[i];
    }else{
      sum+= arr[i];
    }
    
    if(sum>max){
       max= sum;
    } 

  }

printf("%d\n",max);

}


#endif
