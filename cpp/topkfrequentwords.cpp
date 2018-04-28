class Solution {
    struct cmp {
        bool operator()(const pair<int, string>& a, const pair<int, string>& b) {
            return a.first == b.first? a.second < b.second:a.first > b.first;
        }
    };
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        //variable
        unordered_map<string, int> wordCount;
        priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> pq;
        vector<string> res;
        //count word freq
        for (auto &w: words) wordCount[w]++;
        for (auto it = wordCount.begin(); it != wordCount.end(); ++it) {
            pq.push(make_pair(it->second, it->first));
            if (pq.size() > k) pq.pop();
        }
        
        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
