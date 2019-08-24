class Solution {
public:
    string convert(string s, int numRows) {
        string result = "";
        int k = 0;
        int j = 0;
        int i = 0;

        if (numRows == 1) {
            return s;
        }
        for (i = 0; i < numRows; i++) {
            if (i ==0) {
                for (j = 0, k = 0; j < s.length();
                     ++k, j = (numRows - 1) * 2 * k) {
                        result += s[j];
                }
            } else if(i == numRows - 1) {
                for (j = numRows - 1, k = 0; j < s.length(); 
                     ++k, j = (numRows - 1) * ((2 * k) + 1)) {
                        result += s[j];
                    }
            } else {
                result += s[i];
                for (k = 1, j = (numRows - 1) * 2 * k; (j - i) < s.length(); 
                     ++k, j = (numRows - 1) * 2 * k) {
                        result += s[j - i];
                        result = ((j + i) < s.length()) ? (result + s[j + i]) : result;
                } 
            }
        }
        return result;
    }
};