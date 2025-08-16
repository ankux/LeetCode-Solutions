class Solution {
public:
    int maximum69Number (int num) {
        string number = to_string(num);

        for(char &c : number) {
            if(c == '6') {
                c = '9';
                break;
            }
        }

        return stoi(number);
    }
};