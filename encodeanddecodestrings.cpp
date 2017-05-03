class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string encoded = "";
        for (auto &s: strs) {
           encoded += to_string(s.length()) + "@" + s; 
        }
        return encoded;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        int head = 0;
        int numPos;
        int len;
        while(head < s.length()) {
            numPos = s.find_first_of('@', head);
            len = stoi(s.substr(head, numPos-head));
            head = numPos+1;
            res.push_back(s.substr(head, len));
            head += len;
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
