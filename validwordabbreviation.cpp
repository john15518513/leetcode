class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int index = 0;
        int count;
        for (int i = 0; i < abbr.size(); i++) {
            //cout << index << " ";
            if (isdigit(abbr[i]) and abbr[i] != '0') {
                count = 0;
                while (isdigit(abbr[i]) and i < abbr.size()) {
                    count = 10*count + abbr[i]-'0';
                    i++;
                }
                i--;
                index += count;
                if (index > word.size()) return false;
                continue;
            }
            //cout << abbr[i] << " " << word[index] << endl;
            if (abbr[i] != word[index]) return false; 
            index++;
            
        }
        return index == word.size();
    }
};
