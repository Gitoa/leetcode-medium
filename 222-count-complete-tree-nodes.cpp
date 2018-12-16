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
    int ans = 0;
    int getLeftH(TreeNode* node){
        int n = 0;
        while(node->left != NULL){
            n ++;
            node = node->left;
        }
        return n;
    }
    int getRightH(TreeNode* node){
        int n = 0;
        while(node->right != NULL){
            n ++;
            node = node->right;
        }
        return n;
    }
    void dfs(TreeNode* node){
        int leftH = getLeftH(node);
        int rightH = getRightH(node);
        if(leftH == rightH){
            ans += (pow(2, leftH+1) - 1);
        }else{
            ans += 1;
            if(node->left != NULL){
                dfs(node->left);
            }
            if(node->right != NULL){
                dfs(node->right);
            }
        }
    }
    int countNodes(TreeNode* root) {
        TreeNode* tmp = root;
        int h = 0;
        while(tmp!=NULL){
            h ++;
            tmp = tmp -> left;
        }
        cout<<h<<endl;
        if(h == 0){
            return 0;
        }else if(h == 1){
            return 1;
        }else{
            dfs(root);
            return ans;
        }      
    }
};

//faster answer:

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
    int countNodes(TreeNode *root) {
        if(root==NULL) return 0;
        
        int l = getLeft(root) + 1;
        int r = getRight(root) + 1;
        
        if(l==r) {
            return (2<<(l-1)) - 1;
        } else {
            return countNodes(root->left) + countNodes(root->right) + 1;
        }
    }
    
private:
    int getLeft(TreeNode *root) {
        int count = 0;
        while(root->left!=NULL) {
            root = root->left;
            ++count;
        }
        return count;
    }
    int getRight(TreeNode *root) {
        int count = 0;
        while(root->right!=NULL) {
            root = root->right;
            ++count;
        }
        return count;
    }
};