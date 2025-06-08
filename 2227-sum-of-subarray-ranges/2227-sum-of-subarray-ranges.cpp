class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();

        long long sum = 0;

        for(int i=0; i<n; i++){
            long long mini = nums[i];
            long long maxi = nums[i];

            for(int j=i; j<n; j++){
                long long el = nums[j];
                mini = min(mini, el);
                maxi = max(maxi, el);

                sum += (maxi-mini);
            }
        }

        return sum;
    }
};