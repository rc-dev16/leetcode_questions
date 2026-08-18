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
    int longestUnivaluePath(TreeNode* root) {
        int maxLen = 0;

        dfs(root, maxLen);
        return maxLen;
    }

    int dfs(TreeNode* root, int &maxLen){
        if(!root) return 0;

        int leftPath = dfs(root->left, maxLen);
        int rightPath = dfs(root->right, maxLen);

        int leftMatch = 0;
        int rightMatch = 0;

        if(root->left != NULL && root->val == root->left->val)
            leftMatch = leftPath + 1;
             
        if(root->right != NULL && root->val == root->right->val)
            rightMatch = rightPath + 1;

        maxLen = max(maxLen, leftMatch + rightMatch);

        return max(leftMatch, rightMatch);
    }
};