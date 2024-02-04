class Solution:
    def climbStairs(self, n):
        if n == 1:
            return 1
        if n == 2:
            return 2

        dp = [0] * (n + 1)
        dp[1] = 1
        dp[2] = 2

        for i in range(3, n + 1):
            dp[i] = dp[i - 1] + dp[i - 2]

        return dp[n]

# Example usage:
solution_instance = Solution()

n1 = 2
n2 = 3

output1 = solution_instance.climbStairs(n1)
output2 = solution_instance.climbStairs(n2)

print(f"Input: n = {n1}, Output: {output1}")
print(f"Input: n = {n2}, Output: {output2}")
