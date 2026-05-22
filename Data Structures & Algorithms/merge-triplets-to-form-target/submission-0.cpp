class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        // vector<int> candidates;
        int a=0,b=0,c=0;
        for(int i = 0;i<triplets.size();i++){
            auto &v = triplets[i];
            if(v[0] <= target[0] && v[1] <= target[1] && v[2] <= target[2]){
                a = max(a,v[0]);
                b = max(b,v[1]);
                c = max(c,v[2]);
            }
        }
        if(a == target[0] && b == target[1] && c == target[2])
            return true;
        else
            return false;
    }
};
