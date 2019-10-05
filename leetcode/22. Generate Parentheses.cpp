class Solution {
public:
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        if (n <= 0) {
            return res;
        }
        string tmp;
        GetParenthesis(0, 0, 0, n, tmp);
        return res;
    }
    void GetParenthesis(int lCnt, int rCnt, int curCnt, int total, string& str){
        if (lCnt == rCnt && lCnt == total) {
            res.push_back(str);
            return;
        }
        string strTmp = str;
        if (curCnt == 0) {
            strTmp = str + '(';
            lCnt++;
            curCnt++;
            GetParenthesis(lCnt, rCnt, curCnt, total, strTmp);
        } else if (lCnt > 0 && lCnt < total) {
            strTmp = str + '(';
            lCnt++;
            curCnt++;
            GetParenthesis(lCnt, rCnt, curCnt, total, strTmp);

            curCnt--;
            lCnt--;

            strTmp = str + ')';
            rCnt++;
            curCnt--;
            GetParenthesis(lCnt, rCnt, curCnt, total, strTmp);
        } else if (lCnt == total) {
            rCnt++;
            curCnt--;
            strTmp = str + ')';
            GetParenthesis(lCnt, rCnt, curCnt, total, strTmp);
        }
        return;
    }
};