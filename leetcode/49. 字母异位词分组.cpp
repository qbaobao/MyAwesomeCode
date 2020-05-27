class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        map<map<char,int>,vector<string>>strMap;
        vector<int> bitMap;
        for (auto s : strs) {
            map<char, int> m;
            for (int i = 0; i < s.size(); i++) {
                m[s[i]]++;
            }
            strMap[m].push_back(s);
        }

        for (auto it = strMap.begin(); it != strMap.end(); ++it) {
            if (it->second.size() > 0) {
                result.push_back(it->second);
            }
        }
        return result;
    }
};