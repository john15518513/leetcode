class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size(), n = num2.size();
        vector<int> res(m+n, 0);
        for (int i = m-1; i >= 0; i--) {
            for (int j = n-1; j >= 0; j--) {
                int mul = (num1[i]-'0') * (num2[j]-'0');
                int p1 = i + j, p2 = i + j + 1;
                int sum = mul + res[p2];
                res[p1] += sum / 10;
                res[p2] = (sum) % 10;
            }
        }
        string ans = "";
        int index = 0;
        while (res[index] == 0) index++;
        for (int i = index; i < res.size(); i++) ans = ans + to_string(res[i]);
        return ans.size() == 0? "0":ans;
    }
};
