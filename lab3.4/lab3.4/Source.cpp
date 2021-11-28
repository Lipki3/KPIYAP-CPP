#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

class massiv {
	friend char* dop(int, int, int [], massiv[], int j);
public:
	massiv() {
		m = new char[50];
		strcpy(m, " ---");
	}
	massiv(char* a) {
		m = new char[50];
		strcpy(m, a);
	}
	massiv(const massiv& a){
		m = new char[50];
		strcpy(m, a.m);	
	}
	void print() {
		cout << endl << "Строка: " << m ;
	}
	char* enter() {
		rewind(stdin);
		cout << "\nВведите строку: ";
		cin.getline(m, 50);
		return m;
	}
	char* sort() {

		char l;
		for (int i = 0; i < strlen(m) - 1; i++) {
			for (int j = strlen(m) - 1; j > i; j--) {
				l = m[j - 1];
				m[j - 1] = m[j];
				m[j] = l;
			}
		}
		return m;
	}
	int len(massiv A) {
		int l;
		l = strlen(A.m);
		return l;
	}
	
	void* operator new[](size_t size) {
		cout << "Память выделена" << endl;
		return malloc(size);
	}
	void operator delete[](void* p) {
		free(p);
	}
	~massiv() {
		delete[] m;
	};
private:
	char* m;
};

int ent() {
	int l;
	cin >> l;
	return l;
}

int len(int a, int k[]) {
	int max = 0;
	for (int i = 0; i < a; i++) {
		if (k[i] > max) max = k[i];
	}
	//cout << endl << "  " << max;
	return max;
}
char* dop(int kol, int max_l,  int l[], massiv obj[], int j) {
	int sum = 0;  int counter = 0; char a[50];

			for (int i = 0; i < kol; i++) {
				if (l[i] > j) {
					sum = sum + obj[i].m[j];
					counter++;
				}
			}
			if (counter != 0) sum = sum / counter;
			cout << endl << "ascii " << sum << " - ";
			a[j] = (char)sum;
			cout << a[j];

	return a;
}

int main() {
	system("chcp 1251");
	/*
	cout << endl << "==== ОБЪЕКТЫ ====" ;
	massiv object1;
	//object1.print();
	cout << endl;
	
	massiv (object1.enter());
	//object1.print();

	massiv object2(object1);
	//object2.print();

	cout << "\n\nСортировка:";
	object2.sort();
	object2.print();

	object1.~massiv();
	object2.~massiv();
	*/

	cout << endl << "\n==== МАССИВЫ ОБЪЕКТОВ ====" ;
	int n;
	cout << "\nВведите количество массивов: ";
	while (!scanf_s("%d", &n) || n < 1) {
		rewind(stdin);
		cout << "\nError!\n";
	}
	massiv * objects1 = new massiv[n];
	int* l = new int[n];

	for (int i = 0; i < n; i++) {
		massiv(objects1[i].enter());
		l[i] = objects1[i].len(objects1[i]);
	}

	for (int i = 0; i < n; i++) {
		objects1[i].print();
		cout << "  " << l[i];
	}
	
	/*
	for (int i = 0; i < n; i++) {
		objects1[i].sort();
	}
	cout << endl << endl;;
	cout << "Сортировка:";
	for (int i = 0; i < n; i++) {
		objects1[i].print();
	}
	*/

	massiv sum;
	int max_len = len(n, l);
	char* p = new char[max_len+1]; 
	//char p[50];
	cout << endl;
	cout << "Новый массив: ";
	for (int j = 0; j < max_len; j++) {
		dop(n, max_len, l, objects1, j);
	}
	



	for (int i = 0; i < n; i++) {
		objects1[i].~massiv();
	}
	cout << endl;
	

	system("pause");
}