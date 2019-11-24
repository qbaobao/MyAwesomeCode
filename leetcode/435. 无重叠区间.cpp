class Solution {
public:

    static bool cmp(vector<int> vec1, vector<int> vec2) {
        return vec1[0] < vec2[0] || (vec1[0] == vec2[0] && vec1[1] < vec2[1]);
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1) {
            return 0;
        }
        sort(intervals.begin(), intervals.end(), cmp);
        int start = intervals[intervals.size() - 1][0];
        int count = 1;
        for (int i = intervals.size() - 2; i >= 0; i--) {
            if (intervals[i][1] <= start) {
                start = intervals[i][0];
                count++;
            }
        }
        return intervals.size() - count;
    }
};