class Solution {
public:
    int maximumCount(vector<int>& nums) {
        auto lambdaPos = [](int num){
            return num > 0;
        };

        auto lambdaNeg = [](int num){
            return num < 0;
        };
        
        int posCount = count_if(nums.begin(), nums.end(), lambdaPos);
        int negCount = count_if(nums.begin(), nums.end(), lambdaNeg);

        return max(posCount, negCount);

    }
};