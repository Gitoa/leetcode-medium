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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head, *pre, *p;
		head = new ListNode(0);
		pre = head;
		int carry = 0;
		while(l1&&l2){
			int tmp = l1->val + l2->val + carry;
			p = new ListNode(tmp%10);
			pre->next = p;
			pre = p;
			carry = tmp/10;
			l1 = l1->next;
			l2 = l2->next;
		}
		while(l1){
			int tmp = l1->val + carry;
			p = new ListNode(tmp%10);
			pre->next = p;
			pre = p;
			carry = tmp/10;
			l1 = l1->next;
		}
		while(l2){
			int tmp = l2->val + carry;
			p = new ListNode(tmp%10);
			pre->next = p;
			pre = p;
			carry = tmp/10;
			l2 = l2->next;
		}
		if(carry!=0){
			p = new ListNode(carry%10);
			pre->next = p;
			pre = p;
			carry = carry/10;
		}
		return head->next;
    }
};
