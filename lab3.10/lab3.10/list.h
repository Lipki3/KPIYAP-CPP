#pragma once
#include <iostream>
#include <cassert>
#include <string>


// удаление комбинации или одиночного числа на выбор
// переброс дубликатов на место куда захочет пользователь


using namespace std;

class MyException : public exception {
public:
    void catch_null() {
        cout << "catching: Nothing in list\n";
    }
    void catch_letters() {
        cout << "catching: letter(s)\n";
    }
    void catch_2() {
        cout << "catching 2 same objects\n";
    }
};

template <class T>
class D_List {
private:
    class List {
    public:
        List* r;
        List* l;
        T val;
        List(T value) : val(value) { }
        List() {}
        ~List() {}
        void print_val() { cout << val << " "; }
    };
public:
    class iterator {
    private:
        friend class D_List<T>;
        List* the_node;
    public:
        iterator() : the_node(0) { }
        iterator(List* dn) : the_node(dn) { }
        iterator(const iterator& it) : the_node(it.the_node) { }

        iterator& operator=(const iterator& it) {
            the_node = it.the_node;
            return *this;
        }

        bool operator==(const iterator& it) const {
            return (the_node == it.the_node);
        }

        bool operator!=(const iterator& it) const {
            return !(it == *this);
        }

        iterator& operator++() {
            if (the_node == 0)
                throw "incremented an empty iterator";
            if (the_node->r == 0)
                throw "tried to increment too far past the end";
            the_node = the_node->r;
            return *this;
        }

        iterator& operator--() {
            if (the_node == 0)
                throw "decremented an empty iterator";
            if (the_node->l == 0)
                throw "tried to decrement past the beginning";
            the_node = the_node->l;
            return *this;
        }

        T& operator*() const {
            if (the_node == 0)
                throw "tried to dereference an empty iterator";
            return the_node->val;
        }
    };

private:
    List* head;
    List* tail;
    D_List& operator=(const D_List&);
    D_List(const D_List&);
    iterator head_iterator;
    iterator tail_iterator;
public:
    D_List() {
        head = tail = new List;
        tail->r = 0;
        tail->l = 0;
        head_iterator = iterator(head);
        tail_iterator = iterator(tail);
    }
    // конструктор  (создание списка, содержащего один элемент)
    D_List(T node_val) {
        head = tail = new List;
        tail->r = 0;
        tail->l = 0;
        head_iterator = iterator(head);
        tail_iterator = iterator(tail);
        add_front(node_val);
    }
    //  деструктор
    ~D_List() {
        List* node_to_delete = head;
        for (List* sn = head; sn != tail;) {
            sn = sn->r;
            delete node_to_delete;
            node_to_delete = sn;
        }
        delete node_to_delete;
    }

    bool is_empty() { return head == tail; }
    iterator front() { return head_iterator; }
    iterator rear() { return tail_iterator; }

    void add(T node_val) {
        List* node_to_add = new List(node_val);
        node_to_add->r = head;
        node_to_add->l = 0;
        head->l = node_to_add;
        head = node_to_add;
        head_iterator = iterator(head);
    }

    void add_t(T node_val, int pos, int sz) {
        List* dn = tail;
        List* s2 = new List(node_val);
        if (pos < sz) {
            for (int i = 0; i < pos; i++) dn = dn->l;
            s2->l = dn->l;
            dn->l->r = s2;
            s2->r = dn;
            dn->l = s2;
            s2->val = node_val;
            head_iterator = iterator(head);
            tail_iterator = iterator(tail);
        }

        if (pos == sz) {
            add(node_val);
        }
    }


    bool del(iterator key_i) {

        for (List* dn = head; dn != tail; dn = dn->r) {

            if (dn == key_i.the_node) {

                if (dn->l == nullptr) {
                    dn = head;
                    head = head->r;
                    head->l = nullptr;
                    delete dn;
                    key_i.the_node = 0;
                    head_iterator = iterator(head);
                    return true;
                }
                else {
                    dn->l->r = dn->r;
                    dn->r->l = dn->l;

                    delete dn;


                    key_i.the_node = 0;
                    return true;
                }
            }
        }
        return false;
    }


    iterator find(T node_val) const {
        int a;
        a = size();
        if (a == 0) throw MyException();
        List* dn = head;

        for (List* dn = head; dn != tail; dn = dn->r)
            if (dn->val == node_val) return iterator(dn);

        return tail_iterator;
    }

    bool find2(int value, int* ms, int sz) {
        int a; bool flag_ok = true; bool flag_find = false; bool ok = false;
        a = size();

        if (a == 0) throw MyException();
        List* dn = tail; List* dn1 = dn;
        for (List* dn = tail; dn != head; dn = dn->l) {
            if (dn->val == value) {
                dn1 = dn;
                flag_find = true;
                for (int i = 0; i < sz - 1; i++) {
                    if (dn1->l != nullptr) {
                        dn1 = dn1->l;
                        if (dn1->val != ms[i + 1]) ok = false;

                    }
                    if (dn1->l == nullptr && (i + 1) != sz)  ok = false;
                    if (dn1->l == nullptr && (i + 1) == sz) {
                        dn1 = head->r;
                        if (dn1->val != ms[sz - 1] || i != sz - 1)  ok = false;
                        if (dn1->val == ms[sz - 1] && i == sz - 1) {
                            ok = true;
                            return ok;
                        }
                    }
                }
            }
        }

        if (flag_find == true && flag_ok == true) {
            cout << "\nCombination was found\n";
            ok = true;
            return ok;
        }

        cout << "\nCombination not found\n";
        return ok;
    }

    bool find1(T node_val) const {
        List* dn = head; int count = 0; int size = 0;
        for (List* dn = head; dn != tail; dn = dn->r, size++) {}
        bool finder = false;
        for (List* dn = head; dn != tail; dn = dn->r, count++)
            if (dn->val == node_val) {
                cout << "obj " << size - count - 1 << ": " << dn->val << endl;
                finder = true;
            }
        if (finder == false)
            // cout << "No matches found\n";
            return finder;
    }



    int size() const {
        int count = 0;
        for (List* dn = head; dn != tail; dn = dn->r) ++count;
        return count;
    }

    void print() const {
        int a;
        a = size();
        if (a == 0) throw MyException();
        for (List* dn = head; dn != tail; dn = dn->r)
            dn->print_val();
        cout << endl;
    }

};

