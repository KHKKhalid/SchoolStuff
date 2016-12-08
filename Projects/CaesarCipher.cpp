#include <iostream.h>
#include <stdio.h>
#include <conio.h>

int IsLetter(char chr)
{
	if((chr >= 65 && chr <= 90) || (chr >= 97 && chr <= 122))
		return 1;
		
	return 0;
}

void EncryptLetter(char *letter)
{
	switch(*letter)
	{
		case 90:
		{
			*letter = 65;
			break;
		}
		case 122:
		{
			*letter = 97;
			break;
		}
		default:
		{
			*letter = (char)(*letter + 1);
		}
	}
}

void EncryptString(char str[])
{
	for(int i = 0; str[i] != '\0'; ++ i)
	{
		if(IsLetter(str[i]))
		{
			EncryptLetter(&str[i]);
		}
	}
}

void DecryptLetter(char *letter)
{
	switch(*letter)
	{
		case 65:
		{
			*letter = 90;
			break;
		}
		case 97:
		{
			*letter = 122;
			break;
		}
		default:
		{
			*letter = (char)(*letter - 1);
		}
	}
}

void DecryptString(char str[])
{
	for(int i = 0; str[i] != '\0'; ++ i)
	{
		if(IsLetter(str[i]))
		{
			DecryptLetter(&str[i]);
		}
	}
}

void main()
{
	cout << "Enter a message to encrypt (Max: 128 chars): \n";

	char str[128];
	gets(str);
	
	cout << "Before encryption: " << str << endl;
	
	EncryptString(str);
	cout << "After encryption: " << str << endl;

	DecryptString(str);
	cout << "After decryption: " << str << endl;
	
	getch();
}
