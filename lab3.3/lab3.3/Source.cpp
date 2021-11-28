#include <iostream>
#include <locale.h>
#include <cassert>
#define size 5

using namespace std;

class number {
public:
	number() {
		x = 5;
	}
	number(unsigned int d) {
		x = d;
	}
	unsigned int enter() {
		int y, n;
		while (1) {
			y = scanf_s("%i", &n);
			if (y != 1 || n < 0) {
				cout << "\nОшибка!" << endl;
				rewind(stdin);
			}
			else { 
				x = n;
				break;
			}
		}
		return x;
	}
	unsigned int enter(int num) {
		int y, n;
		while (1) {
			y = scanf_s("%i", &n);
			if (y != 1 || n < 0) {
				cout << "\nОшибка!" << endl;
				rewind(stdin);
			}
			else {
			w[num] = n;
			break;
			}
		}
		return  w[num];
	}
	void print() {
		cout << x;
	}
	void print(int num) {
		cout << w[num] << "  ";
	}
	void print(number a) {
		cout << a.x<< "  ";
		cout << ++a.x << "  ";
		cout << a.x++<< "  ";
		cout << a.x;
	}
	void pr(number a, number b) {
		cout << "A: "<<a.x++ << "  B: "<< ++b.x;
	}
	void mas(){
		int min=0, max=0, sum=0;
		for (int i = 0; i < 5; i++) {
			if (i == 0) {
				min = w[i];
				max = w[i];
			}
			else {
				if (w[i] < min) min = w[i];
				if (w[i] > max) max = w[i];
			}
			sum = sum + w[i];
		}
		cout << "Max: " << max << "  Min: " << min << "  Avg: " << (double)sum / 5 << endl;
	}
	int get_number() {
		return x;
	}
	void set_number(int num) {
		x = num;
	}
	
	number & operator = (number &q) {
		x = q.x;
		return *this;
	}
	unsigned int& operator [] (const int index) {
		return w[index];
	}
	unsigned int& operator () (int index) {
		assert(index >= 0 && index < 5);
		w[index] = 999;
		return w[index];
	}
	// префиксная форма
	number & operator ++ (void) {
		++x;
		return *this;
	}
	// постфиксная форма
	number operator ++ (int qq) {
		number temp(x);
		++(*this);
		return temp;
	}
	number operator + (number b) {
		return number(this->x + b.x);
	}
	number & operator = (const number &a) {
		x = a.x;
		return *this;
	}
	bool operator > (const number &b) {
		return this->x > b.x;
	}
	operator int() {
		return x;
	}
	friend number operator -- (number);
	friend number operator - (number, number);
	friend bool operator < (number, number);
	friend ostream& operator << (ostream &, const number);

private:
	unsigned int x;
	unsigned int w[size];
};

number operator -- (number k) {
	k.x--;
	return k;
}
number operator - (number m, number k) {
	m.x = m.x - k.x;
	return m;
}
bool operator < (number a, number b) {
	return a.x < b.x;
}
ostream& operator << (ostream& os, const number a) {
	return os << " aaaa  "<< a.x;
}
void print_numbers(number num) {
	for (int i = 0; i < size; i++) {
		cout << "  ";
		cout << num[i];
	}
}

int main() {
	setlocale(LC_ALL, "Rus");
	number A, B;
	bool t = true;

	// C  =  ++A  +  B--
	cout << "C  =  ++A  +  B--\n";
	int a, b, c;
	cin >> a; cin >> b;
	c = ++a + b--;
	cout << a << " " << b << endl;
	cout << c << endl;

	// "<"
	cout << "\n--- Перегрузка friend оператора '<' ---\n";
	cout << "A (>=0): ";
	A.enter();
	cout << "B (>=0): ";
	B.enter();
	cout << "A < B ";
	t = operator < (A, B);
	if (t == 0)
		cout << "f" << endl;
	else
		cout << "t" << endl;

	// ">"
	cout << "\n--- Перегрузка оператора '>' ---\n";
	t = true;
	cout << "A (>=0): ";
	A.enter();
	cout << "B (>=0): ";
	B.enter();
	cout << "A > B ";
	t = A.operator > (B);
	if (t == 1)
		cout << "t" << endl ;
	else
		cout << "f"<< endl;


	 // "="
	cout << "--- Перегрузка оператора '=' ---\n";
	cout << "A (>=0): ";
	A.enter();
	cout << "B (>=0): ";
	B.enter();
	cout << "A: ";
	A.operator = (B);
	A.print();
	cout << "   B: ";
	B.print();
	cout << endl << "&A: " << &A << "  &B: " << &B << endl;;

	// "[]"
	cout << "\n--- Перегрузка оператора '[]' ---\n";
	number C;
	cout << "Введите массив на 5 чисел (>=0): ";
	for (int i = 0; i < size; i++) 
		C.enter(i);
	cout << "Массив: ";
	for (int i = 0; i < size; i++) 
		C.print(i);
	cout << endl;

	// "()"
	cout << "\n--- Перегрузка оператора '()' ---\n";
	cout << "Массив: ";
	number D; int y, u;
	for (int i = 0; i < size; i++)
		C.print(i);
	cout << endl;
	cout << "Введите номер элемента массива (0-4): ";
	while (!scanf_s("%d", &y) || y < 0 || y>4) {
		cout << "\nОшибка!" << endl;
		rewind(stdin);
	}
	cout << "Новый массив: ";
	C.operator () (y);
	for (int i = 0; i < size; i++)
		C.print(i);
	cout << endl;

	// "++"
	cout << "\n--- Перегрузка оператора '++' ---\n";
	cout << "A (>=0): ";
	A.enter();
	A.print(A);
	

	// "+"
	cout << "\n--- Перегрузка оператора '+' ---\n";
	cout << "A (>=0): ";
	A.enter();
	cout << "B (>=0): ";
	B.enter();
	cout << "A + B = ";
	A = A.operator + (B);
	A.print();


	// "--"
	cout << "\n--- Перегрузка friend оператора'--' ---\n";
	cout << "A (>=0): ";
	A.enter();
	A = operator -- (A);
	A.print();
	A = operator -- (A);
	A.print();
	A = operator -- (A);
	A.print();

	// "-"
	cout << "\n--- Перегрузка friend оператора'-' ---\n";
	cout << "A (>=0): ";
	A.enter();
	cout << "B (>=0): ";
	B.enter();
	cout << "\nA - B = ";
	A = operator - (A,B);
	A.print();
	
	

	// "<<"
	cout << "\n--- Перегрузка friend оператора '<<' ---\n";
	cout << "A (>=0): ";
	A.enter();
	cout << "aaaa + A: ";
	cout << A;

	// Преобразование типов
	cout << "\n--- Преобразование int в double  ---\n";
	cout << "Массив: ";
	for (int i = 0; i < size; i++)
		C.print(i);
	cout << endl;
	C.mas();

	cout << "\n--- Преобразование number в int  ---\n";
	cout << endl; 
	cout << "Массив: ";
	print_numbers(C);


	return 0;
 }
