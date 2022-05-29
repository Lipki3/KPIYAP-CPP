#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm> 
using namespace std;

// добавление строки 
// удаление дубликатов
// поиск комбинаций

int main()
{
    char comb[10];
    vector<string> str1, str2;
    int len;
    char symbol = 'a';
    string st1[30];
    int c[50] = { 0 };
    int cmb[50] = { 0 };
    ofstream out("file1.txt");
    ofstream out9("file1.txt", ios::app);
    out << "first string str stringstr \nsecond string stringstr\nthird stringstr";
    out.close();
    ifstream in;
    in.open("file1.txt");
    if (in.is_open()) {
        cout << "file1.txt is open\n";
        int i = 0;
        while (!in.eof()) {
            getline(in, st1[i]);
            i++;
        }

    }
    else
    {
        cout << "Error";
    }
    in.close();
    int kol = 3;
    for (int j = 0; j < kol; j++)
        str1.push_back(st1[j]);
    int choice = 0; bool flag;

    ofstream out3("result_symb.txt");
    ofstream out4("result_comb.txt");
    ofstream out5("result_symb.txt");
    ofstream out6("result_comb.txt");
    out3 << ""; out4 << "";

    do {
        cout << "1 - Print all, 2 - Add new, 3 - Find symbol, 4 - Find combination, 5 - Delete dublicats, 9 - Exit\n";
        cin >> choice;
        switch (choice) {
        case 1:
            for (int i = 0; i < kol; i++) {
                for (string::iterator it = st1[i].begin(); it != st1[i].end(); ++it)
                {
                    cout << *it;
                }
                cout << endl;
            }
            break;
        case 2:
            kol++;
            cout << "\nEnter string: ";
            rewind(stdin);
            getline(cin, st1[kol - 1]);
            str1.push_back(st1[kol - 1]);
            out9 << endl;
            out9 << st1[kol - 1];
            break;
        case 3:
            cout << "\nEnter symbol to find: ";
            cin >> symbol;
            for (int i = 0; i < kol; i++) {
                c[i] = 0;
            }
            for (int i = 0; i < kol; i++) {
                for (int j = 0; j < st1[i].size(); j++) {
                    if (st1[i][j] == symbol) c[i]++;
                }
            }
            for (int i = 0; i < kol; i++) {
                cout << "\n" << c[i] << " matches found in " << i << " string.";
            }
            cout << endl;
            if (out5.is_open()) {
                out5 << "\nSYMBOL '" << symbol;
                for (int i = 0; i < kol; i++) {
                    out5 << "\n" << c[i] << " matches found in " << i << " string.";
                }
            }
            break;
        case 4:
            cout << "\nEnter combination to find: ";
            rewind(stdin);
            cin.getline(comb, 10);
            cout << "\nYour combination: " << comb << endl;
            len = strlen(comb);
            for (int i = 0; i < kol; i++) {
                cmb[i] = 0;
            }

            for (int i = 0; i < kol; i++) {

                for (int j = 0; j < st1[i].size(); j++) {
                    if (st1[i][j] == comb[0]) {
                        flag = true;
                        for (int k = 0; k < len; k++) {
                            if (st1[i][j + k] != comb[k]) {
                                flag = false;
                                break;
                            }
                            if (k == len - 1 && flag == true) cmb[i]++;
                        }
                    }
                }
            }
            for (int i = 0; i < kol; i++) {
                cout << "\n" << cmb[i] << " matches found in " << i << " string.";
            }
            if (out6.is_open()) {
                out6 << "\nCOMBINATION '" << comb << "'";
                for (int i = 0; i < kol; i++) {
                    out6 << "\n" << cmb[i] << " matches found in " << i << " string.";
                }
            }
            cout << endl;
            break;
        case 5:
            for (int i = 0; i < kol - 1; i++) {
                for (int j = kol - 1; j > i; j--) {
                    flag = true;
                    if (st1[i].size() == st1[j].size()) {
                        for (int k = 0; k < st1[i].size(); k++) {
                            if (st1[i][k] != st1[j][k]) {
                                flag = false;
                                break;
                            }
                            if (k == (st1[i].size() - 1) && flag == true) {
                                cout << "FIND\n";
                                for (int p = i; p < kol - 1; p++) {

                                    st1[p] = st1[p + 1];

                                }

                                kol--;
                                i--;

                            }
                        }
                    }
                }
            }
            break;
        case 9:
          //  out3.close();
            //out4.close();
            break;
        }

    } while (choice != 9);


}