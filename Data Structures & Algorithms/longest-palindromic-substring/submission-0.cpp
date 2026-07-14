class Solution {
public:
    vector<int> manacher(string& s){
        string t = "#" + string(1, s[0]);
        int n = s.size();
        for(int i = 1; i < n; i++){
            t += "#" + string(1, s[i]);
        }

        t += "#";
        int m = t.size();
        vector<int> p(m, 0);
        int l =0, r = 0;

        for(int i = 0; i < m; i++){
            p[i] = (i < r) ? min(r-i, p[l + (r-i)]) : 0;

            while(i + p[i] + 1 < m && i - p[i] - 1 >=0 && t[i + p[i] + 1] == t[i - p[i] - 1]){
                p[i]++;
            }

            if (i + p[i] > r){
                l = i - p[i];
                r = i + p[i];
            }
        }

        return p;
    }

    string longestPalindrome(string s) {
        vector<int> p = manacher(s);
        int resLen = 0;
        int center_idx = 0;
        int n = p.size();
        for(int i= 0 ;i < n; i++){
            if(p[i] > resLen) {
                resLen = p[i];
                center_idx = i;
            }
        }
        int resIdx = (center_idx - resLen)/2;
        return s.substr(resIdx, resLen);
    }
};
