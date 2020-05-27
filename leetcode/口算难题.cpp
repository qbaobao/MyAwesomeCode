class Solution {
public:
    bool res;
    bool isSolvable(vector<string>& words, string result) {
        vector<bool> canBeZero(m_maxAlphaNum, true);
        vector<int> eco(m_maxAlphaNum, 0);
        vector<bool> alphaVal(10, false);
        words.push_back(result);
        for (int i = 0; i < words.size(); i++) {
            canBeZero[words[i][0] - 'A'] = false;
            for (int j = 0; j < words[i].size(); j++) {
                int flag = (i == words.size() - 1 ?) -1 : 1;
                eco[words[i][j] - 'A'] += (flag * pow(words.size() - j , 10));
            }
        }
        helper(canBeZero, eco, alphaVal, 0, 0);
        return res;
    }

    void helper(vector<bool>& canBeZero, vector<int>& eco, vector<bool>& alphaVal, int start, int resVal)
    {
        if (start == m_maxAlphaNum && resVal == 0) {
            res = true;
            return;
        }
        if (eco[start] == 0) {
            return;
        }
        for (int i = 0; i < 10; i++) {
            if ((i == 0 && !canBeZero[start]) || alphaVal[i]) {
                continue;
            }
            resVal += i * eco[start];
            alphaVal[i] = true;
            helper(canBeZero, eco, alphaVal, start + 1, resVal);
            if (res) {
                break;
            }
            resVal -= i * eco[start];
            alphaVal[i] = false;
        }
        return;
    }

private:
    const int m_maxAlphaNum = 26;
};