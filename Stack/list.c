#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct node {
     item value;
     struct node *next;
};

list newList(void){
	return NULL;
}

int emptyList(list l){

	return (l==NULL);
}

list consList(item val, list l){
	list newlist;
	newlist=malloc(sizeof(struct node));
	if(!newlist)
		printf("Errore di allocazione\n");
	newlist->value=val;
	newlist->next=l;
	l=newlist;

return l;
}
list tailList(list l){
	list temp;

	if (l!=NULL)
		temp=l->next;
	else
		temp=NULL;

return temp;
}
item getFirst (list l){
    item newitem;

	if(l!=NULL)
		newitem=l->value;
	else
		newitem=NULLITEM;

return newitem;
}
int sizeList (list l){
	int i=0;
	list nextitem;
	nextitem=l;
	while(nextitem!=NULL){
		i++;
		nextitem=nextitem->next;
	}
	return i;
}

int posItem (list l, item val){
	int pos=0;
	int found=0;

	while(!emptyList(l) && !found){
		if(eq(getFirst(l),val)==0){
			found=1;
			pos++;
		}
		else{
			pos++;
			l=l->next;
		}
	}
	if(!found)
		pos=-1;

	return pos;
}

item getItem (list l, int pos){
    int i=0;
    printf("Restituisco elemento in posizione %d\n",pos);
    item a=NULL;
    while(i<pos && !emptyList(l)){
    	i++;
    	l=tailList(l);
    }
    if(!emptyList(l))
    	a=getFirst(l);
    else
    	a=NULLITEM;

    return a;
}

list reverseList (list l){
	list revlist;
	item val;

	revlist=newList();
	while(!emptyList(l)){
		val=getFirst(l);
		revlist=consList(val,revlist);
		l=tailList(l);
	}
	return revlist;
}

void outputList (list l){
	int i =0;
	item val;

	while(!emptyList(l)){
		val = getFirst(l);
		printf("Elemento di posizione %d: \n", i+1);
		output_item(val);
		l = tailList(l);
		i++;
	}
}

list insertList(list l,int pos,item val){
	int i;
	list l1,prec=l;

	if(pos==0)
		return consList(val,l);
	for(i=0;i<pos-1&&prec;i++)
		prec=prec->next;
	if(!prec)
		return l;

	l1=consList(val,prec->next);
	prec->next=l1;

return l;
}

list removeList(list l,int pos){
	list l1,prec;
	int i;

	if(pos==0&&l){
		l1=l;
		l=tailList(l);
		free(l1->value);
		free(l1);
	}
	else{
		prec=l;
		for(i=0;i<pos-1 && prec;i++)
			prec=prec->next;
		if(prec&&prec->next){
			l1=prec->next;
			prec->next=l1->next;
			free(l1->value);
			free(l1);
		}
	}
return l;
}
int getsize(list l){
	list nextitem=l;
	if (emptyList(l)) printf("\n\nlista vuota\n\n");
	int counter=0;
	while (!emptyList(nextitem)){
			printf("\ndentro while trovato: %d\n",counter);
		counter++;
		nextitem=nextitem->next;
	}
	printf("\ntrovato: %d\n",counter);
	return counter;

}
