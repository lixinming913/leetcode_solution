/**
 *  Reverse Integer 
 *  Reverse digits of an integer. Example1: x = 123, return 321;x = -123, return -321
 *  除以10是因为当其真的超过边界时，num根本无法表示，所以直接判断少一位时是否已经触犯边界
 */
int reverse(int x) {
    int num = 0;
    while(x) {
        if(num > INT_MAX/10 || num < INT_MIN/10) 
            return 0;
        num = num*10 + x % 10;
        x /= 10;
    }

    
    return num;
}