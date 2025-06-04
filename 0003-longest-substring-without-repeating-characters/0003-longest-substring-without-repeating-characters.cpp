class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxLen = 0;
        for(int i=0; i<n; i++) {
            int len = 0;
            string str = "";
            for(int j=i; j<n; j++){
                if(str.find(s[j]) == string::npos){
                    str.push_back(s[j]);
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