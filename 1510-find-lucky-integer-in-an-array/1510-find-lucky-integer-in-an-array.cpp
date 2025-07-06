class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> mp;
        for(int num : arr) {
            mp[num]++;
        }

        int result = -1;
        for(int num : arr) {
            if(mp[num] == num) {
                result = max(result, num);
            }
        }

        return result;
    }
};