class Solution {
public:
    vector<vector<int>> ans;
    void solve(int i, vector<int>& temp, vector<int>& c, int t) {
        if(i >= c.size())
            return;
            
        if(t == 0){
            ans.push_back(temp);
            return;
        }

        //take
        if(t > 0) {
            temp.push_back(c[i]);
            solve(i, temp, c, t-c[i]);
            temp.pop_back();
        }

        //skip
        solve(i+1, temp, c, t);
    } 

    vector<vector<int>> combinationSum(vector<int>& c, int t) {
        vector<int> temp;
        solve(0, temp, c, t);
        return ans;
    }
};