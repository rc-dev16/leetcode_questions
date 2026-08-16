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
bool isBal = true;
    bool isBalanced(TreeNode* root) {

        helper(root);
        return isBal;
        
    }
    int helper(TreeNode* l){
       if(l == NULL) return 0;

       int lh = helper(l->left);

       int rh = helper(l->right);

       if(abs(lh - rh) > 1) isBal = false;

       return 1 + max(lh, rh); 
    }
};