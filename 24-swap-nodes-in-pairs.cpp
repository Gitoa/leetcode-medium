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
    ListNode* swapPairs(ListNode* head) {
        ListNode *pre = new ListNode(0);
        ListNode *ans;
        pre->next = head;
        ListNode *p = head;
        if(!head||!(head->next)){
            return head;
        }
        bool flag=true;
        while(p){
            ListNode *next = p->next;
            if(!next){
                break;
            }
            pre->next = next;
            p->next = next->next;
            next->next = p;
            if(flag){
                ans = pre->next;
                flag=false;
            }
            int i=2;
            if(!p){
                break;
            }
            pre=pre->next->next;
            p=p->next;
        }
        return ans;
    }
};