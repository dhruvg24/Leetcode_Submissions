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
    void solve(TreeNode* root, int par, int gPar, int &ans){
        if(root == NULL){
            return;
        }
        if(gPar%2 == 0){
            ans += root->val;
        }
        solve(root->left, root->val, par, ans);
        // gPar becomes par, par becomes root->val
        solve(root->right, root->val, par, ans);
    }
    int sumEvenGrandparent(TreeNode* root) {
        int ans = 0;
        // need to pass the parent and grandparent in recursion
        solve(root, -1, -1, ans);
        return ans;
    }
};