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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        if(root->val % 2 == 0) return false;
        int level = 0;
        while(!q.empty()) {
            int s = q.size();
            int pre = 0;
            for(int i = 0; i < s; i++) {
                auto top = q.front();
                q.pop();
                if(level % 2 == 0) {
                    if((pre == 0 || top->val > pre) && top->val % 2 == 1)
                        pre = top->val;
                    else
                        return false;
                }
                else{
                    if((pre == 0 || top->val < pre) && top->val % 2 == 0)
                        pre = top->val;
                    else
                        return false;
                }
                if(top->left != NULL) q.push(top->left);
                if(top->right != NULL) q.push(top->right);
            }
            level++;
        }
        return true;
    }
};