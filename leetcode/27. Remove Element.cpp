class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.size() == 0) {
            return 0;
        }
        int idx = 0;
        for (; idx < nums.size() && nums[idx] != val; idx++) ;
        if (idx >= nums.size()) {
            return 0;
        }
        int count = 1;
        for (int i = idx + 1; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[idx] = nums[i];
                idx++;
            } else {
                count++;
            }
        }
        nums.resize(nums.size() - count);
        return count;
    }
};