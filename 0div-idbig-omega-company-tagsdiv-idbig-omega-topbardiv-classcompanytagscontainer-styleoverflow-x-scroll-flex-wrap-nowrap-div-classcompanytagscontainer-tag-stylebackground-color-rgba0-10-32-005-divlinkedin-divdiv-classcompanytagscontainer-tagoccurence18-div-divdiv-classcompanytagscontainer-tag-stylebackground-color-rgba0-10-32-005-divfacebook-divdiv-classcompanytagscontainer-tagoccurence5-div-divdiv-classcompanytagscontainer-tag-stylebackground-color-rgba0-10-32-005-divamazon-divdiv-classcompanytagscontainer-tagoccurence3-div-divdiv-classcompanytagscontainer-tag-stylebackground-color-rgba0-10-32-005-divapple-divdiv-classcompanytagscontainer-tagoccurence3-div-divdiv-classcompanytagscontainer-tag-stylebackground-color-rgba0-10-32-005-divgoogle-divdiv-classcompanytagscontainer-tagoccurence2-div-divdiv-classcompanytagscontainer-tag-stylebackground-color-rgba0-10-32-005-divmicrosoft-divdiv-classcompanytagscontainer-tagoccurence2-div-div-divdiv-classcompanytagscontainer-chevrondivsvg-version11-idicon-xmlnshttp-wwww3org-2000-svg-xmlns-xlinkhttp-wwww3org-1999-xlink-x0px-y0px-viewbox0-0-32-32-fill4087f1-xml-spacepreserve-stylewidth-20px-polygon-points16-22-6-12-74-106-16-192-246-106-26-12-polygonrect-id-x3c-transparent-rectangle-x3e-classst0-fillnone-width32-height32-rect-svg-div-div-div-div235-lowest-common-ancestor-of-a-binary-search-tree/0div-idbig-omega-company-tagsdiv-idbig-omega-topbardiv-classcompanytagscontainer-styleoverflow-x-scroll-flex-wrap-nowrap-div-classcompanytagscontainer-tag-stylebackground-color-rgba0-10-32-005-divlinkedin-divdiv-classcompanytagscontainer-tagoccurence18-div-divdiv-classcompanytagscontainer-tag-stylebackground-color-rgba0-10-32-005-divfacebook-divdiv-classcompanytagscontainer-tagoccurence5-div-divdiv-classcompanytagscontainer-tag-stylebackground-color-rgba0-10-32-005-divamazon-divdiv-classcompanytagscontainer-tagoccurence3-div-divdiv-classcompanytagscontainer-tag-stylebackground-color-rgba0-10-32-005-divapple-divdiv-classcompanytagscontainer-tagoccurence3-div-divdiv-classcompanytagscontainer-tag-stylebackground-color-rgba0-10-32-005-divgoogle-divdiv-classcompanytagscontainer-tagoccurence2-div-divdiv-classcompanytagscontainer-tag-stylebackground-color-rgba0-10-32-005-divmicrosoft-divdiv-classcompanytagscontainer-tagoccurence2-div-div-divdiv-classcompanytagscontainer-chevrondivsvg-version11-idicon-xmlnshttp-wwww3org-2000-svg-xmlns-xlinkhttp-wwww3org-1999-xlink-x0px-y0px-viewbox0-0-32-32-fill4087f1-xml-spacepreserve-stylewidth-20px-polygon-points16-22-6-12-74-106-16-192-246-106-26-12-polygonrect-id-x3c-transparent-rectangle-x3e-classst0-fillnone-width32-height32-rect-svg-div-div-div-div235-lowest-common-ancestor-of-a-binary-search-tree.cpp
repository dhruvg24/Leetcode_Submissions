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
        while(1){
            int diffp = root->val - p->val;
            int diffq = root->val - q->val;
            if(diffp>0 && diffq>0){
//                 both p and q are on the left
                root = root->left;
            }
            else if(diffp<0 && diffq<0){
//                 both on right
                root = root->right;
            }
            else{
                break;
//                 both are on opp sides the curr node is the node being LCA
            }
        }
        return root;
    }
};