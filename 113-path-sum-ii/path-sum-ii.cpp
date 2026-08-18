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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

        vector<int> path;
        vector<vector<int>> res;

        helper(root, 0, targetSum, path, res);

        return res;
    }

    void helper(TreeNode* root, int cs, int ts, vector<int> path, vector<vector<int>> &res){
        if(!root){
            return;
        }

        cs += root->val;
        path.push_back(root->val);

        if(root->left == NULL && root->right == NULL){
            if(cs == ts) res.push_back(path);
        }

        helper(root->left, cs, ts, path, res);
        helper(root->right, cs, ts, path, res);
    }
};