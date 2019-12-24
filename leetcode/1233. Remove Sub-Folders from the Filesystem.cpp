class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        if (folder.size() == 0) {
            return folder;
        }
        sort();
        unordered_map<string, int> map;
        for (auto string s : folder) {
            string str = "";
            int cnt = 0;
            for (auto c : s) {
                if (c == '/') {
                    cnt++;
                    continue;
                }
                if (map.count(str))
                str += c;
            }
            
        }


    }
};