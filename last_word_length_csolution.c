/**
 *  Length of Last Word 
 */


int lengthOfLastWord(char* s) {
    int length = strlen(s);
    int end = length - 1;
    
    while(s[end] == ' ' && end >= 0)
        end--;
    
    if(end < 0)
        return 0;
        
    int begin = end;
    while(s[begin] != ' ' && begin >= 0) 
        begin--;
    
    return end - begin;

}