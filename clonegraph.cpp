/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        return dfs(node);
    }
    UndirectedGraphNode* dfs(UndirectedGraphNode* node) {
        if (!node) return NULL;
        if (map.find(node) != map.end()) return map[node];
        UndirectedGraphNode *root = new UndirectedGraphNode(node->label);
        map[node] = root;
        for (auto &n: node->neighbors) {
            root->neighbors.push_back(dfs(n));
        }
        return root;
    }
private:
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> map;
};
