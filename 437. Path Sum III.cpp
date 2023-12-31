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
    int cnt = 0;
    void Sum(TreeNode* root, long long target) {
        if(root == NULL)
            return;

        if(root->val == target)
            cnt++;
        Sum(root->left, target-root->val);
        Sum(root->right, target-root->val);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root) {
            Sum(root, targetSum);
            pathSum(root->left, targetSum);
            pathSum(root->right, targetSum);
        }
        return cnt;
    }
};