class Solution {
public:
    vector<string> ans;
    vector<string> digitToChar = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return ans;

        helper(0, "", digits);
        return ans;    
    }

    void helper(int i, string curr, string &digits){
        if(curr.size() == digits.size()){
            ans.push_back(curr);
            return;
        }

        string chars = digitToChar[digits[i] - '0'];
        for(char c: chars){
            helper(i+1, curr + c, digits);
        }
    }
};
