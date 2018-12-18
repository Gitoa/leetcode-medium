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
    int pos = 0, ans = -1;
    void preTraversal(TreeNode* root, int k){
        if(root->left != NULL){
            preTraversal(root->left, k);
        }
        pos ++;
        if(pos == k){
            ans = root->val;
        }else{
            if(root->right != NULL){
                preTraversal(root->right, k);
            }    
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        preTraversal(root, k);
        return ans;
    }
};