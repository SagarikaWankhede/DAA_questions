#include <iostream>
using namespace std;

void sortArray(int A[], int N) {
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (A[j] > A[j + 1]) {
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}
int maxGoodSubsequence(int A[], int N) {
    sortArray(A, N);

    int maxLen = 1;

    for (int i = 0; i < N; i++) {
        int count = 1;
        for (int j = i + 1; j < N; j++) {
            if (A[j] - A[i] <= 10) {
                count++;
            } else {
                break;
            }
        }

        if (count > maxLen)
            maxLen = count;
    }

    return maxLen;
}

int main() {
    int N;
    cout << "Enter N: ";
    cin >> N;

    int A[1000];
    cout << "Enter array elements:\n";

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int result = maxGoodSubsequence(A, N);

    cout << "Maximum length of good subsequence = " << result;

    return 0;
}
