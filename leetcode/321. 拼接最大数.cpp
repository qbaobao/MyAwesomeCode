class Solution {
public:
	Solution() = default;
	~Solution() = default;
	vector<int> MergeStr(const vector<int>& s1, const vector<int>& s2)
	{
		int l = 0;
		int r = 0;
		vector<int> res;
		auto iter1 = s1.begin(), iter2 = s2.begin();
		while (iter1 != s1.end() || iter2 != s2.end()) {
			res.push_back(lexicographical_compare(iter1, s1.end(), iter2, s2.end()) ? *iter2++ : *iter1++);
		}
		return res;
	}
	vector<int> GetSequence(vector<int>& nums, int len)
	{
		vector<int> res;
		if (nums.size() <= len) {
			return nums;
		}
		int reserve = nums.size() - len;
		for (auto c : nums) {
			while (res.size() > 0 && res.back() < c && reserve-- > 0) {
				res.pop_back();
			}
			res.push_back(c);
		}
		res.resize(len);
		return res;
	}
	vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k)
	{
		vector<int> res(k, 0);
		int size1 = nums1.size();
		int size2 = nums2.size();
		for (int i = max(0, k - size2); i <= min(k, size1); i++) {
			vector<int> s1 = GetSequence(nums1, i);
			vector<int> s2 = GetSequence(nums2, k - i);
			vector<int> s3 = MergeStr(s1, s2);
			res = lexicographical_compare(res.begin(), res.end(), s3.begin(), s3.end()) ? s3 : res;
		}
		return res;
	}
};