/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //正确的递归做法：

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL || root==p || root==q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if(left!=NULL && right!=NULL) return root;
        return left==NULL?right:left;
    }
};
 
 
 //超时做法
class Solution {
public:
    bool flag=false;
    void getPath(TreeNode* current, TreeNode* target, vector<TreeNode*>& finalPath, vector<TreeNode*>path){
        path.push_back(current);
        if(current == target){
            flag = true;
            finalPath = path;
            return;
        }else{
            if(current->left!=NULL && !flag){
                getPath(current->left, target, finalPath, path);
            }
            if(current->right!=NULL && !flag){
                getPath(current->right, target, finalPath, path);
            }
        }
        path.pop_back();
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pathOfp, pathOfq;
        vector<TreeNode*> path;
        flag = false;
        getPath(root, p, pathOfp, path);
        flag = false;
        getPath(root, q, pathOfq, path);
        int i=0;
        for(i=0; i<pathOfp.size() && i<pathOfq.size(); i++){
            if(pathOfp[i] != pathOfq[i]){
                break;
            }
        }
        if(i == pathOfp.size()){
            return pathOfp[i-1];
        }else if(i == pathOfq.size()){
            return pathOfq[i-1];
        }else{
            return pathOfp[i-1];
        }
    }
};