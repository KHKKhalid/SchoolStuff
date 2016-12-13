#include <iostream.h>
#include <conio.h>

void hanoi(int x, char from, char to, char aux)
{
	if(x == 1)
    	cout << "\nMove disk from " << from << " to " << to;
    else
    {
    	hanoi(x-1, from, aux, to);
    	cout << "\nMove disk from " << from << " to " << to;
        hanoi(x-1, aux, to, from);
    }
}

void main()
{
	cout << "Enter the number of disks: ";
    int d;
    cin >> d;
	hanoi(d, 'A', 'C', 'B');
    getch();
}
