class Solution {
public:
    int m, n;

    int solve(int i, int j, vector<vector<int>> &grid) {
        if(i >= m || i < 0 || j >= n || j < 0 || grid[i][j] == 0) return 0;

        int temp = grid[i][j];
        grid[i][j] = 0;

        int l = solve(i, j-1, grid);
        int u = solve(i-1, j, grid);
        int r = solve(i, j+1, grid);
        int d = solve(i+1, j, grid);

        grid[i][j] = temp;

        return temp + max({l, u, r,d});
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int maxi = 0;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] != 0) {
                    int ans = solve(i, j, grid);
                    maxi = max(maxi, ans);
                }
            }
        }

        return maxi;
    }
};