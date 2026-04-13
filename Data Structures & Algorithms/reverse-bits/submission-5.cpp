class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int s = 0;
        for(int i = 0;i < 16;i++){
            int front = (n>>i) & 1;
            int back = n>>(31-i) & 1;
            // cout << front << " " << back << " " << i<< " " << n <<  endl;
            if(back == front) continue;
            if(back){
                n = n | (1<<i);
                n = n & ~(1<<(31-i));
            }
            else{
                n = n & ~(1<<i);
                n = n | (1<<(31-i));
            }
        }
        return n;
    }
};
