class Solution {
public:
    vector<int> getNSL(vector<int>& arr) {
        int n = arr.size();
        vector<int> result(n);
        stack<int> st;

        for(int i=0; i<n; i++) {
            while(!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            result[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        return result;
    }

    vector<int> getNSR(vector<int>& arr) {
        int n = arr.size();
        vector<int> result(n);
        stack<int> st;

        for(int i=n-1; i>=0; i--) {
            while(!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            result[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        return result;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> NSL = getNSL(heights);
        vector<int> NSR = getNSR(heights);

        int maxi = 0;

        for(int i=0; i<n; i++) {
            int area = heights[i] * (NSR[i] - NSL[i] - 1);
            maxi = max(maxi, area);
        }

        return maxi;
    }
};