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
    TreeNode* buildTreeTmp(int inLeft, int inRight, int preLeft, int preRight, vector<int>& preorder, vector<int>& inorder){
        if(inRight>=inLeft){
            TreeNode* tmp = new TreeNode(preorder[preLeft]);
            int pos=inLeft;
            for(pos=inLeft; pos<=inRight; pos++){
                if(inorder[pos] == preorder[preLeft]){
                    break;
                }
            }
            tmp->left = buildTreeTmp(inLeft, pos-1, preLeft+1, preLeft+1+pos-1-inLeft, preorder, inorder);
            tmp->right = buildTreeTmp(pos+1, inRight, preRight-(inRight-pos-1), preRight, preorder, inorder);
            return tmp;
        }
        return NULL;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTreeTmp(0, preorder.size()-1, 0, preorder.size()-1, preorder, inorder);
    }
};