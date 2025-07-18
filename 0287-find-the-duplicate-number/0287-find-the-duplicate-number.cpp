class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int ans = -1;

        for(int i=1; i<nums.size(); i++) {
            if(nums[i-1] == nums[i]) {
                ans = nums[i];
            }
        }

        return ans;
    }
};