#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include "Settings.h"


//#define Linked
#ifdef Linked
typedef struct stacknode
{
    void *entry;
    struct stacknode* next;

}
StackNode;

typedef struct Stack
{
    StackNode* top;
    int size;
}
Stack;
#else
typedef struct Stack
{
    int top;
    void *entry[MAX_ELEMENTS];
}
Stack;
#endif

//Initializes the stack.
void CreateStack(Stack *);

//Pushs new element to the stack.
//Pre:Stack is not empty.
int Push(void *, Stack *, int);

//Pops the last element.
//Pre:Stack is not empty.
void Pop(void **, Stack *, int);

//Checks if stack is full.
//Pre:Stack is initialized.
int StackFull(Stack *);

//Checks if stack is empty.
//Pre:Stack is initialized.
int StackEmpty(Stack *);

//Returns the top element
//Pre:Stack is not empty.
void StackTop(void **, Stack*);

//Returns the StackSize
int StackSize(Stack *ps);


//Clears the stack.
//Pre:Stack is not empty.
//Pos:Stack is empty.
void ClearStack(Stack *);

//Traverse elements
//Pre:Stack is not empty.
void TraverseStack(Stack *, void (*pfun) (void*));




 // Linked

#endif // STACK_H_INCLUDED




