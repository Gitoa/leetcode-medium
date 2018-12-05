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
    ListNode* insertionSortList(ListNode* head) {
        if(head==NULL){
            return head;
        }
        ListNode* h = new ListNode(0);
        h->next = head;
        ListNode* t = head;
        ListNode* pos = h;
        ListNode* cur = head->next;
        t->next = NULL;
        while(cur!=NULL){
            pos = h;
            if(cur->val > t->val){
                t->next = cur;
                t = cur;
                cur = cur->next;
                t->next = NULL;
                continue;
            }
            while(pos!=t){
                if(cur->val <= pos->next->val){
                    ListNode* next = cur->next;
                    cur->next = pos->next;
                    pos->next = cur;
                    cur = next;
                    break;
                }
                pos = pos->next;
            }
        }
        return h->next;
    }
};