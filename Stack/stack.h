#include "list.h"
typedef struct c_stack *stack;

stack newStack(void);
int emptyStack(stack s);
int push(item val,stack s);
item pop(stack s);
item top(stack s);
