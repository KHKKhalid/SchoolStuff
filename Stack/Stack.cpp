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

void main()
{
	stack S;
	createStack(S);

	push(5, S);
	push(4, S);
	push(3, S);
	push(2, S);

	cout << "sorted: " << checksorted(S) << endl;
	
   	getch();
}

