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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (root == NULL) {
            return root;
        }
        TreeNode* tmp = root;
        if (d > 1) {
            helper(root, v, d);
        } else {
            tmp = new TreeNode(v);
            tmp->left = root;
        }

        return tmp;
    }
    void helper(TreeNode* root, int v, int d) {
        if (d == 2) {
            TreeNode* l = new TreeNode(v);
            l->left = root->left;
            TreeNode* r = new TreeNode(v);
            r->right = root->right;
            root->left = l;
            root->right = r;
            return;
        }
        if (root->left) {
            helper(root->left, v, d - 1);
        }
        if (root->right) {
            helper(root->right, v, d - 1);
        }
    }
};