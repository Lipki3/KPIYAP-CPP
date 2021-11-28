#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <exception>


using namespace std;

class MyException : public exception {
public:
    void catch_null() {
        cout << "catching: Nothing in Array";
    }
    void catch_letters() {
        cout << "catching: letter(s)";
    }
    void catch_2() {
        cout << "catching: < 2 objects";
    }
};


class Array {
    friend void del(Array*, int);
private:
    int a[5]; 
public:
    Array() {  
        for (int i = 0; i < 5; i++) {
            a[i] = 0;
        }
    }
    Array(int* mas) {
        for (int l = 0; l < 5; l++)
            a[l] = mas[l];
   }
   
    int* enter() {
        cout << "Enter 5 numbers: " << endl;
        int q;
        cin.exceptions(cin.failbit);
        for (int i = 0; i < 5; i++) {
            try {
                cout << "Enter a[" << i << "] = ";
                cin >> a[i];

            }
            catch (const exception& ex) {
                cout << "Error!" << endl;
                cin.clear();
                cin.ignore(10, '\n');
                cout << "1 - continue, 2 - break: ";
                cin >> q;
                if(q==1)  i--;
                else {
                    rewind(stdin);
                   
                    i = -1;
                }
            }
        }
        return a;
    }
    void print(Array* arr, int p) {
        if (p < 1) throw MyException();
        for (int i = 0; i < p; i++) {
            cout << "\nArray " << i << ":  ";
            for (int j = 0; j < 5; j++) {
                cout << arr[i].a[j] << " ";
            }
        }
        
    }
    
            
    void find(Array* arr, int p) {
        if (p < 1) throw MyException();
        bool flag = false;
        int n;
        cout << "Enter number to find: ";
        while (!scanf("%d", &n)) {
            cout << "Error!\n";
            rewind(stdin);
        }
        for (int c = 0; c < p; c++) {
            flag = false;
            for (int i = 0; i < 5; i++) {
                if (arr[c].a[i] == n) {
                    cout << "\nArray " << c << " a[" << i << "] == " << n;
                    flag = true;
                }
            }
            if (flag == false) cout << "\nNo matches found in Array " << c;
        }
    }
    bool compare(Array aa, Array bb, int p) {
        if (p < 2) throw MyException();
        int sum_a = 0, sum_b = 0;
        for (int i = 0; i < 5; i++) {
            sum_a = sum_a + aa.a[i];
            sum_b = sum_b + bb.a[i];
        }
        return sum_a > sum_b;
    }
    void term(int p) {
        if (p > 5) throw MyException();
    }
    ~Array() {
    } 
};

void del(Array* arr, int p) {
    if (p < 1) throw MyException();
    int n;
    cout << "Enter number to delete: ";
    while (!scanf("%d", &n) || n > p-1) {
        cout << "Error!\n";
        rewind(stdin);
    }
    for (int i = n; i < p - 1; i++) {
        arr[i] = arr[i + 1];
    }
}

void termfunction() {
    cout << "My terminate function called." << endl;
    abort();
}

int main() {
    system("chcp 1251");
    int n; int choice; int kol = 0;
    Array* arr = (Array*)malloc(0);
    do {
        cout << "\n1 - Add\n2 - Print\n3 - Find\n4 - Delete\n5 - Compare 2 first\n6 - Exit" << endl;
        while (!scanf("%d", &choice) || choice < 1 || choice > 7) {
            cout << "Error" << endl;
            rewind(stdin);
        }
        switch (choice) {
        case 1:
            try {
                kol++;
                arr = (Array*)realloc(arr, (sizeof(Array) * kol));
                Array(arr[kol - 1].enter());
            }
            catch (MyException p) {
                rewind(stdin);
                p.catch_letters();
                kol--;
                arr = (Array*)realloc(arr, (sizeof(Array) * kol));
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
                del(arr, kol);
                kol--;
                arr = (Array*)realloc(arr, (sizeof(Array) * kol));

            }
            catch (MyException p) {
                p.catch_null();
                arr = (Array*)realloc(arr, (sizeof(Array) * kol));
            }
            break;
        case 5:
            try {
                cout << "Array 0 > Array 1: " << arr[0].compare(arr[0], arr[1], kol);
            }
            catch (MyException p) {
                p.catch_2();
            }
            break;

        case 6:
            break;

        case 7:
            try {
                arr[0].term(kol);
            }
            catch (MyException) {
                terminate_handler oldHandler = set_terminate(termfunction);
                terminate();
            }
            break;
        }
    } while (choice != 6);

    return 0;
}