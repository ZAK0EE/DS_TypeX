#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Stack.h"

#ifdef Linked



//Initializes the stack.
void CreateStack(Stack *ps)
{
    ps->top = NULL;
    ps->size = 0;
}
/*Push new element to the end of the stack.
  Pre: The stack exists and initialized.
  Post:The argument item has been stored at the top of the stack.*/
int Push(void* value, Stack *ps, int size)
{
    StackNode *pn = (StackNode*)malloc(sizeof(StackNode));
    if (pn == NULL)
        return 0;
    //Entry lines.
    void *ptr = malloc(size);
    memcpy(ptr, value, size);
    pn->entry = ptr;
    //End of entry.
    //pn->entry = value;
    pn->next = ps->top;
    ps->top = pn;
    ps->size++;
    return 1;
}

/*Push new element to the end of the stack.
  Pre: The stack is not empty.
  Post:The argument item has been popped out of the top of the stack.*/
void Pop(void **element, Stack *ps, int size)
{
    //Moving the data and freeing the pointer
    memcpy(*element, ps->top->entry, size);
    free(ps->top->entry);

    StackNode *temp= ps->top;
    ps->top = ps->top->next;
    free(temp);
    ps->size--;
}

//Checks if stack is full.
//Pre:Stack is initialized.
int StackFull(Stack *ps)
{
    return 0;
}

//Checks if stack is empty.
//Pre:Stack is initialized.
int StackEmpty(Stack *ps)
{
    return (ps->top == NULL);
}

//Returns the top element
//Pre:Stack is not empty.
void StackTop(void **element, Stack *ps)
{
    *element = ps->top->entry;
}

//Returns the StackSize
int StackSize(Stack *ps)
{
//    int count = 0;
//    for (StackNode *tmp = ps->top; tmp != NULL; tmp = tmp->next)
//        count++;
//    return count;
    return ps->size;
}

//Clears the stack.
//Pre:Stack is not empty.
//Pos:Stack is empty.
void ClearStack(Stack *ps)
{
    StackNode *tmp = ps->top;    //[top] - [next] - =
    while (tmp != NULL)
    {
        tmp = tmp->next;
        free(ps->top);
        ps->top = tmp;

    }
    ps->size = 0;

}

//Traverse elements
//Pre:Stack is not empty.
void TraverseStack(Stack *ps, void (*pfun) (void*))
{
    StackNode *tmp;
    for (tmp = ps->top; tmp != NULL; tmp = tmp->next)
    {
        (*pfun)(tmp->entry);
    }

}

#endif
