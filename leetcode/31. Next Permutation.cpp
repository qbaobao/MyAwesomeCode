class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() == 0) {
            return;
        }
        bool flag = false;
        for (int i = nums.size() - 1; i > 0; i--) {
            if (nums[i] > nums[i - 1]) {
                flag = true;
                int j = nums.size() - 1;
                for (; j >= i && nums[j] <= nums[i - 1]; j--) ;
                nums[i - 1] ^= nums[j];
                nums[j] ^= nums[i - 1];
                nums[i - 1] ^= nums[j];
                sort(nums.begin() + i, nums.end());
                break;
            }
        }
        if (!flag) {
            sort(nums.begin(), nums.end());
        }
        return;
    }
};