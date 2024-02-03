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

    
    vector<int> arr1 = {1, 15, 7, 9, 2, 5, 10};
    int k1 = 3;
    cout << solution.maxSumAfterPartitioning(arr1, k1) << endl;  

    vector<int> arr2 = {1, 4, 1, 5, 7, 3, 6, 1, 9, 9, 3};
    int k2 = 4;
    cout << solution.maxSumAfterPartitioning(arr2, k2) << endl; 

    vector<int> arr3 = {1};
    int k3 = 1;
    cout << solution.maxSumAfterPartitioning(arr3, k3) << endl;  

    return 0;
}
