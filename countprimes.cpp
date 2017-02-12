class Solution {
public:
    int countPrimes(int n) {
        int sum = 0;
        vector<bool> primenumber(n,true);
        for(int i = 2; i <n; i++){
            if(primenumber[i] == true){
                sum++;
                for(int j = i; j <n; j += i){
                    primenumber[j] = false;
                }
            }
        }
        return sum;
    }
};
