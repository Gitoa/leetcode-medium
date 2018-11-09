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
    TreeNode* buildTreeNode(int inLeft, int inRight, int postLeft, int postRight, vector<int>& inorder, vector<int>& postorder){
        if(inRight>=inLeft){
            TreeNode* tmp = new TreeNode(postorder[postRight]);
            int pos = inLeft;
            for(pos; pos<=inRight; pos++){
                if(inorder[pos] == postorder[postRight]){
                    break;
                }
            }
            tmp->left = buildTreeNode(inLeft, pos-1, postLeft, postLeft+pos-1-inLeft, inorder, postorder);
            tmp->right = buildTreeNode(pos+1, inRight, postLeft+pos-inLeft, postRight-1, inorder, postorder);
            return tmp;
        }
        return NULL;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTreeNode(0, inorder.size()-1, 0, inorder.size()-1, inorder, postorder);
    }
};