class Solution {
private:
    pair<int, int> dfs(TreeNode* node, int& validCount) {
        if (!node) return {0, 0};
        auto left = dfs(node->left, validCount);
        auto right = dfs(node->right, validCount);
        int sum = left.first + right.first + node->val;
        int count = left.second + right.second + 1;
        if (node->val == sum / count) {
            validCount++;
        }
        return {sum, count};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        int validCount = 0;
        dfs(root, validCount);
        return validCount;
    }
};