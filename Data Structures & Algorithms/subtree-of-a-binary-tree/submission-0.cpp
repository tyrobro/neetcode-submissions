/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    string serialize(TreeNode* root){
        if(!root){
            return "$#";
        }
        return "$"+to_string(root->val)+serialize(root->left)+serialize(root->right);
    }

    vector<int> helper(string s){
        int l = 0, r = 0, n = s.length();
        vector<int> z(n);

        for(int i = 1; i < n; i++){
            if(i <= r){
                z[i] = min(r - i + 1, z[i-l]);
            }
            
            while (i + z[i] < n && s[z[i]] == s[i + z[i]]){
                z[i]++;
            }

            if(i + z[i] - 1 > r){
                l = i;
                r = i + z[i] - 1;
            }
        }

        return z;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string rootSerial = serialize(root);
        string subRootSerial = serialize(subRoot);
        string combo = subRootSerial + "|" + rootSerial;

        vector<int> helping = helper(combo);
        int subLen = subRootSerial.length();
        int n = combo.length();

        for(int i = subLen + 1; i <n; i++ ){
            if(helping[i] == subLen){
                return true;
            }
        }

        return false;
    }
};
