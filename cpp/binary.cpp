#include <iostream>
#include <chrono>
#include <iomanip>
#include <string>
using namespace std;
using namespace std::chrono;

// ===============================
// Binary Search Iteratif
// ===============================
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

// ===============================
// Binary Search Rekursif
// ===============================
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

// ===============================
// MAIN
// ===============================
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int MAXN = 1000000;
    static long long data[MAXN];

    cout << fixed << setprecision(6);

    string mode;
    cin >> mode;

    // ===============================
    // MODE 1: SEARCH BIASA
    // ===============================
    if (mode == "search") {
        const int N = 100000;
        const int REPEAT = 500000;

        for (int i = 0; i < N; i++)
            data[i] = i + 1;

        long long target;
        cin >> target;

        int stepsIter = 0, stepsRec = 0;
        int idxIter = -1, idxRec = -1;

        auto start = high_resolution_clock::now();
        for (int i = 0; i < REPEAT; i++)
            idxIter = binarySearchIterative(data, N, target, stepsIter);
        auto end = high_resolution_clock::now();
        double timeIter = duration<double, milli>(end - start).count() / REPEAT;

        start = high_resolution_clock::now();
        for (int i = 0; i < REPEAT; i++)
            idxRec = binarySearchRecursive(data, 0, N - 1, target, stepsRec);
        end = high_resolution_clock::now();
        double timeRec = duration<double, milli>(end - start).count() / REPEAT;

        cout << "{";
        cout << "\"iterative\":{";
        cout << "\"index\":" << idxIter << ",";
        cout << "\"steps\":" << stepsIter << ",";
        cout << "\"time\":" << timeIter;
        cout << "},";
        cout << "\"recursive\":{";
        cout << "\"index\":" << idxRec << ",";
        cout << "\"steps\":" << stepsRec << ",";
        cout << "\"time\":" << timeRec;
        cout << "}";
        cout << "}";

    }
    // ===============================
    // MODE 2: BENCHMARK
    // ===============================
    else if (mode == "bench") {
        int sizes[] = {1000, 5000, 10000, 50000, 100000};
        int len = 5;
        const int REPEAT = 200000;

        cout << "{";
        cout << "\"sizes\":[";

        for (int i = 0; i < len; i++) {
            cout << sizes[i];
            if (i < len - 1) cout << ",";
        }
        cout << "],";

        cout << "\"iterative\":[";
        for (int i = 0; i < len; i++) {
            int N = sizes[i];
            for (int j = 0; j < N; j++)
                data[j] = j + 1;

            long long target = data[N - 1];
            int steps = 0, idx;

            auto start = high_resolution_clock::now();
            for (int r = 0; r < REPEAT; r++)
                idx = binarySearchIterative(data, N, target, steps);
            auto end = high_resolution_clock::now();
            double t = duration<double, milli>(end - start).count() / REPEAT;

            cout << t;
            if (i < len - 1) cout << ",";
        }
        cout << "],";

        cout << "\"recursive\":[";
        for (int i = 0; i < len; i++) {
            int N = sizes[i];
            for (int j = 0; j < N; j++)
                data[j] = j + 1;

            long long target = data[N - 1];
            int steps = 0, idx;

            auto start = high_resolution_clock::now();
            for (int r = 0; r < REPEAT; r++)
                idx = binarySearchRecursive(data, 0, N - 1, target, steps);
            auto end = high_resolution_clock::now();
            double t = duration<double, milli>(end - start).count() / REPEAT;

            cout << t;
            if (i < len - 1) cout << ",";
        }
        cout << "]";

        cout << "}";
    }

    return 0;
}
