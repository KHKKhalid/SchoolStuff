#include <iostream.h>
#include <conio.h>

void string_reverse(char str[])
{
	int i = 0;
    int j = strlen(str) - 1;
    int len = j;
    int half_len = (len / 2);
    char tmp;
    while(i < len && j != half_len)
    {
    	tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
    	i ++;
        j --;
    }
}

// Question 2
// a. Delete a character from a string
void delete_char(char str[], char c)
{
	int found = 0;
    int len = strlen(str);
	for(int i = 0; i != len; ++ i)
    {
    	if(str[i] == c)
    		found = 1;

        if(found == 1)
        {
        	str[i] = str[i+1];
        }
    }
}

// Question 2
// b. Count the occurrence of a given character in a given string
int count_occurrence(char str[], char c)
{
	int count = 0;
    int len = strlen(str);
	for(int i = 0; i != len; ++ i)
    {
    	if(str[i] == c)
    		count ++;
    }
    return count;
}

void main()
{
    char str1[4] = "sad";
    char str2[6] = "satan";
    char str3[6] = "rules";
    char str4[7] = "always";

	/*
    	Question 1:

        Check <string.h> library and find the functions responsible for manipulating strings.
        Write the name, description and give a working example of the function that is responsible for:
    */

    // i. Calculating the length of a string.
    cout << "The length of str1 is: " << strlen(str1) << endl;

    // ii. Copying one string into another.
    strcpy(str2, str1);
    cout << "The result of copying str1 into str2 using strcpy is (str2=): " << str2 << endl;

    // iii. Appending a string.
    strcat(str1, str3);
    cout << "The result of appending str3 to str1 using strcat is (str1=): " << str1 << endl;

    // iv. Find the first occurrence of a given character in a string.
    cout << "The first occurrence of 'a' in str4 is: " << strchr(str4, 'a') << endl;

    // v. Find the last occurrence of a given character in a string.
    cout << "The last occurrence of 'a' in str4 is: " << strrchr(str4, 'a') << endl;

    // vi. Reverse a given string.
    cout << "strrev(str4) = " << strrev(str4) << endl;

    // vii. Set all characters in a given string with a given character.
    cout << "The effect of strset on str4 is: " << strset(str4, 'b') << endl;

	// viii. Converts all lowercase letters in a given string into uppercase
    cout << "The effect of strupr on str4 is: " << strupr(str4) << endl;

	getch();
}

