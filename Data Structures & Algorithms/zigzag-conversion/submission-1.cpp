class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1) return s;
        int n = s.size();
        string ans = "";
        for(int i = 0;i<numRows;i++){
            int j = i;
            bool down = false;
            while(j<n){
                if(i == 0) down = true;
                else if(i == numRows-1) down = false;
                else down = !down;
                ans += s[j];
                if(down)
                    j += (numRows-1-i)*2;
                else
                    j += i*2;
            }
        }
        return ans;
    }
};