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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> lv;
        if(root != NULL)
            lv.push(root);
        while(!lv.empty()) {
            int size = lv.size();
            for(int i = 0; i < size; i++) {
                TreeNode* top = lv.front();
                lv.pop();
                if(top->left != NULL)
                    lv.push(top->left);
                if(top->right != NULL)
                    lv.push(top->right);
                if(i == size-1)
                    ans.push_back(top->val);
            }
        }
        return ans;
    }
};