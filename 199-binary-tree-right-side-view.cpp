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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> q;
        if(root!=NULL){
            q.push(root);
        }
        while(!q.empty()){
            ans.push_back(q.back()->val);
            queue<TreeNode*> tmpQ;
            while(!q.empty()){
                TreeNode* tmp = q.front();
                q.pop();
                if(tmp->left!=NULL){
                    tmpQ.push(tmp->left);
                }
                if(tmp->right!=NULL){
                    tmpQ.push(tmp->right);
                }
            }
            q = tmpQ;
        }
        return ans;
    }
};