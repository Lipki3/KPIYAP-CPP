// вместо записи в определенный файл на выбор реализовать запись в текстовый файл сразу при вводе, 
// сделать кнопку для записи в бинарный
// сделать сортировку файла на выбор по возрастанию или убыванию
// сортировка по любому полю на выбор пользователя


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <exception>
#include <fstream>
#include <string>


using namespace std;

class MyException : public exception {
public:
    void catch_null() {
        cout << "catching: Nothing";
    }
    void catch_letters() {
        cout << "catching: letter(s)";
    }
    void catch_rate() {
        cout << "catching uncorrected rate";
    }

};


class Student {

    friend void del(Student*, int);
    friend ostream& operator<<(ostream&, const Student);
    friend istream& operator>>(istream&, Student&);
private:
    char name[30];
    char group[20];
    float rate;
    bool t;

public:

    Student() {
        strcpy(name, "-");
        rate = 0;
        strcpy(group, "000000");
        t = false;

    }
    Student(float r, char* gr, char* nm, bool iii) {
        strcpy(name, nm);
        rate = r;
        strcpy(group, gr);
        t = iii;
 
    }

    char* enter_n() {
        cout << "Enter name: ";
        rewind(stdin);
        cin.getline(name, 30);
        return name;
    }
    char* enter_g() {
        cout << "Enter group: ";
        rewind(stdin);
        cin.getline(group, 20);
        return group;
    }
    bool en_t() {
        t = false;
        return t;
    }

    float enter_r(float r) {
        if (!r || r < 0 || r > 10) throw MyException();
        rate = r;
        //cout << "rate " << rate;

        return rate;
    }
    void print(Student* arr, int p) {
        if (p < 1) throw MyException();
        for (int i = 0; i < p; i++) {
            cout.unsetf(ios::dec);
            cout.setf(ios::oct);
            cout << "\nStudent " << arr[i].name << " Group: " << arr[i].group << " Rate (oct): ";
            cout << (int)arr[i].rate;
            cout << " Rate (dec): " << arr[i].rate << endl;

        }
    }

    void find(Student* arr, int p) {
        if (p < 1) throw MyException();
        bool flag = false;
        int n;
        cout << "Enter rate to find: ";
        while (!scanf("%d", &n)) {
            cout << "Error!\n";
            rewind(stdin);
        }
        flag = false;
        for (int c = 0; c < p; c++) {
            if (arr[c].rate == n) {
                cout << "\nStudent " << arr[c].name << ", rate = " << n;
                flag = true;
            }
        }
        if (flag == false) cout << "\nNo matches found ";
    }
    ~Student() {
    }

    void write_tt(int p) {
        if (p < 1) throw MyException();
        if (t == false) {
            ofstream out("file.txt", ios::app);
            out << "Rate: " << rate;
            out << " Name: " << name;
            out << " Group: " << group << endl;
            out.close();
            t = true;
        }
    }

    void write_b(Student a, int p) {
        if (p < 1) throw MyException();
        ofstream out1("file1.bin", ios::binary | ios::app | ios::out);
        out1.seekp(0, ios::end);
        out1.write((char*)&a, sizeof(a));
        out1.close();

    }


    void read_tt(int p) {
        int i = p - 1;
        if (p < 1) throw MyException();
        string line, line1;
        ifstream in("file.txt");
        if (in.is_open()) {
            while (getline(in, line)) {
                cout << line << endl;
            }
        }
        in.close();

        cout << endl;

        ifstream in5("file.txt");
        if (in5.is_open()) {
            do {
                for (int c = 0; c < i; c++) {
                    getline(in5, line1);
                }
                i--;
                getline(in5, line1);
                cout << line1 << endl;
                if (i == -1) break;
                in5.seekg(0, ios::beg);
            } while (1);
        }
        in5.close();



    }

    void read_bb(Student a, int p) {
        if (p < 1) throw MyException();
        int i = 1;
        ifstream in1("file1.bin", ios::in | ios::binary);
           while (in1.read((char*)&a, sizeof(a)))
           cout << "Group: " << a.group << " Name: " << a.name << " Rate: " << a.rate << endl;
        in1.close();
        cout << endl;
        
        ifstream in3("file1.bin", ios::in | ios::binary);
        do {
            in3.seekg((p - i) * sizeof(a), ios::beg);
            in3.read((char*)&a, sizeof(a));
            cout << "Group: " << a.group << " Name: " << a.name << " Rate: " << a.rate << endl;
            i++;
        } while (p >= i);
        in3.close();
    }

    void write_tb(Student a, int p) {
        if (p < 1) throw MyException();

            ofstream out2("file2.txt", ios::binary | ios::out);
            out2.seekp(0, ios::end);
            out2.write((char*)&a, sizeof(a));
            out2.close();
        

    }

    void read_tb(Student a, int p) {
        int i = 1;
        if (p < 1) throw MyException();
        ifstream in2("file2.txt", ios::in | ios::binary);
        while (in2.read((char*)&a, sizeof(a)))
            cout << "Group: " << a.group << " Name: " << a.name << " Rate: " << a.rate << endl;
        in2.close();

        cout << endl;

        ifstream in4("file2.txt", ios::in | ios::binary);
        do {
            in4.seekg((p - i) * sizeof(a), ios::beg);
            in4.read((char*)&a, sizeof(a));
            cout << "Group: " << a.group << " Name: " << a.name << " Rate: " << a.rate << endl;
            i++;
        } while (p >= i);
        in4.close();
    }

    int del(Student* arr, int p) {  
        int count = 0;
        bool flag = false;
        int n;
        cout << "Enter rate to delete: ";
        while (!scanf("%d", &n)) {
            cout << "Error!\n";
            rewind(stdin);
        }
        flag = false;
        for (int c = 0; c < p; c++) {
            if (arr[c].rate == n) {
                count++;
                cout << "\nStudent " << arr[c].name << ", rate = " << n;
                flag = true;
               
                    for (int i = c; i < p - 1; i++) {
                        arr[i] = arr[i + 1];
                    }
               
                p--;
                c--;
                

                
            }

        }
        ofstream out("file.txt"); out << "";
        for (int i = 0; i < p; i++) {
            arr[i].t = false;
            arr[i].write_tt(p);
        }
        if (flag == false) cout << "\nNo matches found ";
        return count;
    }

    void sort(Student a[], Student b, int ch, int num) {
        for (int i = 0; i < num; i++)
            a[i].t = false;
 

        int k;
        cout << "1 - Ub, 2 - Vozr\n";
        cin >> k;
        switch(k){
        case 1:
            switch (ch) {
            case 1:
                for (int i = 0; i < num - 1; i++) {
                    for (int j = num - 1; j > i; j--) {
                        if (strcmp(a[j - 1].name, a[j].name) < 0) {
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
                        if (strcmp(a[j - 1].group, a[j].group) < 0) {

                            b = a[j - 1];
                            a[j - 1] = a[j];
                            a[j] = b;

                        }
                    }
                }
                break;
            case 3:
                for (int i = 0; i < num - 1; i++) {
                    for (int j = num - 1; j > i; j--) {
                        if (a[j - 1].rate < a[j].rate)
                        {
                            b = a[j - 1];
                            a[j - 1] = a[j];
                            a[j] = b;
                        }
                    }
                }
                break;
            }
            break;
        case 2: 
            switch (ch) {
            case 1:
                for (int i = 0; i < num - 1; i++) {
                    for (int j = num - 1; j > i; j--) {
                        if (strcmp(a[j - 1].name, a[j].name) > 0) {
                            b = a[j];
                            a[j] = a[j - 1];
                            a[j - 1] = b;
                        }
                    }
                }
                write_tt(num);
                break;
            case 2:
                for (int i = 0; i < num - 1; i++) {
                    for (int j = num - 1; j > i; j--) {
                        if (strcmp(a[j - 1].group, a[j].group) > 0) {

                            b = a[j - 1];
                            a[j - 1] = a[j];
                            a[j] = b;

                        }
                    }
                }
                break;
            case 3:
                for (int i = 0; i < num - 1; i++) {
                    for (int j = num - 1; j > i; j--) {
                        if (a[j - 1].rate > a[j].rate)
                        {
                            b = a[j - 1];
                            a[j - 1] = a[j];
                            a[j] = b;
                        }
                    }
                }
                break;
            }
            break;
        }
        ofstream out("file.txt"); out << "";
        for (int i = 0; i < num; i++)
        a[i].write_tt(num);
    }
};



ostream& operator<<(ostream& out, const Student obj) {
    out << obj.name << obj.group << obj.rate << endl;
    return out;
}

istream& operator>>(istream& in, Student& obj) {
    in >> obj.name >> obj.group >> obj.rate;
    return in;
}


int main() {
    system("chcp 1251"); float rr; int fch;
    ofstream out("file.txt"); out << "";
    ofstream out1("file1.bin"); out1 << "";
    ofstream out2("file2.txt"); out2 << "";


    Student vvoid;
    int ch = 0;
    int n; int choice; int kol = 0; int chf; int dd;
    Student* arr = (Student*)malloc(0);
    do {
        cout << "\n1 - Add\n2 - Print\n3 - Find\n4 - Delete\n5 - File\n6 - Sort\n7 - Exit" << endl;
        while (!scanf("%d", &choice) || choice < 1 || choice > 7) {
            cout << "Error" << endl;
            rewind(stdin);
        }
        switch (choice) {
        case 1:
            try {
                cout << "enter rate ";
                rewind(stdin);
                cin >> rr;
                kol++;
                arr = (Student*)realloc(arr, (sizeof(Student) * kol));
                Student(arr[kol - 1].enter_r(rr), arr[kol - 1].enter_g(), arr[kol - 1].enter_n(), arr[kol - 1].en_t());
                arr[kol - 1].write_tt(kol);
            }
            catch (MyException p) {
                rewind(stdin);
                p.catch_rate();
                kol--;
                arr = (Student*)realloc(arr, (sizeof(Student) * kol));
            }
            break;
        case 2:
            try {
                arr[0].print(arr, kol);
            }
            catch (MyException p) {
                p.catch_null();
            }
            break;
        case 3:
            try {
                arr[0].find(arr, kol);
            }
            catch (MyException p) {
                p.catch_null();
            }
            break;
        case 4:
            try {
                dd = arr[0].del(arr, kol);
                for (int i = 0; i<dd; i++)
                kol--;
                arr = (Student*)realloc(arr, (sizeof(Student) * kol));

            }
            catch (MyException p) {
                p.catch_null();
                for (int i = 0; i < dd; i++)
                    kol++;
                arr = (Student*)realloc(arr, (sizeof(Student) * kol));
            }
            break;
        case 5:
            out1 << "";
            out2 << "";
            for (int i = 0; i < kol; i++) {
                arr[i].write_tb(arr[i], kol);
                arr[i].write_b(arr[i], kol);
            }          
            arr[0].read_bb(arr[0], kol);
            break;
        case 6:
            
            cout << "1 - Name, 2 - Group, 3 - Rate\n";
            cin >> ch;
            arr[0].sort(arr, vvoid, ch, kol);
	
		break;
	
        case 7:
            out.close();
            out2.close();
            out1.close();
            break;
        }
    } while (choice != 7);
    
    return 0;
}