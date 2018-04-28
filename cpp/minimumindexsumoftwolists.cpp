class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> map;
        for (int i = 0; i < list1.size(); i++) {
            map[list1[i]] = i;
        }
        vector<vector<string>> mis(list1.size()+list2.size(), vector<string>(0));
        for (int i = 0; i < list2.size(); i++) {
            if (map.find(list2[i]) != map.end()) {
                mis[map[list2[i]]+i].push_back(list2[i]);
            }
        }
        for (int i = 0; i < mis.size(); i++) {
            if (mis[i].size()!=0) return mis[i];
        }
        //return vector<string> {"hello"};
    }
};
