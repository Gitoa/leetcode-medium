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
    struct fcNode{
        TreeLinkNode *fNode, *cNode;
        fcNode(): fNode(NULL), cNode(NULL){}
    };
    bool haveChild(TreeLinkNode* root){
        return (root->left!=NULL || root->right!=NULL);
    }
    fcNode nextNodeChild(TreeLinkNode* root){
        TreeLinkNode* tmp = root->next;
        fcNode ansNode;
        while(tmp!=NULL){
            if(haveChild(tmp)){
                ansNode.fNode = tmp;
                if(tmp->left!=NULL){
                    ansNode.cNode = tmp->left;
                }else{
                    ansNode.cNode = tmp->right;
                }
                break;
            }
            tmp = tmp->next;
        }
        return ansNode;
    }
    fcNode nextNode(fcNode root){
        fcNode ansNode;
        TreeLinkNode *fNode = root.fNode;
        TreeLinkNode *cNode = root.cNode;
        if(fNode->left == cNode){
            if(fNode->right!=NULL){
                ansNode.fNode = fNode;
                ansNode.cNode = fNode->right;
            }else{
                ansNode = nextNodeChild(fNode);
            }
        }else{
            ansNode = nextNodeChild(fNode);
        }
        return ansNode;
    }
    void connectNode(TreeLinkNode* root){
        if(root==NULL){     
            return;
        }
        TreeLinkNode* tmp = root;
        TreeLinkNode* nextLevel = root->left;
        fcNode firstNode;
        while(tmp!=NULL){
            if(!haveChild(tmp)){
                tmp = tmp->next;
            }else{
                if(tmp->left!=NULL){
                    if(nextLevel==NULL){
                        nextLevel = tmp->left;
                    }
                    firstNode.fNode = tmp;
                    firstNode.cNode = tmp->left;
                }else{
                    if(nextLevel==NULL){
                        nextLevel = tmp->right;
                    }
                    firstNode.fNode = tmp;
                    firstNode.cNode = tmp->right;
                }
                break;
            }
        }
        fcNode tmpNode = firstNode;
        while(tmpNode.cNode!=NULL){
            fcNode nextFcNode = nextNode(tmpNode);
            tmpNode.cNode->next = nextFcNode.cNode;
            tmpNode = nextFcNode;
        }
        connectNode(nextLevel);
        
    }
    void connect(TreeLinkNode *root) {
        connectNode(root);
    }
};