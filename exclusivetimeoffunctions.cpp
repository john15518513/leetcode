class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> res(n, 0);
        int prev = 0;
        int index1, index2, id, timestamp;
        string se;
        stack<int> st;
        for (auto &s: logs) {
            index1 = s.find(":");
            index2 = s.find(":", index1+1);
            id = stoi(s.substr(0, index1));
            se = s.substr(index1+1, index2-index1-1);
            timestamp = stoi(s.substr(index2+1));
            if (st.size()) res[st.top()] += timestamp-prev;
            prev = timestamp;
            if (se == "start") {
                st.push(id);
            }
            else {
                res[st.top()]++;
                st.pop();
                prev++;
            }
        }
        return res;
    }
};
