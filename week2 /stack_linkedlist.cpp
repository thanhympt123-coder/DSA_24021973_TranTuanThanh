#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* topNode;
    int count;

public:
    // Khoi tao Stack rong
    Stack() {
        topNode = nullptr;
        count = 0;
    }

    // Huy Stack, giai phong bo nho
    ~Stack() {
        while (topNode != nullptr) {
            Node* temp = topNode;
            topNode = topNode->next;
            delete temp;
        }
    }

    // Kiem tra Stack rong
    bool isEmpty() {
        return topNode == nullptr;
    }

    // Them phan tu vao dinh Stack
    void push(int x) {
        Node* p = new Node;
        p->data = x;
        p->next = topNode;

        topNode = p;
        count++;
    }

    // Xoa phan tu o dinh Stack
    void pop() {
        if (isEmpty()) {
            cout << "Stack rong!\n";
            return;
        }

        Node* temp = topNode;
        topNode = topNode->next;

        delete temp;
        count--;
    }

    // Lay gia tri dinh Stack
    int top() {
        if (isEmpty()) {
            cout << "Stack rong!\n";
            return -1;
        }

        return topNode->data;
    }

    // Dem so phan tu
    int size() {
        return count;
    }

    // In Stack tu dinh xuong day
    void display() {
        Node* p = topNode;

        cout << "TOP -> ";
        while (p != nullptr) {
            cout << p->data << " -> ";
            p = p->next;
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

