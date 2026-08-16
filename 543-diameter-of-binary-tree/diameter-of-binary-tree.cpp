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
    int res = INT_MIN;
    int diameterOfBinaryTree(TreeNode* root) {

        helper(root);

        return res;
        
    }

    int helper(TreeNode* root){
        if(root == NULL) return 0;

        int lh = helper(root->left);
        int rh = helper(root->right);

        res = max(res, lh + rh);

        return 1 + max(lh, rh);
    }
};