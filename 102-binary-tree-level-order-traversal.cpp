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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<TreeNode*> s;
        vector<TreeNode*> childSet;
        vector<int> tmpAns;
        vector<vector<int>> ans;
        if(root==NULL){
            return ans;
        }
        s.push_back(root);
        while(!s.empty()){
            TreeNode* tmp = *s.begin();
            s.erase(s.begin());
            tmpAns.push_back(tmp->val);
            if(tmp->left!=NULL){
                childSet.push_back(tmp->left);
            }
            if(tmp->right!=NULL){
                childSet.push_back(tmp->right);
            }
            if(s.empty()){
                s = childSet;
                childSet.clear();
                ans.push_back(tmpAns);
                tmpAns.clear();
            }
        }
        return ans;
    }
};