class Solution {
    int[] t = new int[100001];

    boolean solve(int i, int[] nums) {
        if(i == nums.length){
            t[i] = 1;
            return true;
        } 

        if(t[i] != -1) return t[i] == 1;

        if(i+1 < nums.length && nums[i] == nums[i+1]) {
            if(solve(i+2, nums)) {
                t[i] = 1;
                return true;
            }
        }

        if(i+2 < nums.length && nums[i] == nums[i+1] && nums[i+1] == nums[i+2]) {
            if(solve(i+3, nums)) {
                t[i] = 1;
                return true;
            }
        }

        if(i+2 < nums.length && nums[i+1] - nums[i] == 1 && nums[i+2] - nums[i+1] == 1) {
            if(solve(i+3, nums)) {
                t[i] = 1;
                return true;
            }
        }

        t[i] = 0;
        return false;
    }

    public boolean validPartition(int[] nums) {
        Arrays.fill(t, -1);
        return solve(0, nums);
    }
}