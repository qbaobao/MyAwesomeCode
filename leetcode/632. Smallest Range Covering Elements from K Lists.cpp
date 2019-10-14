class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int> res;
        if (nums.size() == 0) {
            return res;
        }

        unodered_map<int, string> flag;
        vector<int> tmp;
        int step = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums[i].size(); j++) {
                tmp.push_back(nums[i][j]);
                if (flag.count(nums[i][j])) {
                    flag[nums[i][j]] =  + 'i';
                } else {
                    flag[nums[i][j]] = flag[nums[i][j]] + 'i';
                }
            }
        }
        sort(tmp.begin(), tmp.end());
        int subV = 0xffff;
        int start = 0;
        int end = tmp.size();
        for (int i = 0; i < step; i++) {
            bool exit[step] = {false};
            bool find = true;
            int count = 0;
            for (int j = i; j <= tmp.size() - step; j += step) {
                string strstr = flag[nums[j]];
                int k = 0;
                for (int k = 0; k < strstr.size(); j++) {
                     if (!exit[strstr[k] - '0']) {
                        exit[idx] = true;
                        count++;
                        break;
                    }                 
                }
                if (k >= strstr.size()) {
                    memset(exit, 0, step);
                    j += (step - count);
                    count = 0;
                }
            }
            if (count == step &&
                subV > (tmp[i + step - 1] - tmp[i])) {
                subV = tmp[i + step - 1] - tmp[i];
                start = i;
                end = i + step - 1;
            }
        }
        res[0] = start;
        res[0] = end;
        return res;
    }
};