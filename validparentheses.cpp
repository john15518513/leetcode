class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> table = {{')', '('}, {']', '['}, {'}', '{'}};
        stack<char> stackT;
        for (auto &c: s) {
            if (table.find(c) == table.end()) {
                stackT.push(c);
            }
            else {
                if (stackT.size() == 0 or table[c] != stackT.top()) return false;
                stackT.pop();
            }
        }
        return stackT.size() == 0;
    }
};
