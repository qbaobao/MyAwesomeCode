class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> tmp;
        helper(tmp, 0, candidates, target);
        return res;
    }
    
    void helper(vector<int>& tmp, int start, vector<int>& candidates, int target) {
        if (target == 0) {
            res.push_back(tmp);
            return;
        }
        if (target < 0) {
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            tmp.push_back(candidates[i]);
            helper(tmp, i, candidates, target - candidates[i]);
            tmp.pop_back();
        }
        return;
    }
};