/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connectNext(TreeLinkNode* root){
        if(root==NULL){
            return;
        }
        if(root->left==NULL){
            return;
        }
        TreeLinkNode* tmp = root;
        while(tmp->next!=NULL){
            tmp->left->next = tmp->right;
            tmp->right->next = tmp->next->left;
            tmp = tmp->next;
        }
        tmp->left->next = tmp->right;
        connectNext(root->left);
    }
    void connect(TreeLinkNode *root) {
        connectNext(root);
    }
};