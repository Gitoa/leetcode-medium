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
    void reorderList(ListNode* head) {
        vector<ListNode*> v;
        ListNode* p = head;
        while(p!=NULL){
            v.push_back(p);
            p = p->next;
        }
        int top=0, bottom=v.size()-1;
        if(bottom<1){
            return;
        }
        while(bottom>top+1){
            v[bottom]->next = v[top]->next;
            v[top]->next = v[bottom];
            top++;
            bottom--;
        }
        v[bottom]->next = NULL;
    }
};