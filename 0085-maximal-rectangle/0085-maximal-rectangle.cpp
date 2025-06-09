class Solution {
public:
    int largestRectangle(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        int maxi = 0;

        for(int i=0; i<n; i++) {
            while(!st.empty() && arr[st.top()] > arr[i]) {
                int idx = st.top();
                st.pop();

                int NSE = i;
                int PSE = st.empty() ? -1 : st.top();

                int area = (arr[idx]) * (NSE - PSE - 1);
                maxi = max(maxi, area);
            }
            st.push(i);
        }

        while(!st.empty()) {
            int idx = st.top();
            st.pop();

            int NSE = n;
            int PSE = st.empty() ? -1 : st.top();

            int area = (arr[idx]) * (NSE - PSE - 1);
            maxi = max(maxi, area);
        }

        return maxi;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();      // rows
        int m = matrix[0].size();   // cols

        int maxi = 0;
        vector<int> heights(m, 0);

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(matrix[i][j] == '1') heights[j]++;
                else heights[j] = 0;
            }

            int area = largestRectangle(heights);
            maxi = max(maxi, area);
        }

        return maxi;
    }
};