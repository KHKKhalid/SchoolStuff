#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
#include "LinkedList.h"

// Question 1: Write a function that returns the maximum element in a linked list
int ListMax(list L)
{
	int max = L->data;
    node *p;
    p = L->next;
    while(p != NULL)
    {
        if(p->data > max)
        	max = p->data;

    	p = p->next;
    }
    return max;
}

// Question 2: Write a function that returns the average of the elements in a linked list
int ListAverage(list L)
{
	int sum = 0, count = 0;
    node *p;
    p = L;
    while(p != NULL)
    {
     	sum += p->data;
        count ++;

    	p = p->next;
    }
    return (sum/count);
}

// Question 3: Write a function that counts the even numbers in a linked list
int ListCountEven(list L)
{
	int count = 0;
    node *p;
    p = L;
    while(p != NULL)
    {
     	if(p->data % 2 == 0)
        	count ++;

    	p = p->next;
    }
    return count;
}

// Question 4: Write a function that checks if two linked lists are identical or not
int ListIsIdentical(list L1, list L2)
{
	int identical = 1; // assume they are identical
    node *p, *q;
    p = L1;
    q = L2;
    while(p != NULL && q != NULL)
    {
    	if(p->data != q->data)
        {
        	// if the corresponding elements are not identical, then the two lists are not identical
        	identical = 0; // not identical
            break; // break out of the while loop
        }
        p = p->next;
        q = q->next;
    }
    return identical; // return whether they are identical (1) or not (0)
}

void ListInsertSorted(list L, int item)
{
	if(L == NULL)
    {
    	// If the list is empty, it does not matter where we insert the new item
        insertbeg(L, item);
    }
	else if(item <= L->data)
    {
    	/*
        	If the new item is lower than the first item, then it surely is lower than
            all the other items since the list is already sorted (given).

            Hence, we should insert it at the beginning to keep the list sorted.
        */
    	insertbeg(L, item);
    }
    else
    {
    	node *nextNode;
    	node *p;
        p = L;
        while(p != NULL)
        {
        	nextNode = p->next;
            if(nextNode == NULL)
            {
            	/*
                	Here we reached the end of the list which means
                    the new item is greater than all the known items
                    which are already in the sorted list.

                    Hence, we should insert it at the end of the list to
                    keep it sorted.

                */
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
                    return; // end the whole function execution
                }
            }

            p = nextNode;
        }
    }
}

// Question 6: Write a function that accepts two sorted linked lists L1 and L2
// and merge them into a third linked list L3
// Note: this version of function would work only if the two linked lists had
// the same number of nodes.
// Note: the solution of this depends on the concept of the previous function "ListInsertSorted"
list MergeEqualSortedLists(list L1, list L2)
{
	list L3;
    create(L3);

    node *p, *q, *o;
	node *nextNode;
    p = L1;
    q = L2;
    int item[2]; // 0 for p, 1 for q
	while(p != NULL && q != NULL)
    {
    	item[0] = p->data;
        item[1] = q->data;
        for(int i = 0; i < 2; ++ i)
        {
        	if(L3 == NULL)
            {
                insertbeg(L3, item[i]);
            }
        	else if(item[i] <= L3->data)
	    	{
	    		insertbeg(L3, item[i]);
	    	}
	    	else
	    	{
	        	o = L3;
	        	while(o != NULL)
	        	{
	        		nextNode = o->next;
	            	if(nextNode == NULL)
	            	{
	                	insertend(L3, item[i]);
	            	}
	            	else
	            	{
	            		if(item[i] >= o->data && item[i] <= nextNode->data)
	                	{
	                		node *newNode;
	                    	newNode = new(node);
	                    	if(newNode == NULL) return NULL; // end the whole function execution
							o->next = newNode;
	                    	newNode->next = nextNode;
	                    	newNode->data = item[i];
                            break;
	                	}
	            	}

	            	o = nextNode;
				}
	    	}
        }
        p = p->next;
        q = q->next;
    }
    return L3;
}

// Question 7: Write a function that accepts two linked lists (have the same number of nodes)
// and store the sum of every corresponding nodes in a third linked list
list SumEqualLists(list L1, list L2)
{
	list L3;
    create(L3);

    node *p, *q;
    p = L1;
    q = L2;
    while(p != NULL && q != NULL)
    {
    	insertend(L3, (p->data + q->data));

    	p = p->next;
        q = q->next;
    }
    return L3;
}

/*
	Question 8: consider the following node structure

    		struct node {
            	long id;
                int year;
                float gpa;
                node *next;
            }
*/

// Question 8 (a): Write a function which counts the number of students for a given year
int ListCountYear(list L, int year)
{
	int count = 0;
    node *p;
    p = L;
    while(p != NULL)
    {
    	if(p->year == year)
        	count ++;

    	p = p->next;
    }
    return count;
}

// Question 8 (b): Write a function which prints the students' ID whose GPA is below the average GPA
void ListPrintBelowAvg(list L)
{
	int count = 0;
    float sum = 0.0;
	node *p;
    p = L;
    while(p != NULL)
    {
    	sum += p->gpa;
		count ++;
    	p = p->next;
    }

    float average = sum / count;

    p = L;
    while(p != NULL)
    {
    	if(p->gpa < average)
        	cout << p->id << endl;

    	p = p->next;
    }
}

void main()
{
	// Test question 6 solution

	list L1, L2;

	create(L1);
	create(L2);

   	insertend(L1, 2);
   	insertend(L1, 8);
   	insertend(L1, 10);
	insertend(L1, 14);

	insertend(L2, 9);
   	insertend(L2, 11);
   	insertend(L2, 16);
	insertend(L2, 20);

    printlist(MergeEqualSortedLists(L1, L2));

   	getch();
}
