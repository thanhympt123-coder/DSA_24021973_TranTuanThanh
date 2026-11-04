#include <iostream>
#include <queue>
using namespace std;
int main() {
priority_queue<int> pq;
int n, x;
cout << "Nhap so phan tu: ";
cin >> n;
cout << "Nhap cac phan tu: ";
for (int i = 0; i < n; i++) {
    cin >> x;
    pq.push(x);
}
cout << "Phan tu uu tien cao nhat: " << pq.top() << endl;
cout << "Cac phan tu theo thu tu uu tien: ";
while (!pq.empty()) {
    cout << pq.top() << " ";
    pq.pop();
}
return 0;
}
