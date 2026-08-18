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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        if(!root) return {};

        vector<vector<int>> res;

        bool ltor = true;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int lvlSize = q.size();

            vector<int> temp;

            while(lvlSize--){
                auto curr= q.front();
                temp.push_back(curr->val);

                q.pop();

                if(curr->left){
                    q.push(curr->left);
                }

                if(curr->right){
                    q.push(curr->right);
                }
            }

            if(ltor == false){
                reverse(temp.begin(), temp.end());
            }

            ltor = !ltor;

            res.push_back(temp);
        }
        return res;
    }
};