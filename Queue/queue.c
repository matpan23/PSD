#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

//implementazione con liste collegate

struct node{
    item value;
    struct node *next;
};
struct c_queue{
	struct node *head, *tail;
	int numel;
};
queue newQueue(void){
	struct c_queue *q;
	q = malloc(sizeof(struct c_queue));
	if (q == NULL)
	{
		return NULL;
	}
	q->numel = 0;
	q->head = NULL;
	q->tail = NULL;
	return q;
}
int emptyQueue(queue q){
	if (q == NULL)
	{
		return -1;
	}
	return q->numel == 0;
}
int emptyList(list l){
    return l == NULL;
}
int enQueue(item val, queue q){
	if (q == NULL)
		return -1;
	struct node *nuovo;
	nuovo = malloc(sizeof(struct node));
	if (nuovo == NULL)
	{
		return 0;
	}
	nuovo->value = val;
	nuovo->next = NULL;
	if (q->head == NULL)
	{
		q->head = nuovo;
	}
	else
	{
		q->tail->next = nuovo;
	}
	q->tail = nuovo;
	(q->numel)++;
	return 1;
}
item getFirst (list l){
    item e;
    if (l != NULL)
        e = l->value;
    else
        e = NULLITEM;
    return e;
}
list tailList(list l){
    list temp;
    if (l != NULL){
        temp = l->next;
     }
     else
        temp = NULL;
    return temp;
}
item deQueue(queue q)
{
	if (q == NULL)
	{
		return NULLITEM;
	}
	if (q->numel == 0)
	{
		return NULLITEM;
	}
	item result = q->head->value;
	struct node *temp = q->head;
	q->head = q->head->next;
	free(temp);
	if (q->head == NULL)
	{
		q->tail == NULL;
	}
	(q->numel)--;
	return result;
}
void outputList (list l){
    int i = 0;
    item val;
    while (!emptyList(l)){
        val = getFirst(l);
        printf("elemento di posizione %d: ", i);
        output_item(val);
        printf("\n");
        l = tailList(l);
        i++;
     }
}
void outputQueue(queue q){
    struct node *t;
    t = q->head;
    printf("Stampo elementi della coda\n");
    while (t){
        output_item(t->value);
        printf("-");
        t = t->next;
    }
    printf("\n");
}
