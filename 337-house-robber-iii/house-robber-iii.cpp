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
    unordered_map<TreeNode*, vector<int>> dp;
    
    int rob(TreeNode* root){

        return dfs(root, 0);        
    }

    int dfs(TreeNode* root, int isPaRob){
        if(root == NULL){
            return 0;
        }

       if(!dp.count(root)){
         dp[root] = {-1, -1};
       }

        if(dp[root][isPaRob] != -1){
            return dp[root][isPaRob];
        }

        int pick = 0;
        if(isPaRob == 0){
            pick = root->val +  dfs(root->left, 1) + dfs(root->right, 1);
        }

        int skip = dfs(root->left, 0) + dfs(root->right, 0);

        return dp[root][isPaRob] = max(pick, skip);
    } 
};