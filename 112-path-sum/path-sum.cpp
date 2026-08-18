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
    bool hasPath = false;
    bool hasPathSum(TreeNode* root, int targetSum) {

        int currSum = 0;

        if(root == NULL) return 0;

        helper(root, currSum, targetSum);

        return hasPath;
    }

    void helper(TreeNode* root, int currSum, int targetSum){

        if(root->left == NULL && root->right == NULL){
            if((currSum + root->val) == targetSum){
                hasPath = true;
            }
        }

        if(root->left){
            helper(root->left, currSum + root->val, targetSum);
        }

        if(root->right){
            helper(root->right, currSum + root->val, targetSum);
        }
    }
};