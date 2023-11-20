
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
//Project files.
#include "Settings.h"
#include "Stack/Stack.h"
#include "Queue/Queue.h"


//Maximum allowed name.
#define MAX_NAME 30

typedef struct person
{
    char name[MAX_NAME];
    int age;
    int pincode;
}Person;

//Function used to show elements through Stack or Queue.
void Display(Person* element)
{
    printf("element <%d> name '%s' of age %d\n", element->pincode, element->name, element->age);
}
int main()
{

    Stack stk;
    CreateStack(&stk);
    Person input;
    char choice = 'y';
    //Input loop.
    printf("Please enter the persons data.\n");
    for (int i = 0; tolower(choice) == 'y'; i++)
    {
        printf("<%d> Person name: ", i);
        scanf("%s", input.name);
        printf("<%d> Person age: ", i);
        scanf("%d", &input.age);
        input.pincode = i;
        if (!Push(&input, &stk, sizeof(Person)))
        {
            printf("Data could not be inserted!\a\n");
            return 1;
        }
        else
            printf("Person <%d> is pushed in stack.\n", i);
        //Safety check.
        if (StackFull(&stk))
        {
            printf("Stack is full! you can not store any more data in the stack.\a\n");
            break;
        }
        printf("Do you want to insert a new person ? (y/n): ");
        scanf(" %c", &choice);

    }

    Person* output = malloc(sizeof(Person));
    Queue que;
    CreateQueue(&que);

    int tmp_pincode = 0;
    //Popping the stack and sending the data to a queue.
    while (!StackEmpty(&stk))
    {

        Pop(&output, &stk, sizeof(Person));
        tmp_pincode = output->pincode;
        printf("Person <%d> is popped.\n", tmp_pincode);
        if (!Append(output, &que, sizeof(Person)))
        {
            printf("Data could not be inserted!\a\n");
            return 1;
        }
        else
        {
            printf("Person <%d> is appended in queue\n", tmp_pincode);

        }
        if (QueueFull(&que))
        {
            printf("Stack is full! you can not store any more data in the queue.\a\n");
            break;
        }

    }
    //Retrieving data from the queue
    printf("Displaying final data retrieved from queue.\n");
    while (!QueueEmpty(&que))
    {
        Serve(&output, &que, sizeof(Person));
        printf("element <%d> name '%s' of age '%d' is retrieved\n", output->pincode, output->name, output->age);

    }
    free(output);
    return 0;
}
