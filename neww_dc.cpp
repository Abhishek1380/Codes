#include<iostream>
using namespace std;

void findMinMax(int A[], int start, int end, int &minVal, int &maxVal) {
    if (start == end) {
        minVal = maxVal = A[start];
        return;
    }

    if (end == start + 1) {
        if (A[start] < A[end]) {
            minVal = A[start];
            maxVal = A[end];
        } else {
            minVal = A[end];
            maxVal = A[start];
        }
        return;
    }

    int mid = (start + end) / 2;

    int leftMin, leftMax, rightMin, rightMax;
    findMinMax(A, start, mid, leftMin, leftMax);
    findMinMax(A, mid + 1, end, rightMin, rightMax);

    minVal = min(leftMin, rightMin);
    maxVal = max(leftMax, rightMax);
}

int main() {
    int A[] = {4, 5, 3, 2, 7, 6};
    int n = 6;

    int minVal, maxVal;
    findMinMax(A, 0, n - 1, minVal, maxVal);

    cout << "Minimum element: " << minVal << endl;
    cout << "Maximum element: " << maxVal << endl;

    return 0;
}
