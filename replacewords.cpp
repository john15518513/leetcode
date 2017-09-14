class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        unordered_set<string> set;
        for (auto &s: dict) set.insert(s);
        string res = "";
        stringstream ss(sentence);
        string tmp;
        while (getline(ss, tmp, ' ')) {
            for (int i = 0; i < tmp.size(); i++) {
                if (set.find(tmp.substr(0, i+1)) != set.end()) {
                    tmp = tmp.substr(0, i+1);
                    break;
                }
            }
            res = res + tmp + " ";
        }
        res.pop_back();
        return res;
    }
};
