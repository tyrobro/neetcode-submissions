class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int ans = 0;
        int count = 0;
        int n = s.size();
        unordered_map<char, int> mp;

        for(int r = 0; r < n; r++){
            mp[s[r]]++;
            count = max(count, mp[s[r]]);

            while((r-l+1) - count > k){
                mp[s[l]]--;
                l++;
            }
            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};
