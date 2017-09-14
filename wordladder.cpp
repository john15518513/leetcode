class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> set;
        for (auto &s: wordList) set.insert(s);
        if (set.find(endWord) == set.end()) return 0;
        queue<string> que;
        que.push(beginWord);
        int count = 0;
        while (!que.empty()) {
            int size = que.size();
            count++;
            for (int i = 0; i < size; i++) {
                auto target = que.front();
                que.pop();
                if (target == endWord) return count;
                for (int j = 0; j < target.size(); j++) {
                    string tmp = target;
                    for (int k = 0; k < 26; k++) {
                        target[j] = 'a' + k;
                        if (set.find(target) != set.end()) {
                            que.push(target);
                            set.erase(target);
                        }
                    }
                    target = tmp;
                }
                
            }
        }
        return 0;
    }
};
