class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }

        int preNum = nums[0];
        int preIdx = 1;
        int count = 1;
        for (int i = 1; i < nums.size(); i++) {
            for (; i < nums.size() && nums[i] == preNum; i++) ;
            if (i < nums.size()) {
                nums[preIdx] = nums[i];
                count++;
                preIdx++;
                preNum = nums[i];
            }
        }
        nums.resize(count);
        return count;
    }
};