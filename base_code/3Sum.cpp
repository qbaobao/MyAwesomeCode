/* 
problem:
  Given an array nums of n integers, 
   are there elements a, b, c in nums such that a + b + c = 0? 
   Find all unique triplets in the array which gives the sum of zero. 

example:
    Given array nums = [-1, 0, 1, 2, -1, -4],
    A solution set is:
    [
    [-1, 0, 1],
    [-1, -1, 2]
    ]
*/

vector<vector<int>> threeSum(vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    int len = nums.size();
    if(len < 3) return result;
    int i = 0;
    int j = i + 1;
    int k = len - 1;
    int sum = 0;
        
    while(i < len - 2) {
        if(nums[i] > 0) break;
        j = i + 1;
        k = nums.size() - 1;
        while(j < k) {
            sum = nums[i] + nums[j] + nums[k]; 
            if(sum == 0) {
                result.push_back({nums[i], nums[j], nums[k]});
                while(nums[j] == nums[++j] && j < k);
                while(nums[k] == nums[--k] && j < k);
            } else if(sum < 0 ) {
                while(nums[j] == nums[++j] && j < k);
            } else {
                while(nums[k] == nums[--k] && j < k);
            }
        }
        while(nums[i] == nums[++i] && i < len - 2);
    }
    return result;
}