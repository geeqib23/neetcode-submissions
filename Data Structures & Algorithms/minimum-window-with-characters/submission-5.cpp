class Solution {
public:
    string minWindow(string s, string t) {
        int i =0,j,mn = INT_MAX;
        pair<int,int> ans ={-1,-1};
        unordered_map<char,int> freq;
        // unordered_set<char> hs;
        for(j = 0;j<t.size();j++){
            freq[t[j]]++;
            // hs.insert(t[j]);
        }
        int cnt = 0;
        unordered_map<int,int> currCount;
        for(j = 0;j<s.size() && i<=j;j++){
            // cout << i << " " << j << endl;

            if(freq.count(s[j])){
                currCount[s[j]]++;
                if(currCount[s[j]] == freq[s[j]])
                    cnt++;
            }
            // cout << cnt << "count "  << endl;
            while(cnt == freq.size()){
                // cout << i <<endl;
                if(j-i+1 < mn){
                    mn = j-i+1;
                    ans = {i,j};
                }
                if(freq.count(s[i])){
                    currCount[s[i]]--;
                    if(currCount[s[i]]  == freq[s[i]]-1){
                        cnt--;
                    }
                }
                i++;
            }
            
        }
        return ans.first != -1 ? s.substr(ans.first,ans.second-ans.first+1) : "";

    }
};
