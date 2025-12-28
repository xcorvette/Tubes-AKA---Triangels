#include <iostream>
using namespace std;

// Binary Search Iteratif
int binarySearchIterative(int arr[], int n, int target, int &steps) {
    int left = 0, right = n - 1;
    steps = 0;

    while (left <= right) {
        steps++;
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

// Binary Search Rekursif
int binarySearchRecursive(int arr[], int left, int right, int target, int &steps) {
    steps++;
    if (left > right)
        return -1;

    int mid = left + (right - left) / 2;

    if (arr[mid] == target)
        return mid;
    else if (arr[mid] < target)
        return binarySearchRecursive(arr, mid + 1, right, target, steps);
    else
        return binarySearchRecursive(arr, left, mid - 1, target, steps);
}

int main() {
    // Data dummy ID produk e-commerce (terurut)
    int data[] = {101, 203, 305, 412, 550, 678, 789, 890, 945, 1001};
    int n = sizeof(data) / sizeof(data[0]);

    int target;
    cout << "Masukkan ID Produk: ";
    cin >> target;

    int stepsIter = 0, stepsRec = 0;

    int idxIter = binarySearchIterative(data, n, target, stepsIter);
    int idxRec  = binarySearchRecursive(data, 0, n - 1, target, stepsRec);

    cout << "\n=== Hasil Pencarian ===\n";

    if (idxIter != -1)
        cout << "Iteratif -> Index: " << idxIter
             << ", Langkah: " << stepsIter << endl;
    else
        cout << "Iteratif -> Data tidak ditemukan, Langkah: " << stepsIter << endl;

    if (idxRec != -1)
        cout << "Rekursif -> Index: " << idxRec
             << ", Langkah: " << stepsRec << endl;
    else
        cout << "Rekursif -> Data tidak ditemukan, Langkah: " << stepsRec << endl;

    return 0;
}
