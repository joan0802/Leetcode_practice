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
	int DFS(TreeNode* root, int mx) {
		int cnt = 0;
		if(root == NULL)
			return 0;
        if(root->val < mx)
            return cnt += DFS(root->left, mx) + DFS(root->right, mx);
        else {
            mx = root->val;
            return cnt += DFS(root->left, mx) + DFS(root->right, mx) + 1;
        }
    }
    int goodNodes(TreeNode* root) {
        return DFS(root, root->val);
    }
};
