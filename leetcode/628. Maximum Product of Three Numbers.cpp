class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        if(nums[0] > 0 || nums[nums.size() - 1] <= 0) {
            return (nums[nums.size() - 3]) * (nums[nums.size() - 2]) * (nums[nums.size() - 1]);
        } else {
            int tmp = max(nums[nums.size() - 2] * nums[nums.size() - 3], nums[0] * nums[1]);
            return tmp * nums[nums.size() - 1];
        }
        return 0;
    }
};