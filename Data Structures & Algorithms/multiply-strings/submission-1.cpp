class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1.size() > num2.size())
            swap(num1,num2);
        if(num1 == "0") return "0";
        int n1 = num1.size(),n2 = num2.size();
        string res = "";
        for(int i = n1-1;i>=0;i--){
            string prod = "";
            int carry = 0;
            int dig1 = num1[i]-48;
            for(int j = n2-1;j>=0;j--){
                int dig2 = num2[j]-48;
                int mod = (dig1*dig2+carry)%10;
                carry = (dig1*dig2+carry)/10;
                prod += to_string(mod);
            }
            if(carry > 0)
                prod += to_string(carry);
            reverse(prod.begin(),prod.end());
            for(int c = n1-1;c>i;c--)
                prod += '0';
            res = add(res,prod);
        }
        return res;
    }
    string add(string &a,string &b){
        int i = a.size()-1,j = b.size()-1;
        int carry = 0;
        string res = "";
        while(i >= 0 || j >= 0){
            int dig1 = i>=0 ? a[i]-48 : 0; 
            int dig2 = j>=0 ? b[j]-48 : 0; 
            int s = (dig1+dig2+carry)%10;
            carry = (dig1+dig2+carry)/10;
            res += to_string(s);
            i--;
            j--;
        }
        if(carry >0)
            res += to_string(carry);
        reverse(res.begin(),res.end());
        return res;
    }
};
