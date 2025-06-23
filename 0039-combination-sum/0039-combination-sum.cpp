class Solution {
public:
    vector<vector<int>> ans;

    void solve(int i, int sum, vector<int>& temp, vector<int>& candidates, int target) {
        if(i >= candidates.size() || sum >= target) {
            if(sum == target) {
                ans.push_back(temp);
            }
            return;
        }

        temp.push_back(candidates[i]);
        solve(i, sum+candidates[i], temp, candidates, target);
        temp.pop_back();

        solve(i+1, sum, temp, candidates, target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        solve(0, 0, temp, candidates, target);
        return ans;
    }
};