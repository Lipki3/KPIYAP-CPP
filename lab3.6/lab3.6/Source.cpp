#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;

class B {
public:
	B() {
		strcpy(name, "name");
		id = 0;
	}
	B(int a, const char* b) {
		id = a;
		strcpy(name, b);
	}

	virtual void see(void) {
		cout << "ID: " << id << endl;
		cout << "Name: " << name << endl;
	}
	virtual void count(void) = 0;
	virtual ~B() {
		cout << endl;
	};
	char* en_n() {
		rewind(stdin);
		cout << "Enter name: ";
		cin.getline(name, 30);
		return name;
	}
protected:
	char name[20];
private:
	int id;
};


class P1 : public B {
public:
	P1() {
		strcpy(danger, "not_selected");
		speed = 0;
		strcpy(name, "Not selected");
	}
	P1(char* a, int b, char* c) {
		strcpy(danger, a);
		speed = b;
		strcpy(name, c);
	}
	void see() override {
		cout << "Name: " << name << endl;
		cout << "Danger: " << danger << endl;
		cout << "Speed: " << speed << endl;
	}
	void count() override {
		cout << "Speed (km/h): " << speed << endl;
		float sp;
		sp = speed / 3.6;
		cout << "Speed (m/s): " << sp << endl;
	}
	char* en_d() {
		rewind(stdin);
		cout << "Enter danger level: ";
		cin.getline(danger, 30);
		return danger;
	}
	int en_s() {
		cout << "Enter speed: ";
		cin >> speed;
		return speed;
	}
	~P1() {};
protected:
	char danger[30];
private:
	int speed;
};

class P11 : virtual public P1 {
public:
	P11() {
		weight = 0;
		length = 0;
		strcpy(name, "Not selected");
		strcpy(danger, "Not selected");
	}
	P11(char* d, char* c, int a, int b) {
		weight = a;
		length = b;
		strcpy(name, c);
		strcpy(danger, d);
	}
	void see() override {
		cout << "Name: " << name << endl;
		cout << "Danger: " << danger << endl;
		cout << "Weight: " << weight << endl;
		cout << "Length: " << length << endl;
	}
	void count() {
		float index;
		index = length - weight;
		if (index > 100 || index < 115) cout << "100 < index < 115" << endl;
		if (index >= 115) cout << "index >= 115" << endl;
		if (index <= 100) cout << "index <= 100" << endl;
	}
	int en_w() {
		cout << "Enter weight: ";
		cin >> weight;
		return weight;
	}
	int en_l() {
		cout << "Enter length: ";
		cin >> length;
		return length;
	}
	~P11() {};
protected:
	int weight;
private:
	int length;
};

class P2 : virtual public B {
public:
	P2() {
		strcpy(vid, "Not selected");
		strcpy(color, "Not selected");
		strcpy(name, "Not selected");
	}
	P2(char* a, char* b, char* c) {
		strcpy(name, c);
		strcpy(vid, a);
		strcpy(color, b);
	}
	void see() override {
		cout << "Name: " << name << endl;
		cout << "Vid: " << vid << endl;
		cout << "Color: " << color << endl;
	}
	void count() override {
		cout << "P2 count" << endl;
		int a = 10; int b = 5;
		int c = a + b * b;
		cout << "C = " << c << endl;
	}
	char* en_v() {
		rewind(stdin);
		cout << "Enter vid: ";
		cin.getline(vid, 30);
		return vid;
	}
	char* en_c() {
		rewind(stdin);
		cout << "Enter color: ";
		cin.getline(color, 30);
		return color;
	}
	~P2() {};
protected:
	char vid[20];
private:
	char color[20];
};



int main() {
	
	P1 object1; P1(object1.en_d(), object1.en_s(), object1.en_n());
	P11 object11; P11(object11.en_d(), object11.en_n(), object11.en_w(), object11.en_l());
	P2 object2; P2(object2.en_v(), object2.en_c(), object2.en_n());


	B** ptr = new B * [3];
	ptr[0] = &object1;
	ptr[1] = &object11;
	ptr[2] = &object2;

	int choice = 0;
	do {
		cout << endl << "Print: \n1 - object 1\n2 - object11\n3 - object\n4 - exit" << endl;
		while (!scanf("%d", &choice) || choice < 1 || choice > 4) {
			rewind(stdin);
			cout << "Error!" << endl;
		}

		switch (choice) {
		case 1:
			cout << "=== OBJECT P1 ===" << endl;
			cout << "SEE: " << endl;
			ptr[0]->see();
			cout << "COUNT: " << endl;
			ptr[0]->count();
			cout << endl;
			break;
		case 2:
			cout << "=== OBJECT P11 ===" << endl;
			cout << "SEE: " << endl;
			ptr[1]->see();
			cout << "COUNT: " << endl;
			ptr[1]->count();
			cout << endl;
			break;
		case 3:
			cout << "=== OBJECT P2 ===" << endl;
			cout << "SEE: " << endl;
			ptr[2]->see();
			cout << "COUNT: " << endl;
			ptr[2]->count();
			cout << endl;
			break;
		}
	} while (choice != 4);




	return 0;
}