/**
 *  Multiply Strings 
 *  Given two numbers represented as strings,
 *  return multiplication of the numbers as a string.
 */

class Solution {
public:
    string multiply(string num1, string num2) {
		if(num1=="0" || num2=="0") 
		    return "0";
            
		int l1 = num1.length();
        int l2 = num2.length();
        
		int* n1 = new int[l1];
		int* n2 = new int[l2];
		int* res = new int[l1+l2];
		memset(res, 0, sizeof(int)*(l1+l2));
        		
		for(int i = 0; i < l1; ++i)
			n1[i] = num1[i] - '0';
			
		for(int i = 0; i < l2; ++i)
			n2[i] = num2[i] - '0';
		
		for(int i = 0; i < l1; ++i)
			for (int j = 0; j < l2; ++j)
				res[i+j+1] += n1[i]*n2[j];

		string ss = "";
        
		for (int k = l1+l2-1;  k >= 0;  --k) {
			if(k > 0) 
                res[k-1] += res[k] / 10;
                
			res[k] %= 10;
			ss = char(res[k]+'0')+ss;
		}
  
		ss = ss[0]=='0'? ss.substr(1):ss;
        
		return ss;
    }
};