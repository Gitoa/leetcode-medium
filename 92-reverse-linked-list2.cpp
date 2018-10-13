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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *nodeBeforeM = new ListNode(0);
        nodeBeforeM->next = head;
        int pos = 1;
        for(;pos<m; pos++){
            nodeBeforeM = nodeBeforeM->next;
        }
        ListNode *fir = nodeBeforeM->next;
        ListNode *sec = fir->next;
        if(!sec){
            return head;
        }
        ListNode *tmp = sec->next;
        for(int i=m; i<n; i++){
            sec->next = fir;
            fir = sec;
            sec = tmp;
            if(!tmp){
                break;
            }
            tmp = tmp->next;
        }
        nodeBeforeM->next->next = sec;
        nodeBeforeM->next = fir;
        if(m==1){
            return nodeBeforeM->next;
        }
        return head;
    }
};