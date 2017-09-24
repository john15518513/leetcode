class Solution {
public:
    string nextClosestTime(string time) {
        unordered_set<int> set;
        for (auto &c: time) {
            set.insert(c-'0');
        }
        int h = stoi(time.substr(0, 2));
        int m = stoi(time.substr(3, 2));
        auto ch = h;
        auto cm = m+1;
        if (cm == 60) {
            cm = 0;
            ch += 1;
        }
        if (ch == 24) {
            ch = 0;
        }
        while (ch*60+cm != h*60+m) {
            if(set.find(ch/10) != set.end() &&
               set.find(ch%10) != set.end() &&
               set.find(cm/10) != set.end() &&
               set.find(cm%10) != set.end()) {
                return (ch<10? "0":"") + to_string(ch) + ":" + (cm<10? "0":"") + to_string(cm);
            }
            cm++;
            if (cm == 60) {
                cm = 0;
                ch += 1;
            }
            if (ch == 24) {
                ch = 0;
            }
        }
        return time;
    }
};
