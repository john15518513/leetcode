class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int k = numbers.size()-1;
        int j = 0;
        while(j<k){
            if (numbers[j]+numbers[k]>target){
                k--;
            }
            else if (numbers[j]+numbers[k] < target){
                j++;
            }
            else{
                vector<int> res{j+1,k+1};
                return res;
            }
        }
    }
};
