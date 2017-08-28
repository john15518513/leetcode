class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        vector<int> row(picture.size(), 0);
        vector<int> col(picture[0].size(), 0);
        int count = 0;
        for (int i = 0; i < row.size(); i++) {
            for (int j = 0; j < col.size(); j++) {
                if (picture[i][j] == 'B') {row[i]++; col[j]++;}
            }
        }
        
        for (int i = 0; i < row.size(); i++)
            for (int j = 0; j < col.size(); j++) if (picture[i][j] == 'B' and row[i] == 1 and col[j] == 1) count++;
        return count;
    }
};
