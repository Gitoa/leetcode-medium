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
    void inTraversalRecursive(TreeNode* root, vector<int>& ans){
        if(!root){
            return;
        }else{
            inTraversalRecursive(root->left, ans);
            ans.push_back(root->val);
            inTraversalRecursive(root->right, ans);
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;
        TreeNode* curr = root;
        while(!s.empty()||curr!=NULL){
            while(curr!=NULL){
                s.push(curr);
                curr = curr->left;
            }
            curr = s.top();
            s.pop();
            ans.push_back(curr->val);
            curr = curr->right;
        }
        return ans;
    }
};