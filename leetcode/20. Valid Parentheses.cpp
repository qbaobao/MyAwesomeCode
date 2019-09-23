class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        bool flag = true;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '[' || s[i] == '(' || s[i] == '{') {
                st.push(s[i]);
            } else if (!st.empty()){
                if ((s[i] == ']' && st.top() == '[') ||
                    (s[i] == ')' && st.top() == '(') ||
                    (s[i] == '}' && st.top() == '{')) {
                        st.pop();
                    } else {
                        break;
                    }
            } else {
                flag = false;
                break;
            }
        }
        if (st.empty() && flag) {
            return true;
        } else {
            return false;
        }
    }
};