#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;
void qsort(char*, int, int);
void Shell(char*, int);

template <typename T1, typename T2> 
T1 sort(T1 a, T2 b) {
	cout << "default" << endl;
	double m; int k = 0; int size = 0; int c = 0;
	size = b; 
	int choice = 0;
	for (int i = 0; i < b - 1; i++) {
		int temp = a[i];
		for (int j = i + 1; j < b; j++) {
			if (a[j] == temp) {
				for (int k = j; k < b - 1; k++) a[k] = a[k + 1];
				size--;
				j--;
				b--;
			}
		}
	}
	cout << "1 - vozr, 2 - ub\n";
	while (!scanf("%d", &choice) || choice < 1 || choice > 2) {
		rewind(stdin);
		cout << "Error!\n1 - vozr, 2 - ub\n";
	}
	switch (choice) {
	case 1:
		for (int i = 0; i < size; i++) {
			for (int j = b - 1; j > i; j--) {
				if (a[j - 1] > a[j]) {
					m = a[j - 1];
					a[j - 1] = a[j];
					a[j] = m;
				}
			}
		}
		break;
	case 2:
		for (int i = 0; i < size; i++) {
			for (int j = b - 1; j > i; j--) {
				if (a[j - 1] < a[j]) {
					m = a[j - 1];
					a[j - 1] = a[j];
					a[j] = m;
				}
			}
		}
		break;
	}
	cout << "Sort: ";
	for (int i = 0; i < size; i++)
		cout << "  " << a[i];
	return a;
}

template <> char* sort(char* a, int b) {
	char m;
	cout << "specialized" << endl;
	int choice = 0;

		for (int i = 0; i < b - 1; i++) {
			for (int j = b - 1; j > i; j--) {
				if (a[j - 1] > a[j]) {
					m = a[j - 1];
					a[j - 1] = a[j];
					a[j] = m;
				}
			}
		}
		
	return a;
}

void qsort(char* a, int first, int last) {
	int i = first, j = last;
	double tmp, x = a[(first + last) / 2];
	do {
		while (a[i] < x)
			i++;
		while (a[j] > x)
			j--;
		if (i <= j) {
			if (i < j) {
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
			i++;
			j--;
		}
	} while (i <= j);
	if (i < last)
		qsort(a, i, last);
	if (first < j)
		qsort(a, first, j);
}

void Shell(char * arr, int n)  {
	int d = n / 2;                    
	while (d > 0) {
		for (int i = 0; i < n - d; i++) {
			int j = i;
			while (j >= 0 && arr[j] > arr[j + d]) {
				int temp = arr[j];
				arr[j] = arr[j + d];
				arr[j + d] = temp;
				j--;
			}
		}
		d = d / 2;
	}
}


int main() {
	cout << "=== CHAR ===" << endl;
	char* str = new char[50];
	cout << "Enter string: ";
	cin.getline(str, 50);
	int len = strlen(str);
	cout << "Sort: "<< sort(str, len) << endl;

	cout << "=== INT ===" << endl;
	int size;
	cout << "Enter number of elements: ";
	cin >> size;
	int* mas = new int[size];
	cout << "Enter " << size << " elements:" << endl;
	for (int i = 0; i < size; i++) {
		cin >> mas[i];
	}
	mas = sort(mas, size);


	cout << "\n=== FLOAT ===" << endl;
	int size1;
	cout << "Enter number of elements: ";
	cin >> size1;
	float* mas1 = new float[size1];
	cout << "Enter " << size1 << " elements:" << endl;
	for (int i = 0; i < size1; i++) {
		cin >> mas1[i];
	}
	mas1 = sort(mas1, size1);
	

	return 0;
}