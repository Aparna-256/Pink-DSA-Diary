class Solution {
public:
    int countBits(int n){
        int count = 0;
        while(n>0){
            count = count + n%2;
            n = n/2;
        }
        return count;
    }
    bool isPrime(int n){
        if(n < 2) return false;
        for(int i = 2; i*i <= n; i++){
            if(n%i ==0)return false;
        }
        return true;
    }
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        for(int i = left ; i <= right; i++){
            if(isPrime(countBits(i))){
                ans++;
            }
        }
        return ans;
    }
};
