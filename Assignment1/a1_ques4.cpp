#include <iostream>
#include <climits>
using namespace std;

int maxCrossingSum(int arr[], int left, int mid, int right)
{
    int sum = 0;
    int leftSum = INT_MIN;

    for (int i = mid; i >= left; i--)
    {
        sum += arr[i];
        if (sum > leftSum)
            leftSum = sum;
    }

    sum = 0;
    int rightSum = INT_MIN;

    for (int i = mid + 1; i <= right; i++)
    {
        sum += arr[i];
        if (sum > rightSum)
            rightSum = sum;
    }

    return leftSum + rightSum;
}

int maxSubArraySum(int arr[], int left, int right)
{
    if (left == right)
        return arr[left];

    int mid = (left + right) / 2;

    int leftMax = maxSubArraySum(arr, left, mid);
    int rightMax = maxSubArraySum(arr, mid + 1, right);
    int crossMax = maxCrossingSum(arr, left, mid, right);

    if (leftMax >= rightMax && leftMax >= crossMax)
        return leftMax;
    else if (rightMax >= leftMax && rightMax >= crossMax)
        return rightMax;
    else
        return crossMax;
}

int main()
{
    int arr[] = {-2, -5, 6, -2, -3, 1, 5, -6};
    int n = sizeof(arr) / sizeof(arr[0]);

    int maxSum = maxSubArraySum(arr, 0, n - 1);

    cout << "Maximum subarray sum is: " << maxSum;

    return 0;
}
