class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        stack<int> left,star;
        for(int i = 0;i<n;i++){
            char ch = s[i];
            if(ch == '(')
                left.push(i);
            else if(ch == '*')
                star.push(i);
            else{
                if(!left.empty())
                    left.pop();
                else if(!star.empty())
                    star.pop();
                else
                    return false;
            }
        }
        while(!left.empty()){
            int ind = left.top();
            left.pop();
            if(star.empty() || star.top() < ind) return false;
            star.pop();
        }
        return true;
        // if(star.size() >= left.size())
        //     return true;
        // else
        //     return false;

    }
};
