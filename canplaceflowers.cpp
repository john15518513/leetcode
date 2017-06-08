class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for (int i = 0; i < flowerbed.size(); i++) {
            if (!flowerbed[i] and (i == 0 || !flowerbed[i-1] ) and (i == flowerbed.size()-1 || !flowerbed[i+1])) {
                flowerbed[i] = 1;
                n--;
            }
        }
        return n <= 0;
    }
};
