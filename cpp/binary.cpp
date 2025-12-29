#include <iostream>
#include <chrono>
#include <iomanip>
#include <vector>
using namespace std;
using namespace std::chrono;

int binarySearchIterative(const vector<long long>& arr, long long target, int &steps) {
    int left = 0, right = arr.size() - 1;
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

int binarySearchRecursive(const vector<long long>& arr, int left, int right, long long target, int &steps) {
    steps++;
    if (left > right) return -1;
    int mid = left + (right - left) / 2;
    if (arr[mid] == target) return mid;
    else if (arr[mid] < target)
        return binarySearchRecursive(arr, mid + 1, right, target, steps);
    else
        return binarySearchRecursive(arr, left, mid - 1, target, steps);
}

double testIter(int N) {
    vector<long long> data(N);
    for (int i = 0; i < N; i++) data[i] = i + 1;
    int steps = 0;
    auto start = high_resolution_clock::now();
    binarySearchIterative(data, N, steps);
    auto end = high_resolution_clock::now();
    return duration<double, milli>(end - start).count();
}

double testRec(int N) {
    vector<long long> data(N);
    for (int i = 0; i < N; i++) data[i] = i + 1;
    int steps = 0;
    auto start = high_resolution_clock::now();
    binarySearchRecursive(data, 0, N - 1, N, steps);
    auto end = high_resolution_clock::now();
    return duration<double, milli>(end - start).count();
}

int main() {
    long long target;
    cin >> target;

    cout << fixed << setprecision(6);

if (target == -1) {
    vector<int> sizes = {1000, 5000, 10000, 50000, 100000};

    cout << "[";
    for (int i = 0; i < sizes.size(); i++) {
        int N = sizes[i];
        cout << "{"
             << "\"n\":" << N << ","
             << "\"iterative\":" << testIter(N) << ","
             << "\"recursive\":" << testRec(N)
             << "}";
        if (i != sizes.size() - 1) cout << ",";
    }
    cout << "]\n";
    return 0;
}


    // Mode search biasa
    const int N = 100000;
    vector<long long> data(N);
    for (int i = 0; i < N; i++) data[i] = i + 1;

    int stepsIter = 0, stepsRec = 0;

    auto start = high_resolution_clock::now();
    int idxIter = binarySearchIterative(data, target, stepsIter);
    auto end = high_resolution_clock::now();
    double timeIter = duration<double, milli>(end - start).count();

    start = high_resolution_clock::now();
    int idxRec = binarySearchRecursive(data, 0, N - 1, target, stepsRec);
    end = high_resolution_clock::now();
    double timeRec = duration<double, milli>(end - start).count();

    cout << "{";
    cout << "\"iterative\":{"
         << "\"index\":" << idxIter << ","
         << "\"steps\":" << stepsIter << ","
         << "\"time\":" << timeIter << "},";
    cout << "\"recursive\":{"
         << "\"index\":" << idxRec << ","
         << "\"steps\":" << stepsRec << ","
         << "\"time\":" << timeRec << "}";
    cout << "}\n";

    return 0;
}
