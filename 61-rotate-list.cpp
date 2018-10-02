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
    ListNode* rotateRight(ListNode* head, int k) {
        int len=1;
        ListNode* ans=head;
        ListNode* tmp=head;
        if(!head){
            return head;
        }
        while(tmp->next){
            len++;
            tmp=tmp->next;
        }
        k=k%len;
        if(!k){
            return head;
        }
        tmp->next=head;
        for(int i=0; i<len-k; i++){
            tmp=tmp->next;
        }
        ans=tmp->next;
        tmp->next=NULL;
        return ans;
    }
};