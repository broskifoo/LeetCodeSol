class Solution:
    def rob(self, nums: list[int]) -> int:
        def rob_helper(houses):
            n = len(houses)

            if n == 1:
                return houses[0]

            dp = [0] * ( n+1 )
            dp[0] = houses[0]
            dp[1] = max(houses[0] , houses[1])

            for i in range(2 , n ):
                dp[i] = max(dp[i-1], dp[i-2] + houses[i]
                )
            return dp[n-1]

        if len(nums) == 1:
            return nums[0]

        case1 = nums[ : -1]
        case2 = nums[1 : ]

        return max(rob_helper(case1) , rob_helper(case2))