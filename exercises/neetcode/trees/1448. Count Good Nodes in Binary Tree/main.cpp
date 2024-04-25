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
private:
    int preOrdem(TreeNode* root, int maxValue){
        if(root == NULL)
            return 0;
        int add = root->val >= maxValue ? 1 : 0;
        maxValue = max(maxValue, root->val);
        return add + preOrdem(root->left, maxValue) + preOrdem(root->right, maxValue);
    }
public:
    int goodNodes(TreeNode* root) {
        return preOrdem(root, root->val);
    }
};
