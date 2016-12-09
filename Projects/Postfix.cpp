/*

	Write a C program that accepts a postfix expression and evaluates it

*/

#include <iostream.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
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

int IsOperator(char str[])
{
	if(!strcmp(str, "+") || !strcmp(str, "-") || !strcmp(str, "*") || !strcmp(str, "/"))
		return 1;

	return 0;
}

int Operate(int operand1, int operand2, char operator_str[])
{
	if(!strcmp(operator_str, "+"))
	{
		return (operand1 + operand2);
	}
	else if(!strcmp(operator_str, "-"))
	{
		return (operand1 - operand2);
	}
	else if(!strcmp(operator_str, "*"))
	{
		return (operand1 * operand2);
	}
	else if(!strcmp(operator_str, "/"))
	{
		return (operand1 / operand2);
	}
	return 0;
}



int EvaluatePostfix(char postfix[])
{
	stack S;
	createStack(S);

	int x, num1, num2;
	char temp[16];
    int null_position = 0;
    int j = strlen(postfix) + 1;
	for(int i = 0; i != j; ++ i)
	{
		if(postfix[i] == ' ' || postfix[i] == '\0')
		{
			if(null_position > 0)
			{
				if(IsOperator(temp))
				{
					num1 = pop(S);
					num2 = pop(S);
					x = Operate(num2, num1, temp);
					push(x, S);
				}
				else
				{
					x = atoi(temp);
					push(x, S);
				}
				temp[0] = '\0';
                null_position = 0;
			}
		}
		else
		{
            temp[null_position] = postfix[i];
            ++ null_position;
            temp[null_position] = '\0';
		}
	}
	x = pop(S);
	if(!isemptyStack(S))
	{
		cout << "\nError: Invalid postfix expression\n";
	}
	return x;
}

void main()
{
	cout << "Enter the postfix expression you want to evaluate";
	cout << "\nNote: you must separate operands and operators by space (e.g.  3 5 *)";
	cout << "\nNote: only integers and these operators (+ - * /) are accepted\n";
    cout << "Postfix expression: ";

	char str[128];
	gets(str);
	cout << "\nResult = " << EvaluatePostfix(str);

   	getch();
}

