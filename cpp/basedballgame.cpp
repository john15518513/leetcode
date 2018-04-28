class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> stack;
        for (auto &s: ops) {
            if (s == "+") stack.push_back(stack.back()+stack[stack.size()-2]);
            else if (s == "D") {
                stack.push_back(stack.back()*2);
            }
            else if (s == "C") stack.pop_back();
            else stack.push_back(stoi(s));
        }
        int count = 0;
        for (auto &e: stack) {
            //cout << e << endl;
            count += e;
        }
        return count;
    }
};
