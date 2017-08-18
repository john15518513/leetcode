class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> set;
        queue<string> que;
        for (auto &s: bank) set.insert(s);
        int depth = 0;
        if (set.find(end) == set.end()) return -1;
        que.push(start);
        int c = 0;
        while (!que.empty()) {
            int n = que.size();
            c++;
            for (int i = 0; i < n; i++) {
                string s = que.front();
                que.pop();
                if (s == end) return c-1;
                else {
                    vector<string> tmp;
                    for (auto it = set.begin(); it != set.end(); it++) {
                        if (validMutation(s,*it)) {
                            que.push(*it);
                            tmp.push_back(*it);
                        }
                    }
                    for (auto &k: tmp) set.erase(k);
                }
            }
        }
        return -1;
    }
    bool validMutation(string &a, string b) {
        cout << a << " " << b << endl;
        if (a.size() != b.size()) return false;
        int c = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) c++;
        }
        return c == 1;
    } 
};
