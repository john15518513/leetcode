/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> map;
        for (auto &a: employees) map[a->id] = a;
        int importance = 0;
        queue<int> que;
        que.push(id);
        while (!que.empty()) {
            int target = que.front();
            que.pop();
            importance += map[target]->importance;
            for (auto &e: map[target]->subordinates) {
                que.push(e);
            }
        }
        return importance;
    }
};
