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
    int camReqd=0;
    int solve(TreeNode* root){
        if(!root)
            return 0;
        int lTree = solve(root->left);
        int rTree = solve(root->right);
        if(lTree==2||rTree==2){
            // that means no cam present
            camReqd++;
            // now these are getting monitored
            return 1;
        }
        if(lTree==1||rTree==1){
            // already monitored
            return 0;
        }
        return 2;
        // in case no cam present return 2
    }
    int minCameraCover(TreeNode* root) {
        // there are 2 cases:
        // if node has camera 0
        // if node doesnt have:
            // i) covered by some other 1
            // ii) needs to be covered 2(doesnt have)
        
        int func = solve(root);
        if(func==2)
            camReqd++;
        return camReqd;
    }
};
