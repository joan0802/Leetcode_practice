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

// inorder traversal -> time complexity: O(n)
class Solution {
public:
    void dfs(TreeNode* root, vector<int>& node) {
        if(root == NULL)
            return;
        if(root->left != NULL) {
            dfs(root->left, node);
        }
        node.push_back(root->val);
        if(root->right != NULL) {
            dfs(root->right, node);
        }
    }
    int getMinimumDifference(TreeNode* root) {
        vector<int> node;
        dfs(root, node);
        int ans = INT_MAX;
        for(int i = 1; i < node.size(); ++i) {
            ans = min(ans, node[i]-node[i-1]);
        }
        return ans;
    }
};