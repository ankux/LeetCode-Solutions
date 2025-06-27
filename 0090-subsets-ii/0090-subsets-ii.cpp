class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;

    void solve(int i, vector<int>& nums) {
        if(i >= nums.size()) {
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[i]);
        solve(i+1, nums);
        temp.pop_back();

        int idx = i+1;
        while(idx < nums.size() && nums[idx] == nums[idx-1]){
            idx++;
        }

        solve(idx, nums);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        solve(0, nums);
        return ans;
    }
};