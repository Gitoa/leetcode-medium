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
private:
    int currentVal=2147483648;
    int nextVal;
    bool ans=true;
    bool firstVal=false;
public:
    void binarySearch(TreeNode* root){
        if(!root || !ans){
            return;
        }
        binarySearch(root->left);
        if(!firstVal){
            currentVal = root->val;
            firstVal = true;
        }else{
            nextVal = root->val;
            if(nextVal <= currentVal){
                ans = false;
            }
            currentVal = nextVal;
        }
        binarySearch(root->right);
    }
    bool isValidBST(TreeNode* root) {
        binarySearch(root);
        return ans;
    }
};