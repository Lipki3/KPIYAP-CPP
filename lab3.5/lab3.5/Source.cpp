#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;

class B {
public:
	B() {
		strcpy(name, "name");
		id = 0;
		koef = 1;
	}
	B(int a, char* b, int c) {
		id = a;
		strcpy(name, b);
		koef = c;
	}

	void print0() {
		cout << "ID: " <<id << endl;
		cout << "Name: " << name << endl;
	}
	~B() {};
protected:
	char name[20];
private: 
	int id;
	int koef;
};


class P1 : virtual public B {
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

	~P1() {};
protected:
	char danger[20];
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
	void print11() {
		cout << "Name (protected): " << name << endl;
		cout << "Weight (protected): " << weight << endl;
		cout << "Length (private): " << length << endl;
		cout << "Danger level (protected): " << danger << endl;
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
		strcpy(korm, "Not selected");
		strcpy(name, "Not selected");
	}
	P2(char* a, char* b, char* c) {
		strcpy(name, c);
		strcpy(vid, a);
		strcpy(korm, b);
	}
	~P2() {};
protected:
	char vid[20];
private:
	char korm[20];
};

class P21 : virtual public P2 {
public:
	P21() {
		strcpy(color, "Not selected");
		strcpy(sound, "Not selected");
		strcpy(vid, "Not selected");
		strcpy(name, "Not selected");
	}
	P21(char * b, char* a, char* d, char* c) {
		strcpy(color, a);
		strcpy(sound, b);
		strcpy(name, c);
		strcpy(vid, d);
	}
	void print21() {
		cout << "Name (protected): " << name << endl;
		cout << "Vid (protected): " << vid << endl;
		cout << "Color (protected): " << color << endl;
		cout << "Sound level (private): " << sound << endl;
	}
	~P21() {};
protected:
	char color[20];
private:
	char sound[20];
};

class P3 : public P11, public P21 {
public:
	P3() {
		strcpy(color, "Not selected");
		strcpy(vid, "Not selected");
		weight = 0;
		strcpy(danger, "Not selected");
		strcpy(name, "No name");
	}
	P3(int b, const char* a, const char* d, const char* c, const char* e) {
		strcpy(color, a);
		strcpy(vid, d);
		weight = b;
		strcpy(danger, c);
		strcpy(name, e);
	}
	void print() {
		cout << "Name: " << name << endl;
		cout << "Vid: " << vid << endl;
		cout << "Color: " << color << endl;
		cout << "Weight: " << weight << endl;
		cout << "Danger level: " << danger << endl;
	}
	~P3() {};
};


int main() {
	
	P3 obj3(15, "black", "dog", "slightly dangerous", "Ryhor");
	obj3.print();
	
	return 0;
}