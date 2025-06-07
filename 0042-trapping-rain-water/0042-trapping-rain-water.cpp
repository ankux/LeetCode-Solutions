class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        int lmax = 0, rmax = 0, total = 0;
        int l = 0, r = n-1;

        while(l < r) {
            lmax = max(lmax, height[l]);
            rmax = max(rmax, height[r]);

            if(lmax < rmax) {
                total += lmax - height[l];
                l++;
            }
            else {
                total += rmax - height[r];
                r--;
            }
        }

        return total;
    }
};