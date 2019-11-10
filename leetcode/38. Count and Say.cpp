class Solution {
public:
    string countAndSay(int n) {
        string cur = "1";
        for (int i = 2 ; i <= n; i++) {
            updateCur(cur);
        }
        return cur;        
    }
    void updateCur(string& cur) {
        if (cur.size() == 1) {
            cur = "11";
            return; 
        }
        cur = cur + 'A';
        int cnt = 1;
        char pre = cur[0];
        string update = "";
        for (int i = 1; i < cur.size(); i++) {
            if (cur[i] != pre) {
                char tmp = '0' + cnt;
                update = update + tmp;
                update = update + pre;
                pre = cur[i];
                cnt = 0;
            }
            cnt++;
        }
        cur = update;
        return;
    }
};