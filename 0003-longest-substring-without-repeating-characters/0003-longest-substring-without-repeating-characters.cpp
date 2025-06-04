class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxLen = 0;
        for(int i=0; i<n; i++) {
            int visited[256] = {0};
            int len = 0;
            for(int j=i; j<n; j++){
                if(visited[s[j]] == 0){
                    visited[s[j]] = 1;
                    len++;
                } else {
                    break;
                }
            }
            maxLen = max(maxLen, len);
        }
        return maxLen;
    }
};