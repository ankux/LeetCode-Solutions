class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int l=0, r=0, minWindowSize=INT_MAX, start_l=0;

        unordered_map<char, int> mp;

        for(char& ch : t) {
            mp[ch]++;
        }

        int requiredCount = t.size();

        while(r < n) {
            if(mp[s[r]] > 0) {
                requiredCount--;
            }

            mp[s[r]]--;

            while(requiredCount == 0) {
                mp[s[l]]++;
                
                if(mp[s[l]] > 0) {
                    requiredCount++;
                }
                
                int curWindowSize = r-l+1;

                if(curWindowSize < minWindowSize) {
                    minWindowSize = curWindowSize;
                    start_l = l;
                }

                l++;
            }

            r++;
        }

        return minWindowSize == INT_MAX ? "" : s.substr(start_l, minWindowSize);
    }
};