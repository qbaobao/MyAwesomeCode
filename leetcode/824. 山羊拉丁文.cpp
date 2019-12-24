class Solution {
public:
    string toGoatLatin(string S) {
        if (S.size() == 0) {
            return S;
        }

        bool flag = (S[S.size() - 1] == ' ');
        S = S + (flag ? "s" : " s");
        int start = 0;
        size_t pos = S.find(' ', start);
        string aa = "a";
        while (pos != string::npos && start < S.size() - 2) {
            string ss = "";
            if (S[start] == 'a' || S[start] == 'e' ||
                S[start] == 'i' || S[start] == 'o' ||
                S[start] == 'u' || S[start] == 'A' ||
                S[start] == 'E' || S[start] == 'I' ||
                S[start] == 'O' || S[start] == 'U') {
                ss += "ma";
            }
            else {
                ss += S[start];
                ss += "ma";
                S.erase(S.begin() + start);
                pos--;
            }
            ss += aa;
            aa += 'a';
            S.insert(pos, ss);
            pos += ss.size();
            start = pos + 1;
            pos = S.find(' ', start);
            pos = pos == string::npos ? S.size() : pos;
        }
        S.erase(S.begin() + S.size() - 2, S.end());
        S += (flag ? " " : "");
        return S;
    }
};