int FindMindNum(vector<int>& nums1, int lStart, vector<int>& nums2, int rStart, int k)
{
	if (lStart >= nums1.size()) {
		return nums2[rStart + k - 1];
	}
	if (rStart >= nums2.size()) {
		return nums1[lStart + k - 1];
	}
	if (k == 1) {
		return min(nums1[lStart], nums2[rStart]);
	}
	int min1 = (lStart + k / 2 - 1 < nums1.size()) ? nums1[lStart + k / 2 - 1] : 0xffff;
	int min2 = (rStart + k / 2 - 1 < nums2.size()) ? nums2[rStart + k / 2 - 1] : 0xffff;

	return ((min1 < min2) ? FindMindNum(nums1, lStart + k / 2, nums2, rStart, k - k / 2) : FindMindNum(nums1, lStart, nums2, rStart + k / 2, k - k / 2));
}
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	int length1 = nums1.size();
	int length2 = nums2.size();
	int lMind = (length1 + length2 + 1) / 2;
	int rMind = (length1 + length2 + 2) / 2;

	return (FindMindNum(nums1, 0, nums2, 0, lMind) + FindMindNum(nums1, 0, nums2, 0, rMind)) * 1.0 / 2;
}