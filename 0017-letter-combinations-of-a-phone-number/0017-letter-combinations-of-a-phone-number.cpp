class Solution {
public:
    vector<string> res;

    void solve(int idx, string digits, string &temp, unordered_map<char, string> &mp) {
        if(idx >= digits.length()) {
            res.push_back(temp);
            return;
        }
       
        char ch = digits[idx];
        string str = mp[ch];

        for(int i=0; i<str.length(); i++){
            temp.push_back(str[i]);
            solve(idx+1, digits, temp, mp);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0)
            return {};
        
        unordered_map<char, string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        
        int idx = 0;
        string temp = "";
        solve(idx, digits, temp, mp);
        return res;

    }
};