#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
#define size 50
class Dekan;


class Student {
	friend class Dekan;
	friend void print_list(Student);
	friend void sort(Student[], Student ,int, int);
public:
	Student() {
		id = 0;
		strcpy(name, "-");
		strcpy(rate, "-");

	}
	Student(char* b, int a, char* c) {
		id = a;
		strcpy(name, c);
		strcpy(rate, b);
	}
	~Student() {}

	int st_id(Student b[], int a) {
		int k;
		rewind(stdin);
		cout << "Id (1 - 999) : ";
			while (!scanf_s("%d", &id) || id < 1 || id > 999) {
				cout << "\nError!" << endl;
				rewind(stdin);
			}
			for (int j = 0; j < a; j++) {
				k = b[j-1].id;
				if (id == k) {
				cout << "Enter new ID (1-999) : ";
				b[a-1].st_id(b, a);
				}
			}
		return id;
	}
	char* st_name() {
		int len; bool ok = false; int defis = 0; int m; bool numbers = false; int space = 0;
		do {
			ok = false;
			numbers = false;
			defis = 0;
			space = 0;
			rewind(stdin);
			cout << "Name: ";
			cin.getline(name, 50);
			len = strlen(name);
			for (m = 0; m < len; m++) {
				if (name[m] == '-') defis++;
				if (name[m] == ' ') space++;
				if (name[m]!=32 && name[m]!=45 && (name[m]<97 || name[m]>122) && (name[m]<65 || name[m]>90)) {
					numbers = true;
					//if (name[m] == 32 || name[m] == 45) numbers = false;
				}
				
				
				if (name[m] == '-' && name[m - 1] == ' ') numbers = true;
				if (name[m] == ' ' && name[m - 1] == '-') numbers = true;

			}
			if (numbers == false && defis < 2 && space == 1) {
				ok = true;
				if (name[m-1] == '-' || name[0] == '-') ok = false; 
				if (name[m-1] == ' ' || name[0] == ' ') ok = false;
			}
			if (ok == false) cout << "Incorrected name\n";
		} while (ok == false);

		return name;
	}

private:
	int id;
	char* rate = new char[50];
	char* name = new char[50];
};



class Dekan {
public:
	char* st_rate(Student &a) {
		int len1=0; bool ok = false; int m, i=0; 
		do {
			ok = true;
			rewind(stdin);
			cout << "Rate (0.00 - 10.00): ";
			//while (i != '\n') {
				//cin >> a.rate[i];
				//len1++;
				//i++;
			//}
			cin.getline(a.rate, 50);
			len1 = strlen(a.rate);
			if (len1 == 0) ok = false;
			if (len1 == 1) {
					if (a.rate[0] > 57 || a.rate[0] < 48)
						ok = false;
			}
			if (len1 == 2) {
				if (a.rate[0] == 49 && a.rate[1] == 48)
					ok = true;
				else ok = false;
			}
			if (len1 == 3) {
				for (m = 0; m < len1; m++) {
					if (a.rate[m] > 57 || a.rate[m] < 44 || a.rate[m] == 45 || a.rate[m] == 47)
						ok = false;
				}
				if (a.rate[0] == 44 || a.rate[2] == 44 || a.rate[0] == 46 || a.rate[2] == 46)
					ok = false;
				if (a.rate[1] == 44) a.rate[1] = 46;
			}
			if (len1 == 4) {
				for (m = 0; m < len1; m++) {
					if (a.rate[m] > 57 || a.rate[m] < 44 || a.rate[m] == 45 || a.rate[m] == 47)
						ok = false;
				}
				if (a.rate[0] == 44 || a.rate[3] == 44 || a.rate[0] == 46 || a.rate[3] == 46)
					ok = false;
				if (a.rate[0] == 49 && a.rate[1] == 48 && (a.rate[2] == 44 || a.rate[2] == 46)) ok = true;
				else ok = false;
						
				if (a.rate[0] == 48 || a.rate[0] > 49 || a.rate[0] < 58) {
					if (a.rate[1] == 44 || a.rate[1] == 46) ok = true;
					else ok = false;
				}
				if (a.rate[1] == 44) a.rate[1] = 46;
				if (a.rate[2] == 44) a.rate[2] = 46;
			}
			if (len1 == 5) {
				if (a.rate[0] == 49 && a.rate[1] == 48 && (a.rate[2] == 44 || a.rate[2] == 46) && a.rate[3] == 48 && a.rate[4] == 48) ok = true;
				else ok = false;
				if (a.rate[2] == 44) a.rate[2] = 46;
			}
			if (len1 > 5) {
				ok = false;
			}
			if (ok == false)
				cout << "Incorrected rate" << endl;
		} while (ok != true);

		return a.rate;
	}
};


void print_list(Student a) {
		cout << "|                                              |";
		cout << "\r|                                       |" << a.rate;
		cout << "\r|            |" << a.name;
		cout << "\r|" << a.id;
		cout << endl;
}

void sort(Student a[], Student b,  int ch, int num) {
	switch (ch) {
	case 1:
		for (int i = 0; i < num - 1; i++) {
			for (int j = num - 1; j > i; j--) {
				if (a[j - 1].id > a[j].id)
				{
					b = a[j];
					a[j] = a[j - 1];
					a[j - 1] = b;
				}
			}
		}
		break;
	case 2:
		for (int i = 0; i < num - 1; i++) {
			for (int j = num - 1; j > i; j--) {
				if (a[j - 1].id < a[j].id)
				{
					b = a[j - 1];
					a[j - 1] = a[j];
					a[j] = b;
				}
			}
		}
		break;
	}
}


int main() {

	int choice = 0;
	bool exit = false;
	int kol = 0, num; int k = 0; 
	int number_of_students = 0;
	Student group3[30];
	Student vvoid;
	Dekan bobrova;

	do {

		cout << "\n1 - Add new student\n2 - Print info\n3 - Edit information\n4 - Delete student\n5 - Sort by ID\n6 - Exit" << endl;

			while (!scanf_s("%d", &choice) || choice < 1 || choice > 6) {
				cout << "Error!" << endl;
				rewind(stdin);
			}


			switch (choice) {

			case 1:
				k = number_of_students;
				number_of_students++;
				Student (bobrova.st_rate(group3[k]), group3[k].st_id(group3, number_of_students), group3[k].st_name());
				break;

			case 2:
				cout << "| Student ID |     Surname and name     | Rate |\n";
				for (int j = 0; j < number_of_students; j++)
					print_list(group3[j]);
				break;

			case 3:
				cout << "1 - ID\n2 - Name\n3 - Rate\n";
				while (!scanf_s("%d", &choice) || choice < 1 || choice > 3) {
					cout << "Error!" << endl;
					rewind(stdin);
				}
				switch (choice) {
				case 1:
					cout << "| Student ID |     Surname and name     | Rate |\n";
					for (int j = 0; j < number_of_students; j++)
						print_list(group3[j]);
					cout << "\nEnter number of student you want to edit (1 - " << number_of_students << ") : ";
					while (!scanf_s("%d", &num) || num < 1 || num > number_of_students) {
						cout << "Error!" << endl;
						rewind(stdin);
					}
					num = num - 1;
					group3[num].st_id(group3, number_of_students);
					break;
				case 2:
					cout << "| Student ID |     Surname and name     | Rate |\n";
					for (int j = 0; j < number_of_students; j++)
						print_list(group3[j]);
					cout << "\nEnter number of student you want to edit (1 - " << number_of_students << ") : ";
					while (!scanf_s("%d", &num) || num < 1 || num > number_of_students) {
						cout << "Error!" << endl;
						rewind(stdin);
					}
					num = num - 1;
					group3[num].st_name();
					break;
				case 3:
					cout << "| Student ID |     Surname and name     | Rate |\n";
					for (int j = 0; j < number_of_students; j++)
						print_list(group3[j]);
					cout << "\nEnter number of student you want to edit (1 - " << number_of_students << ") : ";
					do {
						while (!scanf_s("%d", &num) || num < 1 || num > number_of_students) {
							cout << "Error!" << endl;
							rewind(stdin);
						}
						num = num - 1;
					} while (num > number_of_students - 1 || num < 0);
					bobrova.st_rate(group3[num]);
					break;
				}
				break;

			case 4:
				cout << "| Student ID |     Surname and name     | Rate |\n";
				for (int j = 0; j < number_of_students; j++)
					print_list(group3[j]);
				cout << "\nEnter student number (1 - " << number_of_students << ") : ";
				while (!scanf_s("%d", &choice) || choice < 1 || choice > number_of_students) {
					cout << "Error!" << endl;
					rewind(stdin);
				}

				for (k = choice - 1; k < number_of_students; k++) {
					group3[k] = group3[k + 1];
				}
				number_of_students--;
				break;

			case 5:
				cout << "1 - Sort Ascending\n2 - Sort descending" << endl;
				while (!scanf_s("%d", &choice) || choice < 1 || choice > 2) {
					cout << "Error!" << endl;
					rewind(stdin);
				}
				sort(group3, vvoid, choice, number_of_students);
				break;


			case 6:
				exit = true;
				break;

			}

		} while (exit == false);

		return 0;

	}