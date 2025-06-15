class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        int changeOfFive = 0;
        int chnageOfTen = 0;
        for(int i=0; i<n; i++) {
            if(bills[i] == 5) {
                changeOfFive += bills[i];
            } else if (bills[i] == 10 && changeOfFive >= 5) {
                chnageOfTen += bills[i];
                changeOfFive -= 5;
            } else if (bills[i] == 20 && (changeOfFive >= 15 || (changeOfFive >=5 && chnageOfTen >= 10))) {
                if (changeOfFive >=5 && chnageOfTen >= 10) {
                    changeOfFive -= 5;
                    chnageOfTen -= 10;
                    continue;
                }

                if(changeOfFive >= 15) {
                    changeOfFive -= 15;
                    continue;
                }
            } else {
                return false;
            }
        }

        return true;
    }
};