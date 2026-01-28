#include <iostream>
using namespace std;
int ceilDiv(int a, int b) {
    return (a + b - 1) / b;
}
int main() {
    int T;
    cout << "Enter number of test cases: ";
    cin >> T;
    while (T--) {
        int N, H, W;
        cout << "Enter N, H, W: ";
        cin >> N >> H >> W;
        int minSide = 1000000000; 
        for (int C = 1; C <= N; C++) {
            int rows = ceilDiv(N, C);

            int totalWidth = C * W;
            int totalHeight = rows * H;

            int side;
            if (totalWidth > totalHeight)
                side = totalWidth;
            else
                side = totalHeight;

            if (side < minSide)
                minSide = side;
        }
        cout << "Minimum square size = " << minSide << endl;
    }
    return 0;
}
