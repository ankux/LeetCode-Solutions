class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        stack<int> st;
        unordered_map<int, int> mp;

        for(int i=m-1; i>=0; i--) {
            int curElement = nums2[i];

            while(!st.empty() && st.top() <= curElement) {
                st.pop();
            }

            st.empty() ? mp[curElement] = -1 : mp[curElement] = st.top();
            st.push(curElement);
        }

        vector<int> ans;

        for(int i=0; i<n; i++) {
            int curElement = nums1[i];
            ans.push_back(mp[curElement]);
        }

        return ans;
    }
};