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
    int totalMax = INT_MIN;
    int helper(TreeNode* root){
        if(!root){
            return 0;
        }

        int lProfit = max(helper(root->left), 0);
        int rProfit = max(helper(root->right), 0);

        int curSum = lProfit + rProfit + root->val;
        totalMax = max(curSum, totalMax);

        return root->val + max(lProfit, rProfit);
    }
    int maxPathSum(TreeNode* root) {
        helper(root);
        return totalMax;
    }
};
