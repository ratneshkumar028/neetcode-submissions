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
    TreeNode* replaceValueInTree(TreeNode* root) {
        root->val = 0;
        vector<TreeNode*> level{root};
        while (!level.empty()) {
            vector<TreeNode*> next;
            int total = 0;
            for (auto node : level) {
                if (node->left) {
                    next.push_back(node->left);
                    total += node->left->val;
                }
                if (node->right) {
                    next.push_back(node->right);
                    total += node->right->val;
                }
            }
            for (auto node : level) {
                int siblings =
                    (node->left ? node->left->val : 0) + (node->right ? node->right->val : 0);
                if (node->left) node->left->val = total - siblings;
                if (node->right) node->right->val = total - siblings;
            }
            level = move(next);
        }
        return root;
    }
};
