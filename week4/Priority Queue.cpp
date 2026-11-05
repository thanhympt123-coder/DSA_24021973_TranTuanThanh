#include <iostream>
using namespace std;
class PriorityQueue {
private:
    int a[100];
    int n;
public:
    PriorityQueue() {
        n = 0;
    }
    // Them phan tu
    void push(int x) {
        int i = n;
        a[n++] = x;
        // Dua phan tu len dung vi tri
        while (i > 0 && a[i] > a[(i - 1) / 2]) {
            swap(a[i], a[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }
    // Lay phan tu lon nhat
    int pop() {
        if (n == 0) {
            cout << "Queue rong!";
            return -1;
        }
        int maxValue = a[0];
        a[0] = a[n - 1];
        n--;
        // Dieu chinh lai Max Heap
        int i = 0;
        while (2 * i + 1 < n) {
            int largest = 2 * i + 1;
            int right = 2 * i + 2;
            if (right < n && a[right] > a[largest])
                largest = right;
            if (a[i] >= a[largest])
                break;
            swap(a[i], a[largest]);
            i = largest;
        }
        return maxValue;
    }
    // Xem phan tu uu tien cao nhat
    int top() {
        if (n == 0) return -1;
        return a[0];
    }
    // Kiem tra rong
    bool empty() {
        return n == 0;
    }
};
int main() {
    PriorityQueue pq;
    pq.push(30);
    pq.push(10);
    pq.push(50);
    pq.push(20);
    pq.push(40);
    cout << "Phan tu uu tien cao nhat: " << pq.top() << endl;
    cout << "Lay cac phan tu: ";
    while (!pq.empty()) {
        cout << pq.pop() << " ";
    }
    return 0;
}
