class Solution {
public:
    vector<int> findPermutation(string s) {
        int n = s.size();
        vector<int> res;
        for (int i = 1; i <= n+1; i++) res.push_back(i);
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'D') {
                int index = i;
                while (index < s.size() and s[index] == 'D') {
                    index++;
                }
                reverse(res.begin()+i, res.begin()+index+1);
                i = index-1;
            }
        }
        return res;
    }
};
