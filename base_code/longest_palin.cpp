class Solution {
public:
    enum PalinT {
        Odd_Palin = 0,
        Before_Even_Palin,
        After_Even_Palin,
        Not_Palin
    };
    PalinT JudgeIsPalin(char pre, char cur, char next) {
        if(pre == next) {
            return Odd_Palin;
        } else if(pre == cur && pre != next) {
            return Before_Even_Palin;
        } else if(cur == next && pre != next) {
            return After_Even_Palin;
        }
        return Not_Palin;
    }
    void OddPalinProc(stuck<char>& stk, const string& s, int& nextIdx) {
        int oldPre = nextIdx - 2;
        ret = s[nextIdx - 1];
        int newLen = 0;
        while(!stk.empty() && nextIdx < s.length() && stk.top() == s[nextIdx]) {
            ret = stk.top() + ret;
            ret = ret + s[nextIdx];
            nextIdx++;
            newLen++;
            stk.pop();
        }
        len = newLen + 1;
        while(newLen--) {
            stk.push(s[oldPre--]);
        }
        return;
    }
    void AfterEvenPalinProc(stuck<char>& stk, const string& s, int& nextIdx) {
        //nothing to do, just continue;
        return;
    }
    void BeforeEvenPalinProc(stuck<char>& stk, const string& s, int& nextIdx) {
        int oldPre = nextIdx - 2;
        int newLen = 0;
        ret = s[nextIdx - 2];
        ret = ret + s[nextIdx - 1];
        stk.pop();
        while(!stk.empty() && nextIdx < s.length() && stk.top() == s[nextIdx]) {
            ret = stk.top() + ret;
            ret = ret + s[nextIdx];
            nextIdx++;
            newLen++;
            stk.pop();
        }
        len = newLen + 2;
        while(newLen--) {
            stk.push(s[oldPre--]);
        }
        return;
    }
    void DefaultProc(stuck<char>& stk, const string& s, int& nextIdx) {
        //nothing to do, just continue;
        return;
    }
    void UpdatePalinLen(enum PalinT palinType, stuck<char>& stk, const string& s, int& nextIdx) {
        stk.push(s[nextIdx - 2]);
        switch(palinType) {
            case Odd_Palin:
                OddPalinProc(stk, s, nextIdx);
                break;
            case After_Even_Palin:
                AfterEvenPalinProc(stk, s, nextIdx);
                break;
            case Before_Even_Palin:
                BeforeEvenPalinProc(stk, s, nextIdx);
                break;
            default:
                DefaultProc(stk, s, nextIdx);
                break;
        }
        maxLen = maxLen > len ? maxLen : len;
        result =  maxLen > len ? result : ret;
        return;
    }
    string longestPalindrome(string s) {
        stuck<char> stk;
        int strLen = s.length();
        if((strLen = s.length()) <= 3) {
            return s;
        }

        int len = 0;
        int palinType;
        char pre  = s[0];
        char cur  = s[1];
        char next = s[2];

        for(int i=3; i<strLen; i++) {
            palinType = JudgeIsPalin(pre, cur, next);
            UpdatePalinLen(palinType, stk, s, i-1);
            pre = cur;
            cur = next;
            next = s[i];
        }

    }

    private:
    vector<char> result;
    int maxLen = 0;
    int len = 0;
    vector<char> ret;
};