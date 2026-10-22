#include <iostream>
#include <list>
using namespace std;

class Stack {
private:
    list<int> L;

public:
    // Kiem tra Stack rong
    bool isEmpty() {
        return L.empty();
    }

    // Them phan tu vao dinh Stack
    void push(int x) {
        L.push_front(x);
    }

    // Xoa phan tu o dinh Stack
    void pop() {
        if (L.empty()) {
            cout << "Stack rong!\n";
            return;
        }

        L.pop_front();
    }

    // Lay gia tri dinh Stack
    int top() {
        if (L.empty()) {
            cout << "Stack rong!\n";
            return -1;
        }

        return L.front();
    }

    // Dem so phan tu
    int size() {
        return L.size();
    }

    // In Stack tu dinh xuong day
    void display() {
        cout << "TOP -> ";

        for (int x : L) {
            cout << x << " -> ";
        }

        cout << "NULL\n";
    }
};

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    s.display();

    cout << "Phan tu dinh: " << s.top() << endl;
    cout << "So phan tu: " << s.size() << endl;

    s.pop();

    cout << "Sau khi pop:\n";
    s.display();

    return 0;
}
