class Solution {
public:
    vector<vector<int>> ans;
    int t;

    void solve(int i, int sum, vector<int>& temp, vector<int>& arr) {
        if(sum == t) {
            ans.push_back(temp);
            return;
        }
        
        if(i >= arr.size() || sum >= t) return;

        for(int k=i; k<arr.size(); k++) {
            if(k > i && arr[k] == arr[k-1])
                continue;

            temp.push_back(arr[k]);
            solve(k+1, sum + arr[k], temp, arr);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        t = target;
        vector<int> temp;
        solve(0, 0, temp, candidates);
        return ans;
    }
};