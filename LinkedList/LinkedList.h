struct node
{
    int data;
    node *next;

	// for question 8 in sheet 5
	long id;
	int year;
	float gpa;
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

#define INVALID_LIST_DELETION		65535

int delbeg(list &L)
{
	if(L == NULL)
   {
   	cout << "\nERROR delbeg(NULL): Linked list is empty!\n";
      return INVALID_LIST_DELETION;
   }
	node *p;
   p = L;
   int x;
   L = L->next;
   x = p->data;
   free(p);
   return x;
}

int delend(list &L)
{
   if(L == NULL)
   {
   	cout << "\nERROR delend(NULL): Linked list is empty!\n";
      return INVALID_LIST_DELETION;
   }
   if(L->next == NULL)
   {
      /*
      	The next node of the first node is equal to NULL
         which means that the list has ONLY one node and
         we can just do the following to delete this node

      */

      int x;
      x = L->data;
      L = NULL; // the list becomes empty at this point
      return x;
   }
   else
   {
		node *p, *q;
      p = L;
      int x;
      while(p->next != NULL)
   	{
      	q = p;
         p = p->next;
      }
      x = p->data;
      q->next = NULL;
      free(p);
      return x;
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