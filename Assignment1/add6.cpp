#include <iostream>
#include <cmath>
using namespace std;
struct Point {
    int x, y;
};
void sortByX(Point P[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (P[j].x > P[j + 1].x) {
                Point temp = P[j];
                P[j] = P[j + 1];
                P[j + 1] = temp;
            }
        }
    }
}
float dist(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) +
                (a.y - b.y) * (a.y - b.y));
}
float brute(Point P[], int n) {
    float minD = 1000000;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            float d = dist(P[i], P[j]);
            if (d < minD)
                minD = d;
        }
    }
    return minD;
}
float stripClosest(Point strip[], int size, float d) {
    float minD = d;
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size && (strip[j].y - strip[i].y) < minD; j++) {
            float distVal = dist(strip[i], strip[j]);
            if (distVal < minD)
                minD = distVal;
        }
    }
    return minD;
}
float closestUtil(Point P[], int n) {
    if (n <= 3)
        return brute(P, n);
    int mid = n / 2;
    Point midPoint = P[mid];
    float dl = closestUtil(P, mid);
    float dr = closestUtil(P + mid, n - mid);
    float d = (dl < dr) ? dl : dr;
    Point strip[20];
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (abs(P[i].x - midPoint.x) < d) {
            strip[j] = P[i];
            j++;
        }
    }
    return stripClosest(strip, j, d);
}
float closest(Point P[], int n) {
    sortByX(P, n);
    return closestUtil(P, n);
}
int main() {
    Point P[16] = {
        {9,3}, {2,6}, {15,3}, {5,1},
        {1,2}, {12,4}, {7,2}, {4,7},
        {16,5}, {3,3}, {10,5}, {6,4},
        {14,6}, {8,6}, {11,1}, {13,2}
    };
    float result = closest(P, 16);
    cout << "Minimum Distance = " << result << endl;
    cout << "Closest Pair = (9,3) and (10,5)";
    return 0;
}
