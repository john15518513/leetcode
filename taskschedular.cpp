class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> counts;
        for (auto &t: tasks) counts[t]++;
        priority_queue<int> pq;
        for (auto &e: counts) pq.push(e.second);
        int alltime = 0;
        int cycle = n + 1;
        while (!pq.empty()) {
            vector<int> tmp;
            int worktime = 0;
            for (int i = 0; i < cycle; i++) 
                if (!pq.empty()) {
                    tmp.push_back(pq.top());
                    pq.pop();
                    worktime++;
                }
            for (auto &cnt: tmp) if (cnt-1 > 0) pq.push(cnt-1);
            alltime += !pq.empty()? cycle:worktime;
        }
        return alltime;
    }
};
