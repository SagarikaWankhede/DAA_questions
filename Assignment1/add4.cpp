#include <iostream>
using namespace std;
int main() {
    int N, K;
    cout << "Enter N and K: ";
    cin >> N >> K;
    int A[1000];
    cout << "Enter array elements:\n";
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    int specialtySum = 0;
    for (int i = 0; i < N; i++) {
        bool isSpecial = false;
        for (int left = i; left >= 0 && !isSpecial; left--) {
            for (int right = i; right < N && !isSpecial; right++) {
                int countGreater = 0;
                for (int j = left; j <= right; j++) {
                    if (A[j] > A[i]) {
                        countGreater++;
                    }
                }
                if (countGreater == K) {
                    isSpecial = true;
                }
            }
        }
        if (isSpecial) {
            specialtySum += A[i];
        }
    }
    cout << "Specialty of the sequence = " << specialtySum;
    return 0;
}
