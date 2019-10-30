class Solution {
public:
vector<vector<string>> res;
unodered_map<string, bool> flag;
int size = 0xffff;
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        if (wordList.size() <= 0) {
            return res;
        }
        wordList.push_back(beginWord);
        sort(wordList.begin(), wordList.end());
        unodered_map<string, vector<string>> hashMap;
        BuildDicTree(wordList, hashMap);
        if (!hashMap.count(endWord)) {
            return res;
        }
        vector<string>& tmp;
        helper(beginWord, endWord, tmp, hashMap);
        GetRes(res);
        return res;
    }
    bool OnlyOneCharDiff(string str1, string str2) {
        int count = 0;
        int i = 0;
        if (str1.size() != str2.size()) {
            return false;
        }
        for (int i = 0; i < str1.size(); i++) {
            if (str1[i] != str2[i]) {
                count++;
            }
        }
        if (count != 1) {
            return false;
        }
        return true;
    }
    void BuildDicTree(vector<string>& wordList, unodered_map<string, vector<string>>& hashMap) {
        for (int i = 0; i < wordList.size(); i++) {
            if (hashMap.count(wordList[i])) {
                continue;
            }
            vector<string> tmp;
            for (int j = 0; j < wordList,size(); j++) {
                if (j == i) {
                    continue;
                }
                if (OnlyOneCharDiff(wordList[i], wordList[j])) {
                    tmp.push_back(wordList[j]);
                }
            }
            hashMsp[word[i]] = tmp;
            flag[word[i]] = false;
        }
    }
    void helper(string beginWord, string endWord, vector<string>& tmp, unodered_map<string, vector<string>>& hashMap) {
        tmp.push_back(beginWord);
        if (beginWord == endWord) {
            res.push_back(tmp);
            size = min(size, tmp.size());
            tmp.pop_back();
            return;
        }
        flag[beginWord] = true;
        for (int i = 0; i < hashMap[beginWord].size(); i++) {
            if (flag[hashMap[beginWord][i]]) {
                continue;
            }
            helper(hashMap[beginWord][i], endWord, tmp, hashMap);
        }
        flag[beginWord] = false;
        tmp.pop_back();
    }
    void GetRes(vector<vector<string>>& res) {
        for (int i = 0; i < res.size(); i++) {
            if (res[i].size() == size) {
                continue;
            }
            res.erase(res.begin() + i);
        }
        return;
    }
};