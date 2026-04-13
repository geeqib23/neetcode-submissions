class Solution {
public:
    vector<int> countBits(int n) {
    //     0
    //     1 1
    //    10 1
    //    11 2 3
    //   100 1
    //   101 2
    //   110 2
    //   111 3 7
    //  1000 1
    //       2
    //       2
            //  2
            //  3
            //  3
    //       4 15
    //       1
        set<int> hs = {2,4,8,16,32,64,128,256,512};
        vector<int> res(n+1,0);
        int reset = 0;
        for(int i = 1;i<=n;i++){
            if(hs.find(i) != hs.end())
                reset = i;
            res[i] = 1+res[i-reset];
        }
        return res;
    }
};
