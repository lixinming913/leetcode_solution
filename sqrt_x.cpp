/*
 *  sqrt(x)
 */

class Solution1 {
public:
    int mySqrt(int x) {
        if(x < 0)
            return -1;
            
        if(x == 0)
            return 0;
        
        int left = 1;
        int right = x;
        while (left < right) {
            int mid = (left + right) / 2;
            if (x / mid == mid) 
                return mid;
            else if (x / mid > mid) {
                if (x / (mid + 1) < mid + 1) 
                    return mid;
                else    
                    left = mid + 1;
            }
            else 
                right = mid - 1;
        }
        return left;
    }

};


class Solution2 {
public:
    int mySqrt(int x) {
        if(x < 0)
            return -1;
            
        unsigned long long begin = 0;
        unsigned long long end = (x+1)/2;
        unsigned long long mid;
        unsigned long long tmp;
        
        while(begin < end) {
            mid = begin + (end - begin) / 2;
            tmp = mid * mid;
            if(tmp == x)
                return mid;
            else if(tmp < x)
                begin = mid + 1;
            else
                end = mid - 1;
        }
        
        tmp = end * end;
        if(tmp > x)
            return end-1;
        else
            return end;
            
    }
};


class Solution3 {
public:
    int mySqrt(int x) {
        if(x < 0)
            return -1;
            
        if(x == 0)
            return 0;
        
        double pre;
        double cur = 1;
        do {
            pre = cur;
            cur = pre / 2.0 + x / (2 * pre);
        }while(abs(cur - pre) > 0.00001);
        
        return int(cur);
    }
};