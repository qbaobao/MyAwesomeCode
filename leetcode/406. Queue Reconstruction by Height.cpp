class Solution {
public:
    static bool cmp(vector<int>& v1, vector<int>& v2) {
        return ((v1[0] > v2[0]) || (v1[0] == v2[0] && v1[1] < v2[1]));
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);
        vector<vector<int>> res;
        for (auto x : people) {
            res.insert(res.begin() + x[1], x);
        }
        return res;
    }
};