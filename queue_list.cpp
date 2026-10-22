
#include <iostream>
#include <list>
using namespace std;

class Queue {
private:
    list<int> L;

public:
    bool isEmpty() {
        return L.empty();
    }

    void enqueue(int x) {
        L.push_back(x);
    }

    void dequeue() {
        if (L.empty()) {
            cout << "Queue rong!\n";
            return;
        }

        L.pop_front();
    }

    int front() {
        if (L.empty()) {
            cout << "Queue rong!\n";
            return -1;
        }

        return L.front();
    }

    int size() {
        return L.size();
    }

    void display() {
        for (int x : L) {
            cout << x << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();

    cout << q.front() << endl;
    cout << q.size() << endl;

    q.dequeue();
    q.display();

    return 0;
}


