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
    int ans = 0;
    
    struct info{
        bool isBst;
        int mx;
        int mn;
        int sum;
    };

    int maxSumBST(TreeNode* root) {
        postDfs(root);
        return ans;
    }

    info postDfs(TreeNode* root){
        if(root == NULL){
            return {true, INT_MIN, INT_MAX, 0};
        }

        info l = postDfs(root->left);
        info r = postDfs(root->right);

        if(l.isBst && r.isBst && l.mx < root->val && r.mn > root->val){
            int currSum = l.sum + r.sum + root->val;

            ans = max(ans, currSum);

            return {
                true,
                max({l.mx, root->val, r.mx}),
                min({l.mn, root->val, r.mn}),
                currSum
            };
        }

        return {false, 0, 0, 0};
    }

};