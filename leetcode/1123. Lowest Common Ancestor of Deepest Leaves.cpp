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

    TreeNode* GetDeepestNodeAncestor(TreeNode* root, int height, int nodeHeight[]) {
        if (!root) {
            return NULL;
        }
        if (root->left &&
            root->right &&
            nodeHeight[root->left->val] == height - 1 &&
            nodeHeight[root->right->val] == height - 1) {
            return root;
        }
        if (!root->left &&
            !root->right &&
            nodeHeight[root->val] == height) {
            return root;
        }
        TreeNode* lRes = GetDeepestNodeAncestor(root->left, height - 1, nodeHeight);
        TreeNode* rRes = GetDeepestNodeAncestor(root->right, height - 1, nodeHeight);
        return lRes == NULL ? rRes : lRes;
    }
    int GetTreeHeight(TreeNode* root, int nodeHeight[]) {
        if (!root) {
            return 0;
        }
        int lHeight = GetTreeHeight(root->left, nodeHeight);
        int rHeight = GetTreeHeight(root->right, nodeHeight);

        if (root->left) {
            nodeHeight[root->left->val] = lHeight;
        }
        if (root->right) {
            nodeHeight[root->right->val] = rHeight;
        }
        return 1 + max(lHeight, rHeight);
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if (root == NULL) {
            return root;
        }
        int nodeHeight[1001] = {0};
        nodeHeight[root->val] = GetTreeHeight(root, nodeHeight);
        return GetDeepestNodeAncestor(root, nodeHeight[root->val], nodeHeight);

    }
};