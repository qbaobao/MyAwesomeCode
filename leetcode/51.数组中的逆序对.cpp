/*
面试题51. 数组中的逆序对
在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。
示例 1:
输入: [7,5,6,4]
输出: 5
限制：
0 <= 数组长度 <= 50000

分析：
采用归并排序。在归并排序的过程中统计逆数对。
因为归并排数的过程中，[nums[1]...nums[i]] [nums[i+1]...nums[j]]
从整体来看，左边这一整坨和右边这一整坨的相对顺序不会变。并且左边这一整坨与右边这一整坨都是有序的。
所以，当左边的nums[idx](1 <= idx <= i) > nums[jdx](i + 1 <= jdx <= j)，左边[idx, i]的数均大于右边的nums[jdx0]。
这样就省去了nums[idx, i]再与nums[jdx]比较。
时间复杂度O(n*lng(n))

*/


class Solution {
public:
    int reversePairs(vector<int>& nums) {
        if (nums.size() <= 1) {
            return 0;
        }
        MergeSort(nums, 0, nums.size() - 1);
        return count;
    }
    void MergeSort(vector<int>& nums, int start, int end) {
        if (start >= end) {
            return;
        }
        int mid = (start + end) / 2;
        MergeSort(nums, start, mid);
        MergeSort(nums, mid + 1, end);
        MergeOne(nums, start, mid, end);
        return;
    }
    void MergeOne(vector<int>& nums, int start, int mid, int end) {
        int i = start;
        int j = mid + 1;
        int idx = 0;
        vector<int> tmpNum(end + 1 - start, 0);
        while (i <= mid && j <= end) {
            if (nums[i] <= nums[j]) {
                tmpNum[idx++] = nums[i++];
            } else {
                tmpNum[idx++] = nums[j++];
                count += (mid - i + 1);
            }
        }
        while (i <= mid) {
            tmpNum[idx++] = nums[i++];
        }
        while (j <= end) {
            tmpNum[idx++] = nums[j++];
        }
        swap_ranges(nums.begin() + start, nums.begin() + end + 1, tmpNum.begin());
        return;
    }

private:
    int count = 0;
};