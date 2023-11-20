#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Stack.h"

#ifndef Linked

//Initializes the stack.
void CreateStack(Stack *ps)
{
    ps->top = 0;
}

//Push new element to the end of the stack, assuming the stack is not full.
int Push(void* value, Stack *ps, int size)
{
    void *ptr = malloc(size);
    if (ptr == NULL)
    return 0;
    memcpy(ptr, value, size);
    ps->entry[ps->top++] = ptr;
    return 1;
}

//Pops the last element
void Pop(void **element, Stack *ps, int size)
{
    //*element = ps->entry[--ps->top];
    //Moving the data and freeing the pointer
    ps->top--;
    memcpy(*element, ps->entry[ps->top], size);
    free(ps->entry[ps->top]);

}

//Checks if stack is full.
int StackFull(Stack *ps)
{
    return (ps->top == MAX_ELEMENTS);
}

//Checks if stack is empty.
int StackEmpty(Stack *ps)
{
    return (ps->top == 0);
}

//Returns the top element
void StackTop(void **element, Stack *ps)
{
    *element = ps->entry[ps->top - 1];
}

//Returns the StackSize
int StackSize(Stack *ps)
{
    return ps->top;
}

//Clears the stack.
void ClearStack(Stack *ps)
{
    for (int i = ps->top - 1; i >= 0; i--)
        free(ps->entry[i]);
    ps->top = 0;
}

//Traverse elements
void TraverseStack(Stack *ps, void (*pfun) (void*))
{
    for (int i = ps->top - 1; i >= 0; i--)
        (*pfun)((void*)ps->entry[i]);
}
#endif

