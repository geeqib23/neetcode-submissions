class Solution {
public:
    int getSum(int a, int b) {
        int s = 0,c = 0;
        for(int i = 0;i<32;i++){
            int addbit = ((a>>i) & 1) ^ ((b>>i) & 1) ^ c;
            s = s | (addbit<<i);
            if(((a>>i) & 1) && ((b>>i) & 1))
                c = 1;
            else if((((a>>i) & 1) || ((b>>i) & 1)) && c == 1)
                c = 1;
            else
                c = 0;
        }
        return s;
    }
};
