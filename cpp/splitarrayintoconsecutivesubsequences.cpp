class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> freq;
        unordered_map<int, int> appendFreq;
        for (auto &n: nums) freq[n]++;
        for (auto &i: nums) {
            if (freq[i] == 0) continue;
            else if (appendFreq[i] > 0) {
                appendFreq[i] -= 1;
                appendFreq[i+1] += 1;
            }
            else if (freq[i+1] > 0 and freq[i+2] > 0) {
                freq[i+1] -= 1;
                freq[i+2] -= 1;
                appendFreq[i+3] += 1;
            }
            else return false;
            freq[i]--;
        }
        return true;
    }
};
