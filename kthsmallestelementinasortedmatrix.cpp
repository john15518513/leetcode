class Solution {
struct cmp
{
    bool operator()(const pair<int,pair<int, int> >& a, const pair<int,pair<int, int> >& b)
    {
        return a.first>b.first;
    }
};
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        priority_queue<pair<int,pair<int, int> >, vector<pair<int, pair<int, int> > >, cmp> pq;
        for (int i = 0; i < n; i++) pq.push(make_pair(matrix[0][i], make_pair(0, i)));
        int ans;
        while (k--) {
            pair<int, int> rc = make_pair(pq.top().second.first, pq.top().second.second);
            ans = pq.top().first;
            //cout << ans << " "<< rc.first << ", " << rc.second <<endl;
            pq.pop();
            if (rc.first != n-1) pq.push(make_pair(matrix[rc.first+1][rc.second],make_pair(rc.first+1, rc.second)));
        }
        return ans;
    }
};
