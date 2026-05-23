class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());

        int sum = digits[0] + 1;
        digits[0] = sum % 10;
        int carry = sum / 10;

        for(int i = 1; i < digits.size(); i++){
            sum = digits[i] + carry;
            digits[i] = sum % 10;
            carry = sum / 10;
        }

        if(carry > 0){
            digits.push_back(carry);
        }

        reverse(digits.begin(), digits.end());

        return digits;
    }
};
