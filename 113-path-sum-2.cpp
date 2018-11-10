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
    vector<int> tmpPath;
    vector<vector<int>> ans;
public:
    void DFSTraversal(TreeNode* node, int tmpSum, int sum){
        if(tmpSum == sum && node->left == NULL && node->right == NULL){
            ans.push_back(tmpPath);
        }else{
            if(node->left != NULL){
                tmpPath.push_back(node->left->val);
                DFSTraversal(node->left, tmpSum + node->left->val, sum);
                tmpPath.erase(tmpPath.end()-1);
            }
            if(node->right != NULL){
                tmpPath.push_back(node->right->val);
                DFSTraversal(node->right, tmpSum + node->right->val, sum);
                tmpPath.erase(tmpPath.end()-1);
            }
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(root==NULL){
            return ans;
        }
        tmpPath.push_back(root->val);
        DFSTraversal(root, root->val, sum);
        return ans;
    }
};