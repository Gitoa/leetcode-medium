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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *fir=new ListNode(0);
        ListNode *sec, *third, *ans;
        if(!head){
            return NULL;
        }
        if(!head->next){
            return head;
        }
        fir->next = head;
        ans = fir;
        sec = head;
        third = head->next;
        while(third){
            if(third->val == sec->val){
                while(third){
                    if(third->val != sec->val){
                        break;
                    }
                    third = third->next;
                }
                fir->next = third;
                if(!third || !third->next){
                    break;
                }else{
                    sec = third;
                    third = third->next;
                }
            }else{
                fir = sec;
                sec = third;
                third = third->next;
            }
        }
        return ans->next;
    }
};