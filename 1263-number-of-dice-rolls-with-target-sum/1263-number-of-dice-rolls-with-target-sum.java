class Solution {
    int MOD = (int)1e9 + 7;
    int[][] dp = new int[31][1001];

    int solve(int n, int k, int t) {
        if(t < 0) return 0;

        if(n == 0) return t == 0 ? 1 : 0;

        if(dp[n][t] != -1) return dp[n][t];

        int ways = 0;

        for(int face = 1; face <= k; face++) {
            ways = (ways + solve(n-1, k, t-face)) % MOD;
        }

        return dp[n][t] = ways;
    }

    public int numRollsToTarget(int n, int k, int target) {
        for (int[] row : dp) {
            Arrays.fill(row, -1);
        }

        return solve(n, k, target);
    }
}