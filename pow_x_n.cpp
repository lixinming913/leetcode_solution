/*
 *  Pow(x, n) 
 */


class Solution1 {
public:
    double myPow(double x, int n) {
        if (n == 0) {
            return 1.0;
        }
        
        if (n < 0) {
            x = 1.0 / x;
            n = -n;
        }
        
        double res = myPow(x, n / 2);
        
        if(n % 2 == 0)
            return res*res;
        else
            return x*res*res;
    }
};


class Solution2 {
public:
    double myPow(double x, int n) {
        if(n < 0) {
            if(n == INT_MIN)
                return 1.0 / (myPow(x, INT_MAX)*x);
            else
                return 1.0 / myPow(x, -n);
        }
        
        if(n == 0)
            return 1.0;
        
        double ans = 1.0;
        for(; n > 0; n>>=1) {
            if(n & 1 > 0)
                ans *= x;
            x *= x;
        }
        
        return ans;
    }
};