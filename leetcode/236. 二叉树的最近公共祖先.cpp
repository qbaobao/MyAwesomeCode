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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if (root == nullptr) {
            return nullptr;
        }
        helper(root, p, q);
        return res;
    }
    bool helper(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if (!root) {
            return false;
        }
        bool l = helper(root->left, p, q);
        bool r = helper(root->right, p, q);

        if (((root == p || root == q) && (r || l)) ||
            (l && r)) {
            res = root;
        }
        return root == p || root == q || l || r;
    }
private:
    TreeNode* res = nullptr;
};