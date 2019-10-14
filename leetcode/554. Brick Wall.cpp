class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        if (wall.size() == 0) {
            return 0;
        }

        unordered_map<int, int> hash;
        int res = 0;
        for (vector<int> vec : wall) {
            int sum = 0;
            for (int i = 0; i < vec.size(); i++) {
                sum += vec[i];
                ++hash[sum];
            }
            res = max(res, hash[sum]);
        }

        return wall.size() - res;
    }
};