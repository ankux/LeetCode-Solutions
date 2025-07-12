class Solution {
public:

    int solve(int i, int curXOR, vector<int>& nums) {
        if(i == nums.size()){
            return curXOR;
        }

        int take = solve(i+1, curXOR ^ nums[i], nums);

        int skip = solve(i+1, curXOR, nums);

        return take + skip;
    }

    int subsetXORSum(vector<int>& nums) {
        return solve(0, 0, nums);
    }
};