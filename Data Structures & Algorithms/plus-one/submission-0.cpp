class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        for(int i = digits.size()-1;i>=0;i--){
            if(carry == 0) break;
            if(digits[i] == 9){
                carry = 1;
                digits[i] = 0;
            }
            else{
                carry = 0;
                digits[i] = digits[i]+1;
            }
        }
        if(carry == 1)
            digits.insert(digits.begin(),1);
        return digits;
    }
};
