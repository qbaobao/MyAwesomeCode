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
  TreeNode* helper(TreeNode* root) {
	  if (root->right) {
		  helper(root->right);
	  }
	  if (root->left == NULL) {
		  return root;
	  }
	  TreeNode* tmp = helper(root->left);
	  tmp->left = NULL;
	  for (; tmp->right; tmp = tmp->right);
	  tmp->right = root->right ? root->right : tmp->right;
	  root->right = root->left ? root->left : root->right;
	  root->left = NULL;
	  return tmp;
  }
  void flatten(TreeNode* root) {
	  if (!root) {
		  return;
	  }
	  helper(root);
	  return;
  }
};