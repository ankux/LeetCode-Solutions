class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i, int j, int row, int col) {
        if(i>=row|| j >= col) return 0;
        if(i == row-1 && j == col-1) return 1;

        if(dp[i][j] != -1) return dp[i][j];

        int right = solve(i, j+1, row, col);
        int down = solve(i+1, j, row, col);

        return dp[i][j] = right + down;
    }

    int uniquePaths(int m, int n){
        dp.assign(101, vector<int>(101, -1));
        return solve(0, 0, m, n);
    }
};