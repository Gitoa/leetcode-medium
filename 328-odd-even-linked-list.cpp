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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode *oddEnd = head;
        ListNode *evenBegin = head->next;
        ListNode *evenEnd = head->next;
        bool isOdd = true;
        ListNode *tmp = head->next->next;
        while(tmp!=NULL){
            if(isOdd){
                oddEnd->next = tmp;
                oddEnd = oddEnd->next;
            }else{
                evenEnd->next = tmp;
                evenEnd = evenEnd->next;
            }
            tmp = tmp->next;
            isOdd = !isOdd;
        }
        oddEnd->next = evenBegin;
        evenEnd->next = NULL;
        return head;
    }
};