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
    int DFS(TreeNode* root, int& dia) {
        if(root == NULL)
            return 0;
        int left = DFS(root->left, dia);
        int right = DFS(root->right, dia);
        dia = max(dia, right+left); // node 的直徑
        return max(left, right) + 1; // node 的高度
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int dia = 0;
        DFS(root, dia);
        return dia;
    }
};