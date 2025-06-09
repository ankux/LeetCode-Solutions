class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxi = 0;

        for(int i=0; i<n; i++) {
            while(!st.empty() && heights[st.top()] > heights[i]) {
                int idx = st.top();
                st.pop();

                int NSE = i;
                int PSE = st.empty() ? -1 : st.top();

                int area = heights[idx] * (NSE - PSE - 1);
                maxi = max(maxi, area); 
            }
            st.push(i);
        }

        while(!st.empty()) {
            int idx = st.top();
            st.pop();
            int NSE = n;
            int PSE = st.empty() ? -1 : st.top();

            int area = heights[idx] * (NSE - PSE - 1);
            maxi = max(maxi, area);
        }

        return maxi;
    }
};