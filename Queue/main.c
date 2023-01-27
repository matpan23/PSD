#include<stdio.h>
#include<stdlib.h>
#include"queue.h"

int main(){
	int el=0;
	item feq,seq,teq,qeq;
	queue q=newQueue();
	input_item(&feq);
	input_item(&seq);
	input_item(&teq);
	input_item(&qeq);
	el=enQueue(feq,q);
	el+=enQueue(seq,q);
	el+=enQueue(teq,q);
	el+=enQueue(qeq,q);
	printf("numero di elementi della coda:%d\n",el);
	outputQueue(q);
	/*qtemp=concat(quad4,quad3);
	printf("qtemp\n");
	outputQueue(qtemp);
	qtemp2=concat(quad2,quad1);
	qfirst=concat(qtemp,qtemp2);
	printf("Stampo la coda concatenata\n");
	outputQueue(qfirst);*/

return 0;
}
