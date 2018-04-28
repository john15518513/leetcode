class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> map;
        vector<vector<string>> res;
        for (auto &s: strings) {
            string key = "";
            int offset = s[0] - 'a';
            for (auto &w: s) {
                char c = w-offset;
                if (c < 'a') c += 26;
                key += char(c);
            }
            //cout << key << ":" << s << endl;
            map[key].push_back(s);
        }
        for (auto &it: map) {
            res.push_back(it.second);
        }
        return res;
    }
};
