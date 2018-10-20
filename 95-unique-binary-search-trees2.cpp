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
    vector<TreeNode*> createNodes(int left, int right){
        vector<TreeNode*> res;
        if(left>right){
            res.push_back(NULL);
            return res;
        }else{
            for(int i=left; i<=right; i++){
                vector<TreeNode*> leftList = createNodes(left, i-1);
                vector<TreeNode*> rightList = createNodes(i+1, right);
                for(int k=0; k<leftList.size(); k++){
                    for(int j=0; j<rightList.size(); j++){
                        TreeNode* tmp = new TreeNode(i);
                        tmp->left = leftList[k];
                        tmp->right = rightList[j];
                        res.push_back(tmp);
                    }
                }
            }
        }
        return res;
    }
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> ans;
        if(n==0){
            return ans;
        }
        return createNodes(1, n);
    }
};