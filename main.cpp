#include <iostream>
#include <ctime>
using namespace std;

int binarySearchIterative(int arr[], int n, int target, int &steps) {
    int left = 0, right = n - 1;
    steps = 0;
    while (left <= right) {
        steps++;
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int binarySearchRecursive(int arr[], int left, int right, int target, int &steps) {
    steps++;
    if (left > right) return -1;
    int mid = left + (right - left) / 2;
    if (arr[mid] == target) return mid;
    else if (arr[mid] < target)
        return binarySearchRecursive(arr, mid + 1, right, target, steps);
    else
        return binarySearchRecursive(arr, left, mid - 1, target, steps);
}

int main() {
    int n = 10000;
    int data[10000];
    for (int i = 0; i < n; i++) data[i] = (i + 1) * 2;

    int target;
    cout << "Masukkan ID Produk: ";
    cin >> target;

    int stepsIter = 0, stepsRec = 0;

    clock_t start = clock();
    int idxIter = binarySearchIterative(data, n, target, stepsIter);
    clock_t end = clock();
    double timeIter = double(end - start) / CLOCKS_PER_SEC * 1000;

    start = clock();
    int idxRec = binarySearchRecursive(data, 0, n - 1, target, stepsRec);
    end = clock();
    double timeRec = double(end - start) / CLOCKS_PER_SEC * 1000;

    cout << "\n--- HASIL ---\n";
    cout << "Iteratif : Index = " << idxIter << ", Steps = " << stepsIter
         << ", Waktu = " << timeIter << " ms\n";
    cout << "Rekursif : Index = " << idxRec << ", Steps = " << stepsRec
         << ", Waktu = " << timeRec << " ms\n";

    return 0;
}
