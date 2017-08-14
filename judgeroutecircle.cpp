class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0, y = 0;
        for (auto &s: moves) {
            switch(s) {
                case 'U':
                    y += 1;
                    break;
                case 'D':
                    y -= 1;
                    break;
                case 'L':
                    x -= 1;
                    break;
                case 'R':
                    x += 1;
                    break;
                default:
                    break;
            }
        }
        return x == 0 and y == 0;
    }
};
