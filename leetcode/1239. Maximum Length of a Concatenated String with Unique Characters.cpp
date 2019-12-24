class Solution {
public:
    int res = 0;
    int maxLength(vector<string>& arr) {
        helper(arr, 0, 0, 0);
        return res;
    }

    void helper(vector<string>& arr, int index, int bitmap, int result) {
        if (index >= arr.size()) {
            res = max(result, res);
            return;
        }
        int flag = true;
        int tmp = bitmap;
        for (auto c : arr[index]) {
            int bit = c - 'a';
            bit = 1 << bit;
            if (bit & tmp) {
                flag = false;
                break;
            }
            tmp |= bit;
        }
        if (flag) {
            result += arr[index].size();
            helper(arr, index + 1, tmp, result);
            result -= arr[index].size();
        }
        helper(arr, index + 1, bitmap, result);
        return;
    }
};