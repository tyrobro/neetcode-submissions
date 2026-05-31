class Solution {
public:
    string minWindow(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();
        if(n2 < 1){
            return "";
        }
        unordered_map<char, int> countT, window;

        for(char c: t){
            countT[c]++;
        }

        int seen = 0;
        int total = countT.size();
        pair<int, int> ans = {-1, -1};
        int ansLen = INT_MAX;
        int l = 0;

        for(int r = 0; r < n1; r++){
            char c = s[r];
            window[c]++;

            if(countT.count(c) && window[c] == countT[c]){
                seen++;
            }

            while(seen == total){
                if((r- l + 1) < ansLen){
                    ansLen = r - l + 1;
                    ans = {l, r};
                }

                window[s[l]]--;
                if(countT.count(s[l]) && window[s[l]] < countT[s[l]]){
                    seen--;
                }
                l++;
            }
        }

        return ansLen == INT_MAX?"":s.substr(ans.first, ansLen);

    }
};
