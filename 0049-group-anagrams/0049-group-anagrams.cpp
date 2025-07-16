class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for(string str : strs) {
            string val = str;
            sort(str.begin(), str.end());
            string key = str;
            mp[key].push_back(val);
        }

        vector<vector<string>> ans;

        for(auto it : mp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};