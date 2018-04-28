// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long int i = 1;
        long long int j = n;
        long long int mid;
        if(n == 1)return 1;
        while(i <= j){
            mid = (i+j)/2;
            if(isBadVersion(mid)){
                j = mid-1;
            }
            else{
                i = mid+1;
            }
        }
        return i;
    }
};
