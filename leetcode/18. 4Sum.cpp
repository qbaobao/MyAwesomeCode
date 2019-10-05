class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if (nums.size() == 0) {
            return res;
        }
        sort(nums.begin(), nums.end());
        if (nums[0] > target) {
            return res;
        }
        
        for (int i = 0; i < nums.size() - 3; i++) {
            Get3Sum(nums, target - nums[i], i, res);
        }
        return res;
    }

    void Get3Sum(vector<int>& nums, int target, int start, vector<vector<int>>& res) {
		int len = nums.size();
		if (len < 3) return;
        int i = start + 1;
        int j = i + 1;
        int k = len - 1;
        int sum = target;
        while(i < len - 2) {
            if(nums[i] > 0) break;
            j = i + 1;
            k = len - 1;
            while(j < k) {
                sum = nums[i] + nums[j] + nums[k]; 
                if(sum == target) {
                    res.push_back({nums[start], nums[i], nums[j], nums[k]});
                    while(nums[j] == nums[++j] && j < k);
                    while(nums[k] == nums[--k] && j < k);
                } else if(sum < target) {
                    while(nums[j] == nums[++j] && j < k);
                } else {
                    while(nums[k] == nums[--k] && j < k);
                }
            }
            while(nums[i] == nums[++i] && i < len - 2);
        }
		return;
    }
};