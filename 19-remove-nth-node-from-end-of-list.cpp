/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p = head;
        ListNode *ans = new ListNode(0);
        ans->next = head;
        while(n--){
            p=p->next;
        }
        if(p==NULL){
            return head->next;
        }
        ListNode *preN = head;
        while(p!=NULL){
            p=p->next;
            preN=preN->next;
            ans=ans->next;
        }
        ans->next=preN->next;
        return head;
    }
};
