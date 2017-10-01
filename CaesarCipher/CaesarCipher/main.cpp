#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

/* 
	Purpose: Encrypt or decrypt a whole string by shifting all letters

	Parameters:
		str - the string to encrypt or decrypt
		key - the shift
		encrypt - the string is encrypted if set to true, otherwise the string is decrypted
*/
void ApplyCaesarCipher(string &str, unsigned short int key, bool encrypt)
{
	for (string::size_type i = 0; i < str.size(); ++i)
	{
		// Shift only letters
		if (!isalpha(str[i]))
			continue;

		// See whether it's lowercase or uppercase and get a base value
		unsigned char base = (islower(str[i])) ? 'a' : 'A';

		// Make the letter start from zero by subtracting the ASCII value. This is needed to make use of the MOD.
		str[i] -= base;

		// Apply the shift
		str[i] += (encrypt == true) ? key : (26 - key);

		// If you reach the end of alphabet, you wrap around
		str[i] %= 26;

		// Add ASCII value back
		str[i] += base;
	}
}

int main()
{
	cout << "Enter a message to encrypt: \n";

	string str;
	getline(cin, str);

// GOTO LABEL
reselect:
	cout << "Shift: ";
	unsigned short int key;
	cin >> key;

	if(key > 25 || key < 1)
    {
        cout << "\nError: No-brainer... Key value ranges from 1 to 25\n";
        goto reselect;
    }

	cout << "Plain text: " << str << endl;

	ApplyCaesarCipher(str, key, true);
	cout << "After encryption: " << str << endl;

	ApplyCaesarCipher(str, key, false);
	cout << "After decryption: " << str << endl;

	getch();
	return 0;
}
