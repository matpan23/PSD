#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct c_stack{
  list top;
};

stack newStack(void){
  stack s;
  s=malloc(sizeof(*s));
  if(!s)
    return NULL;
  s->top = newList();
  return s;
}
int emptyStack(stack s){
  return emptyList(s->top);
}
int push(item val,stack s){
  list pre = s->top;
  s->top = consList(val,s->top);

  return pre!= s->top;
}
item pop(stack s){
  item pre = getFirst(s->top);
  s->top = tailList(s->top);

  return pre;
}
item top(stack s){
  return getFirst(s->top);
}
