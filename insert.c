#include <stdio.h>
#include <stdlib.h>


struct node{
	int height;
	struct node * next;
};


struct node * insert(struct node * head, int height)
{
	struct node ** tmp;
	struct node ** prev;
	struct node * new;
	if(!head){
		if((head = (struct node *)malloc(sizeof(struct node))) != NULL){
			head->height = height;
			head->next = NULL;
			return head;
		}else{
			return NULL;
		}
	
	}else{
		if((new = (struct node *)malloc(sizeof(struct node))) != NULL){
			new->height = height;
			new->next = NULL;
		}else{
			return head;
		}
		
		tmp = &head;
		prev = NULL;
		do{
		   if((*tmp)->height > new->height)
		   {
			new->next = *tmp;
			if(prev){(*prev)->next =new; return head;}else{return new;}		
		   	//return (new->height < head->height)?new:head;
		   }else{
                         if((*tmp)->next != NULL){
				prev = tmp;
				tmp = &((*tmp)->next);
			 }else{
				(*tmp)->next = new;
				 return head;

		        }
				
		  }
		
		}while(1);
	}

}

void main(void)
{
 struct node * head = NULL;
 struct node * t;
 struct node ** tmp;

 head = insert(head,19);
 head = insert(head,1);
 head = insert(head,0);
 head = insert(head,4);
 head = insert(head,9);
 head = insert(head,203);
 head = insert(head,-6);
 head = insert(head,9);
 head = insert(head,9);
 head = insert(head,5);
 head = insert(head,8);

 for(t= head;t!=NULL;t=t->next)
{
  printf("%d\n",t->height);

}

for(tmp =&head;(*tmp)!=NULL;)
{
   struct node * entry = (*tmp);
   if(entry!=NULL)
 {
  tmp = &entry->next;
  free(entry);
} 
   

}


}
