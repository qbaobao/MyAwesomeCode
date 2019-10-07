class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        if (nums.size() == 0) {
            return res;
        }
        if (nums.size() == 1 && nums[0] == target) {
            res[0] = res[1] = 0;
            return res;
        }
        int left = 0;
        int right = nums.size() - 1;
        int mid = 0;
        while (left < right) {
            mid = (left + right) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        res[0] = (nums[left] == target) ? left : -1;
        left = 0;
        right = nums.size() - 1;
        while (left < right) {
            mid = (left + right + 1) / 2;
            if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid;
            }
        }
        res[1] = (nums[right] == target) ? right : -1;
        return res;
    }
};