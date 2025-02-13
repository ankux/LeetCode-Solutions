class Solution {
public:
    int totalSum;

    int solve(int i, int curSum, int target, vector<int>& nums, vector<vector<int>> &dp){
        if(i >= nums.size()) {
            return (curSum == target) ? 1 : 0;
        }

        if(dp[i][curSum + totalSum] != -1)
            return dp[i][curSum + totalSum];

        int add = solve(i+1, curSum + nums[i], target, nums, dp);
        int sub = solve(i+1, curSum - nums[i], target, nums, dp);

        return dp[i][curSum + totalSum] = add + sub;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        totalSum = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> dp(n+1, vector<int>(2*totalSum+1, -1));
        return solve(0, 0, target, nums, dp);    
    }
};