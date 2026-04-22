class Solution {
public:
    //in descending order, last one takes a fleet of consecutive, then a break comes, and that one takes consecutive
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> pair;
        for (int i = 0; i < position.size(); i++) {
            pair.push_back({position[i], speed[i]});
        }
        sort(pair.rbegin(), pair.rend()); //DESCENDING ORDER
        vector<double> stack;
        for (auto& [pos,sp] : pair) {
            stack.push_back((double)(target - pos) / sp);
            if (stack.size() >= 2 &&
                stack.back() <= stack[stack.size() - 2])
            {
                stack.pop_back();
            }
        }
        return stack.size();
    }
};
// 7,1 4,2  1,2  0,10
//  3  3  4.5  10. NEXT GREATER element, break