/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parent;

    void inorder(TreeNode* root){
        if(root == NULL) return;

        if(root->left != NULL){
            parent[root->left] = root;
        }
        inorder(root->left);

        if(root->right != NULL){
            parent[root->right] = root;
        }
        inorder(root->right);

    }
    
    void bfs(TreeNode* target, int k, vector<int>& res){
        queue<TreeNode*> que;
        que.push(target);

        unordered_set<int> vis;
        vis.insert(target->val);

        while(!que.empty()){
            int lvl = que.size();

            if(k == 0) break;
            
            while(lvl--){
                TreeNode* curr= que.front();
                que.pop();

                if(curr->left != NULL && !vis.count(curr->left->val)){
                    que.push(curr->left);
                    vis.insert(curr->left->val);
                } 
                
                if(curr->right != NULL && !vis.count(curr->right->val)){
                    que.push(curr->right);
                    vis.insert(curr->right->val);
                } 

                if(parent.count(curr) && !vis.count(parent[curr]->val)){
                    que.push(parent[curr]);
                    vis.insert(parent[curr]->val);
                }  
            }
            k--;
        }

        while(!que.empty()){
            TreeNode* temp = que.front();
            que.pop();

            res.push_back(temp->val);
        }
    }


    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> res;

        inorder(root);

        bfs(target, k, res);

        return res;
        
    }
};