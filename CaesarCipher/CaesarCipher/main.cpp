#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>

using namespace std;

// Encrypt a whole string by shifting all letters
void EncryptString(char str[], unsigned short int key)
{
	for(int i = 0; str[i] != '\0'; ++ i)
	{
		// See whether it's lowercase or uppercase and get a base value
        char base = (islower(str[i])) ? 'a' : 'A';

        // Make the letter start from zero by subtracting the ASCII value. This is needed to make use of the MOD.
        str[i] -= base;

        // Apply the shift
        str[i] += key;

        // If you reach the end of alphabet, you wrap around
        str[i] %= 26;

        // Add ASCII value back
        str[i] += base;
	}
}

// Decrypt a whole string by shifting all letters
void DecryptString(char str[], unsigned short int key)
{
	for(int i = 0; str[i] != '\0'; ++ i)
	{
	    // See whether it's lowercase or uppercase and get a base value
        char base = (islower(str[i])) ? 'a' : 'A';

        // Make the letter start from zero by subtracting the ASCII value. This is needed to make use of the MOD.
        str[i] -= base;

        // Apply the shift
        str[i] += (26 - key);

        // If you reach the end of alphabet, you wrap around
        str[i] %= 26;

        // Add ASCII value back
        str[i] += base;
	}
}

int main()
{
	cout << "Enter a message to encrypt (Max: 128 chars): \n";

	char str[128];
	gets_s(str);

    reselect:
	cout << "Shift: \n";
	unsigned short int key;
	cin >> key;

	if(key > 25 || key < 1)
    {
        cout << "No-brainer... Key value ranges from 1 to 25\n";
        goto reselect;
    }

	cout << "Plain text: " << str << endl;

	EncryptString(str, key);
	cout << "After encryption: " << str << endl;

	DecryptString(str, key);
	cout << "After decryption: " << str << endl;

	getch();
	return 0;
}
