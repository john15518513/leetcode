class Solution {
public:
    int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
        vector<int> nutToTree;
        vector<int> nutToSquirrel;
        int sum = 0;
        for (int i = 0; i < nuts.size(); i++) {
            int dis = manDist(nuts[i], squirrel);
            int dis1 = manDist(nuts[i], tree);
            sum += dis1*2;
            nutToSquirrel.push_back(dis);
            nutToTree.push_back(dis1);
        }
        int minV = INT_MAX;
        for (int i = 0; i < nuts.size(); i++) {
            minV = min(minV, sum + nutToSquirrel[i] - nutToTree[i]);
        }
        return minV;
    }
    int manDist(vector<int>& p1, vector<int>& p2) {
        return abs(p1[0]-p2[0]) + abs(p1[1]-p2[1]);
    }
};
