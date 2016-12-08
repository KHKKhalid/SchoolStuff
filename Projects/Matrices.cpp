#include <iostream.h>
#include <conio.h>

#define COLUMNS					4
#define ROWS					3
#define NUMBER_OF_MATRICES		2

int
	matrix[NUMBER_OF_MATRICES][ROWS][COLUMNS];


void ReadMatrices()
{
	for(int m = 0; m < NUMBER_OF_MATRICES; ++ m)
	{
		cout << "Input values for Matrix " << (m+1) << " ( m[" << m << "] )\n";

		for(int i = 0; i < ROWS; ++ i)
		{
			for(int j = 0; j < COLUMNS; ++ j)
			{
				cout << "Enter value at row " << i << " | column " << j << ": ";
				cin >> matrix[m][i][j];
				cout << endl;
			}
		}
	}
}

void SumMatrices()
{
	int eq[ROWS][COLUMNS];

	for(int i = 0; i < ROWS; ++ i)
		for(int j = 0; j < COLUMNS; ++ j)
			eq[i][j] = matrix[0][i][j] + matrix[1][i][j];

	cout << "\n\n";
	for(int i = 0; i < ROWS; ++ i)
	{
		for(int j = 0; j < COLUMNS; ++ j)
			cout << eq[i][j] << "\t";
			
		cout << "\n";
	}
	cout << "\n\n";
}

void DiffMatrices()
{
	int eq[ROWS][COLUMNS];

	for(int i = 0; i < ROWS; ++ i)
		for(int j = 0; j < COLUMNS; ++ j)
			eq[i][j] = matrix[0][i][j] - matrix[1][i][j];

	cout << "\n\n";
	for(int i = 0; i < ROWS; ++ i)
	{
		for(int j = 0; j < COLUMNS; ++ j)
			cout << eq[i][j] << "\t";
			
		cout << "\n";
	}
	cout << "\n\n";
}

void MultiplyMatrices()
{
	int eq[ROWS][COLUMNS];

	for(int i = 0; i < ROWS; ++ i)
		for(int j = 0; j < COLUMNS; ++ j)
			eq[i][j] = matrix[0][i][j] * matrix[1][i][j];

	cout << "\n\n";
	for(int i = 0; i < ROWS; ++ i)
	{
		for(int j = 0; j < COLUMNS; ++ j)
			cout << eq[i][j] << "\t";

		cout << "\n";
	}
	cout << "\n\n";
}

void TransposeMatrices()
{
	int transpose[COLUMNS][ROWS];

	for(int m = 0; m < NUMBER_OF_MATRICES; ++ m)
	{
		for(int i = 0; i < ROWS; ++ i)
			for(int j = 0; j < COLUMNS; ++ j)
				transpose[j][i] = matrix[m][i][j];

		cout << "\n\n";
		for(int i = 0; i < COLUMNS; ++ i)
		{
			for(int j = 0; j < ROWS; ++ j)
				cout << transpose[i][j] << "\t";

			cout << "\n";
		}
		cout << "\n\n";	
	}
}

void main()
{
	int quit = 0;
	while(quit == 0)
    {
    	cout << "\nType the number of the operation you want:\n0.Input two matrices\n1.Sum\n2.Difference\n3.Multiply\n4.Transpose\n5.Quit\n";
        int op;
		cin >> op;
        switch(op)
        {
        	case 0:
            {
            	ReadMatrices();
            	break;
            }
        	case 1:
            {
            	SumMatrices();
            	break;
            }
            case 2:
            {
            	DiffMatrices();
            	break;
            }
            case 3:
            {
            	MultiplyMatrices();
            	break;
            }
            case 4:
            {
            	TransposeMatrices();
            	break;
            }
            case 5:
            {
            	quit = 1;
                break;
            }
        }
    }

	getch();
}
