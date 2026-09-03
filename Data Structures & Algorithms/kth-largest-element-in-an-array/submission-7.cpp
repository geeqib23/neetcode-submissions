//Practice quick sort
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int L = 0, R= nums.size()-1;
        int sorted = -1;
        while(sorted != k-1){
            sorted = partition(L,R,nums);
            if(sorted > k-1)
                R = sorted-1;
            else
                L = sorted+1;
        }
        return nums[sorted];
    }

    int partition(int l,int r, vector<int>& nums){
        // cout << l << " " << r  <<endl;
        int pivotIdx = r;
        int i = l;
        for(int j = l;j<r;j++){
            if(nums[j] >= nums[pivotIdx]){
                swap(nums[i],nums[j]);
                i++;
            }
        }
        swap(nums[i],nums[pivotIdx]);
        // cout << i << endl;
        return i;
    }
};
