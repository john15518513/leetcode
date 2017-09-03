class Solution {
public:
    string rearrangeString(string s, int k) {
        if(k == 0) return s;
        int left = s.size(); 
        unordered_map<char, int> dict;
        priority_queue<pair<int, char>> pq;
        
        for(char ch : s) dict[ch]++;
        for(auto it = dict.begin(); it != dict.end(); it++){
            pq.push(make_pair(it->second, it->first));
        }
        string res = "";
        while(!pq.empty()){
            vector<pair<int, char>> cache; //store used char during one while loop
            int count = min(k, left); //count: how many steps in a while loop
            for(int i = 0; i < count; i++){
                if(pq.empty()) return "";
                auto tmp = pq.top();
                pq.pop();
                res = res + tmp.second;
                if(--tmp.first > 0) cache.push_back(tmp);
                left--;
            }
            for(auto p : cache) pq.push(p);
        }
        return res;
    }
};
