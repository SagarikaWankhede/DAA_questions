
#include <iostream>
using namespace std;
bool canDivide(int A[], int N, int M, int X) {
    int segments = 1;
    int currentOR = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] > X)
            return false;
        if ((currentOR | A[i]) <= X) {
            currentOR = currentOR | A[i];
        } else {
            segments++;
            currentOR = A[i];
        }
    }
    return segments <= M;
}
int minimizeMaxOR(int A[], int N, int M) {
    int low = 0;
    int high = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] > low)
            low = A[i];
        high = high | A[i];
    }
    int answer = high;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (canDivide(A, N, M, mid)) {
            answer = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return answer;
}
int main() {
    int N, M;
    cout << "Enter N and M: ";
    cin >> N >> M;
    int A[1000];   
    cout << "Enter array elements:\n";
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    int result = minimizeMaxOR(A, N, M);
    cout << "Minimum possible maximum OR = " << result;
    return 0;
}
