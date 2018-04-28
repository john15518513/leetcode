class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;
        vector<int> s1cnt(26, 0);
        vector<int> s2cnt(26, 0);
        for (auto &c: s1) {
            s1cnt[c-'a'] += 1;
        }
        for (int i = 0; i < s1.length(); i++) {
            s2cnt[s2[i]-'a'] += 1;
        }
        if(isSame(s1cnt, s2cnt)) return true;
        for (int i = s1.length(); i < s2.length(); i++) {
            s2cnt[s2[i]-'a']++;
            //cout << i-s1.length() << " ";
            s2cnt[s2[i-s1.length()]-'a']--;
            //cout << s2[i-s1.length()]-'a' << endl;
            //cout << s2[i] << " " << s2[i-s1.length()] << endl;
            if(isSame(s1cnt, s2cnt)) return true;
        }
        return false;
        
    }
    bool isSame(vector<int> &s1cnt, vector<int> &s2cnt) {
        /*for (int i = 0; i < 26; i++) {
            cout << s1cnt[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < 26; i++) {
            cout << s2cnt[i] << " ";
        }
        cout << endl;*/
        for (int i = 0; i < 26; i++) {
            if (s1cnt[i] != s2cnt[i]) return false;
        }
        return true;
    }
};
