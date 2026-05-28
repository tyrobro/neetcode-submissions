class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int>charInd;
        int l = 0;
        int ans = 0;
        int n = s.size();
        
        for(int r = 0; r< n; r++){
            if(charInd.find(s[r]) != charInd.end()){
                l = max(charInd[s[r]]+1, l);
            }
            charInd[s[r]] = r;
            ans = max(ans, r - l +1);
        }

        return ans;
        
    }
};
