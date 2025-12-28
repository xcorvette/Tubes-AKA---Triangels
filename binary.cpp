#include <iostream>
#include <ctime>
using namespace std;

// Binary Search Iteratif
int binarySearchIterative(long long arr[], int n, long long target, int &steps) {
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

// Binary Search Rekursif
int binarySearchRecursive(long long arr[], int left, int right, long long target, int &steps) {
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
    const int n = 100000; // ukuran data dummy
    static long long data[n];

    // Dummy ID produk: 1, 2, 3, ..., n
    for (int i = 0; i < n; i++) {
        data[i] = i + 1;
    }

    long long target;
    cin >> target; // input dari web / user

    int stepsIter = 0, stepsRec = 0;

    clock_t start = clock();
    int idxIter = binarySearchIterative(data, n, target, stepsIter);
    clock_t end = clock();
    double timeIter = double(end - start) / CLOCKS_PER_SEC * 1000;

    start = clock();
    int idxRec = binarySearchRecursive(data, 0, n - 1, target, stepsRec);
    end = clock();
    double timeRec = double(end - start) / CLOCKS_PER_SEC * 1000;

    // Output JSON
    cout << "{\n";
    cout << "  \"iterative\": {\n";
    cout << "    \"index\": " << idxIter << ",\n";
    cout << "    \"steps\": " << stepsIter << ",\n";
    cout << "    \"time\": " << tim
