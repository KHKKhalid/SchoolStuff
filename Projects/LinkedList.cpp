#include <iostream.h>
#include <stdlib.h>
#include <conio.h>

struct node
{
    int data;
    node *next;
};

typedef node *list;

list create(list &L)
{
    return L = NULL;
}

void insertbeg(list &L, int item)
{
    node *p;
    p = new(node);
    if(p == NULL) return;
    p->data = item;
    p->next = L;
    L = p;
}

void insertend(list &L, int item)
{
    node *p, *q;
    p = new(node);
    if(p == NULL) return;
    p->data = item;
    p->next = NULL;
    if(L == NULL)
        L = p;
    else
    {
        q = L;
        while(q->next != NULL)
            q = q->next;

        q->next = p;
    }
}

void printlist(list L)
{
    node *p;
    p = L;
    while(p != NULL)
    {
        cout << p->data << "\t";
        p = p->next;
	}
}

/*
	Question:  merge two sorted lists into a third sorted list regardless of the number of nodes in each list.
    For example:
    	L1: 2 6 10
        L2: 5 7
        L3 should be: 2 5 6 7 10
*/

void InsertSorted(list &L, int item)
{
	if(L == NULL)
    {
    	insertbeg(L, item);
    }
    else if(item <= L->data)
    {
    	insertbeg(L, item);
    }
    else
    {
    	node *p, *nextNode;
    	p = L;
		while(p != NULL)
    	{
    		nextNode = p->next;
        	if(nextNode == NULL)
        	{
        		insertend(L, item);
        	}
        	else
        	{
        		if(item >= p->data && item <= nextNode->data)
            	{
					node *newNode;
                	newNode = new(node);
            		if(newNode == NULL) return; // end the whole function execution
                	p->next = newNode;
                	newNode->next = nextNode;
                	newNode->data = item;
                	break;
            	}
        	}

        	p = nextNode;
    	}
    }
}

list MergeSortedLists(list L1, list L2)
{
	list L3;
    create(L3);

    node *p, *q;
    p = L1;
    q = L2;
	while(p != NULL && q != NULL)
    {
    	InsertSorted(L3, p->data);
        InsertSorted(L3, q->data);

        p = p->next;
        q = q->next;
    }

    while(p != NULL)
    {
        InsertSorted(L3, p->data);

    	p = p->next;
    }

    while(q != NULL)
    {
        InsertSorted(L3, q->data);

    	q = q->next;
    }

    return L3;
}

void main()
{
	list L1, L2;

	create(L1);
	create(L2);

   	insertend(L1, 2);
   	insertend(L1, 8);
   	insertend(L1, 10);
	insertend(L1, 14);
    insertend(L1, 17);
    insertend(L1, 18);

	insertend(L2, 9);
   	insertend(L2, 11);
   	insertend(L2, 16);
	insertend(L2, 20);

    printlist(MergeSortedLists(L1, L2));

   	getch();
}