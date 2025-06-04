class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l = 0, r = 0, maxLen = 0;
        vector<int> visited(256, -1);

        while(r < n) {
            if(visited[s[r]] != -1) {
                if(visited[s[r]] >= l){
                    l = visited[s[r]] + 1;
                }
            }

            int len = r - l + 1;
            maxLen = max(maxLen, len);
            visited[s[r]] = r;
            r++;    
        }

        return maxLen;
    }
};