/* C++ program for sum of two large numbers */

#include <iostream>
#include <string.h>
using namespace std;

#define Max 1000

//define function
char * sumOfBigNumber(char st1[], char st2[]);

//program
int main()
{
	char str1[Max];
	cout<<"Enter First Number: ";
	cin >> str1;

	char str2[Max];
	cout<<"Enter Second Number: ";
	cin >> str2;

	cout<<"sum of numbers: "<<sumOfBigNumber(str1, str2)<<endl;

	getchar();
	getchar();
	return 0;
}

//functions
char * sumOfBigNumber(char str1[], char str2[]) {

	if(strlen(str2)>strlen(str1))
		swap(str1, str2);

	//char str[Max];
	int n1 = strlen(str1);
	int n2 = strlen(str2);

	int i,j,carry = 0;

	for (i = n1-1, j = n2-1; i >= 0 && j >= 0; j--, i--) {
		int sum = ((str1[i] - '0') + (str2[j] - '0') + carry);
		str1[i] = sum % 10 + '0';
		carry = sum / 10;
	}
	while (i >= 0) {
		int sum = ((str1[i] - '0') + carry);
		str1[i] = sum % 10 + '0';
		carry = sum / 10;
		i--;
	}

	if (carry > 0) {
		for (i = n1; i >= 0; i--) {
			str1[i + 1] = str1[i];
		}
		str1[0] = carry + '0';
	}

	return str1;
}