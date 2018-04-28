class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int n = rooms.size();
        if (n == 0 || rooms[0].empty()) return;
        int m = rooms[0].size();
        queue<pair<int, int>> que;
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < rooms[i].size(); j++)
                if (rooms[i][j] == 0) que.push(make_pair(i,j));
        //cout << "hi";
        while (!que.empty()) {
            auto it = que.front();
            que.pop();
            //cout << "ker";
            if (it.first-1 >= 0 and rooms[it.first-1][it.second] == 2147483647) {
                rooms[it.first-1][it.second] = rooms[it.first][it.second]+1;
                que.push(make_pair(it.first-1, it.second));
            }
            if (it.first+1 < n and rooms[it.first+1][it.second] == 2147483647) {
                rooms[it.first+1][it.second] = rooms[it.first][it.second]+1;
                que.push(make_pair(it.first+1, it.second));
            }
            if (it.second-1 >= 0 and rooms[it.first][it.second-1] == 2147483647) {
                rooms[it.first][it.second-1] = rooms[it.first][it.second]+1;
                que.push(make_pair(it.first, it.second-1));
            }
            if (it.second+1 < m and rooms[it.first][it.second+1] == 2147483647) {
                rooms[it.first][it.second+1] = rooms[it.first][it.second]+1;
                que.push(make_pair(it.first, it.second+1));
            }
        }
    }
};
