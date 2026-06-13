class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        // vector<int> diff(n);
        int ind = 0,sum = 0;
        if(accumulate(gas.begin(),gas.end(),0) < accumulate(cost.begin(),cost.end(),0)) return -1;
        for(int i = 0;i<n;i++){
            sum += gas[i]-cost[i];
            if(sum < 0){
                sum = 0;
                ind = i+1;
            }
        } 
        return ind;
    }
};
