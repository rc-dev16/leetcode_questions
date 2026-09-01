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
    int res = 0;
    int amountOfTime(TreeNode* root, int start) {
        postDfs(root, start);
        return res;
    }

    int postDfs(TreeNode* root, int &start){
        if(root == NULL) return 0;

        int l = postDfs(root->left, start);
        int r = postDfs(root->right, start);

        if(root->val == start){
            res = max(l, r);
            return -1;
        } else if(l >=0 && r >= 0){
            return max(l, r) + 1;
        } else{
            int d = abs(l) + abs(r);
            res = max(res, d);
            return min(l, r) - 1;
        }

        return 0; 
    }
};