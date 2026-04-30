class Solution {
public:
    string encode(vector<string>& strs) {
        string code;
        for (string &str : strs) {
            code += to_string(str.size()) + "#" + str;
        }
        return code;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int i = 0;
        while (i < s.size()) {
            int j = i;
            while (s[j] != '#') j++; // find separator
            int len = stoi(s.substr(i, j - i)); // extract length
            string word = s.substr(j + 1, len);
            result.push_back(word);
            i = j + 1 + len; // move to next encoded string
        }
        return result;
    }
};