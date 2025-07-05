class Solution {
public:
    int n;
    unordered_set<string> st;
    int dp[301];

    bool solve(int idx, string &s){
        if(idx >= s.size()) return true;

        if(dp[idx] != -1) return dp[idx];
        
        if(st.find(s) != st.end()) return true;
        
        for(int l=1; l<=n; l++) {
            string temp = s.substr(idx, l);
            if(st.find(temp) != st.end())
                if(solve(idx+l, s))
                    return dp[idx] = true;
        }

        return dp[idx] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.size();

        memset(dp, -1, sizeof(dp));

        //storing all dictionary words in set
        for(string &word : wordDict){
            st.insert(word);
        }

        return solve(0, s);
    }
};