#include <iostream>
using namespace std;

class SymbolTable {
private:
    string key[100];
    int value[100];
    int n;

public:
    SymbolTable() {
        n = 0;
    }

    // Them phan tu
    void insert(string k, int v) {
        for (int i = 0; i < n; i++) {
            if (key[i] == k) {
                value[i] = v;
                return;
            }
        }

        if (n < 100) {
            key[n] = k;
            value[n] = v;
            n++;
        }
    }

    // Tim kiem
    void search(string k) {
        for (int i = 0; i < n; i++) {
            if (key[i] == k) {
                cout << "Tim thay: " << value[i] << endl;
                return;
            }
        }

        cout << "Khong tim thay!" << endl;
    }

    // Xoa phan tu
    void remove(string k) {
        for (int i = 0; i < n; i++) {
            if (key[i] == k) {
                for (int j = i; j < n - 1; j++) {
                    key[j] = key[j + 1];
                    value[j] = value[j + 1];
                }

                n--;
                return;
            }
        }
    }

    // Hien thi
    void display() {
        for (int i = 0; i < n; i++) {
            cout << key[i] << " : " << value[i] << endl;
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
