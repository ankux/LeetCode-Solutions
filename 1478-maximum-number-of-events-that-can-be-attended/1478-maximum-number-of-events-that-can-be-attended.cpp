class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(begin(events), end(events));

        // finding max day
        int max_day = 0;
        for(auto val : events) {
            max_day = max(max_day, val[1]);
        }

        priority_queue<int, vector<int>, greater<int>> pq;

        int day = 1;     // counts day from 1 to max_day
        int process = 0; // to iterate over events one by one
        int ans = 0;

        while(day <= max_day) {
            // put new items, that are available today
            while(process < n && events[process][0] <= day) {
                // storing their expiring value
                pq.push(events[process][1]); 

                // move to the next item to process
                process++; 
            }

            // remove all the expired items
            while(!pq.empty() && pq.top() < day) {
                pq.pop();
            }

            // take one item which is going to expire early
            if(!pq.empty()) {
                pq.pop();
                ans += 1;
            }

            day += 1;
        }
        
        return ans;
    }
};