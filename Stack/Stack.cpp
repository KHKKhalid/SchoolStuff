#include <iostream.h>
#include <stdlib.h>
#include <conio.h>

struct node
{
	int data;
    node *next;
};

typedef node *stack;

stack createStack(stack &S)
{
	return S = NULL;
}

void push(int inputdata, stack &S)
{
	node *newnode;
	newnode = new(node);
	if(newnode == NULL) return;
	newnode->data = inputdata;
	newnode->next = S;
	S = newnode;
}

int pop(stack &S)
{
	node *p;
	p = S;
	int x = p->data;
	S = S->next;
	free(p);
	return x;
}

int isemptyStack(stack S)
{
	return (S == NULL);
}

// Question 4: Write a function that checks if a stack is sorted
int checksorted(stack S)
{
	stack tmp;
	createStack(tmp);

	int a, b;
	a = pop(S);
	push(a, tmp);
	int sorted = 1;
	while(!isemptyStack(S) && sorted == 1)
	{
		b = pop(S);
		push(b, tmp);
		if(a > b) sorted = 0;
		a = b;
	}

	while(!isemptyStack(tmp))
	{
		push(pop(tmp), S);
	}
    return sorted;
}

// Question 7: Write a function that inserts an element in a sorted stack
void StackInsertSorted(stack &S, int item)
{
	int	x;

	x = pop(S);
    if(item < x)
    {
    	push(x, S);
        push(item, S);
        return;
    }

    stack tmp;
    createStack(tmp);

    int y, inserted = 0;

    push(x, tmp);
    while(!isemptyStack(S) && inserted == 0)
    {
		y = pop(S);

       	if(x <= item && item <= y)
       	{
            push(item, tmp);
            push(y, tmp);
        	inserted = 1;
       	}
        else
        {
        	push(y, tmp);
        	x = y;
        }
    }

    if(inserted == 0)
    {
        push(item, tmp);
    }

    while(!isemptyStack(tmp))
    {
    	push(pop(tmp), S);
    }
}

void PrintStack(stack S)
{
	stack t;
    createStack(t);

    int x;
    while(!isemptyStack(S))
    {
    	x = pop(S);
        cout << x << endl;
    	push(x, t);
    }

    while(!isemptyStack(t))
    {
    	push(pop(t), S);
    }
}

void main()
{
	stack S;
	createStack(S);

	push(40, S);
	push(30, S);
	push(20, S);
	push(10, S);

	cout << "sorted: " << checksorted(S) << endl;

    StackInsertSorted(S, 25);

    PrintStack(S);
	
   	getch();
}

