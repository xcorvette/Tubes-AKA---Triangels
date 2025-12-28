#include <iostream>
using namespace std;

void generateData(int arr[], int n) {
    for (int i = 0; i < n; i++)
        arr[i] = (i + 1) * 2;
}

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
    const int N = 10000;
    int data[N];
    generateData(data, N);

    int target;
    cout << "Masukkan ID produk: ";
    cin >> target;

    int stepsI = 0, stepsR = 0;
    int idxI = binarySearchIterative(data, N, target, stepsI);
    int idxR = binarySearchRecursive(data, 0, N - 1, target, stepsR);

    cout << "\n=== HASIL ===\n";
    cout << "Iteratif  -> Index: " << idxI << ", Steps: " << stepsI << endl;
    cout << "Rekursif -> Index: " << idxR << ", Steps: " << stepsR << endl;

    return 0;
}
