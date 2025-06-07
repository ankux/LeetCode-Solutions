class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> st;

        for(int& a : asteroids) {
            bool destroyed = false; // agar -ve val destroy hogi toh true.

            while(!st.empty() && a < 0 && st.top() > 0) {

                if(abs(a) > st.top()){
                    st.pop();

                } else if (abs(a) < st.top()){
                    destroyed = true;
                    break;

                } else { // abs(a) == st.top()
                    st.pop();
                    destroyed = true;
                    break;
                }
            }

            if(!destroyed) {
                st.push(a);
            }
        }

        int s = st.size();
        vector<int> ans(s);
        int i = s-1;
        
        while(!st.empty()){
            ans[i] = st.top();
            st.pop();
            i--;
        }

        return ans;
    }
};