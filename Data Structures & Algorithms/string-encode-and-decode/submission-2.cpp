class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        for(auto &s:strs){
            res += to_string(s.size())+'#';
            res += s;
        }
        cout <<res<< endl;
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        for(int i = 0;i<s.size();){
            string temp="";
            while(s[i] != '#'){
                temp += s[i];
                i++;
            }
            int sz = stoi(temp);
            res.push_back(s.substr(i+1,sz));
            i+= sz+1;
        }
        return res;
    }
};
