class Solution {
public:
    bool checkValidString(string s) {
        stack<int> left, star;
        int n = s.size();
        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                left.push(i);
            } else if (s[i] == '*') {
                star.push(i);
            } else {
                if(left.empty() && star.empty()) return false;
                if(!left.empty()) {
                    left.pop();
                } else {
                    star.pop();
                }
            }
        }

        while(!left.empty() && !star.empty()) {
            if(left.top() > star.top()) return false;

            left.pop();
            star.pop();
        }
        return left.empty();
    }
};
