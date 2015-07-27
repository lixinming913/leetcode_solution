/**
 *  ZigZag Conversion 
 *  The first line and the last line: the space between two adjacent elements is 2*numRows - 2;
 *  Middle lines: the space  between two adjacent elements is 2*numRows-2 - 2*i;
 */

char* convert(char* s, int numRows) {
    int n = strlen(s);
    if(n <= numRows || numRows == 1)
        return s;
    
    char *res;
    int k = 0;
    int span = 2*(numRows - 1)
    for(int i = 0; i < numRows; i++) {
        for(int j = i; j < n; j += span) {
            res[k++] = s[j];
            
            if(i != 0 && i != (numRows - 1)) {
                int t = j + span - 2*i; /*中间行间隔，i为第i行，所取元素位置在t*/
                if(t < n)
                    res[k++] = s[t];
            }
        }
    }
    
    res[k] = '\0';
    return res;
}
