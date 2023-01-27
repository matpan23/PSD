#include"item.h"
typedef struct c_queue *queue;
typedef struct node *list;
queue newQueue(void);
int emptyQueue(queue q);
item deQueue(queue q);
int enQueue(item val,queue q);
void outputList (list l);
void outputQueue(queue q);
int emptyList(list l);
list tailList(list l);
item getFirst (list l);
