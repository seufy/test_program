/*
 * reversely print out a single chain
 *
 */

#include <stdio.h>
#include <stdlib.h>

struct node{
	struct node * next;
	unsigned char num;
};

struct node * monkey=NULL;

void monkey_create(unsigned char m)
{
	unsigned char k;
	struct node * i;

	if((monkey = (struct node *)malloc(sizeof(struct node)*m)) !=NULL)
	{
		for(i=monkey,k=0;k<m;k++)
		{
		  i->num =k;
		 	if(k!=m-1){
		  		i->next = i+1;
		 	}else{
 		  		i->next = NULL;
		 	}
		  i = i+1;
		}		
	}
}


void print_chain(struct node * ptr)
{
  if(ptr->next  == NULL)
  {
    printf("%d\n",ptr->num);
  }else{
    print_chain(ptr->next);
    printf("%d\n",ptr->num);
  }

}

void main(void)
{
 int i; 
 monkey_create(6);

 if(!monkey)return;


 print_chain(monkey);


}
