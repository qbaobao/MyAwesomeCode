/*
53. Maximum Subarray
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
Follow up:
If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
    Example:
        Input: [-2,1,-3,4,-1,2,1,-5,4],
        Output: 6
        Explanation: [4,-1,2,1] has the largest sum = 6.

分析：采用动态规划完成
    1. dp[i]表示以nums[i]结尾的子数组的最大和。
    2. dp[i] = max(dp[i - 1] + nums[i], nums[i]); //  dp[i-1]表示以nums[i-1]结尾的最大子数组和,如果dp[i-1]+nums[i]<nums[i],则以nums[i]结尾的子数组和不应该包含dp[i-1]相关的数组元素。
        maxSum = max(maxSum, dp[i]);
    3. 返回maxSum

*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() <= 0) {
            return 0;
        }

        int thisSum = nums[0];
        int maxSum = nums[0];

        for(int i = 1; i < nums.size(); i++) {
            thisSum = max(thisSum + nums[i], nums[i]);
            maxSum = max(maxSum, thisSum);
        }
        return maxSum;
    }
};