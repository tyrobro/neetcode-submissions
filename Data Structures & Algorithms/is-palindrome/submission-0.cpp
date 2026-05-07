class Solution {
public:
    bool isPalindrome(string s) {
        string ques = "";
        for(auto x:s){
            if((x <='z' && x >='a') || (x <= 'Z' && x >= 'A') || (x <= '9' && x >= '0')){
                ques += tolower(x);
            }
        }

        int n = ques.size();

        for(int i = 0; i < n; i++){
            if(ques[i] != ques[n-i-1]){
                return false;
            }
        } 

        return true;
    }
};
