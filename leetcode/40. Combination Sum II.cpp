class Solution {
public:
    vector<vector<int>> res;
    bool isExit(vector<int>& tmp)
    {
        sort(tmp.begin(), tmp.end());
        for (int i = 0; i < res.size(); i++) {
            if (tmp.size() == res[i].size() && tmp[0] == res[i][0]) {
                int j = 0;
                for (; j < tmp.size(); j++) {
                    if (tmp[j] != res[i][j]) {
                        break;
                    }
                }
                if (j == tmp.size()) {
                    return true;
                }
            }
        }
        return false;
    }

    void helper(vector<int>& tmp, int start, vector<int>& candidates, int target) {
        if (target == 0 && !isExit(tmp)) {
            res.push_back(tmp);
            return;
        }
        if (target < 0 || start >= candidates.size()) {
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            tmp.push_back(candidates[i]);
            helper(tmp, i + 1, candidates, target - candidates[i]);
            tmp.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> tmp;
        sort(candidates.begin(), candidates.end());
        helper(tmp, 0, candidates, target);
        return res;
    }
};