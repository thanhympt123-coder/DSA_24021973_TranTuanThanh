#include <iostream>
using namespace std;
void quickSort(int a[], int left, int right) {
int i = left, j = right;
int pivot = a[(left + right) / 2];
while (i <= j) {
    while (a[i] < pivot) i++;
    while (a[j] > pivot) j--;
    if (i <= j) {
        swap(a[i], a[j]);
        i++;
        j--;
    }
}
if (left < j)
    quickSort(a, left, j);
if (i < right)
    quickSort(a, i, right);
}
int main() {
int n, a[100];
cout << "Nhap n: ";
cin >> n;
cout << "Nhap day so: ";
for (int i = 0; i < n; i++) {
    cin >> a[i];
}
quickSort(a, 0, n - 1);
cout << "Day sau khi sap xep: ";
for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
}
return 0;

}
