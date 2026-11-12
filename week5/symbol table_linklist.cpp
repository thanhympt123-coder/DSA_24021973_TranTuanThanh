#include <iostream>
using namespace std;

struct Node {
    string key;
    int value;
    Node* next;
};

class SymbolTable {
private:
    Node* head;

public:
    SymbolTable() {
        head = NULL;
    }

    // Them phan tu
    void insert(string key, int value) {
        Node* p = head;

        while (p != NULL) {
            if (p->key == key) {
                p->value = value;
                return;
            }
            p = p->next;
        }

        Node* newNode = new Node;
        newNode->key = key;
        newNode->value = value;
        newNode->next = head;
        head = newNode;
    }

    // Tim kiem
    void search(string key) {
        Node* p = head;

        while (p != NULL) {
            if (p->key == key) {
                cout << "Tim thay: " << p->value << endl;
                return;
            }
            p = p->next;
        }

        cout << "Khong tim thay!" << endl;
    }

    // Xoa phan tu
    void remove(string key) {
        Node* p = head;
        Node* prev = NULL;

        while (p != NULL) {
            if (p->key == key) {
                if (prev == NULL)
                    head = p->next;
                else
                    prev->next = p->next;

                delete p;
                return;
            }

            prev = p;
            p = p->next;
        }
    }

    // Hien thi
    void display() {
        Node* p = head;

        while (p != NULL) {
            cout << p->key << " : " << p->value << endl;
            p = p->next;
        }
    }

    ~SymbolTable() {
        while (head != NULL) {
            Node* p = head;
            head = head->next;
            delete p;
        }
    }
};

int main() {
    SymbolTable st;

    st.insert("a", 10);
    st.insert("b", 20);
    st.insert("c", 30);

    cout << "Symbol Table:" << endl;
    st.display();

    cout << "\nTim kiem b:" << endl;
    st.search("b");

    cout << "\nXoa b:" << endl;
    st.remove("b");
    st.display();

    return 0;
}
