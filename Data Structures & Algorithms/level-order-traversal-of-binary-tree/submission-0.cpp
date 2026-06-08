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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            vector<int> depths;
            int n = q.size();

            for(int i = n; i > 0; i--){
                TreeNode* node = q.front();
                q.pop();

                if(node){
                    depths.push_back(node->val);
                    q.push(node->left);
                    q.push(node->right);
                }
            }

            if(!depths.empty()){
                ans.push_back(depths);
            }
        }

        return ans;
    }
};
