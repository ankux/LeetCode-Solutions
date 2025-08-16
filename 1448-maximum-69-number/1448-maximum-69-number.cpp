class Solution {
public:
    int maximum69Number (int num) {
        vector<int> numbers;
        int temp = num;

        while(temp) {
            int lastDigit = temp%10;
            numbers.push_back(lastDigit);
            temp = temp/10;
        }


        reverse(numbers.begin(), numbers.end());

        int ans = 0;

        for(int i=0; i<numbers.size(); i++) {
            int number = 0;
            for(int j=0; j<numbers.size(); j++) {
                if(j == i) {
                    if(numbers[i] == 9) {
                        number = number * 10 + 6;
                    }
                    else {
                        number = number * 10 + 9;
                    }
                } 
                else {
                    number = number * 10 + numbers[j];
                }

            }
            cout << "i = " << i << " : " << number << endl;
            ans = max({ans, number, num});
        }

        return ans;
    }
};