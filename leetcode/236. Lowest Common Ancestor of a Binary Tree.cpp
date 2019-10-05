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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == p && root == q) {
            return root;
        }
        if (root == p && (root->left == q || root->right == q)) {
            return root;
        }
        if (root == q && (root->left == p || root->right == p)) {
            return root;
        }
        if (!root && (q || p)) {
            return NULL;
        }
        deque<TreeNode*> qp,qq;
        FindNode(p, root, qp);
        FindNode(q, root, qq);
        while (qp.size() > qq.size()) {
            qp.pop_front();
        }
        while (qp.size() < qq.size()) {
            qq.pop_front();
        }
        for (; qp.front() != qq.front(); qp.pop_front(), qq.pop_front()) ;

        return qp.front();
    }
    bool FindNode(TreeNode* target, TreeNode* cur, deque<TreeNode*>& que)
    {
        if (cur == target) {
            que.push_back(cur);
            return true;
        }
        if (!cur) {
            return false;
        }
        if (FindNode(target, cur->left, que) || FindNode(target, cur->right, que)) {
            que.push_back(cur);
            return true;
        }
        return false;
    }
};