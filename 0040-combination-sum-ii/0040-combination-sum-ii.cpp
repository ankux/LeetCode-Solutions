class Solution {
public:
    vector<vector<int>> ans;

    void solve(int i, int t, vector<int> temp, vector<int>& c) {
        if(t == 0) {
            ans.push_back(temp);
            return;
        }

        if(i >= c.size() || t < 0) return;

        temp.push_back(c[i]);
        solve(i+1, t - c[i], temp, c);
        temp.pop_back();

        int idx = i+1;
        while(idx < c.size() && c[idx] == c[idx-1]) idx++;

        solve(idx, t, temp, c);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        solve(0, target, temp, candidates);
        return ans;
    }
};