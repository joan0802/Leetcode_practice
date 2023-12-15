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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL)
            return root;
        if(root->val > key)
            root->left = deleteNode(root->left, key);
        else if(root->val < key)
            root->right = deleteNode(root->right, key);
        else {
            TreeNode *right = root->right;
            TreeNode *left = root->left;
            if(right == NULL && left == NULL) // don't have child
                return NULL;
            else if(right == NULL || left == NULL) { // have one child
                return (right == NULL) ? left : right;
            }
            else { // two children
                TreeNode* pre = root;
                TreeNode* cur = right;
                
                while(cur && cur->left != NULL) {
                    pre = cur;
                    cur = cur->left;
                }
                root->val = cur->val; // replace the value of root
                root->right = deleteNode(root->right, cur->val); // delete the node that is moved to root
            }
        }
        return root;
    }
};
