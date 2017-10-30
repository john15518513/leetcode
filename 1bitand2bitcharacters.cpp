class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int index = 0;
        while (index < bits.size()-1) {
            if (bits[index] == 1) index += 2;
            else index += 1;
        }
        return index == bits.size()-1;
    }
};
