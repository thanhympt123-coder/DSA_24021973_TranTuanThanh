#include <iostream>
using namespace std;
void merge(int a[], int left, int mid, int right) {
int b[100];
int i = left, j = mid + 1, k = 0;
while (i <= mid && j <= right) {
    if (a[i] < a[j])
        b[k++] = a[i++];
    else
        b[k++] = a[j++];
}
while (i <= mid)
    b[k++] = a[i++];

while (j <= right)
    b[k++] = a[j++];
for (int i = 0; i < k; i++) {
    a[left + i] = b[i];
}
}
void mergeSort(int a[], int left, int right) {
if (left >= right)
return;
int mid = (left + right) / 2;
mergeSort(a, left, mid);
mergeSort(a, mid + 1, right);
merge(a, left, mid, right);

}
int main() {
int n, a[100];
cout << "Nhap n: ";
cin >> n;
cout << "Nhap day so: ";
for (int i = 0; i < n; i++) {
    cin >> a[i];
}
mergeSort(a, 0, n - 1);
cout << "Day sau khi sap xep: ";
for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
}
return 0;
}
