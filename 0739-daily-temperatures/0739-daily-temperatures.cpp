class Solution {
public:
    vector<int> getNGE(vector<int> arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> result(n);

        for(int i=n-1; i>=0; i--) {
            while(!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }

            result[i] = st.empty() ? 0 : st.top();
            st.push(i);
        }

        return result;
    }

    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> NGE = getNGE(temperatures);
        vector<int> ans(n);

        for(int i=0; i<n; i++) {
            ans[i] = (NGE[i] - i) < 0 ? 0 : (NGE[i] - i);  
        }

        return ans;
    }
};