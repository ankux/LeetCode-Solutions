class Solution {
public:

    int solve(int i, int target, vector<int>& nums, unordered_map<string, int> &mp){
        if(i >= nums.size()) {
            return (target == 0) ? 1 : 0;
        }

        string key = to_string(i) + "_" + to_string(target);

        if(mp.count(key))
            return mp[key];

        int add = solve(i+1, target + nums[i], nums, mp);
        int sub = solve(i+1, target - nums[i], nums, mp);

        return mp[key] = add + sub;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<string, int> mp;
        return solve(0, target, nums, mp);    
    }
};