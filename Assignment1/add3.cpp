#include <iostream>
using namespace std;
int main() {
    int N;
    cout << "Enter N: ";
    cin >> N;

    int A[1000];
    cout << "Enter array elements:\n";

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    int max1 = -1000000;
    int max2 = -1000000;

    for (int i = 0; i < N; i++) {
        if (A[i] > max1) {
            max2 = max1;
            max1 = A[i];
        } else if (A[i] > max2) {
            max2 = A[i];
        }
    }

    int sum = max1 + max2;

    cout << "Sum of remaining elements = " << sum;

    return 0;
}
