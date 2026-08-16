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
    int maxDepth(TreeNode* root) {

        int depth = helper(root);
        return depth;
        
    }
    int helper(TreeNode* root){
        if(root == NULL){
            return 0;
        }

        int leftDepth = helper(root->left);
        int rightDepth = helper(root->right);

        return 1 + max(leftDepth, rightDepth);
    }
};