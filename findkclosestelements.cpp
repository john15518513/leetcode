class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int index = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int i = index-1, j = index;
        while (k--) {
            (i<0 || (j<arr.size() && abs(arr[j]-x) < abs(arr[i]-x)))? j++:i--;
        }
        return vector<int>(arr.begin()+i+1, arr.begin()+j);
    }
};
