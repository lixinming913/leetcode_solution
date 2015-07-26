/**
 *  count primes
 */
class Solution {
public:
    int countPrimes(int n) {
        if(n < 2)
            return 0;
            
        bool prime[n];
        memset(prime, true, n*sizeof(bool));
        prime[0] = false;
        prime[1] = false;
        
        int limit = sqrt(n);
        for(int i = 2; i <= limit; ++i) {
            if(prime[i]) {
                for(int j = i*i; j < n; j += i) {
                    prime[j] = false;
                }
            }
        }
        
        int cnt = 0;
        for(int i = 2; i < n; ++i) {
            if(prime[i])
                ++cnt;
        }
            
        return cnt;
    }
};