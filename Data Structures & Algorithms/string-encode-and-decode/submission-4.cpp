class Solution {
public:

    string encode(vector<string>& strs) {
        string ans = "";
        for(auto s : strs){
            ans+= to_string(s.size())+'!'+s;
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int i = 0;
        int len = s.size();

        while(i < len){
            int j = i;

            while(s[j] != '!'){
                j++;
            }

            int width  = stoi(s.substr(i, j - i));

            string str = s.substr(j+1, width);
            result.push_back(str);

            i = j + 1 + width;
        }

        return result;
        
    }
};
