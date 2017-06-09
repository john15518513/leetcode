class Solution {
public:
    vector<int> constructRectangle(int area) {
        int target = int(sqrt(area));
        while (area%target != 0) target--;
        return vector<int> {area/target,target};
    }
};
