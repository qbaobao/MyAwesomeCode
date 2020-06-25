/**
 * Definition for a binary tree node.
 */
 

 struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
 };

int helper(struct TreeNode* node, int* res)
{
    if (node == NULL) {
        return 1;
    }
    int l = helper(node->left, res);
    int r = helper(node->right, res);
    if (l == 0 || r == 0) {
        (*res)++;
        return 2;
    }
    if (l == 1 && r == 1) {
        return 0;
    }
    return 1;
}


int minCameraCover(struct TreeNode* root){
    int res = 0;
    if (helper(root, &res) < 1) {
        res++;
    }
    return res;
}