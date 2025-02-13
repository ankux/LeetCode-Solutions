class Solution {
public:

    int solve(int i, int target, vector<int>& nums){
        if(i >= nums.size()) {
            return (target == 0) ? 1 : 0;
        }

        int add = solve(i+1, target + nums[i], nums);
        int sub = solve(i+1, target - nums[i], nums);

        return add + sub;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(0, target, nums);    
    }
};