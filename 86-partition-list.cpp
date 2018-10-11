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
    ListNode* partition(ListNode* head, int x) {
        ListNode *leftHead = new ListNode(0), *rightHead = new ListNode(0);
        ListNode *fir = head, *leftEnd = leftHead, *rightEnd = rightHead;
        while(fir){
            ListNode *tmp = new ListNode(fir->val);
            if(fir->val<x){
                leftEnd->next = tmp;
                leftEnd = leftEnd->next;
            }else{
                rightEnd->next = tmp;
                rightEnd = rightEnd->next;
            }
            fir = fir->next;
        }
        leftEnd->next = rightHead->next;
        return leftHead->next;
    }
};