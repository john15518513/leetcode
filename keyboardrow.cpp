ass Solution {
public:
    vector<string> findWords(vector<string>& words) {
        int row[26] = { 1, 2, 2, 1, 0, 1, 1, 1, 0, 1, 1, 1, 2, 2, 0, 0, 0, 0, 1, 0, 0, 2, 0, 2, 0, 2 };
        vector<string> res;
        for (auto &w: words) {
            int i = row[tolower(w[0])-'a'];
            res.push_back(w);
            for (auto &c: w)
                if(i != row[tolower(c)-'a']) {
                    res.pop_back();
                    break;
                }
        }
        return res;
    }
};
