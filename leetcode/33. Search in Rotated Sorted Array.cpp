class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 1 && nums[0] == target) {
            return 0;
        }
        int left = 0;
        int right = nums.size() - 1;
        int mid;
        while (right > left) {
            mid = (left + right) / 2;
            if (nums[mid] == target) return mid;
            if (nums[left] == target) return left;
            if (nums[right] == target) return right;

            if (nums[mid] > nums[left]) {
                if (nums[left] < target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                if (nums[right] > target && target > nums[mid]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};