/* 
problem:
Given an array nums of n integers and an integer target, 
find three integers in nums such that the sum is closest to target. 
Return the sum of the three integers. You may assume that each input would have exactly one solution.

example:
    Given array nums = [-1, 2, 1, -4], and target = 1.
    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/
int ArrySum(vector<int>& nums)
{
	int result = 0;
	for (vector<int>::iterator iter = nums.begin(); iter != nums.end(); iter++) {
		result += (*iter);
	}
	return result;
}
void updateResult(int tmpValue, int target, int& result)
{
	int subValue = (target - tmpValue > 0) ? (target - tmpValue) : (tmpValue - target);
	int abRet = (result - target) > 0 ? (result - target) : (target - result);
	result = (abRet > subValue) ? tmpValue : result;
}
int threeSumClosest(vector<int>& nums, int target) {
	std::sort(nums.begin(), nums.end());
	int result = 10000;
	int len = nums.size();
	if (len < 3) return ArrySum(nums);
	int i = 0;
	int j = i + 1;
	int k = len - 1;
	int sum = 0;
	int index = 0;
	while (i < len - 2) {
		j = i + 1;
		k = len - 1;
		while (j < k) {
			sum = nums[i] + nums[j] + nums[k];
			if (sum == target) {
				return target;
			} else if (sum < target) {
				updateResult(sum, target, result);
				for (index = j, j = j + 1; nums[j] == nums[index] && j < k; j++);
			} else {
				updateResult(sum, target, result);
				for (index = k, k = k - 1; nums[k] == nums[index] && j < k; k--);
			}
		}
		for (index = i, i = i + 1; nums[i] == nums[index] && i < len - 2; i++);
	}
	return result;
}