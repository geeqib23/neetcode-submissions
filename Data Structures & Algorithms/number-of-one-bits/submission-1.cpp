class Solution {
public:
    int hammingWeight(uint32_t n) {
        int s = 0;
        for(int i = 0;i<32;i++){
            s += (n>>i)&1;
        }
        return s;
    }
};
