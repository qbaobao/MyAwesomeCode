class Solution {
public:
    int res = 0xffff;
    int leastInterval(vector<char>& tasks, int n) {
        if (tasks.size() <= 0 || n <= 0) {
            return 0;
        }
        unodered_map<char, int> t;
        vector<int> count(26, 0);
        for (int i = 0; i < tasks.size(); i++) {
            count[tasks[i] - 'A']++;
        }
        sort(count.begin(); count.end());
        int k = 0;
        for (int i = 25; i >= 0 && count[i] == count[25]; i--, k++) ;

        return max((count[25] - 1) * (n + 1) + k, tasks.size());
    }
};