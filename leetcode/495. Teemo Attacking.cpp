class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if (timeSeries.size() == 0) {
            return 0;
        }
        long long result = duration;
        for (int i = 0; i < timeSeries.size() - 1; i++) {
            if (timeSeries[i] + duration <= timeSeries[i + 1]) {
                result += duration;
                continue;
            } 
            while (i < timeSeries.size() - 1 && timeSeries[i] + duration > timeSeries[i + 1]) {
                result += (timeSeries[i + 1] - timeSeries[i]);
                i++;
            }
            i--;
        }
        return result;
    }
};