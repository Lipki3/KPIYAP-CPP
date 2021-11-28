#define _CRT_SECURE_NO_WARNINGS
#include "list.h"
#include <stdio.h>


D_List <int> obj;
int main() {
    char str[50]; char buf[50]; int ms[10]; int mm = 0; int ii = 0; bool ok = true; int chch; int ms_size = 0; int pos;
    int choice = 0; int dl;  bool pp = false; bool ok1 = true;
    int ret = 0; int val;
    D_List<int>::iterator list_iter;
    do {
        cout << "\n1- Add, 2 - Print, 3 - Find, 4 - Delete, 5 - Exit\n";
        cin >> choice;
        switch (choice) {
        case 1:
            int j, a;
            a = obj.size();
            cout << "Enter j: ";
            cin >> j;
            try {
                if (obj.size() > 0) pp = obj.find1(j);
                if (pp == false)
                    obj.add(j);
                if (pp == true) {
                    cout << "\nj was found. Enter position to paste (0 - " << a << ") : ";
                    while (!scanf("%d", &pos) || pos < 0 || pos > a) {
                        rewind(stdin);
                        cout << "\nEnter position to paste (0 - " << a << ") : ";
                    }
                    obj.add_t(j, pos, a);

                }
            }
            catch (MyException p) {
               // p.catch_2();
            }
            break;
        case 2:
            try {
                cout << "Size: ";
                cout << obj.size() << endl;
                cout << "List: ";
                for (list_iter = obj.rear(); list_iter != obj.front(); ) {
                    --list_iter;
                    cout << *list_iter << " ";
                }

            }
            catch (MyException p) {
                p.catch_null();
            }
            break;
        case 3:
            try {
                cout << "Enter j: ";
                cin >> j;
                obj.find1(j);
            }
            catch (MyException p) {
                p.catch_null();
            }
            break;
        case 4:
            try {
                cout << "1 - Delete one, 2 - Delete combination" << endl;
                while (!scanf("%d", &chch) || chch < 1 || chch > 2) {
                    rewind(stdin);
                    cout << "\n1 - Delete one, 2 - Delete combination" << endl;
                }
                switch (chch) {
                case 1:
                    cout << "Enter j: ";
                    cin >> j;
                    obj.del(obj.find(j));
                    break;
                case 2:
                    ok1 = true;
                    ms_size = 0;
                    cout << "Enter combination: ";
                    rewind(stdin);
                    gets_s(str);
                    ii = 0;
                    dl = strlen(str);
                    buf[0] = '\0';
                    for (int i = 0; i < strlen(str) + 1; i++) {
                        if (str[i] == ' ' || str[i] == '\0') {
                            if (ok == false) {
                                mm = 0;
                                ok = true;
                            }
                            if (ok == true) {
                                mm = 0;
                                ok = true;
                                ms[ii] = atoi(buf);
                                ms_size++;
                                ii++;
                            }
                        }
                        else {
                            if (str[i] > 47 && str[i] < 58 && ok == true) {
                                buf[mm] = str[i];
                                buf[mm + 1] = '\0';
                                mm++;
                            }
                            else {
                                ok = false;
                                ok1 = false;
                            }
                        }

                    }
                    
                    if (ok1 == true) {
                        ok = obj.find2(ms[0], ms, ms_size);
                        for (int i = 0; i < ms_size; i++) {
                            obj.del(obj.find(ms[i]));
                        }
                    }
                    break;
                }




            }
            catch (MyException p) {
                p.catch_null();
            }
            break;
        case 5: break;
        }
    } while (choice != 5);

    return 0;

}