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
    vector<string> binaryTreePaths(TreeNode* root) {

        vector<string> res;
        string path = to_string(root->val);

        helper(root, res, path);

        return res;
    }

    void helper(TreeNode* root, vector<string> &res, string path){


        if(root->left == NULL && root->right == NULL){
            res.push_back(path);
            return;
        }

        path += "->";
        if(root->left){
            helper(root->left,  res,  path+to_string(root->left->val));
        }

        if(root->right){
            helper(root->right, res,  path + to_string(root->right->val));
        }

    }
};