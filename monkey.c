/*
 * There is some  monkeys, they will hold a poll to decide their King
 * Rules:
 * 1)TOTAL_MONKEY  monkeys in a circle
 * 2)start position :POS
 * 3)numbers to calculate:NUM
 * 4)the NUM-th monkey get out
 * 5)do again from 3)
 *
 * The last remaining one is the King
 *
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
 		  		i->next = monkey;
		 	}
		  i = i+1;
		}		
	}
}


#define TOTAL_MONKEY	16
#define POS		1
#define	NUM		5
void main(void)
{
 char cnt=0;
 struct node * cur;
 struct node * prev;
 monkey_create(TOTAL_MONKEY);
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
