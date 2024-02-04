#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, 0);

        for (int i = 0; i < n; ++i) {
            int current_max = 0;
            for (int j = 1; j <= min(k, i + 1); ++j) {
                current_max = max(current_max, arr[i - j + 1]);
                if (i >= j) {
                    dp[i] = max(dp[i], dp[i - j] + current_max * j);
                } else {
                    dp[i] = max(dp[i], current_max * j);
                }
            }
        }

        return dp[n - 1];
    }
};

int main() {
    Solution solution;

    // Test cases
    vector<int> arr1;
    arr1.push_back(1);
    arr1.push_back(15);
    arr1.push_back(7);
    arr1.push_back(9);
    arr1.push_back(2);
    arr1.push_back(5);
    arr1.push_back(10);
    int k1 = 3;
    cout << solution.maxSumAfterPartitioning(arr1, k1) << endl;  // Output: 84

    vector<int> arr2;
    arr2.push_back(1);
    arr2.push_back(4);
    arr2.push_back(1);
    arr2.push_back(5);
    arr2.push_back(7);
    arr2.push_back(3);
    arr2.push_back(6);
    arr2.push_back(1);
    arr2.push_back(9);
    arr2.push_back(9);
    arr2.push_back(3);
    int k2 = 4;
    cout << solution.maxSumAfterPartitioning(arr2, k2) << endl;  // Output: 83

    vector<int> arr3;
    arr3.push_back(1);
    int k3 = 1;
    cout << solution.maxSumAfterPartitioning(arr3, k3) << endl;  // Output: 1

    return 0;
}
