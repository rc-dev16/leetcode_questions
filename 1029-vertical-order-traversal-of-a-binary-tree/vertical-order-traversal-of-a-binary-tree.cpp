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
    map<int,map<int, multiset<int>>> mp;
    // imagine it like mp[col][row] = {values}   

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;

        dfs(root, 0, 0);

        for(auto col : mp){
            vector<int> temp;
            for(auto row : col.second){
                for(auto val : row.second){
                    temp.push_back(val);
                }
            }
            res.push_back(temp);
        }

        return res;
    }

    void dfs(TreeNode* root, int row, int col){
        if(root == NULL){
            return;
        }

        mp[col][row].insert(root->val);

        dfs(root->left, row+1, col-1);

        dfs(root->right, row+1, col+1);
    }    
};