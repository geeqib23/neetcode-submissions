class Solution {
public:
//Think of a queue when you need to store/cooldown something for a period of time
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<pair<int,char>> maxHeap;
        unordered_map<char,int> freq;
        for(auto t:tasks){
            if(!freq.count(t))
                freq[t] = 1;
            else
                freq[t]++;
        }
        for(auto &[ch,f]:freq)
            maxHeap.push({f,ch});
        queue<tuple<int,char,int>> q;
        int i = 0;
        while(!maxHeap.empty() || !q.empty()){
            if(!q.empty()){
                auto [f,ch,ind] = q.front();
                if(i >= ind){
                    maxHeap.push({f,ch});
                    q.pop();
                }
            }
            if(!maxHeap.empty()){
                auto [f,ch] = maxHeap.top();
                // cout << ch << " ";
                maxHeap.pop();
                if(f-1>0)
                    q.push({f-1,ch,i+n+1});
            }
            i++;
        }
        return i;
    }
};
