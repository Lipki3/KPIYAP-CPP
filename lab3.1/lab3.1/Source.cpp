#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

int main() {
	char* str1, * str2, * str3;
	int len1, len2, len3, len_symb;
	int count1 = 0, count2 = 0, count3 = 0;
	bool first = false, second = false, third = false;
	int i = 0, j = 0;
	str1 = new char[80];
	str2 = new char[80];
	str3 = new char[80];
	char* symbols;
	symbols = new char[4];

	cout << "Enter first string: ";
	do {
		cin.getline(str1, 80);
		len1 = strlen(str1);
	} while (len1 == 0);
	cout << endl;

	cout << "Enter second string: ";
	do {
		cin.getline(str2, 80);
		len2 = strlen(str2);
	} while (len2 == 0);
	cout << endl;

	cout << "Enter third string: ";
	do {
		cin.getline(str3, 80);
		len3 = strlen(str3);
	} while (len3 == 0);
	cout << endl;

	cout << "Enter symbols: ";
	do {
		cin.getline(symbols, 4);
		len_symb = strlen(symbols);
	} while (len_symb == 0);
	cout << endl;


	for (i = 0; i < len1; i++) {
		for (j = 0; j < len_symb; ) {
			if (str1[i] == symbols[j]) {
				j++;
				if (j == len_symb) {
					first = true;
					count1++;
				}
				i++;
			}
			else {
				if (str1[i] == symbols[0]) i--;
				break;
			}
		}
	}

	for (i = 0; i < len2; i++) {
		for (j = 0; j < len_symb; ) {
			if (str2[i] == symbols[j]) {
				j++;
				if (j == len_symb) {
					second = true;    
					count2++;
				}
				i++;
			}
			else {
				if (str2[i] == symbols[0]) i--;
				break;
			}
		}
	}

	for (i = 0; i < len3; i++) {
		for (j = 0; j < len_symb; ) {
			if (str3[i] == symbols[j]) {
				j++;
				if (j == len_symb) {
					third = true;
					count3++;
				}
				i++;
			}
			else {
				if (str3[i] == symbols[0]) i--;
				break;
			}
		}
	}
	
	

	if (first == true || second == true || third == true) {
		cout << "Symbols '" << symbols << "' is found in strings:" << endl;
		if (first == true)
			cout << "First string: " << str1 << "   Number of meetings: "<< count1<<endl;

		if (second == true)
			cout << "Second string: " << str2 << "   Number of meetings: " << count2 << endl;

		if (third == true)
			cout << "Third string: " << str3 <<"   Number of meetings: " << count3 << endl;
	}
	else
		cout << "Symbols '" << symbols << "' not found" << endl;

	delete[] str1;
	delete[] str2;
	delete[] str3;
	return 0;
}
