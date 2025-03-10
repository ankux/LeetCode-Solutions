class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxVal = 0;
        for(int& el : nums){
            maxVal = max(maxVal, el);
        }

        vector<int> earnTrack(maxVal+1);
        for(int el : nums){
            earnTrack[el] += el;
        }

        vector<int> earnPoint(maxVal+1);
        earnPoint[0] = 0;
        earnPoint[1] = earnTrack[1];

        for(int i=2; i<=maxVal; i++){
            earnPoint[i] = max(earnPoint[i-1], earnTrack[i]+earnPoint[i-2]);
        }

        return earnPoint[maxVal];
     
    }
};