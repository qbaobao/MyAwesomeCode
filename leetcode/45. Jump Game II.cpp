class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() <= 1) {
            return 0;
        }
        if (nums[0] >= nums.size() - 1) {
            return 1;
        }
        int start = 0;
        int begin = 0;
        int end = nums[begin] + begin;
        int maxLen = 0;
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            nums[i] = nums[i] ? nums[i] : 1;
        }
        while (end < nums.size() - 1) {
            maxLen = 0;
            end = nums[begin] + begin;
            for (int j = begin + 1; j < nums.size() && j <= end; j++) {
                if (j + nums[j] >= maxLen) {
                    maxLen = nums[j] + j;
                    start = j;
                }
            }
            begin = start;
            cnt++;
        }
        return cnt;
    }
};