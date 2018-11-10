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
    TreeNode* rightNode(TreeNode* root){
        TreeNode* tmpNode = root->left;
        while(tmpNode->right!=NULL){
            tmpNode = tmpNode->right;
        }
        return tmpNode;
    }
    void flat(TreeNode* root){
        if(root == NULL){
            return;
        }
        TreeNode* rightNodeTmp;
        if(root->left != NULL){
            rightNodeTmp = rightNode(root);
            rightNodeTmp->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }
        flat(root->right);
    }
    void flatten(TreeNode* root) {
        flat(root);
    }
};