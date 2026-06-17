class Solution {
public:
    vector<vector<bool>> dp;

    vector<vector<string>> partition(string s) {
        int n = s.length();
        dp.resize(n, vector<bool>(n));

        for(int l = 1; l <=n; l++){
            for(int i = 0; i <= n-l; i++){
                dp[i][i+l-1] = (s[i] == s[i+l-1] &&(i+1 > (i+l-2) || dp[i+1][i+l-2]));
            }
        }

        vector<vector<string>> ans;
        vector<string> part;
        helper(0, s, part, ans);
        return ans;
    }

    void helper(int i, const string& s, vector<string>& part, vector<vector<string>>& ans){
        int n = s.length();
        if(i >= n){
            ans.push_back(part);
            return;
        }

        for(int j = i; j < n; j++){
            if(dp[i][j]) {
                part.push_back(s.substr(i, j - i + 1));
                helper(j+1, s, part, ans);
                part.pop_back();
            }
        }
    }
};
