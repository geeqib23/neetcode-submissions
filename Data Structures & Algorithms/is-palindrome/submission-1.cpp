class Solution {
public:
    bool isPalindrome(string s) {
        string s1 ="";
        for(auto &x : s){
            x = tolower(x);
            if((x>=97 && x<=122) || (x>=48 && x<=57))
                s1 += x;
        }
        string s2 = s1;
        reverse(s1.begin(),s1.end());
        cout <<s1 << " " << s2;
        if(s1 == s2) return true;
        else return false;

    }
};
