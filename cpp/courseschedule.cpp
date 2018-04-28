class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        unordered_map<int, list<int>> adjList;
        for (auto &p: prerequisites) {
            indegree[p.first]++;
            adjList[p.second].push_front(p.first);
        }
        queue<int> que;
        int count = 0;
        for (int i = 0; i < indegree.size(); i++) 
            if (indegree[i] == 0) {
                que.push(i);
            }
        while (!que.empty()) {
            int target = que.front();
            que.pop();
            count++;
            for (auto it = adjList[target].begin(); it != adjList[target].end(); it++) {
                indegree[*it]--;
                if (indegree[*it] == 0) {
                    que.push(*it);
                }
            }
        }
        
        return count == numCourses;
    }
};
