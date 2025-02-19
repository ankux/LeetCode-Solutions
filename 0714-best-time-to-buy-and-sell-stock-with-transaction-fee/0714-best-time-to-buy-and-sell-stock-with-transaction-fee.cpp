class Solution {
public:
    int solve(int i, vector<int>& prices, int flag, int fee, vector<vector<int>> &dp) {
        if(i >= prices.size()) return 0;

        if(dp[i][flag] != -1) return dp[i][flag];

        if(flag == 1){
            int buy = solve(i+1, prices, 0, fee, dp) - prices[i];
            int skip = solve(i+1, prices, 1, fee, dp);
            return dp[i][flag] = max(buy, skip);
        } 
        else {
            int sell = solve(i+1, prices, 1, fee, dp) + prices[i] - fee;
            int skip = solve(i+1, prices, 0, fee, dp);
            return dp[i][flag] =  max(sell, skip);
        }
    }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, -1));
        return solve(0, prices, 1, fee, dp);
    }
};