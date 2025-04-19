class Solution {
public:
    vector<vector<int>> ans;

    void solve(int i, vector<int>& temp, vector<int>& nums){
        if(i>=nums.size())
            return;

        temp.push_back(nums[i]);
        ans.push_back(temp);

        //take
        solve(i+1, temp, nums);
        temp.pop_back();

        //skip
        solve(i+1, temp, nums);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        ans.push_back({});
        vector<int> temp; 
        solve(0, temp, nums);
        return ans;
    }
};