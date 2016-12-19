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
 		  		i->next = monkey;
		 	}
		  i = i+1;
		}		
	}
}



#define POS	1
#define	NUM	5
void main(void)
{
 char cnt=0;
 struct node * cur;
 struct node * prev;
 monkey_create(16);
 if(!monkey) return;
 cur  = monkey+POS;
 prev = cur;
do{
	cnt=0;
	do{
	prev = cur;
	cur = cur->next;
	cnt++;
	}while(cnt!=NUM);
	prev->next = cur->next;
	cur = prev->next;
}while(cur->next!=cur);


printf("the king monkey is:%d\n",cur->num);
free(monkey);

}
