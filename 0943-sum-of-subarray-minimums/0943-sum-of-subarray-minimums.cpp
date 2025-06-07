class Solution {
public:
    vector<int> getNSL(vector<int>& arr, int n) {
        vector<int> result(n);
        stack<int> st;

        for(int i=0; i<n; i++) {
           while(!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            
            result[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        return result;
    }

    vector<int> getNSR(vector<int>& arr, int n) {
        vector<int> result(n);
        stack<int> st;

        for(int i=n-1; i>=0; i--) {
            while(!st.empty() && arr[st.top()] > arr[i])
                st.pop();
            
            result[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        return result;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();

        vector<int> NSL = getNSL(arr, n);
        vector<int> NSR = getNSR(arr, n);

        long long totalSum = 0;
        int mod = 1e9 + 7;

        for(int i=0; i<n; i++) {
            long long ls = i - NSL[i]; // left mei sabse smallest
            long long rs = NSR[i] - i; // right mei sabse smallest

            long long totalSubarrays = ls * rs;
            long long sum = totalSubarrays * arr[i];

            totalSum = (totalSum + sum) % mod;
        }

        return totalSum;
    }
};