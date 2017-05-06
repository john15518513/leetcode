class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if (!v1.empty()) que.push(make_pair(v1.begin(), v1.end()));
        if (!v2.empty()) que.push(make_pair(v2.begin(), v2.end()));
    }

    int next() {
        auto it = que.front().first;
        auto eit = que.front().second;
        que.pop();
        if (it + 1 != eit) que.push(make_pair(it+1, eit));
        return *it;
    }

    bool hasNext() {
        return !que.empty();
    }
private:
    queue<pair<vector<int>::iterator, vector<int>::iterator>> que;
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
