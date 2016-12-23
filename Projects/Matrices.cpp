#include <iostream.h>
#include <conio.h>

#define MATRIX_SIZE             2

int
	matrix1[MATRIX_SIZE][MATRIX_SIZE];
    matrix2[MATRIX_SIZE][MATRIX_SIZE];


void ReadMatrices()
{
	cout << "Input values for the first matrix\n";

	for(int i = 0; i != MATRIX_SIZE; ++ i)
	{
		for(int j = 0; j != MATRIX_SIZE; ++ j)
		{
			cout << "Enter value at row " << i << " | column " << j << ": ";
			cin >> matrix1[i][j];
		}
	}

    cout << "Input values for the second matrix\n";

	for(int i = 0; i != MATRIX_SIZE; ++ i)
	{
		for(int j = 0; j != MATRIX_SIZE; ++ j)
		{
			cout << "Enter value at row " << i << " | column " << j << ": ";
			cin >> matrix2[i][j];
		}
	}
}

void SumMatrices()
{
    for(int i = 0; i != MATRIX_SIZE; ++ i)
    {
		for(int j = 0; j != MATRIX_SIZE; ++ j)
        {
            cout << (matrix1[i][j] + matrix2[i][j]);
            cout << "\t";
        }
        cout << "\n";
    }
}

void DiffMatrices()
{
    for(int i = 0; i != MATRIX_SIZE; ++ i)
    {
		for(int j = 0; j != MATRIX_SIZE; ++ j)
        {
            cout << (matrix1[i][j] - matrix2[i][j]);
            cout << "\t";
        }
        cout << "\n";
    }
}

void MultiplyMatrices()
{
    int res = 0;
    for(int row = 0; row != MATRIX_SIZE; ++ row)
    {
    	for(int col = 0; col != MATRIX_SIZE; ++ col)
        {
        	for(int each = 0; each != MATRIX_SIZE; ++ each)
            {
                res += matrix1[row][each] * matrix2[each][col];
            }
            cout << res << "\t";
            res = 0;
        }
        cout << "\n";
    }
}

void TransposeMatrices()
{
	int transpose[MATRIX_SIZE][MATRIX_SIZE];

    // Transpose: first matrix
	for(int i = 0; i != MATRIX_SIZE; ++ i)
		for(int j = 0; j != MATRIX_SIZE; ++ j)
			transpose[j][i] = matrix1[i][j];

	cout << "\n\n";
	for(int i = 0; i != MATRIX_SIZE; ++ i)
	{
		for(int j = 0; j != MATRIX_SIZE; ++ j)
			cout << transpose[i][j] << "\t";

		cout << "\n";
	}
	cout << "\n\n";

    // Transpose: second matrix
	for(int i = 0; i != MATRIX_SIZE; ++ i)
		for(int j = 0; j != MATRIX_SIZE; ++ j)
			transpose[j][i] = matrix2[i][j];

	cout << "\n\n";
	for(int i = 0; i != MATRIX_SIZE; ++ i)
	{
		for(int j = 0; j != MATRIX_SIZE; ++ j)
			cout << transpose[i][j] << "\t";

		cout << "\n";
	}
	cout << "\n\n";
}

void main()
{
	int quit = 0, op;
	while(quit == 0)
    {
    	cout << "\nType the number of the operation you want:\n0.Input two matrices\n1.Sum\n2.Difference\n3.Multiply\n4.Transpose\n5.Quit\n";
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
