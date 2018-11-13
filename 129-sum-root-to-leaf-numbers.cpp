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
    int ans=0;
public:
    bool notLeaf(TreeNode* root){
        return (root->left!=NULL || root->right!=NULL);
    }
    void sumPath(TreeNode* root, vector<int>path){
        if(!notLeaf(root)){
            int tmp=0;
            for(int i=0; i<path.size(); i++){
                tmp *= 10;
                tmp += path[i];
            }
            ans += tmp;
        }else{
            if(root->left!=NULL){
                path.push_back(root->left->val);
                sumPath(root->left, path);
                path.erase(path.end()-1);
            }
            if(root->right!=NULL){
                path.push_back(root->right->val);
                sumPath(root->right, path);
                path.erase(path.end()-1);
            }
        }
    }
    int sumNumbers(TreeNode* root) {
        if(root==NULL){
            return ans;
        }
        vector<int>path;
        path.push_back(root->val);
        sumPath(root, path);
        return ans;
    }
};