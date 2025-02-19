class Solution {
public:
    int solve(int i, vector<int>& prices, int flag, int limit, vector<vector<vector<int>>> &dp) {
        if(i >= prices.size() || limit == 0) return 0;

        if(dp[i][flag][limit] != -1) return dp[i][flag][limit];

        if(flag == 1){
            int buy = solve(i+1, prices, 0, limit, dp) - prices[i];
            int notBuy = solve(i+1, prices, 1, limit, dp);
            return dp[i][flag][limit] = max(buy, notBuy);
        } 
        else {
            int sell = solve(i+1, prices, 1, limit-1, dp) + prices[i];
            int notSell = solve(i+1, prices, 0, limit, dp);
            return dp[i][flag][limit] =  max(sell, notSell);
        }
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, -1))); 
        return solve(0, prices, 1, 2, dp);
    }
};