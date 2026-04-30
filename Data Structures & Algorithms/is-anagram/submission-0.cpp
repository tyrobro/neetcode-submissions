class Solution {
public:
    bool isAnagram(string s, string t) {
        int lens = s.size();
        int lent = t.size();
        if (lens != lent) {
            return false;
        } else {
            sort(s.begin(), s.end());
            sort(t.begin(), t.end());
            if(s==t)
            {
                return true;
            }
        }
        return false; 
    }
};