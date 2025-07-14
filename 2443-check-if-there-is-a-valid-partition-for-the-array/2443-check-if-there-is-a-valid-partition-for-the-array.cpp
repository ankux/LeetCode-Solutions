class Solution {
public:
    int dp[1000001];
    
    bool solve(int i, vector<int>& nums) {
        if(i == nums.size()) {
            return dp[i] = true;
        }

        if(dp[i] != -1) return dp[i];

        // rule - 1
        if(i+1 < nums.size() && nums[i] == nums[i+1]){
            if(solve(i+2, nums)) {
                return dp[i] = true;
            }
        }

        // rule - 2
        if(i+2 < nums.size() && nums[i] == nums[i+1] && nums[i+1] == nums[i+2]) {
            if(solve(i+3, nums)) {
                return dp[i] = true;
            }
        }

        // rule - 3
        if(i+2 < nums.size() && nums[i+1] - nums[i] == 1 && nums[i+2] - nums[i+1] == 1) {
            if(solve(i+3, nums)) {
                return dp[i] = true;
            }
        }

        return dp[i] = false;
    }

    bool validPartition(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(0, nums); 
    }  
};