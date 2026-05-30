class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        if(n1 > n2){
            return false;
        }
        int l = 0;
        int r = l+n1;
        vector<int> s1arr(26, 0) ;
        vector<int> s2arr(26, 0);

        for (int i = 0; i < n1; i++) {
            s1arr[s1[i] - 'a']++;
            s2arr[s2[i] - 'a']++;
        }

        for (int i = 0; i < n2 - n1; i++) {
            if (s1arr == s2arr) return true;

            s2arr[s2[i] - 'a']--;
            s2arr[s2[i + n1] - 'a']++;
        }

        return s1arr == s2arr;
    }
};
