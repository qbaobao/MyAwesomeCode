class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (s.size() == 0 || words.size() == 0 || (words.size() * words[0].size() > s.size())) {
            return res;
        }
        unordered_map<string, int> hashMap1, hashMap2;
        for (string str : words) {
            ++hashMap1[str];
        }
        int left = 0;
        int count = 0;
        int step = words[0].size();
        string strTmp = "";
        for (int i = 0; i < step; i++) {
            left = i;
            count = 0;
            hashMap2.clear();
            for (int j = i; j <= s.size() - step; j += step) {
                strTmp = s.substr(j, step);
                if (hashMap1.count(strTmp)) { // 目标字符串数组中包含strTmp字符串
                    ++hashMap2[strTmp];
                    ++count;
                    while (hashMap2[strTmp] > hashMap1[strTmp]) {  // 当前内层循环中遍历到的strTmp个数超过目标字符串数组中此字符串的个数将第一次出现strTmp到第二次出现strTmp之间的字符串全部移除hashMap2
                        string strTmp1 = s.substr(left, step);
                        --hashMap2[strTmp1];
                        --count;
                        left += step;
                    }
                }
                else {  // 目标字符串数组中不包含strTmp字符串,则一切从头开始
                    count = 0;
                    hashMap2.clear();
                    left = j + step;
                }
                if (count == words.size()) {  //当此时hashMap2的元素和hashMap1的元素一致，将left记录在vector中。同时除掉第一个字符。
                    res.push_back(left);
                    --hashMap2[s.substr(left, step)];
                    --count;
                    left += step;
                }
            }
        }
        return res;
    }
};