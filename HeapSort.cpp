#include <iostream>
#include <vector>
using namespace std;
void heapify(vector<int>& a, int idx, int max) {
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    int largest = idx;
    if (left < max && a[left] > a[idx]) {
        largest = left;
    }
    if (right < max && a[right] > a[largest]) {
        largest = right;
    }
    if (largest != idx) {
        swap(a[largest], a[idx]);
        heapify(a, largest, max);
    }
}

void buildHeap(vector<int>& a) {
    int n = a.size();
    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(a, i, n);
    }
}

void heapSort(vector<int>& a) {
    buildHeap(a);
    int n = a.size();
    for (int i = n - 1; i >= 1; --i) {
        swap(a[0], a[i]);
        heapify(a, 0, i);
    }
}

int main() {
    vector<int> a = { 4, 3, 6, 8, 7, 10, 3, 2, 11, 16, 15 };
    heapSort(a);
    for (int i : a) { cout << i << " "; }
    cout << "\n";
    return 0;
}
