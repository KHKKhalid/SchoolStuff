#include <iostream.h>
#include <stdlib.h>
#include <conio.h>

struct node
{
	int data;
    node *next;
};

typedef node *queue;

queue createQueue(queue &Q)
{
	return Q = NULL;
}

void enqueue(int inputdata, queue &Q)
{
	node *newnode;
	newnode = new(node);
	if(newnode == NULL) return;
	newnode->data = inputdata;
	newnode->next = Q;
	Q = newnode;
}

int dequeue(queue &Q)
{
	node *p1, *p2;
    p1 = Q; p2 = Q;
    int x;
    while(p1->next != NULL)
    {
    	p2 = p1;
        p1 = p1->next;
    }
    x = p1->data;
    p2->next = NULL;
    free(p1);
    return x;
}

int isemptyQueue(queue Q)
{
	return (Q == NULL);
}

// Question 6: Write a function that inserts an element in a sorted queue
/*void QueueInsertSorted(queue &Q)
{
}*/

void PrintQueue(queue Q)
{
	queue tmp;
    createQueue(tmp);

    cout << &Q << "  " << &tmp << endl << endl;
    int x;
    while(!isemptyQueue(Q))
    {
    	x = dequeue(Q);
        cout << "x=" << x << " | isempty=" << isemptyQueue(Q) << "\n";
        enqueue(x, tmp);
    }

    while(!isemptyQueue(tmp))
    {
    	cout << "called\n";
    	x = dequeue(tmp);
        cout << x << "  ";
        enqueue(x, Q);
    }
}

void main()
{
    queue Q;
    createQueue(Q);

    enqueue(40, Q);
    enqueue(30, Q);
    enqueue(20, Q);
    enqueue(10, Q);

    /*int x = dequeue(Q);
    cout << x << endl;
    x = dequeue(Q);
    cout << x << endl;
    x = dequeue(Q);
    cout << x << endl;
    x = dequeue(Q);
    cout << x << endl;
    cout << isemptyQueue(Q);*/

    PrintQueue(Q);

   	getch();
}
