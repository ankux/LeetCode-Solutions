class Solution {
public:
    vector<int> getNSL(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        stack<int> st;

        for(int i=0; i<n; i++){
            while(!st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
            }

            result[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        return result;
    }

    vector<int> getNSR(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        stack<int> st;

        for(int i=n-1; i>=0; i--){
            while(!st.empty() && nums[st.top()] > nums[i]){
                st.pop();
            }

            result[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        return result;
    }

    vector<int> getNGL(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        stack<int> st;

        for(int i=0; i<n; i++) {
            while(!st.empty() && nums[st.top()] <= nums[i]){
                st.pop();
            }

            result[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        return result;
    }

    vector<int> getNGR(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        stack<int> st;

        for(int i=n-1; i>=0; i--){
            while(!st.empty() && nums[st.top()] < nums[i]){
                st.pop();
            }

            result[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        return result;
    }

    long long sumSubarrayMins(vector<int>& nums) {
        int n = nums.size();
        vector<int> NSL = getNSL(nums);
        vector<int> NSR = getNSR(nums);

        long long totalSum = 0;

        for(int i=0; i<n; i++){
            long long ls = i - NSL[i];
            long long rs = NSR[i] - i;

            long long totalSubarrays = ls * rs;
            long long sum = totalSubarrays * nums[i];

            totalSum += sum;
        }

        return totalSum;
    }

    long long sumSubarraysMaxs(vector<int>& nums) {
        int n = nums.size();
        vector<int> NGL = getNGL(nums);
        vector<int> NGR = getNGR(nums);

        long long totalSum = 0;

        for(int i=0; i<n; i++) {
            long long lm = i - NGL[i];
            long long rm = NGR[i] - i;

            long long totalSubarrays = lm * rm;
            long long sum = totalSubarrays * nums[i];

            totalSum += sum;
        }

        return totalSum;
    }

    long long subArrayRanges(vector<int>& nums) {
        return sumSubarraysMaxs(nums) - sumSubarrayMins(nums);
    }
};