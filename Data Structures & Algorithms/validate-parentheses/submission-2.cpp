class Solution {
public:
    bool isValid(string s) {
        stack<char> c;

        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];

            if (ch == '{' || ch == '[' || ch == '(') {
                c.push(ch);
            } else {
                if (c.empty()) return false;

                if ((ch == ')' && c.top() != '(') ||
                    (ch == '}' && c.top() != '{') ||
                    (ch == ']' && c.top() != '[')) {
                    return false; 
                }

                c.pop();
            }
        }

        return c.empty();
    }
};