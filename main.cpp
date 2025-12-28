#include <iostream>
using namespace std;

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

        int data[] = {10, 20, 30, 40, 50, 60, 70};
    int n = sizeof(data) / sizeof(data[0]);
    int key = 40;

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


