class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> ans;

        for(int i=0; i<n; i++){
            int curElement = nums1[i];
            for(int j=0; j<m; j++){
                if(curElement == nums2[j]) {
                    int nextGreater = curElement;
                    for(int k=j; k<m; k++){
                        if(nextGreater < nums2[k]) {
                            nextGreater = nums2[k];
                            break;
                        }
                    }
                    (nextGreater == curElement) ? 
                        ans.push_back(-1) : ans.push_back(nextGreater);
                    break;
                }
            }
        }

        return ans;
    }
};