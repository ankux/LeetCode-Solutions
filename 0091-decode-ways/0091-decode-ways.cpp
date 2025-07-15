class Solution {
public:
    int t[101];

    int solve(int i, int n, string &s) {
        if(t[i] != -1) return t[i];
        
        if(i == n) {
            return t[i] = 1;
        }

        if(s[i] == '0') {
            return t[i] = 0;
        }

        int take_one_char = solve(i+1, n, s);

        int take_two_char = 0;

        if(i+1 < n) {
            if(s[i]=='1' || s[i] == '2' && s[i+1] <= '6') {
                take_two_char = solve(i+2, n, s);
            }
        }

        return t[i] = take_one_char + take_two_char;
    }

    int numDecodings(string s) {
        int n = s.size();
        memset(t, -1, sizeof(t));
        return solve(0, n, s);
    }
};