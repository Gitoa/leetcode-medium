/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* createNode(int left, int right, vector<int>& valList){
        if(right<left){
            return NULL;
        }
        int mid = (left+right)/2;
        TreeNode* tmp = new TreeNode(valList[mid]);
        tmp->left = createNode(left, mid-1, valList);
        tmp->right = createNode(mid+1, right, valList);
        return tmp;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> valList;
        ListNode* p = head;
        while(p!=NULL){
            valList.push_back(p->val);
            p=p->next;
        }
        return createNode(0, valList.size()-1, valList);
    }
};