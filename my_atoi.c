/*
 *  my_atoi()
 *  空格略过，出现字母只算字母前面的有效数字，注意越界问题
 */

enum status{kValid = 0, kInvalid};
int cur_status = kValid;

long long check(char *str, bool minus)
{
    long long num = 0;
    
    while(*str != '\0') {
        int flag = minus ? -1 : 1;
        if(*str >= '0' && *str <= '9') {
            num = num * 10 + flag * (*str - '0');
            
            if(num >= INT_MAX)
                num = INT_MAX;
            if(num <= INT_MIN)
                num = INT_MIN;
             
             ++str;
        } 
        else 
        {
            break;
        }
            
    }
    
    if(*str == '\0') {
        cur_status = kValid;
    }
    
    return num;
}


int myAtoi(char* str) {
    cur_status = kInvalid;
    long long num = 0;

    if(str != NULL && *str != '\0') {
        bool minus = false;
        
        while(*str == ' ')
            ++str;
        
        if(*str == '-') {
            minus = true;
            ++str;
        }
        else if(*str == '+') {
            minus = false;
            ++str;
        }
        
        if(*str != '\0')
            num = check(str, minus);
    }
    
    
    return (int)num;
}