class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l=0, r=0, maxLen=0, maxFreq=0;
        int hash[26] = {0};
        
        while(r < n) {
            hash[s[r] - 'A']++;
            maxFreq = max(maxFreq, hash[s[r] - 'A']);
            int len = r - l + 1;

            // no. of changes = len - maxFreq
            if(len-maxFreq > k){ 
                hash[s[l] - 'A']--;
                l++;
            }

            if(len-maxFreq <= k) {
                maxLen = max(maxLen, len);
            }

            r++;
        }

        return maxLen;
    }
};