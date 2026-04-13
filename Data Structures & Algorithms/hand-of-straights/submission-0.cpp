class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int> mp;
        for(auto x:hand){
            mp[x]++;
        }
        while(!mp.empty()){
            int c = 0, prev = -1;
            for(auto it = mp.begin(); it != mp.end() && c<groupSize;){
                // cout << it->first << " " << it->second << endl;
                // cout << it->first << " " << it->second << endl;
                if(prev != -1 && it->first-prev > 1) return false;
                it->second--;
                prev = it->first;
                c++;
                if(it->second == 0)
                    it = mp.erase(it);
                else
                    it++;
            }
            if(c != groupSize) return false;
        }
        return true;
    }
};
