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
    ListNode *detectCycle(ListNode *head) {
        vector<ListNode*> v;
        ListNode* p = head;
        while(p!=NULL){
            if(find(v.begin(), v.end(), p) != v.end()){
                return p;
            }
            v.push_back(p);
            p=p->next;
        }
        return NULL;
    }
};