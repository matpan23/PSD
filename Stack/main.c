#include<stdio.h>
#include<stdlib.h>
#include"stack.h"

stack copyStack(stack s);
stack outputStack(stack s);
stack reverseStack(stack s);
stack mergeStack(stack s,stack s1);

int main(){
  stack s=newStack();
  stack rs=newStack();
  stack ms=newStack();
  item val;

  do{
      input_item(&val);
      push(val,s);
      if(val==-1)
        pop(s);
  }
  while(val!=-1);
  printf("Stampo lo stack\n");
  outputStack(s);
  printf("\nStampo il reverse stack\n");
  rs=reverseStack(s);
  outputStack(rs);
  printf("\nStampo lo stack Merge\n");
  ms=mergeStack(s,rs);
  outputStack(ms);
}

stack copyStack(stack s){
    stack tmp=newStack();
    stack cstack=newStack();
    item x;

    while(!emptyStack(s)){
        x=pop(s);
        push(x,tmp);
    }
    while(!emptyStack(tmp)){
        x=pop(tmp);
        push(x,s);
        push(x,cstack);
    }
return cstack;
}
stack outputStack(stack s){
    stack ffs=newStack();
    ffs=copyStack(s);
    item x;
    int i=1;
    while(!emptyStack(ffs)){
        x=pop(ffs);
        printf("%d^ Elemento dello stack: ",i);
        output_item(x);
        printf("\n");
        i++;
    }
}
stack reverseStack(stack s){
    stack ffs=newStack();
    ffs=copyStack(s);
    stack rstack=newStack();
    item x;

    while(!emptyStack(ffs)){
        x=pop(ffs);
        push(x,rstack);
    }
return rstack;
}
stack mergeStack(stack s,stack s1){
    item x;
    stack ffs=newStack();
    stack ffs1=newStack();
    stack mergedstack=newStack();
    ffs=copyStack(s);
    ffs1=copyStack(s1);

    while(!emptyStack(ffs)){
        x=pop(ffs);
        push(x,mergedstack);
    }
    while(!emptyStack(ffs1)){
        x=pop(ffs1);
        push(x,mergedstack);
    }

return mergedstack;
}
