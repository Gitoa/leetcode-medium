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
    vector<vector<int>> ans;
    vector<int> levelAns;
    vector<TreeNode*> currentLevel;
    vector<TreeNode*> nextLevel;
    bool reverseLevel = false;
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root){
            return ans;
        }
        currentLevel.push_back(root);
        while(!currentLevel.empty()){
            TreeNode* tmp = *currentLevel.begin();
            currentLevel.erase(currentLevel.begin());
            levelAns.push_back(tmp->val);
            if(tmp->left!=NULL){
                nextLevel.push_back(tmp->left);
            }
            if(tmp->right!=NULL){
                nextLevel.push_back(tmp->right);
            }
            if(currentLevel.empty()){
                if(reverseLevel){
                    reverse(levelAns.begin(), levelAns.end());
                    reverseLevel = false;
                }else{
                    reverseLevel = true;
                }
                ans.push_back(levelAns);
                levelAns.clear();
                currentLevel = nextLevel;
                nextLevel.clear();
            }
        }
        return ans;
    }
};