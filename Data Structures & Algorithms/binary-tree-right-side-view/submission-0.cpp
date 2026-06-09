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
    vector<vector<int>> bfs(TreeNode* root){
        vector<vector<int>> ans;
        if(!root) return ans;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            vector<int> depth;
            int n = q.size();

            for(int i = n; i > 0; i--){
                TreeNode* node = q.front();
                q.pop();

                if(node){
                    depth.push_back(node->val);
                    q.push(node->left);
                    q.push(node->right);
                }
            }

            if(!depth.empty()){
                ans.push_back(depth);
            }
        }

        return ans;
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<vector<int>> levelView = bfs(root);

        int n = levelView.size();
        vector<int> ans;
        for(int i = 0; i < n; i++){
            int m = levelView[i].size();
            if(m > 0){
                ans.push_back(levelView[i][m-1]);
            } else {
                ans.push_back(0);
            }
        }

        return ans;
    }
};
