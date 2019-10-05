class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) {
            return 0;
        }
        if (haystack.size() == 0 && needle.size() != 0) {
            return -1;
        }
        
        return haystack.find(needle);
    }
};