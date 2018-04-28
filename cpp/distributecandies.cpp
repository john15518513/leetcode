class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        unordered_set<int> table;
        for (auto &c: candies) table.insert(c);
        return table.size() > candies.size()/2? candies.size()/2: table.size();
        
    }
};
