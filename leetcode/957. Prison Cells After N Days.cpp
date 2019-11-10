class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        int isEist[256] = {0};
        int times = 0;
        int circle = 0;
        do {
            times++;
            int bitmap = 0;
            vector<int> tmp(cells.size(), 0);
            for (int i = 1; i < cells.size() - 1; i++) {
                if (cells[i - 1] == cells[i + 1]) {
                    bitmap |= (1 << i);
                    tmp[i] = 1;
                }
            }
            if (isEist[bitmap] == 0) {
                isEist[bitmap] = times;
            } else {
                cells = tmp;
                circle = times - isEist[bitmap];
                break;
            }
            cells = tmp;
        } while (--N);
        int res = (circle == 0) ? 0 : ((N - 1) % circle);
        for (int i = 0; i < res; i++) {
            vector<int> tmp(cells.size(), 0);
            for (int i = 1; i < cells.size() - 1; i++) {
                if (cells[i - 1] == cells[i + 1]) {
                    tmp[i] = 1;
                }
            }
            cells = tmp;
        }
        return cells;
    }
};