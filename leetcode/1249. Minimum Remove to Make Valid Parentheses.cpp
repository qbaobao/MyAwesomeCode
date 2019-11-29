class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> q;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                q.push(i);
            } else if (s[i] == ')') {
                if (!q.empty() && s[q.top()] == '(') {
                    q.pop();
                } else {
                    q.push(i);
                }
            }
        }
        while (!q.empty()) {
            s.erase(q.top(), 1);
            q.pop();
        }
        return s;
    }
};