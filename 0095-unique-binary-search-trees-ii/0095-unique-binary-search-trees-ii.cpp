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
    vector<TreeNode*> build(int l, int r){
        vector<TreeNode*> res;
        if(l>r){
            res.push_back(NULL);
            return res;
        }
        for(int i = l;i<=r;++i){
            vector<TreeNode*>lTree = build(l, i - 1);
            vector<TreeNode*>rTree = build(i + 1, r);
            for(int j = 0;j<lTree.size();j++){
                for(int k = 0;k<rTree.size();k++){
                    TreeNode* root = new TreeNode(i);
                    root->left = lTree[j];
                    root->right = rTree[k];
                    res.push_back(root);
                }
            }
        }
        return res;
    }
    vector<TreeNode*> generateTrees(int n) {
        // left subtree will start from 0 to i - 1 index
        // root at i
        // right subtree from i + 1 to n index

        return build(1, n);
        // we pass index start = 1 , end = n
    }
};