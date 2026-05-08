class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(char x: s){
            if(x == '(' || x == '{' || x == '['){
                st.push(x);
            }
            else{
                if(st.empty()){
                    return false;
                }
                char up = st.top();
                st.pop();
                if ((x == ')' && up != '(') ||
                    (x == '}' && up != '{') ||
                    (x == ']' && up != '[')) {
                    return false; 
                }
            }
        }

        return st.empty();
    }
};
