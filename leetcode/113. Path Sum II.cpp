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
    vector<vector<int>> res;
    void helper(TreeNode* root, int sum, vector<int>& q) {
      if (root == NULL) {
          return;
      }
      q.push_back(root->val);
      if (root->val == sum && root->left == NULL && root->right == NULL) {
          res.push_back(q);
          q.pop_back();
          return;
      }
      if (root->left) {
          helper(root->left, sum - root->val, q);
      }
      if (root->right) {
          helper(root->right, sum - root->val, q);
      }
      q.pop_back();
      return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
      if (root == NULL) {
          return res;
      }
      vector<int> q;
      helper(root, sum, q);
      return res;
    }
};