class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>,vector<string>> hs;
        for(int i = 0;i<strs.size();i++){
            vector<int> bits(26,0);
            for(char &ch:strs[i]){
                bits[ch-'a']++;
            }
            hs[bits].push_back(strs[i]);
        }
        vector<vector<string>> res;
        for(auto &[bits,vec]:hs){
            res.push_back(vec);
        }
        return res;
    }
};
