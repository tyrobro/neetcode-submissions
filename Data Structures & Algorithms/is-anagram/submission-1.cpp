class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int>counter1;
    int len1 = s.size();
    int len2 = t.size();
    if(len1 == len2)
    {
        for(int i = 0; i < len1; i++)
        {
            counter1[s[i]]++;
            counter1[t[i]]--;
        }
        for(auto &p: counter1)
        {
            if(p.second != 0)
            {
                return false;
            }
            
        }
        return true;
    } 
    else{
        return false;
    }
    }
};