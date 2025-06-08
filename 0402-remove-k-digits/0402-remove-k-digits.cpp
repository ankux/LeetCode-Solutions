class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();

        stack<char> st;

        for(int i=0; i<n; i++){

            // popping val untill st.top() > cur_digit, provided k>0 and st isn't empty
            while(!st.empty() && k > 0 && (st.top() - '0') > (num[i] - '0')) {
                st.pop();
                k--;
            }

            st.push(num[i]);
        }

        // in case k still has some val,  
        // we will remove the digits from the end untill k == 0
        while(k > 0) {
            st.pop();
            k--;
        }

        if(st.empty()) return "0";

        string res = "";
        while(!st.empty()) {
            res += st.top();
            st.pop();
        }

        while(res.size() != 0 && res.back() == '0') {
            res.pop_back();
        }

        if(res.empty()) return "0";

        reverse(res.begin(), res.end());

        return res;
    }
};